/***********************************************************************
 * Source File:
 *    TEST BISHOP
 * Author:
 *    Calvin Bullock, Daniel Malasky
 * Summary:
 *    The unit tests for a bishop
 ************************************************************************/


#include "testBishop.h"
#include "pieceBishop.h"     
#include "board.h"
#include "pieceType.h"
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
 * 3     p   p           3
 * 2      (b)            2
 * 1     p   p           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+C
 **************************************/
void TestBishop::getMoves_blocked()
{
   // SETUP
   BoardEmpty board;
   Bishop bishop(7, 7, false /*white*/);
   bishop.fWhite = true;
   bishop.position.set(2, 1);
   board.board[2][1] = &bishop;

   // col row??
   White black1(PAWN);
   board.board[3][0] = &black1;
   White black2(PAWN);
   board.board[1][0] = &black2;
   White black3(PAWN);
   board.board[1][2] = &black3;
   White black4(PAWN);
   board.board[3][2] = &black4;

   set <Move> moves;

   // EXERCISE
   bishop.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 0);  // No possible moves

   // TEARDOWN
   board.board[2][1] = nullptr; // white Bishop
   
   board.board[3][0] = nullptr;
   board.board[1][0] = nullptr;
   board.board[1][2] = nullptr;
   board.board[3][2] = nullptr;
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                 .   7
 * 6               .     6
 * 5             .       5
 * 4   .       .         4
 * 3     .   .           3
 * 2      (b)            2
 * 1     .   .           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestBishop::getMoves_slideToEnd()
{
   // SETUP
   BoardEmpty board;
   Bishop bishop(7, 7, false /*white*/);
   bishop.fWhite = true;
   bishop.position.set(2, 1);
   board.board[2][1] = &bishop;

   // col row??
   set <Move> moves;

   // EXERCISE
   bishop.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 9);  // No possible moves
   
   assertUnit(moves.find(Move("c2d1")) != moves.end());
   assertUnit(moves.find(Move("c2b1")) != moves.end());
   assertUnit(moves.find(Move("c2b3")) != moves.end());

   assertUnit(moves.find(Move("c2a4")) != moves.end());
   assertUnit(moves.find(Move("c2d3")) != moves.end());
   assertUnit(moves.find(Move("c2e4")) != moves.end());

   assertUnit(moves.find(Move("c2f5")) != moves.end());
   assertUnit(moves.find(Move("c2g6")) != moves.end());
   assertUnit(moves.find(Move("c2h7")) != moves.end());

   // TEARDOWN
   board.board[2][1] = nullptr; // white bishop
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                 p   7
 * 6               .     6
 * 5             .       5
 * 4   p       .         4
 * 3     .   .           3
 * 2      (b)            2
 * 1     p   p           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+C
 **************************************/
void TestBishop::getMoves_slideToBlock()
{
   // SETUP
   BoardEmpty board;
   Bishop bishop(7, 7, false /*white*/);
   bishop.fWhite = true;
   bishop.position.set(2, 1);
   board.board[2][1] = &bishop;

   // col row??
   White black1(PAWN);
   board.board[3][0] = &black1;
   White black2(PAWN);
   board.board[1][0] = &black2;
   White black3(PAWN);
   board.board[0][3] = &black3;
   White black4(PAWN);
   board.board[7][6] = &black4;

   // col row??
   set <Move> moves;

   // EXERCISE
   bishop.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 5);  // No possible moves
   assertUnit(moves.find(Move("c2b3")) != moves.end());

   assertUnit(moves.find(Move("c2d3")) != moves.end());
   assertUnit(moves.find(Move("c2e4")) != moves.end());
   assertUnit(moves.find(Move("c2f5")) != moves.end());
   assertUnit(moves.find(Move("c2g6")) != moves.end());

   // TEARDOWN
   board.board[2][1] = nullptr; // white bishop
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                 P   7
 * 6               .     6
 * 5             .       5
 * 4   P       .         4
 * 3     .   .           3
 * 2      (b)            2
 * 1     P   P           1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestBishop::getMoves_slideToCapture()
{
   // SETUP
   BoardEmpty board;
   Bishop bishop(7, 7, false /*white*/);
   bishop.fWhite = true;
   bishop.position.set(2, 1);
   board.board[2][1] = &bishop;

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
   bishop.getMoves(moves, board);

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
 * GET TYPE : bishop
 * Input:
 * Output: BISHOP
 **************************************/
void TestBishop::getType()
{
   // SETUP
   Bishop bishop(7, 7, false /*white*/);

   // EXERCISE


   // VERIFY
   assertUnit(bishop.getType() == BISHOP);  // No possible moves
   
   // TEARDOWN
}
