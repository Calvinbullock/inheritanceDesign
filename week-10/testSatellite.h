
/***********************************************************************
 * Header File:
 *    TEST Satellite
 * Author:
 *    Daniel Malasky, Calvin Bullock
 * Summary:
 *    All the unit tests for Satellite
 ************************************************************************/

#pragma once


#include "satellite.h"
#include "satelliteGPS.h"
#include "satelliteHubble.h"
#include "unitTest.h"
#include <iostream>
#include <vector>

/*******************************
* TEST ENTITY
********************************/
class TestSatellite : public UnitTest
{
public:
   void run()
   {
      // impact
      hubbleImpact();
      hubbleTelescopeImpact();
      hubbleLeftImpact();
      hubbleRightImpact();
      hubbleComputerImpact();

      gpsImpact();
      gpsLeftImpact();
      gpsRightImpact();
      gpsCenterImpact();

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
              entities has: [ Fragment, Fragment ]
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

};
