/***********************************************************************
 * Source File:
 *    MOVE 
 * Author:
 *    Calvin Bullock, Daniel Malasky
 * Summary:
 *    Everything we need to know about a single chess move
 ************************************************************************/

#include "move.h"
#include "pieceType.h"
#include <cassert>
#include <iostream>
#include <sstream>

using namespace std;

/***************************************************
 * MOVE : DEFAULT CONSTRUCTOR
 ***************************************************/
Move::Move() : source(), dest(), promote(INVALID),
   capture(INVALID), moveType(MOVE_ERROR), isWhite(true), text("")
{
   
}

/***************************************************
 * MOVE : LETTER FROM PIECE TYPE
 ***************************************************/
char Move::letterFromPieceType(PieceType pt)     const 
{ 
   switch (pt) 
   {
      case SPACE:
         return ' ';
         break;
      case PAWN:
         return 'p';
      case BISHOP:
         return 'b';
      case KNIGHT:
         return 'n';
      case ROOK:
         return 'r';
      case QUEEN:
         return 'q';
      case KING:
         return 'k';
      case INVALID:
         return 'i';
      default:
         return 'i';
   }
}

/***************************************************
 * MOVE : PIECE TYPE FROM LETTER 
 ***************************************************/
PieceType Move::pieceTypeFromLetter(char letter) const
{ 
   switch (letter) 
   {
      case ' ':
         return SPACE;
      case 'p':
         return PAWN;
      case 'b':
         return BISHOP;
      case 'n':
         return KNIGHT;
      case 'r':
         return ROOK;
      case 'q':
         return QUEEN;
      case 'k':
         return KING;
      case 'i':
         return INVALID;
      default:
         return INVALID;
   }
}

/***************************************************
 * MOVE : READ
 * reads smith notation to a move
 ***************************************************/
void Move::read(string moveText)
{
   text = moveText;
   source = moveText.substr(0, 2);
   dest = moveText.substr(2, 5);
   moveType = MOVE; // default move

   if (moveText.length() == 5)
   {  
      switch (moveText[4])
      {
      case 'p':   // capture a pawn
      case 'n':   // capture a knight
      case 'b':   // capture a bishop
      case 'r':   // capture a rook
      case 'q':   // capture a queen
      case 'k':   // !! you can't capture a king you silly!
         capture = pieceTypeFromLetter(moveText[4]);
         moveType = MOVE;
         break;
      case 'E':
         moveType = ENPASSANT;
         break;
      case 'C':
         moveType = CASTLE_QUEEN;
         break;
      case 'c':
         moveType = CASTLE_KING;
         break;
      case 'N':  // Promote to knight
      case 'B':  // Promote to Bishop
      case 'R':  // Promote to Rook
      case 'Q':  // Promote to Queen
         promote = pieceTypeFromLetter(moveText[4]);
      default:
         moveType = MOVE_ERROR;
      }
   }
}

/***************************************************
 * MOVE : GET TEXT
 * gets smith notation from a move
 ***************************************************/
string Move::getText()
{
   string moveText;

   moveText.append(source.getColRowText());
   moveText.append(dest.getColRowText());


   if (capture != INVALID)
   {
      switch (capture)
      {
      case PAWN:     // capture a pawn
      case KNIGHT:   // capture a knight
      case BISHOP:   // capture a bishop
      case ROOK:     // capture a rook
      case QUEEN:    // capture a queen
         //case KING:   // !! you can't capture a king you silly!
         moveText.push_back(letterFromPieceType(capture));
         break;
      }
   }

   if (moveType != MOVE_ERROR || moveType != MOVE)
   {
      switch (moveType)
      {
      case ENPASSANT:
         moveText.push_back('E');
         break;
      case CASTLE_QUEEN:
         moveText.push_back('C');
         break;
      case CASTLE_KING:
         moveText.push_back('c');
         break;
      }
   }
   return moveText;
}


