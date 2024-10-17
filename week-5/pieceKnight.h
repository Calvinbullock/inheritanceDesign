/***********************************************************************
 * Header File:
 *    KNIGHT
 * Author:
 *    Calvin Bullock, Daniel Malasky
 * Summary:
 *    The KNIGHT class
 ************************************************************************/

#pragma once

#include "piece.h"

 /***************************************************
  * KNIGHT
  * The knight, aka the "Horse"
  ***************************************************/
class Knight : public Piece
{
public:
   Knight(const Position& pos, bool isWhite) : Piece(pos, true) { }
   Knight(int c, int r, bool isWhite) : Piece(c, r, true) { }
   ~Knight() {                }
   PieceType getType()            const { return KNIGHT; }
   void getMoves(set <Move>& moves, const Board& board) const override;

   void display(ogstream* pgout)  const;
};
