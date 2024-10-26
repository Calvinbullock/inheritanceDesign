/**********************************************************************
* Source File:
*    Lab 04: Chess
* Author:
 *    Calvin Bullock, Daniel Malasky
* Summary:
*    Play the game of chess
************************************************************************/


#include "pieceType.h"
#include "uiInteract.h"   // for Interface
#include "uiDraw.h"       // for OGSTREAM
#include "position.h"     // for POSITION
#include "piece.h"        // for PIECE and company
#include "board.h"        // for BOARD
#include "test.h"
#include <set>            // for STD::SET
#include <cassert>        // for ASSERT
#include <fstream>        // for IFSTREAM
#include <string>         // for STRING
using namespace std;


void takeTurn(Interface *pUI, Board* &pBoard, std::set <Move> &possibleMoves)
{
   Move selectedMove;

   // selection is not a space
   if ((*pBoard)[pUI->getSelectPosition()].getType() != SPACE)
   {
      // get possible moves from a selected position
      (*pBoard)[pUI->getSelectPosition()].getMoves(possibleMoves, *pBoard);
   }

   // if previous move exists and is valid
   if (pUI->getPreviousPosition().isValid())
   {
      if ((*pBoard)[pUI->getPreviousPosition()].getType() != SPACE)
      {
         // re-gets moves new selection/scope change
         (*pBoard)[pUI->getPreviousPosition()].getMoves(possibleMoves, *pBoard);

         // Check is selectedMove is in possible Moves
         set <Move>::iterator it;
         for (it = possibleMoves.begin(); it != possibleMoves.end(); ++it) 
         {
            if (it->getSource() == pUI->getPreviousPosition() &&
               it->getDest() == pUI->getSelectPosition())
            {
               selectedMove = *it;
            }
         }

         // Move if possible
         if (possibleMoves.find(selectedMove) != possibleMoves.end())
         {
            // move the piece
            pBoard->move(selectedMove);
            pUI->clearSelectPosition();
         }
      }
   }
}

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(Interface *pUI, void * p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Board * pBoard = (Board *)p;  
   set<Move> possibleMoves;
   bool isWhiteTurn = (*pBoard).whiteTurn();

   // if valid selection
   if (pUI->getSelectPosition().isValid()) 
   {
      bool selectedIsWhite = (*pBoard)[pUI->getSelectPosition()].isWhite();
      PieceType selectedPT = (*pBoard)[pUI->getSelectPosition()].getType();

      // turn color determination
      if (isWhiteTurn && selectedIsWhite && selectedPT != SPACE)
      {
         takeTurn(pUI, pBoard, possibleMoves);
      }
      else if (!isWhiteTurn && !selectedIsWhite)
      {
         takeTurn(pUI, pBoard, possibleMoves);
      }
      else if (pUI->getPreviousPosition().isValid()) // Attacking
      {
         bool prevSelectedIsWhite = (*pBoard)[pUI->getPreviousPosition()].isWhite();
         PieceType prevSelectedPT = (*pBoard)[pUI->getPreviousPosition()].getType();

         if (isWhiteTurn && prevSelectedIsWhite 
               && (!selectedIsWhite || selectedPT == SPACE))
         {
            takeTurn(pUI, pBoard, possibleMoves);
         }
         else if (!isWhiteTurn && !prevSelectedIsWhite && selectedIsWhite)
         {
            takeTurn(pUI, pBoard, possibleMoves);
         }
      }
      else
      {
         pUI->clearSelectPosition();
      }
      pUI->clearPreviousPosition();
   }

   // display the board
   pBoard->display(pUI->getHoverPosition(), 
                   pUI->getSelectPosition(), 
                   *pUI , possibleMoves);
}


/*********************************
 * MAIN - Where it all begins...
 *********************************/
#ifdef _WIN32
#include <windows.h>
int WINAPI WinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{

   // run all the unit tests
   testRunner();
   
   // Instantiate the graphics window
   Interface ui("Chess");    

   // Initialize the game class
   ogstream* pgout = new ogstream;
   Board board(pgout);

   // set everything into action
   ui.run(callBack, (void *)(&board));
   
   // All done.
   delete pgout;
   return 0;
}
