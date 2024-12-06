
#pragma once

#include "position.h"
#include "uiDraw.h"
#include "uiInteract.h"

class Earth
{
public:
   Earth() : position(0.0, 0.0), rotation(0) {}
   Earth(Position positionIn, double rotaionIn) : position(), rotation()
   {
      position = positionIn;
      rotation = rotaionIn;
      radius = 6378000; // radius in meters
   }

   void rotate(double delta)
   {
      rotation -= delta; // 2PI / 1800 || full orbit / frames in a min
   }

   void draw(ogstream &gout)
   {
      gout.drawEarth(position, rotation);
   }

   double getRadius() { return radius; }
   Position getPosition() { return position;}

private:
   Position position;
   double rotation;
   double radius;
};
