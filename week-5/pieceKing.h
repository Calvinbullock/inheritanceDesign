/***********************************************************************
 * Header File:
 *    KING
 * Author:
 *    Calvin Bullock, Daniel Malasky
 * Summary:
 *    The KING class
 ************************************************************************/

#pragma once

#include "piece.h"

 /***************************************************
  * KING
  ***************************************************/
class King : public Piece
{
public:
   King(const Position& pos, bool isWhite) : Piece(pos, true) { }
   King(int c, int r, bool isWhite) : Piece(c, r, true) { }
   ~King() {                }
   PieceType getType()            const { return KING; }
   void getMoves(set <Move>& moves, const Board& board) const;
   void display(ogstream* pgout)  const;
};
