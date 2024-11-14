/***********************************************************************
 * Header File:
 *    Entity class
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    TODO:
 ************************************************************************/

#pragma once

#include "acceleration.h"
#include "position.h"
#include "uiDraw.h"
#include "velocity.h"
#include "angle.h"


/***********************************************************************
 * Entity
 *    TODO:
 ************************************************************************/
class Entity
{
public:

   // Constructors
   Entity() {}

   // Getters
   Position getPosition() const { return pos;      }
   Velocity getVelocity() const { return vel;      }
   bool     getIsBroken() const { return isBroken; }
   double   getWidth()    const { return width;    }
   Angle    getAngle()    const { return angle;    }

   // Setters
   void setPosition  (const Position& newPos) { pos = newPos;      }
   void setVelocity  (const Velocity& newVel) { vel = newVel;      }
   void setIsBroken  (bool broken)            { isBroken = broken; }
   void setAngle     (const Angle& newAngle)  { angle = newAngle;  }
   void setWidth     (double newWidth)        { width = newWidth;  }

   void orbit(double time, double grav, Acceleration accel) {}
   virtual void draw(ogstream gout);
   virtual void impact();

protected:
   Position pos;
   Velocity vel;
   Angle angle;
   bool isBroken;
   double width;
};
