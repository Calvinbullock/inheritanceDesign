
/***********************************************************************
 * Header File:
 *    For Simulator class, main function and callback
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    Holds the class with all the simulator class parts.
 *       also has the callback function for the openGL
 *       and the main function.
 ************************************************************************/

#include <vector>
#define _USE_MATH_DEFINES

#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "satelliteGPS.h" // for GPS satellite
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"   // for POINT
#include "test.h"
#include <cmath>        // for sin, cos
#include <math.h>       // for M_PI
#include "physics.cpp"  // for physics

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

      // initial GPS satellite values
      Position initialGPSPos = Position(0.0, 42164000.0);
      Velocity initialGPSVel = Velocity(-3100.0, 0.0);
      Angle a = Angle();

      // Create 1 GPS Satellite
      GPS = SatelliteGPS(initialGPSPos, initialGPSVel, a);
      //entities.push_back(GPS);

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

      angleEarth = 0.0;
      phaseStar = 0;
   }

   std::vector<unsigned char> starPhases;
   std::vector<Position> positions;
   //std::vector<Satellite> entities; // TODO:

   SatelliteGPS GPS;

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
   // perform all the game logic
   //

   // Gravity
   double gravity = getGravity(GRAVITY_SEA_LEVEL, RADIUS_EARTH, EARTH_SURFACE);

   // TODO: -- this should all be in a loop of entity's when we add more Entitys [
   // direction of the pull of gravity
   Angle gravityAngle;
   double gravityAngleRadians = getDirectionGravity(Position(), pSim->GPS.getPosition());
   gravityAngle.setRadians(gravityAngleRadians);

   // Acceleration
   Acceleration acceleration;
   acceleration.set(gravityAngle, gravity);

   // orbit entities
   pSim->GPS.orbit(TIME, acceleration);
   // ]

   // rotate the earth
   pSim->angleEarth -= 0.00349; // 2PI / 1800 || full orbit / frames in a min
   pSim->phaseStar++;

   //
   // draw everything
   //

   Position pt;
   ogstream gout(pt);

   // draw satellites
   pSim->GPS.draw(gout);
   pSim->GPS.rotate(0.02);

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
      "Demo",   /* name on the window */
      ptUpperRight);

   // Initialize the demo
   Simulator demo(ptUpperRight);

   // set everything into action
   //ui.run(callBack, &demo);

   return 0;
}
