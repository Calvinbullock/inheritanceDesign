/***********************************************************************
 * Source File:
 *    Pawn
 * Author:
 *    Calvin Bullock, Daniel Malasky
 * Summary:
 *    The Pawn class
 ************************************************************************/

#include "piecePawn.h"
#include "board.h"
#include "pieceType.h"
#include "position.h"
#include "uiDraw.h"    // for draw*()
#include <iostream>

void Pawn::getMoves(set<Move>& moves, const Board& board) const
{
   
   CR whitePosMoves[8] =
   {
               { 1, 0 },
               { 2, 0 }
   };
   CR blackPosMoves[8] =
   {
               { -1, 0 },
               { -2, 0 }
   };
   
   Position newPos;
   Move m;

   // black pawn
   if (!this->fWhite)
   {
      newPos.setRow(this->position.getRow() - 2); // forward 2 spaces
      newPos.setCol(this->position.getCol());
      
      // valid move
      if (newPos.isValid())
      {
         // starting row and has not moved
         if (this->position.getRow() == 6 && this->isMoved())
         {
            m = this->position.getColRowText()     // src
               + newPos.getColRowText();           // dest

            // check if potential move is a space.
            if (board[this->position].getType() == SPACE)
            {
               moves.insert(m); //insert a possible move.
            }
         }
      }

      newPos.setRow(this->position.getRow() - 1); // forward 1 space
      // valid move
      if (newPos.isValid())
      {
         m = this->position.getColRowText()     // src
            + newPos.getColRowText();           // dest

         // check if potential move is a space.
         if (board[newPos].getType() == SPACE)
         {
            moves.insert(m); //insert a possible move.
         }
      }
      
      Position pawnRight = Position(this->position.getCol() + 1, this->position.getRow());
      Position pawnLeft  = Position(this->position.getCol() - 1, this->position.getRow());
      Position spaceRight = Position(this->position.getCol() + 1, this->position.getRow() - 1);
      Position spaceLeft  = Position(this->position.getCol() - 1, this->position.getRow() - 1);

      if (this->position.getRow() == 4) // en-passont
      {
         if (board[pawnRight].getType() == PAWN && 
               board[pawnRight].justMoved(board.getCurrentMove()) &&
               board[pawnLeft].isWhite())
         {
            m = this->position.getColRowText() // src
               + spaceRight.getColRowText() + (string)"E";   // dest
            moves.insert(m);
         }
         if (board[pawnLeft].getType() == PAWN && 
               board[pawnLeft].justMoved(board.getCurrentMove()) && 
               board[pawnLeft].isWhite())
         {

            m = this->position.getColRowText() // src
               + spaceLeft.getColRowText() + (string)"E";   // dest
            moves.insert(m);
         }
      }
   }
}

void Pawn::display(ogstream* pgout) const
{
   pgout->drawPawn(position, !fWhite);
}
