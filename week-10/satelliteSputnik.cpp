/***********************************************************************
 * Source File:
 *    SatelliteSputnik class
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    Everything to know about a Sputnik satellite
 ************************************************************************/

#include "SatelliteSputnik.h"

 /****************************************
 * DRAW
 * Draw the Sputnik satellite
 *****************************************/
void SatelliteSputnik::draw(ogstream& gout)
{
   gout.drawSputnik(position, angle.getRadians());
}

/****************************************
* DRAW
* What happens on impact?
*****************************************/
void SatelliteSputnik::impact()
{
   // TODO:
}
