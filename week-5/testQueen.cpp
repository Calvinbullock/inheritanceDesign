/***********************************************************************
 * Source File:
 *    TEST QUEEN
 * Author:
 *    Calvin Bullock, Daniel Malasky
 * Summary:
 *    The unit tests for the queen
 ************************************************************************/

#include "testQueen.h"
#include "pieceQueen.h"     
#include "board.h"
#include "uiDraw.h"
#include <cassert>      




/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3     p p p           3
 * 2     p(q)p           2
 * 1     p p p           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestQueen::getMoves_blocked()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       .             8
 * 7       .         .   7
 * 6       .       .     6
 * 5       .     .       5
 * 4   .   .   .         4
 * 3     . . .           3
 * 2   . .(q). . . . .   2
 * 1     . . .           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestQueen::getMoves_slideToEnd()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       p             8
 * 7       .         p   7
 * 6       .       .     6
 * 5       .     .       5
 * 4   p   .   .         4
 * 3     . . .           3
 * 2   p .(q). . . . p   2
 * 1     p p p           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestQueen::getMoves_slideToBlock()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       P             8
 * 7       .         P   7
 * 6       .       .     6
 * 5       .     .       5
 * 4   P   .   .         4
 * 3     . . .           3
 * 2   P .(q). . . . P   2
 * 1     P P P           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestQueen::getMoves_slideToCapture()
{
   // SETUP
   BoardEmpty board;
   Queen queen(7, 7, false /*white*/);
   queen.fWhite = true;
   queen.position.set(2, 1);
   board.board[2][1] = &queen;

   // col row??
   set <Move> moves;

   Black black1(PAWN);
   board.board[3][0] = &black1;
   Black black2(PAWN);
   board.board[1][0] = &black2;
   Black black3(PAWN);
   board.board[0][3] = &black3;
   Black black4(PAWN);
   board.board[7][6] = &black4;

   // EXERCISE
   queen.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 9);  // No possible moves
   
   assertUnit(moves.find(Move("c2d1p")) != moves.end());
   assertUnit(moves.find(Move("c2b1p")) != moves.end());
   assertUnit(moves.find(Move("c2b3")) != moves.end());

   assertUnit(moves.find(Move("c2a4p")) != moves.end());
   assertUnit(moves.find(Move("c2d3")) != moves.end());
   assertUnit(moves.find(Move("c2e4")) != moves.end());

   assertUnit(moves.find(Move("c2f5")) != moves.end());
   assertUnit(moves.find(Move("c2g6")) != moves.end());
   assertUnit(moves.find(Move("c2h7p")) != moves.end());

   // TEARDOWN
   board.board[2][1] = nullptr; // white bishop
}


/*************************************
 * GET TYPE : queen
 * Input:
 * Output: QUEEN
 **************************************/
void TestQueen::getType()
{
   // SETUP
   Queen queen(7, 7, false /*white*/);

   // EXERCISE

   // VERIFY
   assertUnit(queen.getType() == BISHOP);  // No possible moves
   
   // TEARDOWN
}
