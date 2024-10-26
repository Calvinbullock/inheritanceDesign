
/***********************************************************************
 * Source File:
 *   Bishop 
 * Author:
 *    Calvin Bullock, Daniel Malasky
 * Summary:
 *    The Bishop class
 ************************************************************************/

#include "pieceBishop.h"
#include "board.h"
#include "position.h"
#include "uiDraw.h"    // for draw*()

 /***************************************************
 * PIECE DRAW
 * Draw all the pieces.
 ***************************************************/
void Bishop::display(ogstream* pgout) const
{
   pgout->drawBishop(position, !fWhite);
}

/**********************************************
 * BISHOP : GET POSITIONS
 *********************************************/
void Bishop::getMoves(set <Move>& moves, const Board& board) const
{
   {
      CR posMoves[4] =
      {
         {-1,  1}, {1,  1},
         {-1, -1}, {1, -1}
      };

      PieceType pt;
      Position newPos = this->position;

      for (int i = 0; i < 4; i++)
      {
         // first move
         newPos.setCol(this->position.getCol() + posMoves[i].c);
         newPos.setRow(this->position.getRow() + posMoves[i].r);

         bool enemyHit = false;
         
         // slide while new move valid, and a space or an enemy
         while (newPos.isValid() &&
            (board[newPos].getType() == SPACE || this->fWhite != board[newPos].isWhite())
            && enemyHit == false)
         {
            // set new move
            Move m;
            pt = board[newPos].getType();
            m = this->position.getColRowText()     // src
               + newPos.getColRowText()            // dest
               + m.letterFromPieceType(pt);        // capture
 
            moves.insert(m); // add new move
            
            // stop if enemy hit
            if (this->fWhite != board[newPos].isWhite() && board[newPos].getType() != SPACE)
            {
               enemyHit = true;
            }

            // next move
            newPos.setCol(newPos.getCol() + posMoves[i].c);
            newPos.setRow(newPos.getRow() + posMoves[i].r);
            
         }
      }
   }
}
