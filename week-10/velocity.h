/***********************************************************************
 * Header File:
 *    VELOCITY
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    Everything we need to know about speed
 ************************************************************************/

#pragma once

 // for unit tests
class TestPosition;
class TestVelocity;
class TestAcceleration;
class TestSatellite;
class TestEntity;
class TestSatelliteShip;
class TestSimulator;


// for add()
class Acceleration;
class Angle;

/*********************************************
 * Velocity
 * I feel the need, the need for speed
 *********************************************/
class Velocity
{
   // for unit tests
   friend TestPosition;
   friend TestVelocity;
   friend TestSatellite;
   friend TestSatelliteShip;
   friend TestEntity;
   friend TestSimulator;

public:
   // constructors
   Velocity() : dx(0.0), dy(0.0) { }
   Velocity(double dx, double dy) : dx(dx), dy(dy) { }

   // getters
   double getDX()       const { return dx; }
   double getDY()       const { return dy; }
   double getSpeed()    const;

   // setters
   void setDX(double dx) { this->dx = dx; }
   void setDY(double dy) { this->dy = dy; }
   void set(const Angle& angle, double magnitude);
   void addDX(double dx) { this->dx += dx; }
   void addDY(double dy) { this->dy += dy; }
   void add(const Acceleration& acceleration, double time);
   void addV(const Velocity& rhs) { dx += rhs.dx; dy += rhs.dy; }
   void reverse() { dx = -dx, dy = -dy; }

   // overload the += operator
   Velocity& operator+=(const Velocity& rhs)
   {
      dx += rhs.dx;
      dy += rhs.dy;
      return *this;
   }

private:
   double dx;           // horizontal velocity
   double dy;           // vertical velocity
};

