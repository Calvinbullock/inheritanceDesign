/***********************************************************************
 * Source File:
 *    Point : The representation of a position on the screen
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    Everything we need to know about a location on the screen.
 ************************************************************************/

#include "position.h"
#include <cassert>


Position::Position(double x, double y) : x(0.0), y(0.0)
{
   setMetersX(x);
   setMetersY(y);
}

/******************************************
 * POINT : ASSIGNMENT
 * Assign a point
 *****************************************/
Position& Position::operator = (const Position& pt)
{
   x = pt.x;
   y = pt.y;
   return *this;
}

/********************************************************
* ADD : calculating new position and adding
* to the current position
*
* s0 = initial distance (m)
* v  = velocity (m/s)
* a  = acceleration (m/s^2)
* t  = time (s)
*
* s  = distance at time t (m)
*
* s = s0 + v * t + ½ * a * t^2
*********************************************************/
void Position::add(Acceleration a, Velocity v, double t)
{
   x += v.getDX() * t + 0.5 * a.getDDX() * (t * t);
   y += v.getDY() * t + 0.5 * a.getDDY() * (t * t);
}

/******************************************
 * POSITION insertion
 *       Display coordinates on the screen
 *****************************************/
std::ostream& operator << (std::ostream& out, const Position& pt)
{
   out << "(" << pt.getMetersX() << "m , " << pt.getMetersY() << "m)";
   return out;
}

/*******************************************
* POSITION extraction
*       Prompt for coordinates
******************************************/
std::istream& operator >> (std::istream& in, Position& pt)
{
   double x;
   double y;
   in >> x >> y;

   pt.setMetersX(x);
   pt.setMetersY(y);

   return in;
}
