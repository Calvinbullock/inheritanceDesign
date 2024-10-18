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
  
  // TODO: nullptr needs to return space piece
  /* if (board[pos.getCol()][pos.getRow()] == nullptr) {
      return Piece();
   } else {
      return *board[pos.getCol()][pos.getRow()];
   }*/
   return *board[pos.getCol()][pos.getRow()];
}
Piece& Board::operator [] (const Position& pos)
{
   return *board[pos.getCol()][pos.getRow()];
}

 /***********************************************
 * BOARD : DISPLAY
 *         Display the board
 ***********************************************/
void Board::display(const Position & posHover, const Position & posSelect) const
{
   pgout->drawBoard();

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
   Rook*    rookW1      = new Rook(0, 0, true);
   Knight*  knightW1    = new Knight(1, 0, true);
   Bishop*  bishopeW1   = new Bishop(2, 0, true);
   Queen*   queenW      = new Queen(3, 0, true);
   King*    kingW       = new King(4, 0, true);
   Bishop*  bishopW2    = new Bishop(5, 0, true);
   Knight*  knightW2    = new Knight(6, 0, true);
   Rook*    rookW2      = new Rook(7, 0, true);

   board[0][0] = rookW1;
   board[1][0] = knightW1;
   board[2][0] = bishopeW1;
   board[3][0] = queenW;

   board[4][0] = kingW;
   board[5][0] = bishopW2 ;
   board[6][0] = knightW2;
   board[7][0] = rookW2;

   //loop for pawns

   // black
   Rook*    rookB1      = new Rook(0, 7, false);
   Knight*  knightB1    = new Knight(1, 7, false);
   Bishop*  bishopeB1   = new Bishop(2, 7, false);
   Queen*   queenB      = new Queen(3, 7, false);
   King*    kingB       = new King(4, 7, false);
   Bishop*  bishopB2    = new Bishop(5, 7, false);
   Knight*  knightB2    = new Knight(6, 7, false);
   Rook*    rookB2      = new Rook(7, 7, false);

   board[0][7] = rookB1;
   board[1][7] = knightB1;
   board[2][7] = bishopeB1;
   board[3][7] = queenB;

   board[4][7] = kingB;
   board[5][7] = bishopB2 ;
   board[6][7] = knightB2;
   board[7][7] = rookB2;

   //loop for pawns
}

Board::~Board()
{
   //for (int col = 0; col < 8; ++col)
   //{
   //   for (int row = 0; row < 8; ++row)
   //   {
   //      // Access the piece at board[col][row]
   //      delete board[col][row];
   //      board[col][row] = nullptr; 
   //   }
   //}
}

/************************************************
 * BOARD : FREE
 *         Free up all the allocated memory
 ************************************************/
void Board::free()
{
   // set every piece on board to be null
   for (int i = 0; i < 8; i++) {
      for (const Piece *p : board[i]) {
         if (p != nullptr) {
            // TODO: delete it...
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
   numMoves++;       

   // attacking make sure you kill the piece.
   // Does not handle and special movetypes.
}

void Board::swap(Position& pos1, Position& pos2)
{
   // Swap the pieces position
   board[pos1.getCol()][pos1.getRow()]->setPosition(pos2);
   board[pos2.getCol()][pos2.getRow()]->setPosition(pos1);

   //std::swap(board[pos1.getCol()][pos1.getRow()], board[pos2.getCol()][pos2.getRow()]);

   // DOES NOT HANDLE ATTACKING

   //// no capture
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
