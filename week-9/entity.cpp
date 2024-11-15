#include "entity.h"
#include <math.h>  

void Entity::orbit(double time, double grav, Acceleration accel)
{
   //// positions
   //double currXPos = pDemo->ptGPS.getMetersX();
   //double currYPos = pDemo->ptGPS.getMetersY();


   //// Velocity
   //DX = getAxisVelocity(DX, ddx, TIME);
   //DY = getAxisVelocity(DY, ddy, TIME);

   //// new distance
   //double xPos = getAxisDistance(currXPos, DX, ddx, TIME);
   //double yPos = getAxisDistance(currYPos, DY, ddy, TIME);

   //// orbit the GPS satelite
   //pDemo->ptGPS.setMetersX(getAxisDistance(currXPos, DX, ddx, TIME));
   //pDemo->ptGPS.setMetersY(getAxisDistance(currYPos, DY, ddy, TIME));
}

void Entity::rotate(double delta)
{
   angle.add(delta);

}
