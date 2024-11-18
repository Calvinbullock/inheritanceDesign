/***********************************************************************
 * Source File:
 *    SatelliteHubble class
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    Everything to know about a Hubble satellite's
 ************************************************************************/

#include "satelliteHubble.h"

/****************************************
* DRAW
* Draw the GPS satellite
*****************************************/
void SatelliteHubble::draw(ogstream& gout)
{
   gout.drawHubble(position, angle.getRadians());
}

/****************************************
* DRAW
* What happens on impact?
*****************************************/
void SatelliteHubble::impact()
{
   // TODO:
}
