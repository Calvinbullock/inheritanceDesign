/***********************************************************************
 * Header File:
 *    BOARD 
 * Author:
 *    Calvin Bullock, Daniel Malasky
 * Summary:
 *    A collection of pieces and the state of the board
 ************************************************************************/

#pragma once

#include <cassert>
#include "move.h"   // Because we return a set of Move

class ogstream;
class TestPawn;
class TestKnight;
class TestBishop;
class TestRook;
class TestQueen;
class TestKing;
class TestBoard;
class Position;
class Piece;



/***************************************************
 * BOARD
 * The game board
 **************************************************/
class Board
{
   friend TestPawn;
   friend TestKnight;
   friend TestBishop;
   friend TestRook;
   friend TestQueen;
   friend TestKing;
   friend TestBoard;

public:

   // getters
   virtual int  getCurrentMove() const { return numMoves;      }
   virtual bool whiteTurn()      const { return (numMoves == 0) || (numMoves % 2 == 0); }
   virtual void display(const Position& posHover, const Position& posSelect) const {}

   // setters
   virtual void move                (const Move & move) { }
   virtual const Piece& operator [] (const Position& pos) const;
   virtual Piece& operator []       (const Position& pos);

protected:
   int numMoves;
   Piece * board[8][8];    // the board of chess pieces
};


/***************************************************
 * BOARD DUMMY BOARD
 * A board double that does nothing but assert. Will need this for unit tests.
 **************************************************/
class BoardDummy : public Board
{
   friend TestBoard; 
public:
   BoardDummy()                                           
   { 
      numMoves = 0;
      for (int col = 0; col < 8; col++)
      {
         for (int row = 0; row < 8; row++)
         {
            board[col][row] = nullptr;
         }
      }
   }
   ~BoardDummy()                                 {                }

   void display(const Position& posHover,
                const Position& posSelect) const { assert(false); }
   void move       (const Move& move)            { assert(false); }
   int  getCurrentMove() const                   { assert(false); return 0; }
   bool whiteTurn()      const                   { assert(false); return false; }
   Piece& operator [] (const Position& pos)
   { 
      assert(false); 
      throw true;
   }
   const Piece& operator [] (const Position& pos) const 
   { 
      assert(false); 
      throw true;
   }
};

/***************************************************
 * BOARD EMPTY
 * The game board that is completely empty.
 * It does not even have spaces though each non-filled
 * spot will report it has a space. This is for unit testing
 **************************************************/
class BoardEmpty : public BoardDummy
{
   friend TestBoard;
public:
   Piece * pSpace;

   BoardEmpty();
   ~BoardEmpty();
   const Piece& operator [] (const Position& pos) const
   {
      assert(pos.isValid());
      if (board[pos.getCol()][pos.getRow()])
         return *(board[pos.getCol()][pos.getRow()]);
      else
         return *pSpace;
   }
};

