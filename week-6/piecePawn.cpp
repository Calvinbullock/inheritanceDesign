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

   // BLACK
   if (!this->fWhite)
   {
      
      // --------- BLACK FORWARD 2 ------------
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

      // --------- BLACK FORWARD 1 ------------
      newPos.setRow(this->position.getRow() - 1);

      // valid move
      if (newPos.isValid())
      {
         // check if potential move is a space.
         if (board[newPos].getType() == SPACE)
         {
            if (newPos.getRow() == 0) // BLACK PAWN PROMOTION
            {
               m = this->position.getColRowText() +  // src
                   newPos.getColRowText() +          // dest
                   (string)"Q";                      // promotion
               moves.insert(m); //insert a possible move.
            }
            else // normal move
            {
               m = this->position.getColRowText()  // src
                  + newPos.getColRowText();        // dest
               moves.insert(m); //insert a possible move.
            }
         }
      }

      // --------- BLACK ATTACK LEFT ------------
      newPos.set(this->position.getCol() - 1, 
                 this->position.getRow() - 1);
      pt = board[newPos].getType();

      // valid move and capturable piece
      if (newPos.isValid() &&
         pt != SPACE &&
         board[newPos].isWhite())
      {
         if (newPos.getRow() == 0) // BLACK ATTACKING PAWN PROMOTION
         {
            m = this->position.getColRowText() + // src
               newPos.getColRowText() +          // dest
               m.letterFromPieceType(pt) +       // capture
               (string)"Q";                      // promotion
            moves.insert(m); //insert a possible move.
         }
         else // normal attack move
         {
            m = this->position.getColRowText() + // src
               newPos.getColRowText() +          // dest
               m.letterFromPieceType(pt);        // capture    

            moves.insert(m); //insert a possible move.
         }
      }

      // --------- BLACK ATTACK RIGHT ------------
      newPos.set(this->position.getCol() + 1,
                 this->position.getRow() - 1);
      pt = board[newPos].getType();

      // valid move and capturable piece
      if (newPos.isValid() &&
          pt != SPACE &&
          board[newPos].isWhite())
      {
         if (newPos.getRow() == 0) // BLACK ATTACKING PAWN PROMOTION
         {
            m = this->position.getColRowText() + // src
               newPos.getColRowText() +          // dest
               m.letterFromPieceType(pt) +       // capture
               (string)"Q";                      // promotion
            moves.insert(m); //insert a possible move.
         }
         else // normal attack move
         {
            m = this->position.getColRowText() + // src
               newPos.getColRowText() +          // dest
               m.letterFromPieceType(pt);       // capture    

            moves.insert(m); //insert a possible move.
         } 
      }

      // --------- BLACK EN-PASSANT ------------
      if (this->position.getRow() == 3)
      {
         Position pawnRight = Position(this->position.getCol() + 1, this->position.getRow());
         Position pawnLeft = Position(this->position.getCol() - 1, this->position.getRow());
         Position attackRight = Position(this->position.getCol() + 1, this->position.getRow() - 1);
         Position attackLeft = Position(this->position.getCol() - 1, this->position.getRow() - 1);

         // --------- EN-PASSANT - RIGHT ------------
         if (board[pawnRight].getType() == PAWN &&
            board[pawnRight].justMoved(board.getCurrentMove()) &&
            board[pawnRight].isWhite())
         {
            m = this->position.getColRowText() +            // src
                attackRight.getColRowText() + (string)"E";  // dest

                moves.insert(m);
         }
         // --------- EN-PASSANT - LEFT ------------
         if (board[pawnLeft].getType() == PAWN &&
            board[pawnLeft].justMoved(board.getCurrentMove()) &&
            board[pawnLeft].isWhite())
         {
            m = this->position.getColRowText() +          // src
               attackLeft.getColRowText() + (string)"E";  // dest

            moves.insert(m);
         }
      }



   }
   else // WHITE PAWN
   {
      // --------- WHITE FORWARD 2 ------------
      newPos.setRow(this->position.getRow() + 2);
      newPos.setCol(this->position.getCol());

      // valid move
      if (newPos.isValid())
      {
         // starting row and has not moved
         if (this->position.getRow() == 1 && this->hasMoved())
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

      // --------- WHITE FORWARD 1 ------------
      newPos.setRow(this->position.getRow() + 1);
      // valid move
      if (newPos.isValid())
      {
         // check if potential move is a space.
         if (board[newPos].getType() == SPACE)
         {
            if (newPos.getRow() == 7) // WHITE PAWN PROMOTION
            {
               m = this->position.getColRowText() + // src
                  newPos.getColRowText() +          // dest
                  (string)"Q";                      // promotion
               moves.insert(m); //insert a possible move.
            }
            else // normal move
            {
               m = this->position.getColRowText()  // src
                  + newPos.getColRowText();        // dest
               moves.insert(m); //insert a possible move.
            }
         }
      }

      // --------- WHITE ATTACK LEFT ------------
      newPos.set(this->position.getCol() - 1,
         this->position.getRow() + 1);
      pt = board[newPos].getType();

      // valid move
      if (newPos.isValid() &&
         pt != SPACE &&
         !board[newPos].isWhite())
      {
         if (newPos.getRow() == 7) // WHITE ATTACKING PAWN PROMOTION
         {
            m = this->position.getColRowText() + // src
               newPos.getColRowText() +          // dest
               m.letterFromPieceType(pt) +       // capture
               (string)"Q";                      // promotion
            moves.insert(m); //insert a possible move.
         }
         else // normal attack move
         {
            m = this->position.getColRowText() + // src
               newPos.getColRowText() +          // dest
               m.letterFromPieceType(pt);       // capture    

            moves.insert(m); //insert a possible move.
         }
      }

      // --------- WHITE ATTACK RIGHT ------------
      newPos.set(this->position.getCol() + 1,
         this->position.getRow() + 1);
      pt = board[newPos].getType();

      // valid move and capturable piece
      if (newPos.isValid() &&
         pt != SPACE &&
         !board[newPos].isWhite())
      {
         if (newPos.getRow() == 7) // WHITE ATTACKING PAWN PROMOTION
         {
            m = this->position.getColRowText() + // src
               newPos.getColRowText() +          // dest
               m.letterFromPieceType(pt) +       // capture
               (string)"Q";                      // promotion
            moves.insert(m); //insert a possible move.
         }
         else // normal attack move
         {
            m = this->position.getColRowText() + // src
               newPos.getColRowText() +          // dest
               m.letterFromPieceType(pt);        // capture   

            moves.insert(m); //insert a possible move.
         }
      }

      // --------- WHITE EN-PASSANT ------------
      if (this->position.getRow() == 4)
      {
         Position pawnRight = Position(this->position.getCol() + 1, this->position.getRow());
         Position pawnLeft = Position(this->position.getCol() - 1, this->position.getRow());
         Position attackRight = Position(this->position.getCol() + 1, this->position.getRow() + 1);
         Position attackLeft = Position(this->position.getCol() - 1, this->position.getRow() + 1);

         // --------- EN-PASSANT - RIGHT ------------
         if (board[pawnRight].getType() == PAWN &&
            board[pawnRight].justMoved(board.getCurrentMove()) &&
            !board[pawnRight].isWhite())
         {
            m = this->position.getColRowText() +            // src
               attackRight.getColRowText() + (string)"E";   // dest

            moves.insert(m);
         }
         // --------- EN-PASSANT - LEFT ------------
         if (board[pawnLeft].getType() == PAWN &&
            board[pawnLeft].justMoved(board.getCurrentMove()) &&
            !board[pawnLeft].isWhite())
         {
            m = this->position.getColRowText() +            // src
               attackLeft.getColRowText() + (string)"E";    // dest

            moves.insert(m);
         }
      }
   }
}

void Pawn::display(ogstream* pgout) const
{
   pgout->drawPawn(position, !fWhite);
}