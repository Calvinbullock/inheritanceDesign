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
#include <set>            // for STD::SET
#include <cassert>        // for ASSERT
#include <fstream>        // for IFSTREAM
#include <string>         // for STRING
using namespace std;


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

   

   // find selected piece
   // get piece type
   // getMoves
   // board.move
   // check if selected position isValid

   //if (pUI->getSelectPosition() != -1 && pBoard[pUI->getSelectPosition()] == ' ')
   //   pUI->clearSelectPosition();

   if (pUI->getSelectPosition().isValid() &&
      (*pBoard)[pUI->getSelectPosition()].getType() != SPACE)
   {
      // get possible moves from a selected position
      (*pBoard)[pUI->getSelectPosition()].getMoves(possibleMoves, *pBoard);

      Move selectedMove;
      selectedMove.setSource(pUI->getPreviousPosition());
      selectedMove.setDest(pUI->getSelectPosition());


      // move the piece
      //pBoard->move(selectedMove);
   }
      
   

   //// move 
   //pBoard->move(board, pUI->getPreviousPosition(), pUI->getSelectPosition()))
   //   pUI->clearSelectPosition();
   //else
   //   possible = getPossibleMoves(board, pUI->getSelectPosition());

   //// if we clicked on a blank spot, then it is not selected
   //if (pUI->getSelectPosition() != -1 && board[pUI->getSelectPosition()] == ' ')
   //   pUI->clearSelectPosition();

   //// draw the board
   //draw(board, *pUI, possible);

   // display the board
   pBoard->display(pUI->getHoverPosition(), pUI->getSelectPosition(), *pUI /*, possibleMoves*/);


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
