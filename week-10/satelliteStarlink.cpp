/***********************************************************************
 * Source File:
 *    SatelliteStarlink class
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    Everything to know about a Starlink satellite
 ************************************************************************/

#include "satelliteStarlink.h"

 /****************************************
 * DRAW
 * Draw the Starlink satellite
 *****************************************/
void SatelliteStarlink::draw(ogstream& gout)
{
   gout.drawStarlink(position, angle.getRadians());
}

/****************************************
* DRAW
* What happens on impact?
*****************************************/
void SatelliteStarlink::impact()
{
   // TODO:
}
