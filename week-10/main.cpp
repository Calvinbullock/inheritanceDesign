
#include "test.h"
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*

#include "simulator.h"

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
