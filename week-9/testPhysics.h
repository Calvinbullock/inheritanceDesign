
/***********************************************************************
 * Header File:
 *    Test Position : Test the inline physics functions
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    Tests for the physics functions
 ************************************************************************/

#define GRAVITY_SEA_LEVEL 9.80665 // m/s2 acceleration towards the earth
#define RADIUS_EARTH 6378000.0 //m
#define EARTH_SURFACE 35786000.0 //m - Distance from earths surface
#define EARTH_CENTER 42164000.0 //m - Distance from earths center

#pragma once

#include "physics.cpp"
#include "unitTest.h"

/*******************************
 * TEST Position
 * A friend class for Position which contains the Position unit tests
 ********************************/
class TestPhysics : public UnitTest {
public:
   void run()
   {
      getGravity_Mid();
      getGravity_far();
      getGravity_close();

      report("Physics");
   }

private:
      /*********************************************
    * name:    GET GRAVITY FAR
    * input:   gravity = 9.80665,
    *          radius = 6378000,
    *          height = -50,000,000 (50,000 km below Earth)
    * output:  gh = 7.338344
    *********************************************/
   void getGravity_far()
   {
      // setup
      double height = -50000000;

      // exercise
      double gh = getGravity(GRAVITY_SEA_LEVEL, RADIUS_EARTH, height);

      // verify
      assertEquals(gh, 0.20964);
   } // tear down

      /*********************************************
    * name:    GET GRAVITY MID
    * input:   gravity = 9.80665,
    *          radius = 6378000,
    *          height = 25,000,000 (25,000 km above Earth)
    * output:  gh = 9.514236
    *********************************************/
   void getGravity_Mid()
   {
      // setup
      double height = 25000000;

      // exercise
      double gh = getGravity(GRAVITY_SEA_LEVEL, RADIUS_EARTH, height);

      // verify
      assertEquals(gh, 0.40517);
   } // tear down

      /*********************************************
    * name:    GET GRAVITY CLOSE
    * input:   gravity = 9.80665,
    *          radius = 6378000,
    *          height = 0 (at sea level)
    * output:  gh = 9.80665
    *********************************************/
   void getGravity_close()
   {
      // setup
      double height = 0;

      // exercise
      double gh = getGravity(GRAVITY_SEA_LEVEL, RADIUS_EARTH, height);

      // verify
      assertEquals(gh, 9.80665);
   } // tear down
};
