/***********************************************************************
 * Header File:
 *    POSITION
 * Author:
 *    Calvin Bullock, Daniel Malasky
 * Summary:
 *    The position of a piece, the cursor, or a possible move on a chess board
 ************************************************************************/

#pragma once

#include <iostream>
#include <string>
#include <cstdint>
using std::string;
using std::ostream;
using std::istream;

const int SIZE_SQUARE = 32;   // number of pixels in a square by default
const int OFFSET_BOARD = 50;   // boarder between the board and the edge of screen

/***********************************************
 * DELTA
 * Movement in a direction (dRow and dCol)
 **********************************************/
struct Delta
{
   int dRow;
   int dCol;
};

const Delta ADD_R = { 1,  0 };
const Delta ADD_C = { 0,  1 };
const Delta SUB_R = { -1,  0 };
const Delta SUB_C = { 0, -1 };


class PositionTest;

/***************************************************
 * POSITION
 * The location of a piece on the board
 ***************************************************/
class Position
{
   friend class PositionTest;
public:

   // Position :    The Position class can work with other positions,
   //               Allowing for comparisions, copying, etc.
   Position(const Position& rhs) : colRow(0)
   {
      set(rhs.colRow);
   }
   Position() : colRow(0xff) { set(0xff); }
   bool isInvalid() const { return !isValid(); }
   bool isValid()   const
   {
      return ((int)((colRow & 0xf0) >> 4) <= 7 &&
         (int)((colRow & 0x0f) >> 0) <= 7);
   }
   void setValid() {                             }
   void setInvalid() {                             }
   bool operator <  (const Position& rhs) const { return colRow < rhs.colRow; }
   bool operator == (const Position& rhs) const { return colRow == rhs.colRow; }
   bool operator != (const Position& rhs) const
   {
      return !(colRow == rhs.colRow);
   }
   const Position& operator =  (const Position& rhs)
   {
      this->colRow = rhs.colRow;
      return *this;
   }

   // Location : The Position class can work with locations, which
   //            are 0...63 where we start in row 0, then row 1, etc.
   Position(int location) : colRow(0xff) { setLocation(location); }
   int getLocation() const { return (getRow() * 8) + (getCol()); }
   void setLocation(int location)
   {
      if (0 <= location && location < 64)
      {
         set(location % 8 /*col*/, location / 8 /*row*/);
      }
      else
         set(0xff);
   }


   // Row/Col : The position class can work with row/column,
   //           which are 0..7 and 0...7
   Position(int c, int r) : colRow(0xff) { set(c, r); }
   virtual int getCol() const
   {
      return isValid() ? (int)((colRow & 0xf0) >> 4) : -1;
   }
   virtual int getRow() const
   {
      return isValid() ? (int)((colRow & 0x0f) >> 0) : -1;
   }
   void setRow(int r)
   {
      this->colRow = (colRow & 0xF0) | (r << 0);
   }
   void setCol(int c)
   {
      this->colRow = (colRow & 0x0F) | (c << 4);
   }
   void set(int c, int r)
   {
      setRow(r);
      setCol(c);
   }

   // Text:    The Position class can work with textual coordinates,
   //          such as "d4"

   Position(const char* s) : colRow(0x00) { *this = s; }
   const Position& operator =  (const char* rhs);
   const Position& operator =  (const string& rhs);
   string getColRowText();
   string getColRowText() const;


   // Pixels:    The Position class can work with screen coordinates,
   //            a.k.a. Pixels, these are X and Y coordinates. Note that
   //            we need to scale them according to the size of the board.
   int getX()   const
   {
      return (int)((double)getCol() * getSquareWidth() + OFFSET_BOARD);
   }
   int getY()   const
   {
      return (int)((double)getRow() * getSquareHeight()) + OFFSET_BOARD;
   }
   void setXY(double x, double y)
   {
      set((int)((x - OFFSET_BOARD) / getSquareWidth()),
         7 - (int)((y - OFFSET_BOARD) / getSquareHeight()));
   }
   double getSquareWidth()  const { return squareWidth; }
   double getSquareHeight() const { return squareHeight; }
   void setSquareWidth(double width)
   {
      if (width > 0.0)
         squareWidth = width;
   }
   void setSquareHeight(double height)
   {
      if (height > 0.0)
         squareHeight = height;
   }

   // Delta:    The Position class can work with deltas, which are
   //           offsets from a given location. This helps pieces move
   //           on the chess board.
   Position(const Position& rhs, const Delta& delta) : colRow(-1)
   {
      set(rhs.getCol() + delta.dCol, rhs.getRow() + delta.dRow);
   }
   void adjustRow(int dRow)
   {
      if (isValid())
         setRow(getRow() + (char)dRow);
   }
   void adjustCol(int dCol)
   {
      if (isValid())
         setCol(getCol() + (char)dCol);
   }
   const Position& operator += (const Delta& rhs);
   Position operator + (const Delta& rhs) const { return *this; }

private:
   void set(uint8_t colRowNew) { colRow = colRowNew; }

   uint8_t colRow;
   static double squareWidth;
   static double squareHeight;
};


ostream& operator << (ostream& out, const Position& pos);
istream& operator >> (istream& in, Position& pos);

