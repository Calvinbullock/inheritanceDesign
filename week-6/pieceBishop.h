/***********************************************************************
 * Header File:
 *   Bishop 
 * Author:
 *    Calvin Bullock, Daniel Malasky
 * Summary:
 *    The Bishop class
 ************************************************************************/

#pragma once

#include "piece.h"
#include "pieceType.h"

 /***************************************************
  * Bishop
  * The Bishop
  ***************************************************/
class Bishop: public Piece
{
public:
   Bishop(const Position& pos, bool isWhite) : Piece(pos, isWhite) { }
   Bishop(int c, int r, bool isWhite) : Piece(c, r, isWhite) { }
   ~Bishop() {                }
   PieceType getType()            const { return BISHOP; }
   void getMoves(set <Move>& moves, const Board& board) const;
   void display(ogstream* pgout)  const;
};
