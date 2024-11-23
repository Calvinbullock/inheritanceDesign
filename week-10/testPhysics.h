
/***********************************************************************
 * Header File:
 *    Test Physics: Test the inline physics functions
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    Tests for the physics functions
 ************************************************************************/

#include <cmath>
#include <iostream>
#include <iterator>
#define _USE_MATH_DEFINES
#include <math.h>

#pragma once

#include "physics.cpp"
#include "unitTest.h"

#define GRAVITY_SEA_LEVEL 9.80665 // m/s2 acceleration towards the earth
#define RADIUS_EARTH 6378000.0 //m
#define EARTH_SURFACE 35786000.0 //m - Distance from earths surface
#define EARTH_CENTER 42164000.0 //m - Distance from earths center

/*******************************
 * TEST PHYSICS
 *    A class for physics which contains physics equations unit tests
 ********************************/
class TestPhysics : public UnitTest {
public:
   void run()
   {
      //getGravity_Mid();
      //getGravity_far();
      //getGravity_close();

      getDirectionGravity_top();
      //getDirectionGravity_right();
      //getDirectionGravity_topLeft();
      //getDirectionGravity_left();
      //getDirectionGravity_bottom();

      report("Physics");
   }

private:
   //   /*********************************************
   // * name:    GET GRAVITY FAR
   // * input:   gravity = 9.80665,
   // *          radius = 6378000,
   // *          height = -50,000,000 (50,000 km below Earth)
   // * output:  gh = 7.338344
   // *********************************************/
   //void getGravity_far()
   //{
   //   // setup
   //   double height = -50000000;

   //   // exercise
   //   double gh = getGravity(GRAVITY_SEA_LEVEL, RADIUS_EARTH, height);

   //   // verify
   //   assertEquals(gh, 0.20964);
   //} // tear down

   //   /*********************************************
   // * name:    GET GRAVITY MID
   // * input:   gravity = 9.80665,
   // *          radius = 6378000,
   // *          height = 25,000,000 (25,000 km above Earth)
   // * output:  gh = 9.514236
   // *********************************************/
   //void getGravity_Mid()
   //{
   //   // setup
   //   double height = 25000000;

   //   // exercise
   //   double gh = getGravity(GRAVITY_SEA_LEVEL, RADIUS_EARTH, height);

   //   // verify
   //   assertEquals(gh, 0.40517);
   //} // tear down

   //   /*********************************************
   // * name:    GET GRAVITY CLOSE
   // * input:   gravity = 9.80665,
   // *          radius = 6378000,
   // *          height = 0 (at sea level)
   // * output:  gh = 9.80665
   // *********************************************/
   //void getGravity_close()
   //{
   //   // setup
   //   double height = 0;

   //   // exercise
   //   double gh = getGravity(GRAVITY_SEA_LEVEL, RADIUS_EARTH, height);

   //   // verify
   //   assertEquals(gh, 9.80665);
   //} // tear down

   /*********************************************
    * name:    GET DIRECTION GRAVITY - TOP
    * input:   earthCenter = Position(0.0, 0.0),
    *          satPos = Position(0.0, 6378000.0)
    * output:  direction = 3.141593 (approx)
    *********************************************/
   void getDirectionGravity_top()
   {
      // setup
      Position earthCenter(0.0, 0.0);
      Position satPos(0.0, 6378000.0);

      // exercise
      double direction = getDirectionGravity(earthCenter, satPos);

      // verify
      assertEquals(direction, 0.0);
   } // tear down

   /*********************************************
    * name:    GET DIRECTION GRAVITY - TOP LEFT
    * input:   earthCenter = Position(0.0, 0.0),
    *          satPos = Position(-30000000.0, 30000000.0)
    * output:  direction = 2.35619 (approx)
    *********************************************/
   void getDirectionGravity_topLeft()
   {
      // setup
      Position earthCenter(0.0, 0.0);
      Position satPos(-30000000.0, 30000000.0);

      // exercise
      double direction = getDirectionGravity(earthCenter, satPos);

      // verify
      assertEquals(direction, 2.35619);
   }

   /*********************************************
    * name:    GET DIRECTION GRAVITY - RIGHT
    * input:   earthCenter = Position(0.0, 0.0),
    *          satPos = Position(42164000.0, 0.0)
    * output:  direction = -1.57079 (approx)
    *********************************************/
   void getDirectionGravity_right()
   {
      // setup
      Position earthCenter(0.0, 0.0);
      Position satPos(42164000.0, 0.0);

      // exercise
      double direction = getDirectionGravity(earthCenter, satPos);

      // verify
      assertEquals(direction, -1.57079);
   } // tear down

   /*********************************************
    * name:    GET DIRECTION GRAVITY - BOTTOM
    * input:   earthCenter = Position(0.0, 0.0),
    *          satPos = Position(0.0, -42164000.0)
    * output:  direction = 0.0 (approx)
    *********************************************/
   void getDirectionGravity_bottom()
   {
      // setup
      Position earthCenter(0.0, 0.0);
      Position satPos(0.0, -42164000.0);

      // exercise
      double direction = getDirectionGravity(earthCenter, satPos);

      // verify
      assertEquals(direction, 0.0);
   } // tear down

   /*********************************************
    * name:    GET DIRECTION GRAVITY - LEFT
    * input:   earthCenter = Position(0.0, 0.0),
    *          satPos = Position(-42164000.0, 0.0)
    * output:  direction = 1.57079 (approx)
    *********************************************/
   void getDirectionGravity_left()
   {
      // setup
      Position earthCenter(0.0, 0.0);
      Position satPos(-42164000.0, 0.0);

      // exercise
      double direction = getDirectionGravity(earthCenter, satPos);

      // verify
      assertEquals(direction, 1.57079);
   } // tear down

};
