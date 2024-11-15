#include "satelliteGPS.h"

/****************************************
* DRAW
* Draw the GPS satellite
*****************************************/
void SatelliteGPS::draw(ogstream gout)
{
   gout.drawGPS(position, angle.getRadians());
}

/****************************************
* DRAW
* What happens on impact?
*****************************************/
void SatelliteGPS::impact()
{
   //TODO:
}
