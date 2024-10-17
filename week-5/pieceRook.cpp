/***********************************************************************
 * Source File:
 *   Rook
 * Author:
 *    Calvin Bullock, Daniel Malasky
 * Summary:
 *    The Rook class
 ************************************************************************/

#include "pieceRook.h"
#include "board.h"
#include "position.h"
#include "uiDraw.h"    // for draw*()

void Rook::display(ogstream* pgout) const
{
}


void Rook::getMoves(set<Move>& moves, const Board& board) const
{
   {
      CR posMoves[4] =
      {
                  {0,  1},
         {-1, 0},         {1, 0},
                  {0, -1}
      };

      PieceType pt;
      Position newPos = this->position;

      for (int i = 0; i < 4; i++)
      {
         // first move
         newPos.setCol(this->position.getCol() + posMoves[i].c);
         newPos.setRow(this->position.getRow() + posMoves[i].r);

         // slide while new move valid, and a space or an enemy
         while (newPos.isValid() && (board[newPos].getType() == SPACE || this->fWhite != board[newPos].isWhite()))
         {
            // set new move
            Move m;
            pt = board[newPos].getType();
            m = this->position.getColRowText()     // src
               + newPos.getColRowText()            // dest
               + m.letterFromPieceType(pt);        // capture

            moves.insert(m); // add new move

            // next move
            newPos.setCol(newPos.getCol() + posMoves[i].c);
            newPos.setRow(newPos.getRow() + posMoves[i].r);

         }
      }
   }
}


