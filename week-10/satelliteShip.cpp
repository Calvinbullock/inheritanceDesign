/***********************************************************************
 * Source File:
 *    SatelliteGPS class
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    Everything to know about a GPS satellite's
 ************************************************************************/

#include "acceleration.h"
#include "satelliteShip.h"

/***************************************************************
 * INPUT
 * Accept input from the Neil Armstrong
 ***************************************************************/
Acceleration SatelliteShip::input(const Thrust& t, double gravity)
{
   // Acceleration due to gravity
   Acceleration a;

   // add gravity
   a.addDDY(gravity);

   // main engines
   if (t.isMain())
   {
      a.addDDX(-sin(angle.getRadians()) * SHIP_THRUST);
      a.addDDY(cos(angle.getRadians()) * SHIP_THRUST);
   }

   // clockwise
   if (t.isClock())
   {
      angle.add(SHIP_ROTATION);
   }
   // counter clockwise
   if (t.isCounter())
   {
      angle.add(SHIP_ROTATION);
   }

   thrust = t;

   return a;
}


/****************************************
* IMPACT
* What happens on impact?
*****************************************/
void SatelliteShip::impact()
{
   // TODO:
}
