
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
      // Sputnik
      sputnikImpact();
      
      // Hubble
      hubbleImpact();
      hubbleTelescopeImpact();
      hubbleLeftImpact();
      hubbleRightImpact();
      hubbleComputerImpact();
      
      // GPS
      GPSConstructor_default();
      gpsImpact();
      gpsLeftImpact();
      gpsRightImpact();
      gpsCenterImpact();
      
      // Starlink
      starlinkImpact();
      starlinkArrayImpact();
      starlinkBodyImpact();
      
      // Dragon
      dragonConstructor_default();
      dragonImpact();
      dragonLeftImpact();
      dragonRightImpact();
      dragonCenterImpact();

      report("Satellite");
   }

private:
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
      sat.fragmentCount = 0;

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
      sat.fragmentCount = 0;

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
};
