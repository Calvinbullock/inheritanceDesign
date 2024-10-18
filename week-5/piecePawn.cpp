/***********************************************************************
 * Source File:
 *    Pawn
 * Author:
 *    Calvin Bullock, Daniel Malasky
 * Summary:
 *    The Pawn class
 ************************************************************************/

#include "piecePawn.h"
#include "board.h"
#include "pieceType.h"
#include "position.h"
#include "uiDraw.h"    // for draw*()
#include <iostream>

void Pawn::getMoves(set<Move>& moves, const Board& board) const
{
   
   
   Position newPos;
   Move m;
   PieceType pt;

   // black pawn
   if (!this->fWhite)
   {
      
      // --------- FORWARD 2 ------------
      newPos.setRow(this->position.getRow() - 2);
      newPos.setCol(this->position.getCol());

      // valid move
      if (newPos.isValid())
      {
         // starting row and has not moved
         if (this->position.getRow() == 6 && this->hasMoved())
         {
            m = this->position.getColRowText()  // src
               + newPos.getColRowText();        // dest

            // check if potential move is a space.
            if (board[newPos].getType() == SPACE)
            {
               moves.insert(m); //insert a possible move.
            }
         }
      }

      // --------- FORWARD 1 ------------
      newPos.setRow(this->position.getRow() - 1);
      // valid move
      if (newPos.isValid())
      {
         m = this->position.getColRowText()  // src
            + newPos.getColRowText();        // dest

         // check if potential move is a space.
         if (board[newPos].getType() == SPACE)
         {
            moves.insert(m); //insert a possible move.
         }
      }

      // --------- ATTACK LEFT ------------
      newPos.set(this->position.getCol() - 1, 
                 this->position.getRow() - 1);
      pt = board[newPos].getType();

      // valid move
      if (newPos.isValid() &&
         pt != SPACE &&
         board[newPos].isWhite())
      {
         m = this->position.getColRowText()  // src
            + newPos.getColRowText()         // dest
            + m.letterFromPieceType(pt);     // capture

         moves.insert(m); //insert a possible move.
      }

      // --------- ATTACK RIGHT ------------
      newPos.set(this->position.getCol() + 1,
                 this->position.getRow() - 1);
      pt = board[newPos].getType();

      // valid move and capturable piece
      if (newPos.isValid() &&
          pt != SPACE &&
          board[newPos].isWhite())
      {
         m = this->position.getColRowText()  // src
            + newPos.getColRowText()         // dest
            + m.letterFromPieceType(pt);     // capture

         moves.insert(m); //insert a possible move.
      }

      // --------- EN-PASSANT ------------
    

      // --------- EN-PASSANT ------------
      if (this->position.getRow() == 3)
      {
         Position pawnRight = Position(this->position.getCol() + 1, this->position.getRow());
         Position pawnLeft = Position(this->position.getCol() - 1, this->position.getRow());
         Position attackRight = Position(this->position.getCol() + 1, this->position.getRow() - 1);
         Position attackLeft = Position(this->position.getCol() - 1, this->position.getRow() - 1);

         //std::cout << (board[pawnRight].getType()) << std::endl;
         //std::cout << board[pawnRight].justMoved(board.getCurrentMove()) << std::endl;
         //std::cout << board[pawnRight].getLastMove() << std::endl;
         //std::cout << board[pawnRight].isWhite() << std::endl;

         if (board[pawnRight].getType() == PAWN &&
            board[pawnRight].justMoved(board.getCurrentMove()) &&
            board[pawnRight].isWhite())
         {
            m = this->position.getColRowText() +            // src
                attackRight.getColRowText() + (string)"E";  // dest

                moves.insert(m);
         }
      }



      //if (this->position.getRow() == 3) // en-passont 
      //{
      //   if (board[pawnRight].getType() == PAWN && 
      //         board[pawnRight].justMoved(board.getCurrentMove()) &&
      //         board[pawnLeft].isWhite())
      //   {
      //      m = this->position.getColRowText() // src
      //         + attackRight.getColRowText() + (string)"E";   // dest
      //      moves.insert(m);
      //   }
      //   if (board[pawnLeft].getType() == PAWN && 
      //         board[pawnLeft].justMoved(board.getCurrentMove()) && 
      //         board[pawnLeft].isWhite())
      //   {

      //      m = this->position.getColRowText() // src
      //         + attackLeft.getColRowText() + (string)"E";   // dest
      //      moves.insert(m);
      //   }

      //// --------- PROMOTION ------------
      //if (this->position.getRow() == 0)
      //{
      //   board[this->position].set
      //}

   }
   else // White Pawn
   {
      // --------- FORWARD 2 ------------
      newPos.setRow(this->position.getRow() + 2);
      newPos.setCol(this->position.getCol());

      // valid move
      if (newPos.isValid())
      {
         // starting row and has not moved
         if (this->position.getRow() == 1 && this->hasMoved())
         {
            m = this->position.getColRowText()     // src
               + newPos.getColRowText();           // dest

            // check if potential move is a space.
            if (board[newPos].getType() == SPACE)
            {
               moves.insert(m); //insert a possible move.
            }
         }
      }

      // --------- FORWARD 1 ------------
      newPos.setRow(this->position.getRow() + 1);
      // valid move
      if (newPos.isValid())
      {
         m = this->position.getColRowText()     // src
            + newPos.getColRowText();           // dest

         // check if potential move is a space.
         if (board[newPos].getType() == SPACE)
         {
            moves.insert(m); //insert a possible move.
         }
      }

      // --------- ATTACK LEFT ------------
      newPos.set(this->position.getCol() - 1,
         this->position.getRow() + 1);
      pt = board[newPos].getType();

      // valid move
      if (newPos.isValid() &&
         pt != SPACE &&
         !board[newPos].isWhite())
      {
         m = this->position.getColRowText()  // src
            + newPos.getColRowText()         // dest
            + m.letterFromPieceType(pt);     // capture

         moves.insert(m); //insert a possible move.
      }

      // --------- ATTACK RIGHT ------------
      newPos.set(this->position.getCol() + 1,
         this->position.getRow() + 1);
      pt = board[newPos].getType();

      // valid move and capturable piece
      if (newPos.isValid() &&
         pt != SPACE &&
         !board[newPos].isWhite())
      {
         m = this->position.getColRowText()  // src
            + newPos.getColRowText()         // dest
            + m.letterFromPieceType(pt);     // capture

         moves.insert(m); //insert a possible move.
      }
   }
}

void Pawn::display(ogstream* pgout) const
{
   pgout->drawPawn(position, !fWhite);
}
