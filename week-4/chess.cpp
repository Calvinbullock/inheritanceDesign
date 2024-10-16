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
   pBoard->display(Position(), Position());
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
 /*  set<Position> s;
   Position pos;
   pos.setLocation(42);
   s.insert(pos);
   pos.setLocation(55);
   s.insert(pos);

   int x;

   for (const Position& p : s)
   
      x = p.getLocation();
   return 0;*/


   //set<Move> m;
   //Move move;
   //move = "a1b1";
   //m.insert(move);
   //move = "a2b2p";
   //m.insert(move);

   //Position x;
   //Position y;

   //for (const Move& mov : m)

   //   x = move.getSource();
   //   y = move.getDest();
   //return 0;

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
