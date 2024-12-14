
/***********************************************************************
 * Header File:
 *    TEST Satellite
 * Author:
 *    Daniel Malasky, Calvin Bullock
 * Summary:
 *    All the unit tests for Satellite and its children
 ************************************************************************/

#pragma once


#include "position.h"
#include "satellite.h"
#include "satelliteDragon.h"
#include "satelliteGPS.h"
#include "satelliteHubble.h"
#include "satelliteSputnik.h"
#include "satelliteStarlink.h"
#include "unitTest.h"
#include <iostream>
#include <vector>

/*******************************
* TEST Satellite
********************************/
class TestSatellite : public UnitTest
{
public:
   void run()
   {
      /****************************************************
      // NOTE: randomness in Copy constructors not tested!
      *****************************************************/

      // Sputnik
      sputnikConstructor_default();
      sputnikConstructor_nonDefault();
      sputnikImpact();

      // Hubble
      hubbleConstructor_default();
      hubbleTelescopeConstructor_default();
      hubbleComputerConstructor_default();
      hubbleRightConstructor_default();
      hubbleLeftConstructor_default();
      hubbleConstructor_nonDefault();
      hubbleTelescopeConstructor_copy();
      hubbleComputerConstructor_copy();
      hubbleRightConstructor_copy();
      hubbleLeftConstructor_copy();

      hubbleImpact();
      hubbleTelescopeImpact();
      hubbleLeftImpact();
      hubbleRightImpact();
      hubbleComputerImpact();

      // GPS
      gpsConstructor_default();
      gpsConstructor_nonDefault();
      gpsRightConstructor_default();
      gpsLeftConstructor_default();
      gpsCenterConstructor_default();
      gpsRightConstructor_copy();
      gpsLeftConstructor_copy();
      gpsCenterConstructor_copy();
 
      gpsImpact();
      gpsLeftImpact();
      gpsRightImpact();
      gpsCenterImpact();


      // Starlink
      starlinkConstructor_default();
      starlinkBodyConstructor_default();
      starlinkArrayConstructor_default();
      starlinkConstructor_nonDefault();
      starlinkBodyConstructor_copy();
      starlinkArrayConstructor_copy();

      starlinkImpact();
      starlinkArrayImpact();
      starlinkBodyImpact();

      // Dragon
      dragonConstructor_default();
      dragonConstructor_nonDefault();
      dragonImpact();
      dragonLeftImpact();
      dragonRightImpact();
      dragonCenterImpact();
      dragonLeftConstructor_copy();
      dragonLeftConstructor_default();
      dragonRightConstructor_copy();
      dragonRightConstructor_default();
      dragonCenterConstructor_copy();
      dragonCenterConstructor_default();

      report("Satellite");
   }

private:

   /*********************************************
   * name:    HUBBLE Default Constructor
   * input:   none
   *********************************************/
   void hubbleConstructor_default()
   {
      // setup

      // exercise
      SatelliteHubble s;

      // verify
      assertEquals(s.angle.radians, 0.0);
      assertEquals(s.position.x, 0.0);
      assertEquals(s.position.y, 0.0);
      assertEquals(s.velocity.dx, 0.0);
      assertEquals(s.velocity.dy, 0.0);
      assertEquals(s.radius, 400.0);    // default value: 10 * 40(meterFromPixels) = 400
      assertEquals(s.fragmentCount, 4); // default value: 4
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == false);

   } // teardown

   /*********************************************
   * name:    HUBBLE Default Constructor
   * input:   none
   *********************************************/
   void hubbleTelescopeConstructor_default()
   {
      // setup

      // exercise
      SatelliteHubbleTelescope s;

      // verify
      assertEquals(s.angle.radians, 0.0);
      assertEquals(s.position.x, 0.0);
      assertEquals(s.position.y, 0.0);
      assertEquals(s.velocity.dx, 0.0);
      assertEquals(s.velocity.dy, 0.0);
      assertEquals(s.radius, 400.0);    // default value: 10 * 40(meterFromPixels) = 400
      assertEquals(s.fragmentCount, 3); // default value: 3
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == false);

   } // teardown

   /*********************************************
   * name:    HUBBLE Default Constructor
   * input:   none
   *********************************************/
   void hubbleComputerConstructor_default()
   {
      // setup

      // exercise
      SatelliteHubbleComputer s;

      // verify
      assertEquals(s.angle.radians, 0.0);
      assertEquals(s.position.x, 0.0);
      assertEquals(s.position.y, 0.0);
      assertEquals(s.velocity.dx, 0.0);
      assertEquals(s.velocity.dy, 0.0);
      assertEquals(s.radius, 280.0);    // default value: 7 * 40(meterFromPixels) = 280
      assertEquals(s.fragmentCount, 2); // default value: 2
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == false);

   } // teardown

   /*********************************************
   * name:    HUBBLE Default Constructor
   * input:   none
   *********************************************/
   void hubbleRightConstructor_default()
   {
      // setup

      // exercise
      SatelliteHubbleLeft s;

      // verify
      assertEquals(s.angle.radians, 0.0);
      assertEquals(s.position.x, 0.0);
      assertEquals(s.position.y, 0.0);
      assertEquals(s.velocity.dx, 0.0);
      assertEquals(s.velocity.dy, 0.0);
      assertEquals(s.radius, 320.0);    // default value: 8 * 40(meterFromPixels) = 320
      assertEquals(s.fragmentCount, 2); // default value: 2
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == false);

   } // teardown

   /*********************************************
   * name:    HUBBLE Default Constructor
   * input:   none
   *********************************************/
   void hubbleLeftConstructor_default()
   {
      // setup

      // exercise
      SatelliteHubbleRight s;

      // verify
      assertEquals(s.angle.radians, 0.0);
      assertEquals(s.position.x, 0.0);
      assertEquals(s.position.y, 0.0);
      assertEquals(s.velocity.dx, 0.0);
      assertEquals(s.velocity.dy, 0.0);
      assertEquals(s.radius, 320.0);    // default value: 8 * 40(meterFromPixels) = 320
      assertEquals(s.fragmentCount, 2); // default value: 2
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == false);

   } // teardown

   /*********************************************
   * name:    HUBBLE NON Default Constructor
   * input:   pos(4000,4500), vel(3500), ang(3.1415)
   *********************************************/
   void hubbleConstructor_nonDefault()
   {
      // setup
      Position p;
      p.x = 4000.0;
      p.y = 4500.0;
      Velocity v;
      v.dx = 3000.0;
      v.dy = 3500.0;
      Angle a;
      a.radians = 3.1415;

      // exercise
      SatelliteHubble s(p, v, a, 4000);

      // verify
      assertEquals(s.angle.radians, 3.1415);
      assertEquals(s.position.x, 4000.0);
      assertEquals(s.position.y, 4500.0);
      assertEquals(s.velocity.dx, 3000.0);
      assertEquals(s.velocity.dy, 3500.0);
      assertEquals(s.chanceDefunct, 4000);
      assertEquals(s.radius, 400.0);    // default value: 10 * 40(meterFromPixels) = 400
      assertEquals(s.fragmentCount, 4); // default value: 4
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == false);

   } // teardown

   /*********************************************
   * name:    HUBBLE TELESCOPE COPY Constructor
   * input:   pos(4000,4500), vel(3500), ang(3.1415)
   *********************************************/
   void hubbleTelescopeConstructor_copy()
   {
      // setup
      SatelliteHubble sh;
      sh.position.x = 4000.0;
      sh.position.y = 4500.0;
      sh.velocity.dx = 3000.0;
      sh.velocity.dy = 3500.0;
      sh.angle.radians = 3.1415;

      // exercise
      SatelliteHubbleTelescope s(sh);

      // verify
      assertEquals(s.angle.radians, 3.1415);
      //assertEquals(s.position.x, 4000.0);
      //assertEquals(s.position.y, 4500.0);
      //assertEquals(s.velocity.dx, 3000.0);
      //assertEquals(s.velocity.dy, 3500.0);
      assertEquals(s.radius, 400.0);    // default value: 10 * 40(meterFromPixels) = 400
      assertEquals(s.fragmentCount, 3); // default value:
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == false);

   } // teardown

   /*********************************************
   * name:    HUBBLE COMPUTER COPY Constructor
   * input:   pos(4000,4500), vel(3500), ang(3.1415)
   *********************************************/
   void hubbleComputerConstructor_copy()
   {
      // setup
      SatelliteHubble sh;
      sh.position.x = 4000.0;
      sh.position.y = 4500.0;
      sh.velocity.dx = 3000.0;
      sh.velocity.dy = 3500.0;
      sh.angle.radians = 3.1415;

      // exercise
      SatelliteHubbleComputer s(sh);

      // verify
      assertEquals(s.angle.radians, 3.1415);
      //assertEquals(s.position.x, 4000.0);
      //assertEquals(s.position.y, 4500.0);
      //assertEquals(s.velocity.dx, 3000.0);
      //assertEquals(s.velocity.dy, 3500.0);
      assertEquals(s.radius, 280.0);    // default value: 7 * 40(meterFromPixels) = 280
      assertEquals(s.fragmentCount, 2); // default value:
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == false);

   } // teardown

   /*********************************************
   * name:    HUBBLE RIGHT COPY Constructor
   * input:   pos(4000,4500), vel(3500), ang(3.1415)
   *********************************************/
   void hubbleRightConstructor_copy()
   {
      // setup
      SatelliteHubble sh;
      sh.position.x = 4000.0;
      sh.position.y = 4500.0;
      sh.velocity.dx = 3000.0;
      sh.velocity.dy = 3500.0;
      sh.angle.radians = 3.1415;

      // exercise
      SatelliteHubbleRight s(sh);

      // verify
      assertEquals(s.angle.radians, 3.1415);
      //assertEquals(s.position.x, 4000.0);
      //assertEquals(s.position.y, 4500.0);
      //assertEquals(s.velocity.dx, 3000.0);
      //assertEquals(s.velocity.dy, 3500.0);
      assertEquals(s.radius, 320);    // default value: 8 * 40(meterFromPixels) = 320
      assertEquals(s.fragmentCount, 2); // default value:
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == false);

   } // teardown

   /*********************************************
   * name:    HUBBLE LEFT COPY Constructor
   * input:   pos(4000,4500), vel(3500), ang(3.1415)
   *********************************************/
   void hubbleLeftConstructor_copy()
   {
      // setup
      SatelliteHubble sh;
      sh.position.x = 4000.0;
      sh.position.y = 4500.0;
      sh.velocity.dx = 3000.0;
      sh.velocity.dy = 3500.0;
      sh.angle.radians = 3.1415;

      // exercise
      SatelliteHubbleLeft s(sh);

      // verify
      assertEquals(s.angle.radians, 3.1415);
      //assertEquals(s.position.x, 4000.0);
      //assertEquals(s.position.y, 4500.0);
      //assertEquals(s.velocity.dx, 3000.0);
      //assertEquals(s.velocity.dy, 3500.0);
      assertEquals(s.radius, 320.0);    // default value: 8 * 40(meterFromPixels) = 320
      assertEquals(s.fragmentCount, 2); // default value: 2
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == false);

   } // teardown

   /*********************************************
    * name:  HUBBLE IMPACT
    * output: isBroken == True
              entities.size == 4
              entities has =
              [
                  SatelliteHubbleLeft, SatelliteHubbleRight,
                  SatelliteHubbleTelescope, SatelliteHubbleComputer
             ]
    *********************************************/
   void hubbleImpact()
   {
      // Setup
      std::vector<Entity*> entities;
      SatelliteHubble sat = SatelliteHubble();
      sat.isBroken = false;
      sat.fragmentCount = 4;

      // Exercise
      sat.impact(entities);

      // Verify
      assertUnit(sat.isBroken == true);
      assertUnit(entities.size() == 4);

      // TODO: how to type check??
      //std::cout << typeid(*entities[0]).name() << ", " << typeid(SatelliteHubbleLeft()).name() << std::endl;
      //assertUnit(typeid(*entities[0]) == typeid(SatelliteHubbleLeft()));
      //assertUnit(typeid(*entities[1]) == typeid(SatelliteHubbleRight()));
      //assertUnit(typeid(*entities[2]) == typeid(SatelliteHubbleTelescope()));
      //assertUnit(typeid(*entities[3]) == typeid(SatelliteHubbleComputer()));

      // teardown
      for (int i = 0; i < entities.size(); i++)
      {
         delete entities[i];
         entities[i] = nullptr;
      }
   }

   /*********************************************
    * name:  HUBBLE TELESCOPE IMPACT
    * output: isBroken == True
              entities.size == 3
              entities has: [ Fragment, Fragment ]
    *********************************************/
   void hubbleTelescopeImpact()
   {
      // Setup
      std::vector<Entity*> entities;
      SatelliteHubbleTelescope sat = SatelliteHubbleTelescope();
      sat.isBroken = false;
      sat.fragmentCount = 3;

      // Exercise
      sat.impact(entities);

      // Verify
      assertUnit(sat.isBroken == true);
      assertUnit(entities.size() == 3);

      // TODO: how to type check??
      //std::cout << typeid(*entities[0]).name() << ", " << typeid(SatelliteHubbleLeft()).name() << std::endl;
      //assertUnit(typeid(*entities[0]) == typeid(SatelliteHubbleLeft()));
      //assertUnit(typeid(*entities[1]) == typeid(SatelliteHubbleRight()));
      //assertUnit(typeid(*entities[2]) == typeid(SatelliteHubbleTelescope()));
      //assertUnit(typeid(*entities[3]) == typeid(SatelliteHubbleComputer()));

      // teardown
      for (int i = 0; i < entities.size(); i++)
      {
         delete entities[i];
         entities[i] = nullptr;
      }
   }

   /*********************************************
    * name:  HUBBLE LEFT IMPACT
    * output: isBroken == True
              entities.size == 3
              entities has: [ Fragment, Fragment, Fragment ]
    *********************************************/
   void hubbleLeftImpact()
   {
      // Setup
      std::vector<Entity*> entities;
      SatelliteHubbleLeft sat = SatelliteHubbleLeft();
      sat.isBroken = false;
      sat.fragmentCount = 3;

      // Exercise
      sat.impact(entities);

      // Verify
      assertUnit(sat.isBroken == true);
      assertUnit(entities.size() == 3);

      // TODO: how to type check??
      //std::cout << typeid(*entities[0]).name() << ", " << typeid(SatelliteHubbleLeft()).name() << std::endl;
      //assertUnit(typeid(*entities[0]) == typeid(SatelliteHubbleLeft()));
      //assertUnit(typeid(*entities[1]) == typeid(SatelliteHubbleRight()));
      //assertUnit(typeid(*entities[2]) == typeid(SatelliteHubbleTelescope()));
      //assertUnit(typeid(*entities[3]) == typeid(SatelliteHubbleComputer()));

      // teardown
      for (int i = 0; i < entities.size(); i++)
      {
         delete entities[i];
         entities[i] = nullptr;
      }
   }

   /*********************************************
    * name:  HUBBLE RIGHT IMPACT
    * output: isBroken == True
              entities.size == 2
              entities has: [ Fragment, Fragment ]
    *********************************************/
   void hubbleRightImpact()
   {
      // Setup
      std::vector<Entity*> entities;
      SatelliteHubbleRight sat = SatelliteHubbleRight();
      sat.isBroken = false;
      sat.fragmentCount = 2;

      // Exercise
      sat.impact(entities);

      // Verify
      assertUnit(sat.isBroken == true);
      assertUnit(entities.size() == 2);

      // TODO: how to type check??
      //std::cout << typeid(*entities[0]).name() << ", " << typeid(SatelliteHubbleLeft()).name() << std::endl;
      //assertUnit(typeid(*entities[0]) == typeid(SatelliteHubbleLeft()));
      //assertUnit(typeid(*entities[1]) == typeid(SatelliteHubbleRight()));
      //assertUnit(typeid(*entities[2]) == typeid(SatelliteHubbleTelescope()));
      //assertUnit(typeid(*entities[3]) == typeid(SatelliteHubbleComputer()));

      // teardown
      for (int i = 0; i < entities.size(); i++)
      {
         delete entities[i];
         entities[i] = nullptr;
      }
   }

   /*********************************************
    * name:  HUBBLE COMPUTER IMPACT
    * output: isBroken == True
              entities.size == 2
              entities has: [ Fragment, Fragment ]
    *********************************************/
   void hubbleComputerImpact()
   {
      // Setup
      std::vector<Entity*> entities;
      SatelliteHubbleComputer sat = SatelliteHubbleComputer();
      sat.isBroken = false;
      sat.fragmentCount = 2;

      // Exercise
      sat.impact(entities);

      // Verify
      assertUnit(sat.isBroken == true);
      assertUnit(entities.size() == 2);

      // TODO: how to type check??
      //std::cout << typeid(*entities[0]).name() << ", " << typeid(SatelliteHubbleLeft()).name() << std::endl;
      //assertUnit(typeid(*entities[0]) == typeid(SatelliteHubbleLeft()));
      //assertUnit(typeid(*entities[1]) == typeid(SatelliteHubbleRight()));
      //assertUnit(typeid(*entities[2]) == typeid(SatelliteHubbleTelescope()));
      //assertUnit(typeid(*entities[3]) == typeid(SatelliteHubbleComputer()));

      // teardown
      for (int i = 0; i < entities.size(); i++)
      {
         delete entities[i];
         entities[i] = nullptr;
      }
   }

   //
   // GPS
   //

   /*********************************************
   * name:    GPS Default Constructor
   * input:   none
   *********************************************/
   void gpsConstructor_default()
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

   /*********************************************
   * name:    GPS Default Constructor
   * input:   none
   *********************************************/
   void gpsRightConstructor_default()
   {
      // setup

      // exercise
      GPSRight s;

      // verify
      assertEquals(s.angle.radians, 0.0);
      assertEquals(s.position.x, 0.0);
      assertEquals(s.position.y, 0.0);
      assertEquals(s.velocity.dx, 0.0);
      assertEquals(s.velocity.dy, 0.0);
      assertEquals(s.radius, 320.0);    // default value: 8 * 40(meterFromPixels) = 320
      assertEquals(s.fragmentCount, 3); // default value: 3
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == false);

   } // teardown

   /*********************************************
   * name:    GPS Default Constructor
   * input:   none
   *********************************************/
   void gpsLeftConstructor_default()
   {
      // setup

      // exercise
      GPSLeft s;

      // verify
      assertEquals(s.angle.radians, 0.0);
      assertEquals(s.position.x, 0.0);
      assertEquals(s.position.y, 0.0);
      assertEquals(s.velocity.dx, 0.0);
      assertEquals(s.velocity.dy, 0.0);
      assertEquals(s.radius, 320.0);    // default value: 8 * 40(meterFromPixels) = 320
      assertEquals(s.fragmentCount, 3); // default value: 3
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == false);

   } // teardown

   /*********************************************
   * name:    GPS Default Constructor
   * input:   none
   *********************************************/
   void gpsCenterConstructor_default()
   {
      // setup

      // exercise
      GPSCenter s;

      // verify
      assertEquals(s.angle.radians, 0.0);
      assertEquals(s.position.x, 0.0);
      assertEquals(s.position.y, 0.0);
      assertEquals(s.velocity.dx, 0.0);
      assertEquals(s.velocity.dy, 0.0);
      assertEquals(s.radius, 280.0);    // default value: 7 * 40(meterFromPixels) = 280
      assertEquals(s.fragmentCount, 3); // default value: 3
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == false);

   } // teardown

   /*********************************************
   * name:    GPS NON Default Constructor
   * input:   pos(4000,4500), vel(3500), ang(3.1415)
   *********************************************/
   void gpsConstructor_nonDefault()
   {
      // setup
      Position p;
      p.x = 4000.0;
      p.y = 4500.0;
      Velocity v;
      v.dx = 3000.0;
      v.dy = 3500.0;
      Angle a;
      a.radians = 3.1415;

      // exercise
      SatelliteGPS s(p, v, a, 4000);

      // verify
      assertEquals(s.angle.radians, 3.1415);
      assertEquals(s.position.x, 4000.0);
      assertEquals(s.position.y, 4500.0);
      assertEquals(s.velocity.dx, 3000.0);
      assertEquals(s.velocity.dy, 3500.0);
      assertEquals(s.chanceDefunct, 4000);
      assertEquals(s.radius, 480.0);    // default value: 12 * 40(meterFromPixels) = 480
      assertEquals(s.fragmentCount, 2); // default value: 2
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == false);

   } // teardown

   /*********************************************
   * name:    GPS RIGHT COPY CONSTRUCTOR
   * input:   pos(4000,4500), vel(3500), ang(3.1415)
   *********************************************/
   void gpsRightConstructor_copy()
   {
      // setup
      SatelliteGPS sg;
      sg.position.x = 4000.0;
      sg.position.y = 4500.0;
      sg.velocity.dx = 3000.0;
      sg.velocity.dy = 3500.0;
      sg.angle.radians = 3.1415;

      // exercise
      GPSRight s(sg);

      // verify
      assertEquals(s.angle.radians, 3.1415);
      //assertEquals(s.position.x, 4000.0);
      //assertEquals(s.position.y, 4500.0);
      //assertEquals(s.velocity.dx, 3000.0);
      //assertEquals(s.velocity.dy, 3500.0);
      assertEquals(s.radius, 320.0);    // default value: 8 * 40(meterFromPixels) = 320
      assertEquals(s.fragmentCount, 3); // default value: 
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == false);

   } // teardown

   /*********************************************
   * name:    GPS LEFT COPY CONSTRUCTOR
   * input:   pos(4000,4500), vel(3500), ang(3.1415)
   *********************************************/
   void gpsLeftConstructor_copy()
   {
      // setup
      SatelliteGPS sg;
      sg.position.x = 4000.0;
      sg.position.y = 4500.0;
      sg.velocity.dx = 3000.0;
      sg.velocity.dy = 3500.0;
      sg.angle.radians = 3.1415;

      // exercise
      GPSLeft s(sg);

      // verify
      assertEquals(s.angle.radians, 3.1415);
      //assertEquals(s.position.x, 4000.0);
      //assertEquals(s.position.y, 4500.0);
      //assertEquals(s.velocity.dx, 3000.0);
      //assertEquals(s.velocity.dy, 3500.0);
      assertEquals(s.radius, 320.0);    // default value: 10 * 40(meterFromPixels) = 320
      assertEquals(s.fragmentCount, 3); // default value: 
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == false);

   } // teardown

   /*********************************************
   * name:    GPS CENTER COPY CONSTRUCTOR
   * input:   pos(4000,4500), vel(3500), ang(3.1415)
   *********************************************/
   void gpsCenterConstructor_copy()
   {
      // setup
      SatelliteGPS sg;
      sg.position.x = 4000.0;
      sg.position.y = 4500.0;
      sg.velocity.dx = 3000.0;
      sg.velocity.dy = 3500.0;
      sg.angle.radians = 3.1415;

      // exercise
      GPSCenter s(sg);

      // verify
      assertEquals(s.angle.radians, 3.1415);
      //assertEquals(s.position.x, 4000.0);
      //assertEquals(s.position.y, 4500.0);
      //assertEquals(s.velocity.dx, 3000.0);
      //assertEquals(s.velocity.dy, 3500.0);
      assertEquals(s.radius, 280.0);    // default value: 7 * 40(meterFromPixels) = 280
      assertEquals(s.fragmentCount, 3); // default value: 
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == false);

   } // teardown

   /*********************************************
    * name:  GPS IMPACT
    * output: isBroken == True
              entities.size == 3
              entities has = [ gpsCenter, gpsLeft, gpsRight ]
    *********************************************/
   void gpsImpact()
   {
      // Setup
      std::vector<Entity*> entities;
      SatelliteGPS sat = SatelliteGPS();
      sat.isBroken = false;

      // Exercise
      sat.impact(entities);

      // Verify
      assertUnit(sat.isBroken == true);
      assertUnit(entities.size() == 5);

      // TODO: how to type check??

      // teardown
      for (int i = 0; i < entities.size(); i++)
      {
         delete entities[i];
         entities[i] = nullptr;
      }
   }

   /*********************************************
    * name:  GPS RIGHT IMPACT
    * input: isBroken = false, fragmentCount = 3;
    * output: isBroken == True
              entities.size == 3
              entities has: [ Fragment, Fragment, Fragment]
    *********************************************/
   void gpsRightImpact()
   {
      // Setup
      std::vector<Entity*> entities;
      GPSRight sat = GPSRight();
      sat.isBroken = false;
      sat.fragmentCount = 3;

      // Exercise
      sat.impact(entities);

      // Verify
      assertUnit(sat.isBroken == true);
      assertUnit(entities.size() == 3);

      // TODO: how to type check??

      // teardown
      for (int i = 0; i < entities.size(); i++)
      {
         delete entities[i];
         entities[i] = nullptr;
      }
   }

   /*********************************************
    * name:  GPS LEFT IMPACT
    * input: isBroken = false, fragmentCount = 3;
    * output: isBroken == True
              entities.size == 3
              entities has: [ Fragment, Fragment, Fragment]
    *********************************************/
   void gpsLeftImpact()
   {
      // Setup
      std::vector<Entity*> entities;
      GPSLeft sat = GPSLeft();
      sat.isBroken = false;
      sat.fragmentCount = 3;

      // Exercise
      sat.impact(entities);

      // Verify
      assertUnit(sat.isBroken == true);
      assertUnit(entities.size() == 3);

      // TODO: how to type check??

      // teardown
      for (int i = 0; i < entities.size(); i++)
      {
         delete entities[i];
         entities[i] = nullptr;
      }
   }

   /*********************************************
    * name:  GPS CENTER IMPACT
    * input: isBroken = false, fragmentCount = 3;
    * output: isBroken == True
              entities.size == 3
              entities has: [ Fragment, Fragment, Fragment]
    *********************************************/
   void gpsCenterImpact()
   {
      // Setup
      std::vector<Entity*> entities;
      GPSCenter sat = GPSCenter();
      sat.isBroken = false;
      sat.fragmentCount = 3;

      // Exercise
      sat.impact(entities);

      // Verify
      assertUnit(sat.isBroken == true);
      assertUnit(entities.size() == 3);

      // TODO: how to type check??

      // teardown
      for (int i = 0; i < entities.size(); i++)
      {
         delete entities[i];
         entities[i] = nullptr;
      }
   }

   /*********************************************
   * name:    STARLINK Default Constructor
   * input:   none
   *********************************************/
   void starlinkConstructor_default()
   {
      // setup

      // exercise
      SatelliteStarlink s;

      // verify
      assertEquals(s.angle.radians, 0.0);
      assertEquals(s.position.x, 0.0);
      assertEquals(s.position.y, 0.0);
      assertEquals(s.velocity.dx, 0.0);
      assertEquals(s.velocity.dy, 0.0);
      assertEquals(s.radius, 240.0);    // default value: 6 * 40(meterFromPixels) = 240
      assertEquals(s.fragmentCount, 2); // default value: 2
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == false);

   } // teardown

    /*********************************************
   * name:    STARLINK BODY Default Constructor
   * input:   none
   *********************************************/
   void starlinkBodyConstructor_default()
   {
      // setup
      Position pos;

      // exercise
      SatelliteStarlinkBody s;

      // verify
      assertEquals(s.angle.radians, 0.0);
      assertEquals(s.position.x, 0.0);
      assertEquals(s.position.y, 0.0);
      assertEquals(s.velocity.dx, 0.0);
      assertEquals(s.velocity.dy, 0.0);
      assertEquals(s.radius, 80.0);    // default value: 2 * 40(meterFromPixels) = 80
      assertEquals(s.fragmentCount, 3); // default value: 3
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == false);

   } // teardown

    /*********************************************
   * name:    STARLINK BODY Default Constructor
   * input:   none
   *********************************************/
   void starlinkArrayConstructor_default()
   {
      // setup
      Position pos;

      // exercise
      SatelliteStarlinkArray s;

      // verify
      assertEquals(s.angle.radians, 0.0);
      assertEquals(s.position.x, 0.0);
      assertEquals(s.position.y, 0.0);
      assertEquals(s.velocity.dx, 0.0);
      assertEquals(s.velocity.dy, 0.0);
      assertEquals(s.radius, 160.0);    // default value: 4 * 40(meterFromPixels) = 160
      assertEquals(s.fragmentCount, 3); // default value: 2
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == false);

   } // teardown



   /*********************************************
   * name:    GPS NON Default Constructor
   * input:   pos(4000,4500), vel(3500), ang(3.1415)
   *********************************************/
   void starlinkConstructor_nonDefault()
   {
      // setup
      Position p;
      p.x = 4000.0;
      p.y = 4500.0;
      Velocity v;
      v.dx = 3000.0;
      v.dy = 3500.0;
      Angle a;
      a.radians = 3.1415;

      // exercise
      SatelliteStarlink s(p, v, a, 4000);

      // verify
      assertEquals(s.angle.radians, 3.1415);
      assertEquals(s.position.x, 4000.0);
      assertEquals(s.position.y, 4500.0);
      assertEquals(s.velocity.dx, 3000.0);
      assertEquals(s.velocity.dy, 3500.0);
      assertEquals(s.chanceDefunct, 4000);
      assertEquals(s.radius, 240.0);    // default value: 6 * 40(meterFromPixels) = 240
      assertEquals(s.fragmentCount, 2); // default value: 2
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == false);

   } // teardown

   /*********************************************
   * name:    STARLINK BODY COPY CONSTRUCTOR
   * input:   pos(4000,4500), vel(3500), ang(3.1415)
   *********************************************/
   void starlinkBodyConstructor_copy()
   {
      // setup
      SatelliteStarlink ss;
      ss.position.x = 4000.0;
      ss.position.y = 4500.0;
      ss.velocity.dx = 3000.0;
      ss.velocity.dy = 3500.0;
      ss.angle.radians = 3.1415;

      // exercise
      SatelliteStarlinkBody s(ss);

      // verify
      assertEquals(s.angle.radians, 3.1415);
      //assertEquals(s.position.x, 4000.0);
      //assertEquals(s.position.y, 4500.0);
      //assertEquals(s.velocity.dx, 3000.0);
      //assertEquals(s.velocity.dy, 3500.0);
      assertEquals(s.radius, 80.0);    // default value: 2 * 40(meterFromPixels) = 80
      assertEquals(s.fragmentCount, 3); // default value: 3
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == false);

   } // teardown


   /*********************************************
   * name:    STARLINK ARRAY COPY CONSTRUCTOR
   * input:   pos(4000,4500), vel(3500), ang(3.1415)
   *********************************************/
   void starlinkArrayConstructor_copy()
   {
      // setup
      SatelliteStarlink ss;
      ss.position.x = 4000.0;
      ss.position.y = 4500.0;
      ss.velocity.dx = 3000.0;
      ss.velocity.dy = 3500.0;
      ss.angle.radians = 3.1415;

      // exercise
      SatelliteStarlinkArray s(ss);

      // verify
      assertEquals(s.angle.radians, 3.1415);
      //assertEquals(s.position.x, 4000.0);
      //assertEquals(s.position.y, 4500.0);
      //assertEquals(s.velocity.dx, 3000.0);
      //assertEquals(s.velocity.dy, 3500.0);
      assertEquals(s.radius, 160.0);    // default value: 4 * 40(meterFromPixels) = 160
      assertEquals(s.fragmentCount, 3); // default value: 2
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == false);

   } // teardown

   /*********************************************
    * name:  STARLINK IMPACT
    * input: isBroken = false, fragmentCount = 0;
    * output: isBroken == True
              entities.size == 3
              entities has: [ SatelliteStarlinkBody, SatelliteStarlinkArray ]
    *********************************************/
   void starlinkImpact()
   {
      // Setup
      std::vector<Entity*> entities;
      SatelliteStarlink sat = SatelliteStarlink();
      sat.isBroken = false;

      // Exercise
      sat.impact(entities);

      // Verify
      assertUnit(sat.isBroken == true);
      assertUnit(entities.size() == 4);

      // TODO: how to type check??

      // teardown
      for (int i = 0; i < entities.size(); i++)
      {
         delete entities[i];
         entities[i] = nullptr;
      }
   }

   /*********************************************
    * name:  STARLINK ARRAY IMPACT
    * input: isBroken = false, fragmentCount = 3;
    * output: isBroken == True
              entities.size == 3
              entities has: [ Fragment, Fragment, Fragment]
    *********************************************/
   void starlinkArrayImpact()
   {
      // Setup
      std::vector<Entity*> entities;
      SatelliteStarlinkArray sat = SatelliteStarlinkArray();
      sat.isBroken = false;
      sat.fragmentCount = 3;

      // Exercise
      sat.impact(entities);

      // Verify
      assertUnit(sat.isBroken == true);
      assertUnit(entities.size() == 3);

      // TODO: how to type check??

      // teardown
      for (int i = 0; i < entities.size(); i++)
      {
         delete entities[i];
         entities[i] = nullptr;
      }
   }

   /*********************************************
    * name:  STARLINK BODY IMPACT
    * input: isBroken = false, fragmentCount = 3;
    * output: isBroken == True
              entities.size == 3
              entities has: [ Fragment, Fragment, Fragment]
    *********************************************/
   void starlinkBodyImpact()
   {
      // Setup
      std::vector<Entity*> entities;
      SatelliteStarlinkBody sat = SatelliteStarlinkBody();
      sat.isBroken = false;
      sat.fragmentCount = 3;

      // Exercise
      sat.impact(entities);

      // Verify
      assertUnit(sat.isBroken == true);
      assertUnit(entities.size() == 3);

      // TODO: how to type check??

      // teardown
      for (int i = 0; i < entities.size(); i++)
      {
         delete entities[i];
         entities[i] = nullptr;
      }
   }

   /*********************************************
   * name:    Sputnik Default Constructor
   * input:   none
   *********************************************/
   void sputnikConstructor_default()
   {
      // setup

      // exercise
      SatelliteSputnik s;

      // verify
      assertEquals(s.angle.radians, 0.0);
      assertEquals(s.position.x, 0.0);
      assertEquals(s.position.y, 0.0);
      assertEquals(s.velocity.dx, 0.0);
      assertEquals(s.velocity.dy, 0.0);
      assertEquals(s.radius, 160.0);    // default value: 4 * 40(meterFromPixels) = 480
      assertEquals(s.fragmentCount, 4); // default value: 4
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == false);

   } // teardown

   /*********************************************
   * name:    SPUTNIK NON Default Constructor
   * input:   pos(4000,4500), vel(3500), ang(3.1415)
   *********************************************/
   void sputnikConstructor_nonDefault()
   {
      // setup
      Position p;
      p.x = 4000.0;
      p.y = 4500.0;
      Velocity v;
      v.dx = 3000.0;
      v.dy = 3500.0;
      Angle a;
      a.radians = 3.1415;

      // exercise
      SatelliteSputnik s(p, v, a, 4000);

      // verify
      assertEquals(s.angle.radians, 3.1415);
      assertEquals(s.position.x, 4000.0);
      assertEquals(s.position.y, 4500.0);
      assertEquals(s.velocity.dx, 3000.0);
      assertEquals(s.velocity.dy, 3500.0);
      assertEquals(s.chanceDefunct, 4000);
      assertEquals(s.radius, 160.0);    // default value: 4 * 40(meterFromPixels) = 160
      assertEquals(s.fragmentCount, 4); // default value: 4
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == false);

   } // teardown

   /*********************************************
    * name:  SPUTNIK IMPACT
    * input: isBroken = false, fragmentCount = 4;
    * output: isBroken == True
              entities.size == 4
              entities has: [ Fragment, Fragment, Fragment, Fragment ]
    *********************************************/
   void sputnikImpact()
   {
      // Setup
      std::vector<Entity*> entities;
      SatelliteSputnik sat = SatelliteSputnik();
      sat.isBroken = false;
      sat.fragmentCount = 4;

      // Exercise
      sat.impact(entities);

      // Verify
      assertUnit(sat.isBroken == true);
      assertUnit(entities.size() == 4);

      // TODO: how to type check??

      // teardown
      for (int i = 0; i < entities.size(); i++)
      {
         delete entities[i];
         entities[i] = nullptr;
      }
   }

  //
  // DRAGON
  //

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

   /*********************************************
   * name:    DRAGON NON Default Constructor
   * input:   pos(4000,4500), vel(3500), ang(3.1415)
   *********************************************/
   void dragonConstructor_nonDefault()
   {
      // setup
      Position p;
      p.x = 4000.0;
      p.y = 4500.0;
      Velocity v;
      v.dx = 3000.0;
      v.dy = 3500.0;
      Angle a;
      a.radians = 3.1415;

      // exercise
      SatelliteDragon s(p, v, a, 4000);

      // verify
      assertEquals(s.angle.radians, 3.1415);
      assertEquals(s.position.x, 4000.0);
      assertEquals(s.position.y, 4500.0);
      assertEquals(s.velocity.dx, 3000.0);
      assertEquals(s.velocity.dy, 3500.0);
      assertEquals(s.chanceDefunct, 4000);
      assertEquals(s.radius, 280.0);    // default value: 7 * 40(meterFromPixels) = 280
      assertEquals(s.fragmentCount, 2); // default value: 2
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == false);

   } // teardown

   /*********************************************
    * name:  DRAGON IMPACT
    * input: isBroken = false, fragmentCount = 0;
    * output: isBroken == True
              entities.size == 3
              entities has: [ DragonCenter, DragonLeft, DragonRight ]
    *********************************************/
   void dragonImpact()
   {
      // Setup
      std::vector<Entity*> entities;
      SatelliteDragon sat = SatelliteDragon();
      sat.isBroken = false;

      // Exercise
      sat.impact(entities);

      // Verify
      assertUnit(sat.isBroken == true);
      assertUnit(entities.size() == 5);

      // TODO: how to type check??

      // teardown
      for (int i = 0; i < entities.size(); i++)
      {
         delete entities[i];
         entities[i] = nullptr;
      }
   }

   /*********************************************
    * name:  DRAGON LEFT IMPACT
    * input: isBroken = false, fragmentCount = 2
    * output: isBroken == True
              entities.size == 2
              entities has: [ fragment, fragment, fragment ]
    *********************************************/
   void dragonLeftImpact()
   {
      // Setup
      std::vector<Entity*> entities;
      DragonLeft sat = DragonLeft();
      sat.isBroken = false;
      sat.fragmentCount = 2;

      // Exercise
      sat.impact(entities);

      // Verify
      assertUnit(sat.isBroken == true);
      assertUnit(entities.size() == 2);

      // TODO: how to type check??

      // teardown
      for (int i = 0; i < entities.size(); i++)
      {
         delete entities[i];
         entities[i] = nullptr;
      }
   }

   /*********************************************
    * name:  DRAGON RIGHT IMPACT
    * input: isBroken = false, fragmentCount = 2
    * output: isBroken == True
              entities.size == 2
              entities has: [ fragment, fragment, fragment ]
    *********************************************/
   void dragonRightImpact()
   {
      // Setup
      std::vector<Entity*> entities;
      DragonRight sat = DragonRight();
      sat.isBroken = false;
      sat.fragmentCount = 2;

      // Exercise
      sat.impact(entities);

      // Verify
      assertUnit(sat.isBroken == true);
      assertUnit(entities.size() == 2);

      // TODO: how to type check??

      // teardown
      for (int i = 0; i < entities.size(); i++)
      {
         delete entities[i];
         entities[i] = nullptr;
      }
   }

   /*********************************************
    * name:  DRAGON CENTER IMPACT
    * input: isBroken = false, fragmentCount = 4
    * output: isBroken == True
              entities.size == 4
              entities has: [ fragment, fragment, fragment ]
    *********************************************/
   void dragonCenterImpact()
   {
      // Setup
      std::vector<Entity*> entities;
      DragonCenter sat = DragonCenter();
      sat.isBroken = false;
      sat.fragmentCount = 4;

      // Exercise
      sat.impact(entities);

      // Verify
      assertUnit(sat.isBroken == true);
      assertUnit(entities.size() == 4);

      // TODO: how to type check??

      // teardown
      for (int i = 0; i < entities.size(); i++)
      {
         delete entities[i];
         entities[i] = nullptr;
      }
   }

   /*********************************************
   * name:    DRAGON RIGHT COPY CONSTRUCTOR
   * input:   pos(4000,4500), vel(3500), ang(3.1415)
   *********************************************/
   void dragonRightConstructor_copy()
   {
      // setup
      Position pos;
      SatelliteDragon sat;
      sat.position.x = 4000.0;
      sat.position.y = 4500.0;
      sat.velocity.dx = 3000.0;
      sat.velocity.dy = 3500.0;
      sat.angle.radians = 3.1415;

      // exercise
      DragonRight satCopy(sat);

      // verify
      assertEquals(satCopy.angle.radians, 3.1415);
      //assertEquals(s.position.x, 4000.0);
      //assertEquals(s.position.y, 4500.0);
      //assertEquals(s.velocity.dx, 3000.0);
      //assertEquals(s.velocity.dy, 3500.0);
      assertEquals(satCopy.radius, 6 * pos.metersFromPixels); // default 6 * zoom
      assertEquals(satCopy.fragmentCount, 2); // default value: 2
      assertUnit(satCopy.isBroken == false);
      assertUnit(satCopy.thrust.clockwise == false);
      assertUnit(satCopy.thrust.counterClockwise == false);
      assertUnit(satCopy.thrust.mainEngine == false);

   } // teardown

   /*********************************************
   * name:    Dragon Right Default Constructor
   * input:   none
   *********************************************/
   void dragonRightConstructor_default()
   {
      // setup
      Position pos;

      // exercise
      DragonRight s;

      // verify
      assertEquals(s.angle.radians, 0.0);
      assertEquals(s.position.x, 0.0);
      assertEquals(s.position.y, 0.0);
      assertEquals(s.velocity.dx, 0.0);
      assertEquals(s.velocity.dy, 0.0);
      assertEquals(s.radius, 6 * pos.metersFromPixels); // default 6 * zoom
      assertEquals(s.fragmentCount, 2); // default value: 2
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == false);

   } // teardown

   /*********************************************
   * name:    DRAGON LEFT COPY CONSTRUCTOR
   * input:   pos(4000,4500), vel(3500), ang(3.1415)
   *********************************************/
   void dragonLeftConstructor_copy()
   {
      // setup
      Position pos;
      SatelliteDragon sat;
      sat.position.x = 4000.0;
      sat.position.y = 4500.0;
      sat.velocity.dx = 3000.0;
      sat.velocity.dy = 3500.0;
      sat.angle.radians = 3.1415;

      // exercise
      DragonLeft satCopy(sat);

      // verify
      assertEquals(satCopy.angle.radians, 3.1415);
      //assertEquals(s.position.x, 4000.0);
      //assertEquals(s.position.y, 4500.0);
      //assertEquals(s.velocity.dx, 3000.0);
      //assertEquals(s.velocity.dy, 3500.0);
      assertEquals(satCopy.radius, 6 * pos.metersFromPixels); // default 6 * zoom
      assertEquals(satCopy.fragmentCount, 2); // default value: 2
      assertUnit(satCopy.isBroken == false);
      assertUnit(satCopy.thrust.clockwise == false);
      assertUnit(satCopy.thrust.counterClockwise == false);
      assertUnit(satCopy.thrust.mainEngine == false);

   } // teardown

   /*********************************************
   * name:    Dragon Left Default Constructor
   * input:   none
   *********************************************/
   void dragonLeftConstructor_default()
   {
      // setup
      Position pos;

      // exercise
      DragonLeft s;

      // verify
      assertEquals(s.angle.radians, 0.0);
      assertEquals(s.position.x, 0.0);
      assertEquals(s.position.y, 0.0);
      assertEquals(s.velocity.dx, 0.0);
      assertEquals(s.velocity.dy, 0.0);
      assertEquals(s.radius, 6 * pos.metersFromPixels); // default 6 * zoom
      assertEquals(s.fragmentCount, 2); // default value: 2
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == false);

   } // teardown

   /*********************************************
   * name:    DRAGON CENTER COPY CONSTRUCTOR
   * input:   pos(4000,4500), vel(3500), ang(3.1415)
   *********************************************/
   void dragonCenterConstructor_copy()
   {
      // setup
      Position pos;
      SatelliteDragon sat;
      sat.position.x = 4000.0;
      sat.position.y = 4500.0;
      sat.velocity.dx = 3000.0;
      sat.velocity.dy = 3500.0;
      sat.angle.radians = 3.1415;

      // exercise
      DragonCenter satCopy(sat);

      // verify
      assertEquals(satCopy.angle.radians, 3.1415);
      //assertEquals(s.position.x, 4000.0);
      //assertEquals(s.position.y, 4500.0);
      //assertEquals(s.velocity.dx, 3000.0);
      //assertEquals(s.velocity.dy, 3500.0);
      assertEquals(satCopy.radius, 6 * pos.metersFromPixels); // default 6 * zoom
      assertEquals(satCopy.fragmentCount, 4); // default value: 2
      assertUnit(satCopy.isBroken == false);
      assertUnit(satCopy.thrust.clockwise == false);
      assertUnit(satCopy.thrust.counterClockwise == false);
      assertUnit(satCopy.thrust.mainEngine == false);

   } // teardown

   /*********************************************
   * name:    Dragon Center Default Constructor
   * input:   none
   *********************************************/
   void dragonCenterConstructor_default()
   {
      // setup
      Position pos;

      // exercise
      DragonCenter s;

      // verify
      assertEquals(s.angle.radians, 0.0);
      assertEquals(s.position.x, 0.0);
      assertEquals(s.position.y, 0.0);
      assertEquals(s.velocity.dx, 0.0);
      assertEquals(s.velocity.dy, 0.0);
      assertEquals(s.radius, 6 * pos.metersFromPixels); // default 6 * zoom
      assertEquals(s.fragmentCount, 4); // default value: 2
      assertUnit(s.isBroken == false);
      assertUnit(s.thrust.clockwise == false);
      assertUnit(s.thrust.counterClockwise == false);
      assertUnit(s.thrust.mainEngine == false);

   } // teardown
};
