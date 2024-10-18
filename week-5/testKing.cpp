/***********************************************************************
 * Source File:
 *    TEST KING
 * Author:
 *    Calvin Bullock, Daniel Malasky
 * Summary:
 *    The unit tests for the King
 ************************************************************************/

#include "testKing.h"
#include "piece.h"
#include "pieceKing.h"
#include "pieceRook.h" 
#include "board.h"
#include "uiDraw.h"
#include <cassert>      
#include <iostream>

// TODO: Reverse all rows and columns

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6       p p p         6
 * 5       p(k)p         5
 * 4       p p p         4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_blocked()
{
   // SETUP
   BoardEmpty board;
   King king(7, 7, false /*white*/);
   king.fWhite = true;
   king.position.set(3, 4);
   board.board[3][4] = &king;

   White white1(PAWN);
   board.board[4][5] = &white1;
   White white2(PAWN);
   board.board[4][4] = &white2;
   White white3(PAWN);
   board.board[4][3] = &white3;
   White white4(PAWN);
   board.board[3][3] = &white4;
   White white5(PAWN);
   board.board[2][3] = &white5;
   White white6(PAWN);
   board.board[2][4] = &white6;
   White white7(PAWN);
   board.board[2][5] = &white7;
   White white8(PAWN);
   board.board[3][5] = &white8;

   set <Move> moves;

   // EXERCISE
   king.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 0); // all moves open

   // TEARDOWN
   board.board[3][4] = nullptr; // King

   board.board[4][5] = nullptr;
   board.board[4][4] = nullptr;
   board.board[4][3] = nullptr;
   board.board[3][3] = nullptr;
   board.board[2][3] = nullptr;
   board.board[2][4] = nullptr;
   board.board[2][5] = nullptr;
   board.board[3][5] = nullptr;
}

/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6       P P P         6
 * 5       P(k)P         5
 * 4       P P P         4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_capture()
{
   // SETUP
   BoardEmpty board;
   King king(7, 7, false /*white*/);
   king.fWhite = true;
   king.position.set(3, 4);
   board.board[3][4] = &king;

   Black black1(PAWN);
   board.board[4][5] = &black1;
   Black black2(PAWN);
   board.board[4][4] = &black2;
   Black black3(PAWN);
   board.board[4][3] = &black3;
   Black black4(PAWN);
   board.board[3][3] = &black4;
   Black black5(PAWN);
   board.board[2][3] = &black5;
   Black black6(PAWN);
   board.board[2][4] = &black6;
   Black black7(PAWN);
   board.board[2][5] = &black7;
   Black black8(PAWN);
   board.board[3][5] = &black8;

   set <Move> moves;

   // EXERCISE
   king.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 8); // all moves open

   assertUnit(moves.find(Move("d5e6p")) != moves.end());
   assertUnit(moves.find(Move("d5e5p")) != moves.end());
   assertUnit(moves.find(Move("d5e4p")) != moves.end());
   assertUnit(moves.find(Move("d5d4p")) != moves.end());
   assertUnit(moves.find(Move("d5c4p")) != moves.end());
   assertUnit(moves.find(Move("d5c5p")) != moves.end());
   assertUnit(moves.find(Move("d5c6p")) != moves.end());
   assertUnit(moves.find(Move("d5d6p")) != moves.end());

   // TEARDOWN
   board.board[3][4] = nullptr; // King

   board.board[4][5] = nullptr;
   board.board[4][4] = nullptr;
   board.board[4][3] = nullptr;
   board.board[3][3] = nullptr;
   board.board[2][3] = nullptr;
   board.board[2][4] = nullptr;
   board.board[2][5] = nullptr;
   board.board[3][5] = nullptr;
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6       . . .         6
 * 5       .(k).         5
 * 4       . . .         4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_free()
{
   // SETUP
   BoardEmpty board;
   King king(7, 7, false /*white*/);
   king.fWhite = true;
   king.position.set(3, 4);
   board.board[3][4] = &king;

   set <Move> moves;

   // EXERCISE
   king.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 8); // all moves open

   assertUnit(moves.find(Move("d5e6")) != moves.end());
   assertUnit(moves.find(Move("d5e5")) != moves.end());
   assertUnit(moves.find(Move("d5e4")) != moves.end());
   assertUnit(moves.find(Move("d5d4")) != moves.end());
   assertUnit(moves.find(Move("d5c4")) != moves.end());
   assertUnit(moves.find(Move("d5c5")) != moves.end());
   assertUnit(moves.find(Move("d5c6")) != moves.end());
   assertUnit(moves.find(Move("d5d6")) != moves.end());

   // TEARDOWN
   board.board[3][4] = nullptr; // white knight
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2   . .               2
 * 1  (k).               1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_end()
{
   // SETUP
   BoardEmpty board;
   King king(7, 7, false /*white*/);
   king.fWhite = true;
   king.position.set(0, 0);
   board.board[0][0] = &king;

   set <Move> moves;

   // EXERCISE
   king.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 3); // all moves open

   assertUnit(moves.find(Move("a1a2")) != moves.end());
   assertUnit(moves.find(Move("a1b2")) != moves.end());
   assertUnit(moves.find(Move("a1b1")) != moves.end());

   // TEARDOWN
   board.board[3][4] = nullptr; // white knight
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2         p p p       2
 * 1   r   . .(k). . r   1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_whiteCastle()
{
   // SETUP
   BoardEmpty board;
   King king(7, 7, false /*white*/);
   king.fWhite = true;
   king.nMoves= 0;
   king.position.set(4, 0);
   board.board[4][0] = &king;
   Rook rook1(0, 0, true);
   board.board[0][0] = &rook1;
   Rook rook2(7, 0, true);
   board.board[7][0] = &rook2;

   set <Move> moves;

   White pWhite1(PAWN);
   board.board[3][1] = &pWhite1;
   White pWhite2(PAWN);
   board.board[4][1] = &pWhite2;
   White pWhite3(PAWN);
   board.board[5][1] = &pWhite3;

   // EXERCISE
   king.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 4); // all moves open

   assertUnit(moves.find(Move("e1d1")) != moves.end());
   assertUnit(moves.find(Move("e1f1")) != moves.end());

   assertUnit(moves.find(Move("e1g1c")) != moves.end());
   assertUnit(moves.find(Move("e1c1C")) != moves.end());

   // TEARDOWN
   board.board[4][0] = nullptr; // king
   board.board[0][0] = nullptr; 
   board.board[7][0] = nullptr;

   board.board[3][1] = nullptr;
   board.board[4][1] = nullptr;
   board.board[5][1] = nullptr;
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8   R   . .(K). . R   8
 * 7         P P P       7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2                     2
 * 1                     1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_blackCastle()
{
   // SETUP
   BoardEmpty board;
   King king(4, 7, false/*white*/);
   board.board[4][7] = &king;
   Rook rook1(0, 7, false);
   board.board[0][7] = &rook1;
   Rook rook2(7, 7, false);
   board.board[7][7] = &rook2;

   set <Move> moves;

   Black pBlack1(PAWN);
   board.board[3][6] = &pBlack1;
   Black pBlack2(PAWN);
   board.board[4][6] = &pBlack2;
   Black pBalck3(PAWN);
   board.board[5][6] = &pBalck3;

   // EXERCISE
   king.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 4); // all moves open

   assertUnit(moves.find(Move("e8g8c")) != moves.end()); // castleing
   assertUnit(moves.find(Move("e8c8C")) != moves.end());

   assertUnit(moves.find(Move("e8f8")) != moves.end());
   assertUnit(moves.find(Move("e8d8")) != moves.end());

   // TEARDOWN
   board.board[4][7] = nullptr; // king
   board.board[0][7] = nullptr;
   board.board[7][7] = nullptr;

   board.board[3][6] = nullptr;
   board.board[4][6] = nullptr;
   board.board[5][6] = nullptr;
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2         p p p       2
 * 1   r     .(k).   r   1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_whiteCastleKingMoved()
{
   // SETUP
   BoardEmpty board;
   King king(7, 7, true/*white*/);
   king.nMoves = 3;
   king.position.set(4, 0);
   board.board[4][0] = &king;
   Rook rook1(0, 0, true);
   board.board[0][0] = &rook1;
   Rook rook2(7, 0, true);
   board.board[7][0] = &rook2;

   set <Move> moves;

   White pWhite1(PAWN);
   board.board[3][1] = &pWhite1;
   White pWhite2(PAWN);
   board.board[4][1] = &pWhite2;
   White pWhite3(PAWN);
   board.board[5][1] = &pWhite3;

   // EXERCISE
   king.getMoves(moves, board);

   // VERIFY
   assertUnit(moves.size() == 2); // all moves open

   assertUnit(moves.find(Move("e1d1")) != moves.end());
   assertUnit(moves.find(Move("e1f1")) != moves.end());

   // TEARDOWN
   board.board[4][0] = nullptr; // king
   board.board[0][0] = nullptr; 
   board.board[7][0] = nullptr;

   board.board[3][1] = nullptr;
   board.board[4][1] = nullptr;
   board.board[5][1] = nullptr;
}


/*************************************
 * +---a-b-c-d-e-f-g-h---+
 * |                     |
 * 8                     8
 * 7                     7
 * 6                     6
 * 5                     5
 * 4                     4
 * 3                     3
 * 2         p p p       2
 * 1   r     .(k).   r   1
 * |                     |
 * +---a-b-c-d-e-f-g-h---+
 **************************************/
void TestKing::getMoves_whiteCastleRookMoved()
{
   // SETUP
   BoardEmpty board;
   King king(7, 7, true/*white*/);
   king.nMoves = 3;
   king.position.set(4, 0);
   board.board[4][0] = &king;

   Rook rook1(0, 0, true);
   rook1.nMoves = 3;
   board.board[0][0] = &rook1;
   Rook rook2(7, 0, true);
   rook2.nMoves = 3;
   board.board[7][0] = &rook2;

   set <Move> moves;

   White pWhite1(PAWN);
   board.board[3][1] = &pWhite1;
   White pWhite2(PAWN);
   board.board[4][1] = &pWhite2;
   White pWhite3(PAWN);
   board.board[5][1] = &pWhite3;

   // EXERCISE
   //std::cout << "-----" << std::endl;
   king.getMoves(moves, board);

   // VERIFY
   //std::cout << "-----" << std::endl;
   //std::cout << moves.size() << std::endl;
   assertUnit(moves.size() == 2); // all moves open

   assertUnit(moves.find(Move("e1d1")) != moves.end());
   assertUnit(moves.find(Move("e1f1")) != moves.end());

   // TEARDOWN
   board.board[4][0] = nullptr; // king
   board.board[0][0] = nullptr; 
   board.board[7][0] = nullptr;

   board.board[3][1] = nullptr;
   board.board[4][1] = nullptr;
   board.board[5][1] = nullptr;
}

/*************************************
 * GET TYPE : king
 * Input:
 * Output: KING
 **************************************/
void TestKing::getType()
{
   // SETUP  
   const King king(7, 7);
   PieceType pt = KING;

   // EXERCISE
   pt = king.getType();

   // VERIFY
   assertUnit(pt == KING);
}  // TEARDOWN


