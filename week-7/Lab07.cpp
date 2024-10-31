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


/******************************************************************
* GET GRAVITY : magnitude of acceleration due to gravity at an altitude
* 
* gh = magnitude of acceleration due to gravity at an altitude(h)
* g = gravity at sea level : 9.80665 m / s2
* r = radius of the earth : 6, 378, 000 m
* h = height above the earth in meters

* gh = g * ((r/(r+h)) * (r/(r+h)))
*********************************************************/
double getGravity(double g, double r, double h)
{
   return g * ((r / (r + h)) * (r / (r + h)));
}

/****************************************************
* GET DIRECTION GRAVITY: direction of the pull of gravity, in radians
* 
* xe = horizontal position of the center of the earth: 0 m
* ye = vertical position of the center of the earth: 0 m
* xs = horizontal position of the satellite in meters
* ys = vertical position of the satellite in meters
* 
* d = atan(xe - xs, ye - ys)
*****************************************************/
double getDirectionGravity(double xe, double ye, double xs, double ys)
{
   return atan2(xe - xs, ye - ys);
}

/**********************************************
* GETDDX: get horizontal component of acceleration
* 
* ddx = horizontal component of acceleration
* a = total acceleration
* angle = angle(0° is up) of the direction of acceleration
* 
* ddx = a * sin(angle)
*********************************************************/
double getDDX(double a, double angle)
{
   return a * sin(angle);
}

/**********************************************
* GETDDY: get vertical component of acceleration
* 
* ddy = vertical component of acceleration
* a = total acceleration
* angle = angle (0° is up) of the direction of acceleration
*
* ddy = a * cos(angle)	
*********************************************************/
double getDDY(double a, double angle)
{
   return a * cos(angle);
}

/********************************************************
* GET AXIS DISTANCE : horizontal or vertical position at time t(m)
* 
* x0 = initial horizontal position (m)
* dx = horizontal component of velocity (m/s)
* ddx = horizontal component of acceleration (m/s2)
* t = time (s)
* 
* * xt = horizontal position at time t (m)
*
* xt = x0 + dx * t + ½ * ddx * t^2
*********************************************************/
double getAxisDistance(double x0, double dx, double ddx, double t)
{
   return x0 + dx * t + (1/2) * ddx * (t * t);
}


/********************************************************
* GET AXIS VELOCITY : horizontal or vertical velocity at time t(m/s)
*
* dx0 = initial horizontal velocity(m / s)
* ddx = horizontal component of acceleration(m / s2)
* t = time(s)
*
* dxt = horizontal velocity at time t(m / s)
*
* dxt = dx0 + ddx t
*********************************************************/
double getAxisVelocity(double dx0, double ddx, double t)
{
   return dx0 + (ddx * t);
}



/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
public:
   Demo(Position ptUpperRight) :
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

      //ptShip.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      //ptShip.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));


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
   Demo* pDemo = (Demo*)p;

   //
   // accept input
   //

   // move by a little
   if (pUI->isUp())
      pDemo->ptShip.addPixelsY(1.0);
   if (pUI->isDown())
      pDemo->ptShip.addPixelsY(-1.0);
   if (pUI->isLeft())
      pDemo->ptShip.addPixelsX(-1.0);
   if (pUI->isRight())
      pDemo->ptShip.addPixelsX(1.0);

   //
   // perform all the game logic
   //

   // positions
   double currXPos = pDemo->ptGPS.getMetersX();
   double currYPos = pDemo->ptGPS.getMetersY();

   // Gravity
   double gravity = getGravity(GRAVITY_SEA_LEVEL, RADIUS_EARTH, EARTH_SURFACE);
   double gravityAngle = getDirectionGravity(0.0, 0.0, currXPos, currYPos);

   // Acceleration
   double ddx = getDDX(gravity, gravityAngle);
   double ddy = getDDY(gravity, gravityAngle);

   // Velocity
   DX = getAxisVelocity(DX, ddx, TIME);
   DY = getAxisVelocity(DY, ddy, TIME);
   
   // new distance
   double xPos = getAxisDistance(currXPos, DX, ddx, TIME);
   double yPos = getAxisDistance(currYPos, DY, ddy, TIME);

   // orbit the GPS satelite
   pDemo->ptGPS.setMetersX(getAxisDistance(currXPos, DX, ddx, TIME));
   pDemo->ptGPS.setMetersY(getAxisDistance(currYPos, DY, ddy, TIME));

   // TODO:
   // SLOW DOWN
   // rotate the earth
   pDemo->angleEarth -= 0.00349; // 2PI / 1800 || full orbit / frames in a min
   pDemo->angleShip += 0.02;
   pDemo->phaseStar++;

   //
   // draw everything
   //

   Position pt;
   ogstream gout(pt);

   // draw satellites
   gout.drawCrewDragon(pDemo->ptCrewDragon, pDemo->angleShip);
   gout.drawHubble    (pDemo->ptHubble,     pDemo->angleShip);
   gout.drawSputnik   (pDemo->ptSputnik,    pDemo->angleShip);
   gout.drawStarlink  (pDemo->ptStarlink,   pDemo->angleShip);
   gout.drawShip      (pDemo->ptShip,       pDemo->angleShip, pUI->isSpace());
   gout.drawGPS       (pDemo->ptGPS,        pDemo->angleShip);

   // draw parts
   pt.setPixelsX(pDemo->ptCrewDragon.getPixelsX() + 20);
   pt.setPixelsY(pDemo->ptCrewDragon.getPixelsY() + 20);
   gout.drawCrewDragonRight(pt, pDemo->angleShip); // notice only two parameters are set
   pt.setPixelsX(pDemo->ptHubble.getPixelsX() + 20);
   pt.setPixelsY(pDemo->ptHubble.getPixelsY() + 20);
   gout.drawHubbleLeft(pt, pDemo->angleShip);      // notice only two parameters are set
   pt.setPixelsX(pDemo->ptGPS.getPixelsX() + 20);
   pt.setPixelsY(pDemo->ptGPS.getPixelsY() + 20);
   gout.drawGPSCenter(pt, pDemo->angleShip);       // notice only two parameters are set
   pt.setPixelsX(pDemo->ptStarlink.getPixelsX() + 20);
   pt.setPixelsY(pDemo->ptStarlink.getPixelsY() + 20);
   gout.drawStarlinkArray(pt, pDemo->angleShip);   // notice only two parameters are set

   // draw fragments
   pt.setPixelsX(pDemo->ptSputnik.getPixelsX() + 20);
   pt.setPixelsY(pDemo->ptSputnik.getPixelsY() + 20);
   gout.drawFragment(pt, pDemo->angleShip);
   pt.setPixelsX(pDemo->ptShip.getPixelsX() + 20);
   pt.setPixelsY(pDemo->ptShip.getPixelsY() + 20);
   gout.drawFragment(pt, pDemo->angleShip);

   // draw a single star
   gout.drawStar(pDemo->ptStar, pDemo->phaseStar);

   // draw stars
   for (int i = 0; i < starCount; ++i) {
      pDemo->starPhases[i]++;
      gout.drawStar(pDemo->positions[i], pDemo->starPhases[i]);
   }

   // draw the earth
   pt.setMeters(0.0, 0.0);
   gout.drawEarth(pt, pDemo->angleEarth);
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
   Demo demo(ptUpperRight);

   // set everything into action
   ui.run(callBack, &demo);


   return 0;
}
