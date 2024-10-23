/**********************************************************************
 * Source File:
 *    KNIGHT
 * Author:
 *    Calvin Bullock, Daniel Malasky
 * Summary:
 *    The knight class
 ************************************************************************/

#include "pieceKing.h"
#include "board.h"
#include "pieceType.h"
#include "position.h"
#include "uiDraw.h"    // for draw*()
#include <iostream>



/**********************************************
 * KING : GET POSITIONS
 *********************************************/
void King::getMoves(set<Move>& moves, const Board& board) const
{
   CR posMoves[8] = 
   {
         {-1,  1}, {0,  1}, {1,  1},
         {-1,  0},          {1,  0},
         {-1, -1}, {0, -1}, {1, -1}
   };

   PieceType pt;
   Position newPos;
   
   for (int i = 0; i < 8; i++)
   {
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
   
   Position rookPos = Position(0, 0);
   Position empty1 = Position(1, 0);
   Position empty2 = Position(2, 0);
   Position empty3 = Position(3, 0);

   // white
   if (this->fWhite) {

      if (!this->hasMoved() &&                 // queen side castle
         !board[rookPos].hasMoved() &&          // rook not moved
         board[rookPos].getType() == ROOK &&  // rook exists in starting spot
         board[empty1].getType() == SPACE &&  // b1 is empty
         board[empty2].getType() == SPACE &&  // c1 is empty
         board[empty3].getType() == SPACE)    // d1 is empty
      {
         Move m = (string)"e1c1C";
         moves.insert(m); 
      }

      empty1.set(5, 0);
      empty2.set(6, 0);
      rookPos.set(7, 0);

      if (!this->hasMoved() &&                 // king side castle
         !board[rookPos].hasMoved() &&          // rook not moved
         board[rookPos].getType() == ROOK &&  // rook exists in starting spot
         board[empty1].getType() == SPACE &&  // f1 is empty
         board[empty2].getType() == SPACE)    // g1 is empty
      {
         Move m = (string)"e1g1c";
         moves.insert(m); 
      }
   } 
   else // black
   {
      empty1.set(3, 7);
      empty2.set(2, 7);
      empty3.set(1, 7);
      rookPos.set(0, 7);

      if (!this->hasMoved() &&                 // queen side castle
         !board[rookPos].hasMoved() &&          // rook not moved
         board[rookPos].getType() == ROOK &&  // rook exists in starting spot
         board[empty1].getType() == SPACE &&  // b8 is empty
         board[empty2].getType() == SPACE &&  // c8 is empty
         board[empty3].getType() == SPACE)    // d8 is empty
      {
         Move m = (string)"e8c8C";
         moves.insert(m); 
      }

      empty1.set(5, 7);
      empty2.set(6, 7);
      rookPos.set(7, 7);

      if (!this->hasMoved() &&                 // king side castle
         !board[rookPos].hasMoved() &&          // rook not moved
         board[rookPos].getType() == ROOK &&  // rook exists in starting spot
         board[empty1].getType() == SPACE &&  // f8 is empty
         board[empty2].getType() == SPACE)    // g8 is empty
      {
         Move m = (string)"e8g8c";
         moves.insert(m); 
      }
   }

}

 /***************************************************
 * PIECE DRAW
 ***************************************************/
void King::display(ogstream* pgout) const
{
   pgout->drawKing(position, !fWhite);
}
