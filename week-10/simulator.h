
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

#pragma once

#define _USE_MATH_DEFINES

#include <vector>
#include <cmath>        // for sin, cos
#include <math.h>       // for M_PI
#include <cassert>      // for ASSERT

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
   Simulator() : ptUpperRight() {}
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
   * *****************************************/
   void initializeSatellites()
   {
      // TODO: this may need fine tuning
      int chanceDefunct = 3000; // 1 in X frames chance of defunct

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
      entities.push_back(new SatelliteGPS(initialPos, initialVel, a, chanceDefunct));

      // GPS satellite 2
      initialPos = Position(23001634.72, 13280000.0 );
      initialVel = Velocity(-1940.00, 3360.18);
      a = Angle();
      entities.push_back(new SatelliteGPS(initialPos, initialVel, a, chanceDefunct));

      // GPS satellite 3
      initialPos = Position(23001634.72, -13280000.0 );
      initialVel = Velocity(1940.00, 3360.18);
      a = Angle();
      entities.push_back(new SatelliteGPS(initialPos, initialVel, a, chanceDefunct));

      // GPS satellite 4
      initialPos = Position(0.0, -26560000.0);
      initialVel = Velocity(3880.0, 0.0);
      a = Angle();
      entities.push_back(new SatelliteGPS(initialPos, initialVel, a, chanceDefunct));

      // GPS satellite 5
      initialPos = Position(-23001634.72, -13280000.0 );
      initialVel = Velocity(1940.00, -3360.18);
      a = Angle();
      entities.push_back(new SatelliteGPS(initialPos, initialVel, a, chanceDefunct));

      // GPS satellite 6
      initialPos = Position(-23001634.72, 13280000.0 );
      initialVel = Velocity(-1940.00, -3360.18);
      a = Angle();
      entities.push_back(new SatelliteGPS(initialPos, initialVel, a, chanceDefunct));

      // initial Hubble satellite
      initialPos = Position(0.0, -42164000.0);
      initialVel = Velocity(3100.0, 0.0);
      a = Angle();
      entities.push_back(new SatelliteHubble(initialPos, initialVel, a, chanceDefunct));

      // sputnik
      initialPos = Position(-36515095.13, 21082000.0);
      initialVel = Velocity(2050.0, 2684.68);
      a = Angle();
      entities.push_back(new SatelliteSputnik(initialPos, initialVel, a, chanceDefunct));

      // starlink
      initialPos = Position(0.0, -13020000.0);
      initialVel = Velocity(5800.0, 0.0);
      a = Angle();
      entities.push_back(new SatelliteStarlink(initialPos, initialVel, a, chanceDefunct));

      // Dragon
      initialPos = Position(0.0, 8000000.0);
      initialVel = Velocity(-7900.0, 0.0);
      a = Angle();
      entities.push_back(new SatelliteDragon(initialPos, initialVel, a, chanceDefunct));
   }

   /****************************************
   * EarthCollisionCheck
   * Check to see if any entities have collided
   *     with the earth
   * *****************************************/
   void earthCollisionCheck()
   {
      //for (int i = 0; i < entities.size(); i++)
      for (int i = 0; i < 1; i++)
      {
         // check for earth collision
         double distanceToEarth = computeDistance(earth.getPosition(),
                                                  entities[i]->getPosition());
         double minDistanceToEarth = earth.getRadius() + entities[i]->getRadius();

         //std::cout << distanceToEarth << std::endl;    // TODO: remove
         //std::cout << minDistanceToEarth << std::endl; // TODO: remove

         // BUG:  TODO: THIS CHECK IS TO SLOW NEED TO FIX
         if (distanceToEarth < minDistanceToEarth)
         {
            //std::cout << "here" << std::endl; // TODO: remove
            entities[i]->impact(entities);

            // remove entity from list
            delete entities[i];
            entities.erase(entities.begin() + i);

            // stop further check for this satellite
            //return;
         }
      }
   }

   /****************************************
   * checkCollision
   * Check to see if any entities have collided
   *
   * NOTE: Must be called in a loop, thought the
   *     entities list
   * *****************************************/
   void checkCollision(int iSat)
   {
      // check for satellite collisions
      for (int iCheck = iSat + 1; iCheck < entities.size(); iCheck++)
      {
         // Find distance between the two ships
         double distance = computeDistance(entities[iSat]->getPosition(),
                                           entities[iCheck]->getPosition());
         // Find the min distance two entities can be
         double minDistance = entities[iSat]->getRadius() + entities[iCheck]->getRadius();

         // If they collide break the entities
         if (distance < minDistance)
         {
            entities[iSat]->impact(entities);
            entities[iCheck]->impact(entities);

            // remove entities from list
            delete entities[iSat];
            delete entities[iCheck];
            entities.erase(entities.begin() + iCheck);
            entities.erase(entities.begin() + iSat);
         }
      }
   }

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
