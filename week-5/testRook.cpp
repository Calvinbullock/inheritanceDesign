/***********************************************************************
 * Source File:
 *    TEST ROOK
 * Author:
 *    Daniel Malasky
 * Summary:
 *    The unit tests for the rook
 ************************************************************************/

#include "testRook.h"
#include "pieceRook.h"     
#include "board.h"
#include "uiDraw.h"
#include <cassert>      

// TODO: reverse all rows and columns.

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3       p             3
 * 2     p(r)p           2
 * 1       p             1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestRook::getMoves_blocked()
{
   // SETUP
   BoardEmpty board;
   Rook rook(7, 7, false /*white*/);
   rook.fWhite = true;
   rook.position.set(2, 1);
   board.board[2][1] = &rook;

   White white1(PAWN);
   board.board[2][0] = &white1; // bottom
   White white2(PAWN);
   board.board[3][1] = &white2; // right
   White white3(PAWN);
   board.board[2][2] = &white3; // top
   White white4(PAWN);
   board.board[1][1] = &white4; // left

   set <Move> moves;

   // EXERCISE
   rook.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 0);  // No possible moves

   // TEARDOWN
   board.board[4][3] = nullptr; // white knight

   board.board[2][0] = nullptr;
   board.board[3][1] = nullptr;
   board.board[2][2] = nullptr;
   board.board[1][1] = nullptr;

}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       .             8
 * 7       .             7
 * 6       .             6
 * 5       .             5
 * 4       .             4
 * 3       .             3
 * 2   . .(r). . . . .   2
 * 1       .             1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestRook::getMoves_slideToEnd()
{
   // SETUP
   BoardEmpty board;
   Rook rook(7, 7, false /*white*/);
   rook.fWhite = true;
   rook.position.set(2, 1);
   board.board[2][1] = &rook;

   set <Move> moves;

   // EXERCISE
   rook.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 14);  // TODO: How many?

   assertUnit(moves.find(Move("c2c1")) != moves.end()); // move down

   assertUnit(moves.find(Move("c2d2")) != moves.end()); // move right
   assertUnit(moves.find(Move("c2e2")) != moves.end());
   assertUnit(moves.find(Move("c2f2")) != moves.end());
   assertUnit(moves.find(Move("c2g2")) != moves.end());
   assertUnit(moves.find(Move("c2h2")) != moves.end());

   assertUnit(moves.find(Move("c2c3")) != moves.end()); // move up
   assertUnit(moves.find(Move("c2c4")) != moves.end());
   assertUnit(moves.find(Move("c2c5")) != moves.end());
   assertUnit(moves.find(Move("c2c6")) != moves.end());
   assertUnit(moves.find(Move("c2c7")) != moves.end());
   assertUnit(moves.find(Move("c2c8")) != moves.end());

   assertUnit(moves.find(Move("c2b2")) != moves.end()); // move left
   assertUnit(moves.find(Move("c2a2")) != moves.end());

   // TEARDOWN
   board.board[4][3] = nullptr; // white knight
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       p             8
 * 7       .             7
 * 6       .             6
 * 5       .             5
 * 4       .             4
 * 3       .             3
 * 2   p .(r). . . . p   2
 * 1       p             1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestRook::getMoves_slideToBlock()
{
   // SETUP
   BoardEmpty board;
   Rook rook(7, 7, false /*white*/);
   rook.fWhite = true;
   rook.position.set(2, 1);
   board.board[2][1] = &rook;

   White white1(PAWN);
   board.board[2][0] = &white1; // bottom
   White white2(PAWN);
   board.board[7][1] = &white2; // right
   White white3(PAWN);
   board.board[2][7] = &white3; // top
   White white4(PAWN);
   board.board[0][1] = &white4; // left

   set <Move> moves;

   // EXERCISE
   rook.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 10);  // TODO: How many?

   assertUnit(moves.find(Move("c2d2")) != moves.end()); // move right
   assertUnit(moves.find(Move("c2e2")) != moves.end());
   assertUnit(moves.find(Move("c2f2")) != moves.end());
   assertUnit(moves.find(Move("c2g2")) != moves.end());

   assertUnit(moves.find(Move("c2c3")) != moves.end()); // move up
   assertUnit(moves.find(Move("c2c4")) != moves.end());
   assertUnit(moves.find(Move("c2c5")) != moves.end());
   assertUnit(moves.find(Move("c2c6")) != moves.end());
   assertUnit(moves.find(Move("c2c7")) != moves.end());

   assertUnit(moves.find(Move("c2b2")) != moves.end()); // move left

   // TEARDOWN
   board.board[4][3] = nullptr; // white knight

   board.board[2][0] = nullptr;
   board.board[7][1] = nullptr;
   board.board[2][7] = nullptr;
   board.board[0][1] = nullptr;
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8       P             8
 * 7       .             7
 * 6       .             6
 * 5       .             5
 * 4       .             4
 * 3       .             3
 * 2   P .(r). . . . P   2
 * 1       P             1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestRook::getMoves_slideToCapture()
{
   // SETUP
   BoardEmpty board;
   Rook rook(7, 7, false /*white*/);
   rook.fWhite = true;
   rook.position.set(2, 1);
   board.board[2][1] = &rook;

   Black black1(PAWN);
   board.board[2][0] = &black1; // bottom
   Black black2(PAWN);
   board.board[7][1] = &black2; // right
   Black black3(PAWN);
   board.board[2][7] = &black3; // top
   Black black4(PAWN);
   board.board[0][1] = &black4; // left

   set <Move> moves;

   // EXERCISE
   rook.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 14);  // TODO: How many?

   assertUnit(moves.find(Move("c2c1p")) != moves.end()); // move down

   assertUnit(moves.find(Move("c2d2")) != moves.end()); // move right
   assertUnit(moves.find(Move("c2e2")) != moves.end());
   assertUnit(moves.find(Move("c2f2")) != moves.end());
   assertUnit(moves.find(Move("c2g2")) != moves.end());
   assertUnit(moves.find(Move("c2h2p")) != moves.end());

   assertUnit(moves.find(Move("c2c3")) != moves.end()); // move up
   assertUnit(moves.find(Move("c2c4")) != moves.end());
   assertUnit(moves.find(Move("c2c5")) != moves.end());
   assertUnit(moves.find(Move("c2c6")) != moves.end());
   assertUnit(moves.find(Move("c2c7")) != moves.end());
   assertUnit(moves.find(Move("c2c8p")) != moves.end());

   assertUnit(moves.find(Move("c2b2")) != moves.end()); // move left
   assertUnit(moves.find(Move("c2a2p")) != moves.end());

   // TEARDOWN
   board.board[4][3] = nullptr; // white knight

   board.board[2][0] = nullptr;
   board.board[7][1] = nullptr;
   board.board[2][7] = nullptr;
   board.board[0][1] = nullptr;
}


/*************************************
 * GET TYPE : rook
 * Input:
 * Output: ROOK
 **************************************/
void TestRook::getType()
{
   // SETUP  
   const Rook rook(7, 7);
   PieceType pt = ROOK;

   // EXERCISE
   pt = rook.getType();

   // VERIFY
   assertUnit(pt == ROOK);
}  // TEARDOWN
