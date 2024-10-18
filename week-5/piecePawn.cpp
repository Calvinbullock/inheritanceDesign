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

   // black pawn
   if (!this->fWhite)
   {
      newPos.setRow(this->position.getRow() - 2); // forward 2 spaces
      newPos.setCol(this->position.getCol());
      
      // valid move
      if (newPos.isValid())
      {
         // starting row and has not moved
         if (this->position.getRow() == 6 && !this->isMoved())
         {
            Move m;
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
         Move m;
         m = this->position.getColRowText()     // src
            + newPos.getColRowText();           // dest

         // check if potential move is a space.
         if (board[this->position].getType() == SPACE)
         {
            moves.insert(m); //insert a possible move.
         }
         
      }
   }

}

void Pawn::display(ogstream* pgout) const
{
   pgout->drawPawn(position, !fWhite);
}
