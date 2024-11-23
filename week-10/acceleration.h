/***********************************************************************
 * Header File:
 *    ACCELERATION
 * Author:
 *    Daniel Malasky, Calvin Bullock
 * Summary:
 *    Everything we need to know about acceleration
 ************************************************************************/


#pragma once

class TestAcceleration;
class TestVelocity;
class TestPosition;
class TestEntity;
class Angle;


/*********************************************
 * Acceleration
 * Let's get moving
 *********************************************/
class Acceleration
{
   friend TestPosition;
   friend TestVelocity;
   friend TestAcceleration;
   friend TestEntity;

public:
   // constructors
   Acceleration() : ddx(0.0), ddy(0.0) { }
   Acceleration(double ddx, double ddy) : ddx(ddx), ddy(ddy) { }

   // getters
   double getDDX()   const { return ddx; }
   double getDDY()   const { return ddy; }

   // setters
   void setDDX(double ddx) { this->ddx = ddx; }
   void setDDY(double ddy) { this->ddy = ddy; }
   void set(const Angle& a, double magnitude);
   void addDDX(double ddx) { this->ddx += ddx; }
   void addDDY(double ddy) { this->ddy += ddy; }
   void add(const Acceleration& rhs) {
      this->ddx += rhs.ddx;
      this->ddy += rhs.ddy;
   }
   void reverseDDX() { ddx *= -1; }

private:
   double ddx;     // horizontal acceleration
   double ddy;     // vertical acceleration
};
