/***********************************************************************
 * Source File:
 *    POSITION
 * Author:
 *    Calvin Bullock, Daniel Malasky
 * Summary:
 *    The position of a piece, the cursor, or a possible move on a chess board
 ************************************************************************/

#include "position.h"

/******************************************
 * POSITION INSERTION OPERATOR
 ******************************************/
ostream & operator << (ostream & out, const Position & rhs)
{
   out << "error";
   return out;
}

/*************************************
 * POSITION EXTRACTION OPERATOR
 **************************************/
istream & operator >> (istream & in,  Position & rhs)
{
   return in;   
}

/*************************************
 * POSITION ASSIGNMENT OPERATOR (CHAR)
 **************************************/
const Position & Position::operator =  (const char     * rhs) 
{
   const char * it = rhs;

   // get the source
   int col = *it - 'a';
   it++;
   int row = *it - '1';
   it++;

   setCol(col);
   setRow(row);
   return *this; 
}

/*************************************
 * POSITION ASSIGNMENT OPERATOR (STRING)
 **************************************/
const Position & Position::operator =  (const string   & rhs) 
{
   string::const_iterator it = rhs.cbegin();

   // get the source
   int col = *it - 'a';
   it++;
   int row = *it - '1';
   it++;

   setCol(col);
   setRow(row);
   return *this; 
}

/*************************************
 * POSITION COMPOUND ASSIGNMENT 
 **************************************/
const Position & Position::operator += (const Delta & rhs) 
{ 
   adjustRow(rhs.dRow);
   adjustCol(rhs.dCol);
   if (!isValid()) 
   {
      colRow = 255;
      return *this;
   }
   return *this; 
}

/*************************************
 * POSITION GET COLROW TEXT
 * get smith notation from position
 **************************************/
string Position::getColRowText()
{
   string text;
   char letters[] = "abcdefgh";

   text.push_back(letters[getCol()]);
   text.push_back(getRow() + '1');   // +1 [ascii] for base 1 board.

   return text;
}
