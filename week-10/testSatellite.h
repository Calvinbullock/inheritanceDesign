
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
      std::cout << "here 1" << std::endl;
      //hubbleTelescopeImpact();
      //std::cout << "here 2" << std::endl;
      //hubbleLeftImpact();
      //std::cout << "here 3" << std::endl;
      //hubbleRightImpact();
      //std::cout << "here 4" << std::endl;
      //hubbleComputerImpact();
      //std::cout << "here 5" << std::endl;

      //gpsImpact();
      //std::cout << "here 6" << std::endl;
      //gpsLeftImpact();
      //std::cout << "here 7" << std::endl;
      //gpsRightImpact();
      //std::cout << "here 8" << std::endl;
      //gpsCenterImpact();
      //std::cout << "here 9" << std::endl;

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
      delete entities[0];
      delete entities[1];
      delete entities[2];
      delete entities[3];
      entities[0] = nullptr;
      entities[1] = nullptr;
      entities[2] = nullptr;
      entities[3] = nullptr;
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
      delete entities[0];
      delete entities[1];
      delete entities[2];
      entities[0] = nullptr;
      entities[1] = nullptr;
      entities[2] = nullptr;
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

      // Exercise
      sat.impact(entities);

      // Verify
      std::cout << "here: " << entities.size() << std::endl;
      std::cout << "frag: " << sat.fragmentCount << std::endl;
      assertUnit(sat.isBroken == true);
      assertUnit(entities.size() == 3);

      // TODO: how to type check??
      //std::cout << typeid(*entities[0]).name() << ", " << typeid(SatelliteHubbleLeft()).name() << std::endl;
      //assertUnit(typeid(*entities[0]) == typeid(SatelliteHubbleLeft()));
      //assertUnit(typeid(*entities[1]) == typeid(SatelliteHubbleRight()));
      //assertUnit(typeid(*entities[2]) == typeid(SatelliteHubbleTelescope()));
      //assertUnit(typeid(*entities[3]) == typeid(SatelliteHubbleComputer()));

      // teardown
      delete entities[0];
      delete entities[1];
      entities[0] = nullptr;
      entities[1] = nullptr;
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
      delete entities[0];
      delete entities[1];
      entities[0] = nullptr;
      entities[1] = nullptr;
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
      delete entities[0];
      delete entities[1];
      entities[0] = nullptr;
      entities[1] = nullptr;
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

      // Exercise
      sat.impact(entities);

      // Verify
      assertUnit(sat.isBroken == true);
      assertUnit(entities.size() == 3);

      // TODO: how to type check??

      // teardown
      delete entities[0];
      delete entities[1];
      delete entities[2];
      entities[0] = nullptr;
      entities[1] = nullptr;
      entities[2] = nullptr;
   }

   /*********************************************
    * name:  GPS RIGHT IMPACT
    * output: isBroken == True
              entities.size == 3
              entities has: [ Fragment, Fragment, Fragment]
    *********************************************/
   void gpsRightImpact()
   {
      // Setup
      std::vector<Entity*> entities;
      GPSRight sat = GPSRight();

      // Exercise
      sat.impact(entities);

      // Verify
      assertUnit(sat.isBroken == true);
      assertUnit(entities.size() == 3);

      // TODO: how to type check??

      // teardown
      delete entities[0];
      delete entities[1];
      delete entities[2];
      entities[0] = nullptr;
      entities[1] = nullptr;
      entities[2] = nullptr;
   }

   /*********************************************
    * name:  GPS LEFT IMPACT
    * output: isBroken == True
              entities.size == 3
              entities has: [ Fragment, Fragment, Fragment]
    *********************************************/
   void gpsLeftImpact()
   {
      // Setup
      std::vector<Entity*> entities;
      GPSLeft sat = GPSLeft();

      // Exercise
      sat.impact(entities);

      // Verify
      assertUnit(sat.isBroken == true);
      assertUnit(entities.size() == 3);

      // TODO: how to type check??

      // teardown
      delete entities[0];
      delete entities[1];
      delete entities[2];
      entities[0] = nullptr;
      entities[1] = nullptr;
      entities[2] = nullptr;
   }

   /*********************************************
    * name:  GPS CENTER IMPACT
    * output: isBroken == True
              entities.size == 3
              entities has: [ Fragment, Fragment, Fragment]
    *********************************************/
   void gpsCenterImpact()
   {
      // Setup
      std::vector<Entity*> entities;
      GPSCenter sat = GPSCenter();

      // Exercise
      sat.impact(entities);

      // Verify
      assertUnit(sat.isBroken == true);
      assertUnit(entities.size() == 3);

      // TODO: how to type check??

      // teardown
      delete entities[0];
      delete entities[1];
      delete entities[2];
      entities[0] = nullptr;
      entities[1] = nullptr;
      entities[2] = nullptr;
   }

};
