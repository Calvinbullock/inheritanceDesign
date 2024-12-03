
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

#define _USE_MATH_DEFINES

#include <vector>
#include <cmath>        // for sin, cos
#include <math.h>       // for M_PI
#include <cassert>      // for ASSERT

#include "test.h"
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*

#include "satelliteGPS.h"
#include "satelliteShip.h"
#include "satelliteHubble.h"
#include "satelliteDragon.h"
#include "satelliteSputnik.h"
#include "satelliteStarlink.h"
#include "star.h"
#include "earth.h"

#include "position.h"   // for POINT
#include "physics.cpp"  // for physics EQTNs

using namespace std;

#define GRAVITY_SEA_LEVEL 9.80665 // m/s2 acceleration towards the earth
#define RADIUS_EARTH 6378000.0    // m
#define ROTATION_SPEED 0.02       // rotation speed for satellites
#define TIME 48.0                 // seconds/frame
#define STAR_COUNT 300            // number or stars

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Simulator
{
public:
   Simulator(Position ptUpperRight, int starCountIn) : ptUpperRight(ptUpperRight)
   {
      starCount = starCountIn;
      earth = Earth();

      initializeSatellites();

      // populate star vector
      for (int i = 0; i < starCount; i++) {
         stars.push_back(Star(ptUpperRight));
      }
   }

   int getStarCount() { return starCount; }

   /****************************************
   * INITIALIZE SATELLITES
   * initialize all the satellites and add them
   *     to the satellite vector.
   *     (DreamChaser is instantiated but not
   *     added to the vector)
   * *****************************************/
   void initializeSatellites()
   {
      // initial DreamChaser satellite
      Position initialPos;
      initialPos.setPixelsX(-450);
      initialPos.setPixelsY(450);
      Velocity initialVel = Velocity(0.0, -2000);
      Angle a = Angle();
      entities.push_back(new SatelliteShip(initialPos, initialVel, a));

      // GPS satellite 1
      initialPos = Position(0.0, 26560000.0);
      initialVel = Velocity(-3880.0, 0.0);
      a = Angle();
      entities.push_back(new SatelliteGPS(initialPos, initialVel, a));

      // GPS satellite 2
      initialPos = Position(23001634.72, 13280000.0 );
      initialVel = Velocity(-1940.00, 3360.18);
      a = Angle();
      entities.push_back(new SatelliteGPS(initialPos, initialVel, a));

      // GPS satellite 3
      initialPos = Position(23001634.72, -13280000.0 );
      initialVel = Velocity(1940.00, 3360.18);
      a = Angle();
      entities.push_back(new SatelliteGPS(initialPos, initialVel, a));

      // GPS satellite 4
      initialPos = Position(0.0, -26560000.0);
      initialVel = Velocity(3880.0, 0.0);
      a = Angle();
      entities.push_back(new SatelliteGPS(initialPos, initialVel, a));

      // GPS satellite 5
      initialPos = Position(-23001634.72, -13280000.0 );
      initialVel = Velocity(1940.00, -3360.18);
      a = Angle();
      entities.push_back(new SatelliteGPS(initialPos, initialVel, a));

      // GPS satellite 6
      initialPos = Position(-23001634.72, 13280000.0 );
      initialVel = Velocity(-1940.00, -3360.18);
      a = Angle();
      entities.push_back(new SatelliteGPS(initialPos, initialVel, a));

      // initial Hubble satellite
      initialPos = Position(0.0, -42164000.0);
      initialVel = Velocity(3100.0, 0.0);
      a = Angle();
      entities.push_back(new SatelliteHubble(initialPos, initialVel, a));

      // sputnik
      initialPos = Position(-36515095.13, 21082000.0);
      initialVel = Velocity(2050.0, 2684.68);
      a = Angle();
      entities.push_back(new SatelliteSputnik(initialPos, initialVel, a));

      // starlink
      initialPos = Position(0.0, -13020000.0);
      initialVel = Velocity(5800.0, 0.0);
      a = Angle();
      entities.push_back(new SatelliteStarlink(initialPos, initialVel, a));

      // Dragon
      initialPos = Position(0.0, 8000000.0);
      initialVel = Velocity(-7900.0, 0.0);
      a = Angle();
      entities.push_back(new SatelliteDragon(initialPos, initialVel, a));
   }

   // Destructor
   ~Simulator()
   {
      // Clean up the dynamically allocated memory
      for (Entity* entity : entities)
      {
         delete entity;
      }
   }

   std::vector<Entity*> entities;
   std::vector<Star> stars;

   int starCount;          // number or stars
   Position ptUpperRight;
   Earth earth;
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

   Position pt;
   ogstream gout(pt);

   // thrust for dreamChaser
   Thrust thrust;
   thrust.set(pUI);

   // Use dynamic_cast to check if the entity is a Satellite
   pSim->entities[0]->input(thrust, TIME);

   // Orbit, rotate, and draw all entities
   for (int i = 0; i < pSim->entities.size(); i++)
   {
      double distanceFromEarth = computeDistance(Position(0, 0), pSim->entities[i]->getPosition());

      // Gravity
      double gravity = getGravity(GRAVITY_SEA_LEVEL, RADIUS_EARTH, distanceFromEarth);

      Angle gravityAngle;
      double gravityAngleRadians = getDirectionGravity(Position(), pSim->entities[i]->getPosition());
      gravityAngle.setRadians(gravityAngleRadians);

      // Acceleration
      Acceleration acceleration;
      acceleration.set(gravityAngle, gravity);

      pSim->entities[i]->orbit(TIME, acceleration); // orbit entities
      pSim->entities[i]->draw(gout);                // draw

      // rotate all but the dreamChaser
      if (!(i == 0)) {
         pSim->entities[i]->rotate(ROTATION_SPEED);    // rotate
      }
   }

   //
   // Draw all but satellites
   //

   // rotate / draw the earth
   pSim->earth.rotate(0.00349);
   pSim->earth.draw(gout);

   // draw stars
   for (int i = 0; i < pSim->getStarCount(); ++i) {
      pSim->stars[i].draw(gout);
   }

   pt.setMeters(0.0, 0.0);

   if (pUI->isSpace())
   {
      for (int i = 0; i < pSim->entities.size(); i++)
      {
         pSim->entities[i]->impact(pSim->entities);
      }
   }
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
   Simulator demo(ptUpperRight, STAR_COUNT);

   // set everything into action
   ui.run(callBack, &demo);

   return 0;
}
