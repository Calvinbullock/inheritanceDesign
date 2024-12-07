
/***********************************************************************
 * Header File:
 *    TEST Satellite
 * Author:
 *    Daniel Malasky, Calvin Bullock
 * Summary:
 *    All the unit tests for Satellite and its children
 ************************************************************************/

#pragma once


#include "satellite.h"
#include "satelliteDragon.h"
#include "satelliteGPS.h"
#include "unitTest.h"

/*******************************
* TEST Satellite
********************************/
class TestSatellite : public UnitTest
{
public:
   void run()
   {
      // Dragon
      dragonConstructor_default();

      // GPS
      GPSConstructor_default();

      
      report("Satellite");
   }

private:
   void dragonConstructor_default()
   {
      // setup

      // exercise
      SatelliteDragon s;

      // verify
      assertEquals(s.angle.radians, 0.0);
      assertEquals(s.position.x, 0.0);
      assertEquals(s.position.y, 0.0);
      assertEquals(s.velocity.dx, 0.0);
      assertEquals(s.velocity.dy, 0.0);
      assertEquals(s.radius, 280.0);    // default value: 7 * 40(meterFromPixels) = 280
      assertEquals(s.fragmentCount, 2); // default value: 5
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == false);

   } // teardown
   
   //
   // GPS
   //

   void GPSConstructor_default()
   {
      // setup

      // exercise
      SatelliteGPS s;

      // verify
      assertEquals(s.angle.radians, 0.0);
      assertEquals(s.position.x, 0.0);
      assertEquals(s.position.y, 0.0);
      assertEquals(s.velocity.dx, 0.0);
      assertEquals(s.velocity.dy, 0.0);
      assertEquals(s.radius, 480.0);    // default value: 12 * 40(meterFromPixels) = 480
      assertEquals(s.fragmentCount, 2); // default value: 5
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == false);

   } // teardown
   

};
