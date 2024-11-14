/*************************************************************
 * 1. Name:
 *      Daniel Malasky & Calvin Bullock
 * 2. Assignment Name:
 *      Lab 07: Orbit Simulator
 * 3. Assignment Description:
 *      Simulate satellites orbiting the earth
 * 4. What was the hardest part? Be as specific as possible.
 *      The hardest part was understanding the physics, but the
 *      video in the problem definition helped out a lot with this.
 * 5. How long did it take for you to complete the assignment?
 *      ~3hrs
 *****************************************************************/

#include <vector>
#define _USE_MATH_DEFINES

#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"   // for POINT
#include "test.h"
#include <cmath>        // for sin, cos
#include <math.h>       // for M_PI

using namespace std;

#define GRAVITY_SEA_LEVEL 9.80665 // m/s2 acceleration towards the earth
#define RADIUS_EARTH 6378000.0 //m
#define EARTH_SURFACE 35786000.0 //m - Distance from earths surface
#define EARTH_CENTER 42164000.0 //m - Distance from earths center
#define TIME 48 // seconds/frame

// EVENTUALLY WILL BE A CLASS
// Initial velocity
double DX = -3100.0;
double DY = 0.0;
int starCount = 300; // number or stars


/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Simulator
{
public:
   Simulator(Position ptUpperRight) :
      ptUpperRight(ptUpperRight)
   {
      //ptHubble.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      //ptHubble.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      //ptSputnik.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      //ptSputnik.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      //ptStarlink.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      //ptStarlink.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      //ptCrewDragon.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      //ptCrewDragon.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      ptShip.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      ptShip.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));


      // Initial Position
      ptGPS.setMetersX(0.0);
      ptGPS.setMetersY(42164000.0);

      // velocity with constant acceleration
      // v = v0 + a t

      ptStar.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      ptStar.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      // populate star vector
      for (int i = 0; i < starCount; i++) {
         ptStar.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
         ptStar.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));
         positions.push_back(ptStar);
      }

      // populate starPhase vector
      for (int i = 0; i < starCount; i++) {
         unsigned char phase = 4 * random(1, 50);
         starPhases.push_back(phase);
      }

      angleShip = 0.0;
      angleEarth = 0.0;
      phaseStar = 0;
   }

   std::vector<unsigned char> starPhases;
   std::vector<Position> positions;
   Position ptHubble;
   Position ptSputnik;
   Position ptStarlink;
   Position ptCrewDragon;
   Position ptShip;
   Position ptGPS;
   Position ptStar;
   Position ptUpperRight;

   unsigned char phaseStar;

   double angleShip;
   double angleEarth;
};


/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL.
   Simulator* pSim = (Simulator*)p;

   //
   // accept input
   //

   // move by a little
   if (pUI->isUp())
      pSim->ptShip.addPixelsY(1.0);
   if (pUI->isDown())
      pSim->ptShip.addPixelsY(-1.0);
   if (pUI->isLeft())
      pSim->ptShip.addPixelsX(-1.0);
   if (pUI->isRight())
      pSim->ptShip.addPixelsX(1.0);

   //
   // perform all the game logic
   //

   // positions
   double currXPos = pSim->ptGPS.getMetersX();
   double currYPos = pSim->ptGPS.getMetersY();

   // TODO:
   // SLOW DOWN
   // rotate the earth
   pSim->angleEarth -= 0.00349; // 2PI / 1800 || full orbit / frames in a min
   pSim->angleShip += 0.02;
   pSim->phaseStar++;

   //
   // draw everything
   //

   Position pt;
   ogstream gout(pt);

   // draw satellites
   gout.drawCrewDragon(pSim->ptCrewDragon, pSim->angleShip);
   gout.drawHubble    (pSim->ptHubble,     pSim->angleShip);
   gout.drawSputnik   (pSim->ptSputnik,    pSim->angleShip);
   gout.drawStarlink  (pSim->ptStarlink,   pSim->angleShip);
   gout.drawShip      (pSim->ptShip,       pSim->angleShip, pUI->isSpace());
   gout.drawGPS       (pSim->ptGPS,        pSim->angleShip);

   // draw parts
   pt.setPixelsX(pSim->ptCrewDragon.getPixelsX() + 20);
   pt.setPixelsY(pSim->ptCrewDragon.getPixelsY() + 20);
   gout.drawCrewDragonRight(pt, pSim->angleShip); // notice only two parameters are set
   pt.setPixelsX(pSim->ptHubble.getPixelsX() + 20);
   pt.setPixelsY(pSim->ptHubble.getPixelsY() + 20);
   gout.drawHubbleLeft(pt, pSim->angleShip);      // notice only two parameters are set
   pt.setPixelsX(pSim->ptGPS.getPixelsX() + 20);
   pt.setPixelsY(pSim->ptGPS.getPixelsY() + 20);
   gout.drawGPSCenter(pt, pSim->angleShip);       // notice only two parameters are set
   pt.setPixelsX(pSim->ptStarlink.getPixelsX() + 20);
   pt.setPixelsY(pSim->ptStarlink.getPixelsY() + 20);
   gout.drawStarlinkArray(pt, pSim->angleShip);   // notice only two parameters are set

   // draw fragments
   pt.setPixelsX(pSim->ptSputnik.getPixelsX() + 20);
   pt.setPixelsY(pSim->ptSputnik.getPixelsY() + 20);
   gout.drawFragment(pt, pSim->angleShip);
   pt.setPixelsX(pSim->ptShip.getPixelsX() + 20);
   pt.setPixelsY(pSim->ptShip.getPixelsY() + 20);
   gout.drawFragment(pt, pSim->angleShip);

   // draw a single star
   gout.drawStar(pSim->ptStar, pSim->phaseStar);

   // draw stars
   for (int i = 0; i < starCount; ++i) {
      pSim->starPhases[i]++;
      gout.drawStar(pSim->positions[i], pSim->starPhases[i]);
   }

   // draw the earth
   pt.setMeters(0.0, 0.0);
   gout.drawEarth(pt, pSim->angleEarth);
}

double Position::metersFromPixels = 40.0;

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   testRunner();

   // Initialize OpenGL
   Position ptUpperRight;
   ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
   ptUpperRight.setPixelsX(1000.0);
   ptUpperRight.setPixelsY(1000.0);

   Interface ui(0, NULL,
      "Orbit Sim",   /* name on the window */
      ptUpperRight);

   // Initialize the demo
   Simulator sim(ptUpperRight);

   // set everything into action
   //ui.run(callBack, &demo);

   return 0;
}
