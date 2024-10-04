/***********************************************************************
 * Source File:
 *    MOVE 
 * Author:
 *    <your name here>
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
Move::Move()
{
}

char Move::letterFromPieceType(PieceType pt)     const 
{ 
   switch (pt) {
      case SPACE:
         return ' ';
         break;
      case PAWN:
         return 'p';
         break;
      case BISHOP:
         return 'b';
         break;
      case KNIGHT:
         return 'n';
         break;
      case ROOK:
         return 'r';
         break;
      case QUEEN:
         return 'q';
         break;
      case KING:
         return 'k';
         break;
      case INVALID:
         return 'i';
         break;
      default:
         return 'i';
   }
}

PieceType Move::pieceTypeFromLetter(char letter) const
{ 
   switch (letter) {
      case ' ':
         return SPACE;
         break;
      case 'p':
         return PAWN;
         break;
      case 'b':
         return BISHOP;
         break;
      case 'n':
         return KNIGHT;
         break;
      case 'r':
         return ROOK;
         break;
      case 'q':
         return QUEEN;
         break;
      case 'k':
         return KING;
         break;
      case 'i':
         return INVALID;
         break;
      default:
         return INVALID;
   }
}


