/***********************************************************************
 * Source File:
 *    Test : Test runner
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The test runner for all the unit tests
 ************************************************************************/

#include "test.h"
#include "testPosition.h"
#include "testAngle.h"
#include "testAcceleration.h"
#include "testSatellite.h"
#include "testThrust.h"
#include "testVelocity.h"
#include "testPhysics.h"
#include "testEntity.h"
#include "testSatelliteShip.h"


#ifdef _WIN32
#include <windows.h>
#include <iostream>
using namespace std;
#endif

/*****************************************************************
 * TEST RUNNER
 * Runs all the unit tests
 ****************************************************************/
void testRunner()
{
#ifdef _WIN32
   AllocConsole();
   FILE* stream;
   errno_t err;
   err = freopen_s(&stream, "CONOUT$", "a", stdout);
#endif // _WIN32

   TestPosition().run();
   TestAngle().run();
   TestAcceleration().run();
   TestVelocity().run();
   TestPhysics().run();
   TestEntity().run();
   TestThrust().run();
   TestSatellite().run();
   TestSatelliteShip().run();
}
