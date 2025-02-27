/***********************************************************************
 * Source File:
 *    For Simulator class, main function and callback
 * Author:
 *    Daniel Malasky & Calvin Bullock
 * Summary:
 *    Holds the class with all the simulator class parts.
 *       also has the callback function for the openGL
 *       and the main function.
 ************************************************************************/


#include "simulator.h"


/****************************************
* INITIALIZE SATELLITES
* initialize all the satellites and add them
*     to the satellite vector.
* *****************************************/
void Simulator::initializeSatellites()
{
   // TODO: this may need fine tuning
   int chanceDefunct = 3000; // 1 in X frames chance of defunct

   // initial DreamChaser satellite
   Position initialPos;
   initialPos.setPixelsX(-450);
   initialPos.setPixelsY(450);
   Velocity initialVel = Velocity(0.0, -2000);
   Angle a = Angle();
   entities.push_back(new SatelliteShip(initialPos, initialVel, a));

   // GPS satellite 1
   initialPos = Position(0.0, 26560000.0);
   initialVel = Velocity(-3880.0, 0.0);
   a = Angle();
   entities.push_back(new SatelliteGPS(initialPos, initialVel, a, chanceDefunct));

   // GPS satellite 2
   initialPos = Position(23001634.72, 13280000.0);
   initialVel = Velocity(-1940.00, 3360.18);
   a = Angle();
   entities.push_back(new SatelliteGPS(initialPos, initialVel, a, chanceDefunct));

   // GPS satellite 3
   initialPos = Position(23001634.72, -13280000.0);
   initialVel = Velocity(1940.00, 3360.18);
   a = Angle();
   entities.push_back(new SatelliteGPS(initialPos, initialVel, a, chanceDefunct));

   // GPS satellite 4
   initialPos = Position(0.0, -26560000.0);
   initialVel = Velocity(3880.0, 0.0);
   a = Angle();
   entities.push_back(new SatelliteGPS(initialPos, initialVel, a, chanceDefunct));

   // GPS satellite 5
   initialPos = Position(-23001634.72, -13280000.0);
   initialVel = Velocity(1940.00, -3360.18);
   a = Angle();
   entities.push_back(new SatelliteGPS(initialPos, initialVel, a, chanceDefunct));

   // GPS satellite 6
   initialPos = Position(-23001634.72, 13280000.0);
   initialVel = Velocity(-1940.00, -3360.18);
   a = Angle();
   entities.push_back(new SatelliteGPS(initialPos, initialVel, a, chanceDefunct));

   // initial Hubble satellite
   initialPos = Position(0.0, -42164000.0);
   initialVel = Velocity(3100.0, 0.0);
   a = Angle();
   entities.push_back(new SatelliteHubble(initialPos, initialVel, a, chanceDefunct));

   // sputnik
   initialPos = Position(-36515095.13, 21082000.0);
   initialVel = Velocity(2050.0, 2684.68);
   a = Angle();
   entities.push_back(new SatelliteSputnik(initialPos, initialVel, a, chanceDefunct));

   // starlink
   initialPos = Position(0.0, -13020000.0);
   initialVel = Velocity(5800.0, 0.0);
   a = Angle();
   entities.push_back(new SatelliteStarlink(initialPos, initialVel, a, chanceDefunct));

   // Dragon
   initialPos = Position(0.0, 8000000.0);
   initialVel = Velocity(-7900.0, 0.0);
   a = Angle();
   entities.push_back(new SatelliteDragon(initialPos, initialVel, a, chanceDefunct));
}

/****************************************
* EarthCollisionCheck
* Check to see if any entities have collided
*     with the earth
* *****************************************/
void Simulator::earthCollisionCheck()
{
   //for (int i = 0; i < entities.size(); i++)
   for (int i = 0; i < 1; i++)
   {
      // check for earth collision
      double distanceToEarth = computeDistance(earth.getPosition(),
         entities[i]->getPosition());
      double minDistanceToEarth = earth.getRadius() + entities[i]->getRadius();

      //std::cout << distanceToEarth << std::endl;    // TODO: remove
      //std::cout << minDistanceToEarth << std::endl; // TODO: remove

      // BUG:  TODO: THIS CHECK IS TO SLOW NEED TO FIX
      if (distanceToEarth < minDistanceToEarth)
      {
         //std::cout << "here" << std::endl; // TODO: remove
         entities[i]->impact(entities);

         // remove entity from list
         delete entities[i];
         entities.erase(entities.begin() + i);

         // stop further check for this satellite
         //return;
      }
   }
}

/****************************************
* checkCollision
* Check to see if any entities have collided
*
* NOTE: Must be called in a loop, thought the
*     entities list
* *****************************************/
void Simulator::checkCollision(int iSat)
{
   // check for satellite collisions
   for (int iCheck = iSat + 1; iCheck < entities.size(); iCheck++)
   {
      // Find distance between the two ships
      double distance = computeDistance(entities[iSat]->getPosition(),
         entities[iCheck]->getPosition());
      // Find the min distance two entities can be
      double minDistance = entities[iSat]->getRadius() + entities[iCheck]->getRadius();

      // If they collide break the entities
      if (distance < minDistance)
      {
         entities[iSat]->impact(entities);
         entities[iCheck]->impact(entities);

         // remove entities from list
         delete entities[iSat];
         delete entities[iCheck];
         entities.erase(entities.begin() + iCheck);
         entities.erase(entities.begin() + iSat);
      }
   }

}


/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL.
   Simulator* pSim = (Simulator*)p;

   //
   // perform all the game logic
   //

   Position pt;
   ogstream gout(pt);

   // draw stars
   for (int i = 0; i < pSim->getStarCount(); ++i) {
      pSim->stars[i].draw(gout);
   }

   pSim->earthCollisionCheck();

   // Use input on ship
   pSim->entities[0]->input(pUI, pSim->entities, TIME);

   // Fire Projectile

   // Orbit, rotate, and draw all entities
   for (int i = 0; i < pSim->entities.size(); i++)
   {
      // TODO: check if ship is dead and draw GAME OVER & pause physics
      if (!pSim->entities[i]->getIsBroken())
      {
         double distanceFromEarth = computeDistance(Position(0, 0), pSim->entities[i]->getPosition());

         // Gravity
         double gravity = getGravity(GRAVITY_SEA_LEVEL, RADIUS_EARTH, distanceFromEarth);

         Angle gravityAngle;
         double gravityAngleRadians = getDirectionGravity(Position(), pSim->entities[i]->getPosition());
         gravityAngle.setRadians(gravityAngleRadians);

         // Acceleration
         Acceleration acceleration;
         acceleration.set(gravityAngle, gravity);

         pSim->entities[i]->orbit(TIME, acceleration); // orbit entities

         pSim->entities[i]->draw(gout);                // draw

         // rotate all but the dreamChaser / check defunct
         if (!(i == 0)) {
            pSim->entities[i]->defunctChance(i);

            if (!pSim->entities[i]->getIsDefunct())
            {
               pSim->entities[i]->rotate(ROTATION_SPEED);    // rotate
            }
            else
            {
               pSim->entities[i]->rotate(ROTATION_SPEED_DEFUNCT);    // rotate faster
            }
         }

         // Check collision
         pSim->checkCollision(i);

         if (pSim->entities[i]->hasExpired())
         {
            delete pSim->entities[i];
            pSim->entities.erase(pSim->entities.begin() + i);
         }
      }
   }

   // rotate / draw the earth
   pSim->earth.rotate(0.00349);
   pSim->earth.draw(gout);

   pt.setMeters(0.0, 0.0);
}

double Position::metersFromPixels = 40.0;

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{

   testRunner();

   // Initialize OpenGL
   Position ptUpperRight;
   ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
   ptUpperRight.setPixelsX(1000.0);
   ptUpperRight.setPixelsY(1000.0);
   Interface ui(0, NULL,
      "Demo",   /* name on the window */
      ptUpperRight);

   // Initialize the demo
   Simulator demo(ptUpperRight, STAR_COUNT);

   // set everything into action
   ui.run(callBack, &demo);

   return 0;
}



