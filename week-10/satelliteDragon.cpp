/***********************************************************************
 * Source File:
 *    SatelliteDragon class
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    Everything to know about a Dragon satellite
 ************************************************************************/

#include "satelliteDragon.h"

 /****************************************
 * DRAW
 * Draw the Dragon satellite
 *****************************************/
void SatelliteDragon::draw(ogstream& gout)
{
   gout.drawCrewDragon(position, angle.getRadians());
}

/****************************************
* DRAW
* What happens on impact?
*****************************************/
void SatelliteDragon::impact()
{
   // TODO:
}
