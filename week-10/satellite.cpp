/***********************************************************************
 * Source File:
 *    SatelliteGPS class
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    Everything to know about a satellite
 ************************************************************************/

#include "satellite.h"

/***************************************************************
 * INPUT
 * update position and velocity based on user input
 ***************************************************************/
void Satellite::input(const Thrust& thrust, const double &time)
{
   // main engines
   if (thrust.isMain())
   {
      Acceleration a;

      a.addDDX(-sin(angle.getRadians()) * SHIP_THRUST);
      a.addDDY(cos(angle.getRadians()) * SHIP_THRUST);
      a.reverseDDX();

      /*std::cout << "ax " << a.getDDX() << std::endl;*/
      /*std::cout << "ay " << a.getDDY() << std::endl;*/

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
      angle.add(-SHIP_ROTATION);
   }

   this->thrust = thrust;
}
