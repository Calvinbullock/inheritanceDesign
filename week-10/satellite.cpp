/***********************************************************************
 * Source File:
 *    SatelliteGPS class
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    Everything to know about a GPS satellite's
 ************************************************************************/

#include "satellite.h"

/***************************************************************
 * INPUT
 * Accept input from the Neil Armstrong
 ***************************************************************/

void Satellite::input(const Thrust& thrust, double gravity, const int &time)
{
   // Acceleration due to gravity
   Acceleration a;

   // add gravity
   a.addDDY(gravity);

   // main engines
   if (thrust.isMain())
   {
      a.addDDX(-sin(angle.getRadians()) * SHIP_THRUST);
      a.addDDY(cos(angle.getRadians()) * SHIP_THRUST);
      a.reverseDDX();

      velocity.add(a, time);
      position.add(a, velocity, time);
   }

   // clockwise
   if (thrust.isClock())
   {
      angle.add(SHIP_ROTATION);
   }
   // counter clockwise
   if (thrust.isCounter())
   {
      angle.add(SHIP_ROTATION);
   }

   this->thrust = thrust;
}
