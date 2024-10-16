
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
}
