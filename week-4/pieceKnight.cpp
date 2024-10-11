/***********************************************************************
 * Source File:
 *    KNIGHT
 * Author:
 *    <your name here>
 * Summary:
 *    The knight class
 ************************************************************************/

#include "pieceKnight.h"
#include "board.h"
#include "uiDraw.h"    // for draw*()

 /***************************************************
 * PIECE DRAW
 * Draw all the pieces.
 ***************************************************/
void Knight::display(ogstream* pgout) const
{

}


/**********************************************
 * KNIGHT : GET POSITIONS
 *********************************************/
void Knight::getMoves(set <Move>& moves, const Board& board) const
{
   
   int r;                   // the row we are checking
   int c;                   // the column we are checking

   Position possibleMoves[8] =
   {
            {-1,  2}, { 1,  2},
   {-2,  1},                    { 2,  1},
   {-2, -1},                    { 2, -1},
            {-1, -2}, { 1, -2}
   };

   for (int i = 0; i < 8; i++)
   {
      //r = this->position.getRow() + possibleMoves[i].getRow();
      //c = this->position.getCol() + possibleMoves[i].getCol();



      if (possibleMoves[i].isValid())
      {
         // check if potential move is opposite color or a space.
         if (this->fWhite != board[possibleMoves[i]].isWhite() || board[possibleMoves[i]].getType() == SPACE)
         {
            moves.insert(possibleMoves[i].getColRowText()); //insert a possible move.
         }

      }

      

      //if (amBlack && isNotBlack(board, c, r))
      //   possible.insert(r * 8 + c);
      //if (!amBlack && isNotWhite(board, c, r))
      //   possible.insert(r * 8 + c);
   }
}