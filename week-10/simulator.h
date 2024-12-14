
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
#pragma once

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
#include "physics.h"  // for physics EQTNs

using namespace std;

#define GRAVITY_SEA_LEVEL 9.80665   // m/s2 acceleration towards the earth
#define RADIUS_EARTH 6378000.0      // m
#define ROTATION_SPEED 0.02         // rotation speed for satellites
#define ROTATION_SPEED_DEFUNCT 0.2    // rotation speed for defunct satellites
#define TIME 48.0                   // seconds/frame
#define STAR_COUNT 300              // number or stars

class TestSimulator;

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Simulator
{

   friend TestSimulator;

public:
   Simulator() {}
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

   // Set satellites status
   void initializeSatellites();

   // Collision Checkers
   void earthCollisionCheck();
   void checkCollision(int iSat);

   // Destructor
   ~Simulator()
   {
      // Clean up the dynamically allocated memory
      for (Entity* entity : entities)
      {
         delete entity;
         entity = nullptr;
      }
   }

   std::vector<Entity*> entities;
   std::vector<Star> stars;

   int starCount;          // number or stars
   Position ptUpperRight;
   Earth earth;
};

