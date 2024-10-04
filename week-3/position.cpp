/***********************************************************************
 * Source File:
 *    POSITION
 * Author:
 *    <your name here>
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
