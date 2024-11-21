/***********************************************************************
 * Source File:
 *    SatelliteGPS class
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    Everything to know about a GPS satellite's
 ************************************************************************/

#include "satelliteGPS.h"

/****************************************
* DRAW
* Draw the GPS satellite
*****************************************/
void SatelliteGPS::draw(ogstream& gout)
{
   gout.drawGPS(position, angle.getRadians());
}

/****************************************
* IMPACT
* What happens on impact?
*****************************************/
void SatelliteGPS::impact()
{
   // TODO:
}
