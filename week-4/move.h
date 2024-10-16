/***********************************************************************
 * Header File:
 *    MOVE 
 * Author:
 *    Calvin Bullock, Daniel Malasky
 * Summary:
 *    Everything we need to know about a single chess move
 ************************************************************************/

#pragma once

#include <string>
#include "position.h"  // Every move has two Positions as attributes
#include "pieceType.h" // A piece type


class TestMove;
class TestBoard;

/***************************************************
 * MOVE
 * One move across the board
 ***************************************************/
class Move
{
public:
   enum MoveType { MOVE, ENPASSANT, CASTLE_KING, CASTLE_QUEEN, MOVE_ERROR };

   friend TestMove;
   friend TestBoard;

   // constructor
   Move();

   Move(string moveText) : source(), dest(), promote(INVALID),
      capture(INVALID), moveType(MOVE_ERROR), isWhite(true), text()
   {
      read(moveText);
      text = getText();
   };
   
   Move(const Move &rhs)
   {
      *this = rhs;
   }

   
   
   // getters
   string getText();
   string getText() const;
   const Position& getDest()     const { return dest;     }
   const Position& getSource()   const { return source;   }
   PieceType getPromotion()      const { return promote;  }
   PieceType getCapture()        const { return capture;  }
   Move::MoveType getMoveType()  const { return moveType; }
   // TODO: moveType getters 

   
   bool operator == (const Move& rhs) const;
   bool operator == (const string& rhs) const { return getText() == rhs; }
   bool operator != (const string& rhs) const { return getText() != rhs; }
   bool operator != (const Move& rhs)  const { return !(text == rhs.text); }
   bool operator <  (const Move& rhs) const
   {
      return dest.getLocation() < rhs.dest.getLocation();
   } // only look at dest.

   // setters
   void read(string moveText);

   void setSource(const Position& src) { source = src; }
   void setDest (const Position& des) { dest = des; }

   const Move & operator =  (const char     * rhs) { read((string)rhs); return *this; }
   const Move & operator =  (const string   & rhs) { read(rhs); return *this; }
   const Move & operator =  (const Move& rhs);


   char letterFromPieceType(PieceType pt)     const;
private:
   PieceType pieceTypeFromLetter(char letter) const;



   Position  source;    // where the move originated from
   Position  dest;      // where the move finished
   PieceType promote;   // piece to be promoted to
   PieceType capture;   // did a capture happen this move?
   MoveType  moveType;  // what type of move is this?
   bool      isWhite;   // whose turn is it anyway?
   string    text;      // what is the textual version of the move?
};

//ostream& operator << (ostream& out, const Move& move) 
//{
//   out << move.getSource()
//      << move.getDest();
//      /*<< move.letterFromPieceType(move.getCapture());*/
//   return out;
//};

