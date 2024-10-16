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
   if (rhs.isValid())
   {
      out << (char)(rhs.getCol() + 'a')
         << (char)(rhs.getRow() + '1');
   }

   else
      out << "error";
   return out;
}

/*************************************
 * POSITION EXTRACTION OPERATOR
 **************************************/
istream & operator >> (istream & in,  Position & rhs)
{
   char text[3] = {};
   in >> text[0] >> text[1];
   if (in.fail())
   {
      in.clear();
      in.ignore();
      throw string("Error reading coordinates");
   }
   else
   {
      rhs = text;
   }
   
   return in;   
}

/*************************************
 * POSITION ASSIGNMENT OPERATOR (CHAR)
 **************************************/
const Position & Position::operator =  (const char     * rhs) 
{
   // convert char to string
   string rhsStr;
   rhsStr = (string)rhs;

   return *this = rhsStr; 
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


string Position::getColRowText() const
{
   string text;
   char letters[] = "abcdefgh";

   text.push_back(letters[getCol()]);
   text.push_back(getRow() + '1');   // +1 [ascii] for base 1 board.

   return text;
}
