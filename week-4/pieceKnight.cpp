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
#include "pieceType.h"
#include "position.h"
#include "uiDraw.h"    // for draw*()
#include <iostream>

 /***************************************************
 * PIECE DRAW
 * Draw all the pieces.
 ***************************************************/
void Knight::display(ogstream* pgout) const
{
   pgout->drawKnight(position, fWhite);
}


struct CR {
   int c;
   int r;
};

/**********************************************
 * KNIGHT : GET POSITIONS
 *********************************************/
void Knight::getMoves(set <Move>& moves, const Board& board) const
{
   /*int r;                   // the row we are checking*/
   /*int c;                   // the column we are checking*/
   /**/
/*Position possibleMoves[8] = {*/
/*            Position(-1,  2), Position(1,  2),*/
/*     Position(-2,  1),                 Position(2,  1),*/
/*     Position(-2, -1),                 Position(2, -1),*/
/*            Position(-1, -2), Position(1, -2)*/
/*};*/

   CR posMoves[8] = 
   {
               {-1,  2}, { 1,  2},
      {-2,  1},                    { 2,  1},
      {-2, -1},                    { 2, -1},
               {-1, -2}, { 1, -2}
   };

   for (int i = 0; i < 8; i++)
   {
      Move m;
      Position pos;
      pos.setCol(this->position.getCol() + posMoves[i].c);
      pos.setRow(this->position.getRow() + posMoves[i].r);
      m = pos.getColRowText();
      //std::cout << pos.getColRowText() << std::endl;
      moves.insert(m); //insert a possible move.
      
      //r = this->position.getRow() + possibleMoves[i].getRow();
      //c = this->position.getCol() + possibleMoves[i].getCol();

      /*if (possibleMoves[i].isValid())*/
      /*{*/
      /*   // check if potential move is opposite color or a space.*/
      /*   if (this->fWhite != board[possibleMoves[i]].isWhite() || board[possibleMoves[i]].getType() == SPACE)*/
      /*   {*/
      /*std::cout << possibleMoves[i].getColRowText() << std::endl;*/

      /*   }*/
      /*}*/

      //if (amBlack && isNotBlack(board, c, r))
      //   possible.insert(r * 8 + c);
      //if (!amBlack && isNotWhite(board, c, r))
      //   possible.insert(r * 8 + c);
   }
}
