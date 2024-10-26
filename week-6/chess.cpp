/**********************************************************************
* Source File:
*    Lab 04: Chess
* Author:
 *    Calvin Bullock, Daniel Malasky
* Summary:
*    Play the game of chess
************************************************************************/


#include "uiInteract.h"   // for Interface
#include "uiDraw.h"       // for OGSTREAM
#include "position.h"     // for POSITION
#include "piece.h"        // for PIECE and company
#include "board.h"        // for BOARD
#include "test.h"
#include <iostream>
#include <set>            // for STD::SET
#include <cassert>        // for ASSERT
#include <fstream>        // for IFSTREAM
#include <string>         // for STRING
using namespace std;


/**************************************
 * GAMEPLAY - Handle rules for each turn
 **************************************/
void gameplay(Interface* &pUI, Board* &pBoard, std::set<Move> &possibleMoves)
{
   
   Move selectedMove;

   // if valid selection
   if (pUI->getSelectPosition().isValid())
   {
      //cout << (*pBoard)[pUI->getSelectPosition()].getNMoves() << endl;
       
      cout << (*pBoard)[pUI->getSelectPosition()].getType() << endl;
      //cout << pBoard->getCurrentMove() << endl;
       
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

            set <Move>::iterator its;
            for (its = possibleMoves.begin(); its != possibleMoves.end(); ++its)
            {
               
               cout << its->getText() << ",";
               
            }
            cout << endl;

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
               cout << selectedMove.getText() << endl;
               pUI->clearSelectPosition();
            }
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
   
   gameplay(pUI, pBoard, possibleMoves);


   //if ((*pBoard)[pUI->getSelectPosition()].getType() == SPACE) // can't select space
   //{
   //   pUI->clearSelectPosition();
   //}

   // display the board
   pBoard->display(pUI->getHoverPosition(), pUI->getSelectPosition(), *pUI , possibleMoves);
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
