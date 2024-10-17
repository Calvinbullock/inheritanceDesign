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
   // TODO: finish test cases
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
   board.board[1][0] = &black1;
   Black black2(PAWN);
   board.board[2][0] = &black2;
   Black black3(PAWN);
   board.board[3][0] = &black3;
   Black black4(PAWN);
   board.board[7][1] = &black4;
   Black black5(PAWN);
   board.board[7][6] = &black5;
   Black black6(PAWN);
   board.board[2][7] = &black6;
   Black black7(PAWN);
   board.board[0][3] = &black7;
   Black black8(PAWN);
   board.board[0][1] = &black8;


   // EXERCISE
   queen.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 23);  // No possible moves
   
   assertUnit(moves.find(Move("c2b1p")) != moves.end()); // bottom-left

   assertUnit(moves.find(Move("c2c1p")) != moves.end());  // down

   assertUnit(moves.find(Move("c2d1p")) != moves.end());   // bottom right

   assertUnit(moves.find(Move("c2d2")) != moves.end());   // right
   assertUnit(moves.find(Move("c2e2")) != moves.end());
   assertUnit(moves.find(Move("c2f2")) != moves.end());
   assertUnit(moves.find(Move("c2g2")) != moves.end());
   assertUnit(moves.find(Move("c2h2p")) != moves.end());
   
   
   assertUnit(moves.find(Move("c2d3")) != moves.end());   // top-right
   assertUnit(moves.find(Move("c2e4")) != moves.end());
   assertUnit(moves.find(Move("c2f5")) != moves.end());
   assertUnit(moves.find(Move("c2g6")) != moves.end());
   assertUnit(moves.find(Move("c2h7p")) != moves.end());

   assertUnit(moves.find(Move("c2c3")) != moves.end());   // top 
   assertUnit(moves.find(Move("c2c4")) != moves.end());
   assertUnit(moves.find(Move("c2c5")) != moves.end());
   assertUnit(moves.find(Move("c2c6")) != moves.end());
   assertUnit(moves.find(Move("c2c7")) != moves.end());
   assertUnit(moves.find(Move("c2c8p")) != moves.end());

   assertUnit(moves.find(Move("c2b3")) != moves.end());  // top-left
   assertUnit(moves.find(Move("c2a4p")) != moves.end());

   assertUnit(moves.find(Move("c2b2")) != moves.end());  // left
   assertUnit(moves.find(Move("c2a2p")) != moves.end());

   // TEARDOWN
   board.board[2][1] = nullptr; // white bishop

   board.board[1][0] = nullptr;
   board.board[2][0] = nullptr;
   board.board[3][0] = nullptr;
   board.board[7][1] = nullptr;
   board.board[7][6] = nullptr;
   board.board[2][7] = nullptr;
   board.board[0][3] = nullptr;
   board.board[0][1] = nullptr;
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
   assertUnit(queen.getType() == QUEEN);  // No possible moves
   
   // TEARDOWN
}
