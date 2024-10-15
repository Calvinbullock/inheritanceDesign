/***********************************************************************
 * Header File:
 *    PAWN
 * Author:
 *    Calvin Bullock, Daniel Malasky
 * Summary:
 *    The PAWN class
 ************************************************************************/

#pragma once

#include "piece.h"

 /***************************************************
  * PAWN
  ***************************************************/
class Pawn : public Piece
{
public:
   Pawn(const Position& pos, bool isWhite) : Piece(pos, true) { }
   Pawn(int c, int r, bool isWhite) : Piece(c, r, true) { }
   ~Pawn() {                }
   PieceType getType()            const { return PAWN; }
   void getMoves(set <Move>& moves, const Board& board) const;
   void display(ogstream* pgout)  const;
};
