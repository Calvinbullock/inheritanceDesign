/***********************************************************************
 * Source File:
 *    PIECE 
 * Author:
 *    Calvin Bullock, Daniel Malasky
 * Summary:
 *    The Piece base class and all the derived classes:
 *       SPACE, KING, QUEEN, ROOK, KNIGHT, BISHOP, PAWN
 ************************************************************************/

#include "position.h"  // for POSITION
#include "piece.h"     // for all the PIECE class definitions
#include "board.h"     // for BOARD
#include "uiDraw.h"    // for draw*()
#include <cassert>     // because we are paranoid
using namespace std;


/************************************************
 * PIECE : Constructor
 ***********************************************/
Piece::Piece(const Position & pos, bool isWhite)   
{ 
   position = pos; 
   fWhite = isWhite; 
}

/************************************************
 * PIECE : Constructor
 ***********************************************/
Piece::Piece(int c, int r, bool isWhite) 
{ 
   position.setCol(c); 
   position.setRow(r); 
   fWhite = isWhite;
   nMoves = 0;
   lastMove = 0;
}

/************************************************
 * PIECE : ASSIGN
 ***********************************************/
const Piece & Piece::operator = (const Piece & rhs)
{
   this->fWhite = rhs.fWhite;
   this->nMoves = rhs.nMoves;
   this->lastMove = rhs.lastMove;
   this->position = rhs.position;

   return *this;
}

///************************************************
// * PIECE : GET MOVES
// * Iterate through the moves decorator to allow a piece to move
// ***********************************************/
//void Piece::getMoves(set <Move> & movesSet, const Board & board) const
//{
//   //assert false?? do we use this??
//}

