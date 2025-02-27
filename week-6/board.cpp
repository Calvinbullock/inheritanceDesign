/***********************************************************************
 * Source File:
 *    BOARD 
 * Author:
 *    Calvin Bullock, Daniel Malasky
 * Summary:
 *    A collection of pieces and a small amount of game state
 ************************************************************************/

#include "board.h"
#include "pieceBishop.h"
#include "pieceKing.h"
#include "pieceQueen.h"
#include "pieceRook.h"
#include "piecePawn.h"
#include "uiDraw.h"
#include "position.h"
#include "piece.h"
#include "pieceSpace.h"
#include "pieceKnight.h"
#include <cassert>
using namespace std;


/***********************************************board
 * BOARD : RESET
 *         Just fill the board with the known pieces
 *   +---a-b-c-d-e-f-g-h---+
 *   |                     |
 *   8     N         N     8
 *   7                     7
 *   6                     6
 *   5                     5
 *   4                     4
 *   3                     3
 *   2                     2
 *   1     n         n     1
 *   |                     |
 *   +---a-b-c-d-e-f-g-h---+
 ***********************************************/
void Board::reset(bool fFree)
{
   // free everything
   for (int r = 0; r < 8; r++)
      for (int c = 0; c < 8; c++)
         board[c][r] = nullptr;
}

// we really REALLY need to delete this.
//Space space(0,0);

/***********************************************
* BOARD : GET
*         Get a piece from a given position.
***********************************************/
const Piece& Board::operator [] (const Position& pos) const
{
   assert(0 <= pos.getCol() && pos.getCol() < 8);
   assert(0 <= pos.getRow() && pos.getRow() < 8);
   assert(nullptr != board[pos.getCol()][pos.getRow()]);
   return *board[pos.getCol()][pos.getRow()];
}
Piece& Board::operator [] (const Position& pos)
{
   assert(0 <= pos.getCol() && pos.getCol() < 8);
   assert(0 <= pos.getRow() && pos.getRow() < 8);
   assert(nullptr != board[pos.getCol()][pos.getRow()]);
   return *board[pos.getCol()][pos.getRow()];
}

 /***********************************************
 * BOARD : DISPLAY
 *         Display the board
 ***********************************************/
void Board::display(const Position & posHover, const Position& posSelect, const Interface& pUI, const set<Move>& possible) const
{
   
   // draw board
   pgout->drawBoard();

   // draw any selections
   pgout->drawHover(posHover);
   pgout->drawSelected(posSelect);

   // draw the possible moves
   if (!possible.empty()) // if set is not empty
   {
      set <Move>::iterator it;
      for (it = possible.begin(); it != possible.end(); ++it)
         pgout->drawPossible(it->getDest());
   }

   for (int i = 0; i < 8; i++) {
      for (const Piece *p : board[i]) {
         if (p != nullptr)
            p->display(pgout);
      }
   }
}


/************************************************
 * BOARD : CONSTRUCT
 *         Free up all the allocated memory
 ************************************************/
Board::Board(ogstream* pgout, bool noreset) : pgout(pgout), numMoves(0), board()
{
   // white
   board[0][0] = new Rook(0, 0, true);
   board[1][0] = new Knight(1, 0, true);
   board[2][0] = new Bishop(2, 0, true);
   board[3][0] = new Queen(3, 0, true);

   board[4][0] = new King(4, 0, true);
   board[5][0] = new Bishop(5, 0, true);
   board[6][0] = new Knight(6, 0, true);
   board[7][0] = new Rook(7, 0, true);
   
   // pawns
   for (int i = 0; i < 8; i++) {
      board[i][1] = new Pawn(i, 1, true);
   }

   // black
   board[0][7] = new Rook(0, 7, false);
   board[1][7] = new Knight(1, 7, false);
   board[2][7] = new Bishop(2, 7, false);
   board[3][7] = new Queen(3, 7, false);

   board[4][7] = new King(4, 7, false);
   board[5][7] = new Bishop(5, 7, false);
   board[6][7] = new Knight(6, 7, false);
   board[7][7] = new Rook(7, 7, false);

   // pawns
   for (int i = 0; i < 8; i++) {
      board[i][6] = new Pawn(i, 6, false);
   }

   // add spaces
   for (int row = 2; row <= 5; row++) {
      for (int col = 0; col <= 7; col++) {
         board[col][row] = new Space(col, row);
      }
   }
}

Board::~Board()
{
   free();
}

/************************************************
 * BOARD : FREE
 *         Free up all the allocated memory
 ************************************************/
void Board::free()
{
   for (int col = 0; col < 8; ++col)
   {
      for (int row = 0; row < 8; ++row)
      {
         if (board[col][row] != nullptr) {
            // NOTE: is this right??
            board[col][row] = nullptr;
         }
      }
   }
}


/**********************************************
 * BOARD : ASSERT BOARD
 *         Verify the board is well-formed
 *********************************************/
void Board::assertBoard()
{

}




/**********************************************
 * BOARD : MOVE
 *         Execute a move according to the contained instructions
 *   INPUT move The instructions of the move
 *********************************************/
void Board::move(const Move & move)
{  
   Position src = move.getSource();
   Position dest = move.getDest();

   int srcCol = move.getSource().getCol();
   int srcRow = move.getSource().getRow();

   // set last move before swapping
   board[srcCol][srcRow]->setLastMove(getCurrentMove());

   // swap the pieces
   swap(src, dest);
   

   switch (move.getMoveType())
   {
      case Move::CASTLE_KING:
         if (whiteTurn()) // white turn
         {
            Position rookSrc = "h1";
            Position rookDest = "f1";
            swap(rookSrc, rookDest);
         }
         else // black turn
         {
            Position rookSrc = "h8";
            Position rookDest = "f8";
            swap(rookSrc, rookDest);
         }
         break;
      case Move::CASTLE_QUEEN:
         if (whiteTurn()) // white turn
         {
            Position rookSrc = "a1";
            Position rookDest = "d1";
            swap(rookSrc, rookDest);
         }
         else // black turn
         {
            Position rookSrc = "a8";
            Position rookDest = "d8";
            swap(rookSrc, rookDest);
         }
         break;
      case Move::ENPASSANT:
         if (whiteTurn()) // white turn
         {
            Position pawnToKill(move.getDest());
            pawnToKill.setRow(pawnToKill.getRow() - 1); // enemy pawn 1 below

            board[pawnToKill.getCol()][pawnToKill.getRow()] =
               new Space(pawnToKill.getCol(), pawnToKill.getRow());
         }
         else // black turn
         {
            Position pawnToKill(move.getDest());
            pawnToKill.setRow(pawnToKill.getRow() + 1); // enemy pawn 1 above

            board[pawnToKill.getCol()][pawnToKill.getRow()] =
               new Space(pawnToKill.getCol(), pawnToKill.getRow());
         }
         break;
      case Move::PROMOTION:
         Position pawnToPromote(move.getDest());
         
         if (board[pawnToPromote.getCol()][pawnToPromote.getRow()]->isWhite())
            board[pawnToPromote.getCol()][pawnToPromote.getRow()] = 
               new Queen(pawnToPromote.getCol(), pawnToPromote.getRow(), true);
         else
            board[pawnToPromote.getCol()][pawnToPromote.getRow()] = 
               new Queen(pawnToPromote.getCol(), pawnToPromote.getRow(), false);
   }

   numMoves++;
}

void Board::swap(Position& pos1, Position& pos2)
{
   // Swap the pieces position
   board[pos1.getCol()][pos1.getRow()]->setPosition(pos2);
   board[pos2.getCol()][pos2.getRow()]->setPosition(pos1);

   // no capture
   if (board[pos2.getCol()][pos2.getRow()]->getType() == SPACE)
   {
      // Swap the position on the board
      std::swap(board[pos1.getCol()][pos1.getRow()], board[pos2.getCol()][pos2.getRow()]);
   }
   else // capture
   {
      std::swap(board[pos1.getCol()][pos1.getRow()], board[pos2.getCol()][pos2.getRow()]);
      board[pos1.getCol()][pos1.getRow()] = new Space(pos1.getCol(), pos1.getRow());
   }

}



/**********************************************
 * BOARD EMPTY
 * The game board that is completely empty.
 * It does not even have spaces though each non-filled
 * spot will report it has a space. This is for unit testing
 *********************************************/
BoardEmpty::BoardEmpty() : BoardDummy(), pSpace(nullptr), moveNumber(0)
{
   pSpace = new Space(0, 0);

   numMoves = 0;
   for (int col = 0; col < 8; col++)
   {
      for (int row = 0; row < 8; row++)
      {
         board[col][row] = nullptr;
      }
   }
}
BoardEmpty::~BoardEmpty() 
{
   delete pSpace;
}
