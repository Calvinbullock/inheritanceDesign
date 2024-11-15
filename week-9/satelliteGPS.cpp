#include "satelliteGPS.h"

/****************************************
* DRAW
* Draw the GPS satellite
*****************************************/
void SatelliteGPS::draw(ogstream& gout)
{
   std::cout << position.getMetersX() << ", " << position.getMetersY() << std::endl;
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
