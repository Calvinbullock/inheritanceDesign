/***********************************************************************
 * Source File:
 *    QUEEN
 * Author:
 *    Calvin Bullock, Daniel Malasky
 * Summary:
 *    The QUEEN class
 ************************************************************************/

#include "pieceQueen.h"
#include "board.h"
#include "pieceType.h"
#include "position.h"
#include "uiDraw.h"    // for draw*()
#include <iostream>

 /***************************************************
 * PIECE DRAW
 * Draw all the pieces.
 ***************************************************/
void Queen::display(ogstream* pgout) const
{
   pgout->drawQueen(position, fWhite);
}

/**********************************************
 * KNIGHT : GET POSITIONS
 *********************************************/
void Queen::getMoves(set <Move>& moves, const Board& board) const
{
}
