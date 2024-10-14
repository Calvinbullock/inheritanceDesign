
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
   pgout->drawBishop(position, fWhite);
}

/**********************************************
 * KNIGHT : GET POSITIONS
 *********************************************/
void Bishop::getMoves(set <Move>& moves, const Board& board) const
{
   CR posMoves[8] = 
   {
               {-1,  2}, { 1,  2},
      {-2,  1},                    { 2,  1},
      {-2, -1},                    { 2, -1},
               {-1, -2}, { 1, -2}
   };

   PieceType pt;
   Position newPos;
   
   for (int i = 0; i < 8; i++)
   {
      // TODO: change to adjusts
      newPos.setCol(this->position.getCol() + posMoves[i].c);
      newPos.setRow(this->position.getRow() + posMoves[i].r);

      if (newPos.isValid())
      {
         Move m;
         pt = board[newPos].getType();
         string smithText = position.getColRowText() 
                  + newPos.getColRowText() 
                  + m.letterFromPieceType(pt);
         m = smithText;
         /*std::cout << "L61 " << m.getText() << std::endl;*/
         /*std::cout << "smith " << smith << std::endl;;*/

         // check if potential move is a space.
         if (board[newPos].getType() == SPACE)
         {
            moves.insert(m); //insert a possible move.
         } 
         else 
         {
            // check if color is opposite
            if (this->fWhite != board[newPos].isWhite()) 
            {
               moves.insert(m); //insert a possible move.
            }
         }
      }
   }
}
