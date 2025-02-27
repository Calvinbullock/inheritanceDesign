/***********************************************************************
 * Header File:
 *    QUEEN
 * Author:
 *    Calvin Bullock, Daniel Malasky
 * Summary:
 *    The QUEEN class
 ************************************************************************/

#pragma once

#include "piece.h"

 /***************************************************
  * QUEEN
  ***************************************************/
class Queen : public Piece
{
public:
   Queen(const Position& pos, bool isWhite) : Piece(pos, isWhite) { }
   Queen(int c, int r, bool isWhite) : Piece(c, r, isWhite) { }
   ~Queen() {                }
   PieceType getType()            const { return QUEEN; }
   void getMoves(set <Move>& moves, const Board& board) const;
   void display(ogstream* pgout)  const;
};
