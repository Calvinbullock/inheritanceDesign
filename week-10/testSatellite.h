
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
#include "unitTest.h"

/*******************************
* TEST ENTITY
********************************/
class TestSatellite : public UnitTest
{
public:
   void run()
   {
      report("Satellite");
   }

private:

};
