/***********************************************************************
 * Source File:
 *    TEST PAWN
 * Author:
 *    Calvin Bullock, Daniel Malasky
 * Summary:
 *    The unit tests for the pawn
 ************************************************************************/

#include "testPawn.h"
#include "piecePawn.h"     
#include "board.h"
#include "pieceType.h"
#include "uiDraw.h"
#include <cassert>      



 /*************************************
  * GET MOVES TEST Simple
  * White pawn in the middle of the board: b4
  *
  * +---a-b-c-d-e-f-g-h---+
  * |                     |
  * 8                     8
  * 7                     7
  * 6                     6
  * 5     .               5
  * 4    (p)              4
  * 3                     3
  * 2                     2
  * 1                     1
  * |                     |
  * +---a-b-c-d-e-f-g-h---+
  **************************************/
void TestPawn::getMoves_simpleWhite()
{
   // SETUP
   BoardEmpty board;
   Pawn pawn(1, 3, true/*white*/);
   board.board[1][3] = &pawn;

   set <Move> moves;

   // EXERCISE
   pawn.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 1); // all moves open
   assertUnit(moves.find(Move("b4b5")) != moves.end());

   // TEARDOWN
   board.board[1][3] = nullptr; // pawn
}

/*************************************
 * GET MOVES TEST Simple
 * Black pawn in the middle of the board: b4
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4    (P)              4
 * 3     .               3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_simpleBlack()
{
   // SETUP
   BoardEmpty board;
   Pawn pawn(1, 3, false/*black*/);
   board.board[1][3] = &pawn;

   set <Move> moves;

   // EXERCISE
   pawn.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 1); // all moves open
   assertUnit(moves.find(Move("b4b3")) != moves.end());

   // TEARDOWN
   board.board[1][3] = nullptr; // pawn
}


/*************************************
 * GET MOVES TEST InitialAdvance
 * White pawn initial advance
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4     .               4
 * 3     .               3
 * 2    (p)              2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_initialAdvanceWhite()
{
   // SETUP
   BoardEmpty board;
   Pawn pawn(1, 1, true /*white*/);
   board.board[1][1] = &pawn;

   set <Move> moves;

   // EXERCISE
   pawn.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 2); // all moves open
   assertUnit(moves.find(Move("b2b3")) != moves.end());
   assertUnit(moves.find(Move("b2b4")) != moves.end());

   // TEARDOWN
   board.board[2][6] = nullptr; // pawn
}

/*************************************
 * GET MOVES TEST InitialAdvance
 * Black pawn initial advance
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7      (P)            7
 * 6       .             6
 * 5       .             5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_initialAdvanceBlack()
{
   // SETUP
   BoardEmpty board;
   Pawn pawn(2, 6, false /*black*/);
   board.board[2][6] = &pawn;

   set <Move> moves;

   // EXERCISE
   pawn.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 2); // all moves open
   assertUnit(moves.find(Move("c7c5")) != moves.end());
   assertUnit(moves.find(Move("c7c6")) != moves.end());

   // TEARDOWN
   board.board[2][6] = nullptr; // pawn
}


/*************************************
 * GET MOVES TEST Capture
 * Double capture: move pawn to b6 and capture
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7   P P P             7
 * 6    (p)              6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_captureWhite()
{
   // SETUP
   BoardEmpty board;
   Pawn pawn(1, 5, true/*white*/);
   board.board[1][5] = &pawn;

   Black black1(PAWN);
   board.board[0][6] = &black1;
   Black black2(PAWN);
   board.board[1][6] = &black2;
   Black black3(PAWN);
   board.board[2][6] = &black3;

   set <Move> moves;

   // EXERCISE
   pawn.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 2); // all moves open
   assertUnit(moves.find(Move("b6a7p")) != moves.end());
   assertUnit(moves.find(Move("b6c7p")) != moves.end());

   // TEARDOWN
   board.board[1][3] = nullptr; // pawn

   board.board[0][6] = nullptr;
   board.board[1][6] = nullptr;
   board.board[2][6] = nullptr;
}


/*************************************
 * GET MOVES TEST Capture
 * Double capture: move pawn to b6 and capture
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6    (P)              6
 * 5   p p p             5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_captureBlack()
{
   // SETUP
   BoardEmpty board;
   Pawn pawn(1, 5, false/*black*/);
   board.board[1][5] = &pawn;

   White white1(PAWN);
   board.board[0][4] = &white1;
   White white2(PAWN);
   board.board[1][4] = &white2;
   White white3(PAWN);
   board.board[2][4] = &white3;

   set <Move> moves;

   // EXERCISE
   pawn.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 2); // all moves open
   assertUnit(moves.find(Move("b6a5p")) != moves.end());
   assertUnit(moves.find(Move("b6c5p")) != moves.end());

   // TEARDOWN
   board.board[1][3] = nullptr; // pawn

   board.board[0][4] = nullptr; 
   board.board[1][4] = nullptr; 
   board.board[2][4] = nullptr; 
}

/*************************************
 * GET MOVES TEST Enpassant
 * Enpassant b5a6E
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6   . P .             6
 * 5   P(p)P             5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_enpassantWhite()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}


/*************************************
 * GET MOVES TEST Enpassant
 * Enpassant f4g3E
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4           p(P)p     4
 * 3           . p .     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_enpassantBlack()
{
   // SETUP
   BoardEmpty board;
   Pawn pawn(5, 3, false/*black*/);
   board.board[5][3] = &pawn;

   set <Move> moves;

   Pawn pawn1(6, 3, true/*white*/);
   board.board[6][3] = &pawn1;
   pawn1.setLastMove(board.getCurrentMove());
   Pawn pawn2(4, 3, true/*white*/);
   board.board[4][3] = &pawn2;
   pawn1.setLastMove(board.getCurrentMove());


   White white1(PAWN);
   board.board[5][2] = &white1; // bottom
   
   // EXERCISE
   pawn.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 2); // all moves open
   assertUnit(moves.find(Move("f4g3E")) != moves.end());
   assertUnit(moves.find(Move("f4e3E")) != moves.end());

   // TEARDOWN
   board.board[1][3] = nullptr; // pawn
}

/*************************************
 * GET MOVES TEST Promotion
 * Promotion: b6a7rQ
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8   P . P             8
 * 7    (p)              7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_promotionWhite()
{
   //checking we're addin rQ at the end.
   assertUnit(NOT_YET_IMPLEMENTED);
}


/*************************************
 * GET MOVES TEST Promotion
 * Promotion: e2d1rQ
 *
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2          (P)        2
 * 1         r   r       1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestPawn::getMoves_promotionBlack()
{
   assertUnit(NOT_YET_IMPLEMENTED);
}


/*************************************
 * GET TYPE : pawn
 * Input:
 * Output: PAWN
 **************************************/
void TestPawn::getType()
{
   // SETUP
   Pawn pawn(7, 7, false /*white*/);

   // EXERCISE

   // VERIFY
   assertUnit(pawn.getType() == PAWN);

   // TEARDOWN
}

