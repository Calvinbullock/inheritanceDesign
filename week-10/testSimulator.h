#pragma once

#include "simulator.cpp"
#include "unitTest.h"

/*******************************
* TEST SIMULATOR
********************************/
class TestSimulator: public UnitTest
{
public:
   void run()
   {
      initializeSatellites();

      report("Simulator");
   }

private:
   void initializeSatellites()
   {
      // Setup
      Simulator sim = Simulator();
      //Angle a = Angle();

      // Exercise
      sim.initializeSatellites();

      // Verify
      assertUnit(sim.entities.size() == 11);

      // initial DreamChaser satellite
      assertUnit(sim.entities[0]->position.x == -450);
      assertUnit(sim.entities[0]->position.y == 450);
      assertUnit(sim.entities[0]->velocity.dx == 0.0);
      assertUnit(sim.entities[0]->velocity.dy == -2000);
      assertUnit(sim.entities[0]->angle.radians == 0.0);

      // GPS satellite 1
      assertUnit(sim.entities[1]->position.x == 0.0);
      assertUnit(sim.entities[1]->position.y == 26560000.0);
      assertUnit(sim.entities[1]->velocity.dx == -3880.0);
      assertUnit(sim.entities[1]->velocity.dy == 0.0);
      assertUnit(sim.entities[1]->angle.radians == 0.0);

      // GPS satellite 2
      assertUnit(sim.entities[2]->position.x == 23001634.72);
      assertUnit(sim.entities[2]->position.y == 13280000.0 );
      assertUnit(sim.entities[2]->velocity.dx == -1940.00);
      assertUnit(sim.entities[2]->velocity.dy == 3360.18);
      assertUnit(sim.entities[2]->angle.radians == 0.0);

      // GPS satellite 3
      assertUnit(sim.entities[3]->position.x == 23001634.72);
      assertUnit(sim.entities[3]->position.y == -13280000.0 );
      assertUnit(sim.entities[3]->velocity.dy == 1940.00);
      assertUnit(sim.entities[3]->velocity.dy == 3360.18);
      assertUnit(sim.entities[3]->angle.radians == 0.0);

      // GPS satellite 4
      assertUnit(sim.entities[4]->position.x == 0.0);
      assertUnit(sim.entities[4]->position.y == -26560000.0);
      assertUnit(sim.entities[4]->velocity.dy == 3880.0);
      assertUnit(sim.entities[4]->velocity.dy == 0.0);
      assertUnit(sim.entities[4]->angle.radians == 0.0);

      // GPS satellite 5
      assertUnit(sim.entities[5]->position.x == -23001634.72);
      assertUnit(sim.entities[5]->position.y == -13280000.0 );
      assertUnit(sim.entities[5]->velocity.dy == 1940.00);
      assertUnit(sim.entities[5]->velocity.dy == -3360.18);
      assertUnit(sim.entities[5]->angle.radians == 0.0);

      // GPS satellite 6
      assertUnit(sim.entities[6]->position.x == -23001634.72);
      assertUnit(sim.entities[6]->position.y == 13280000.0 );
      assertUnit(sim.entities[6]->velocity.dy == -1940.00);
      assertUnit(sim.entities[6]->velocity.dy == -3360.18);
      assertUnit(sim.entities[6]->angle.radians == 0.0);

      // initial Hubble satellite
      assertUnit(sim.entities[7]->position.x == 0.0);
      assertUnit(sim.entities[7]->position.y == -42164000.0);
      assertUnit(sim.entities[7]->velocity.dy == 3100.0);
      assertUnit(sim.entities[7]->velocity.dy == 0.0);
      assertUnit(sim.entities[7]->angle.radians == 0.0);

      // sputnik
      assertUnit(sim.entities[8]->position.x == -36515095.13);
      assertUnit(sim.entities[8]->position.y == 21082000.0);
      assertUnit(sim.entities[8]->velocity.dy == 2050.0);
      assertUnit(sim.entities[8]->velocity.dy == 2684.68);
      assertUnit(sim.entities[8]->angle.radians == 0.0);

      // starlink
      assertUnit(sim.entities[9]->position.x == 0.0);
      assertUnit(sim.entities[9]->position.y == -13020000.0);
      assertUnit(sim.entities[9]->velocity.dy == 5800.0);
      assertUnit(sim.entities[9]->velocity.dy == 0.0);
      assertUnit(sim.entities[9]->angle.radians == 0.0);

      // Dragon
      assertUnit(sim.entities[10]->position.x == 0.0);
      assertUnit(sim.entities[10]->position.y == 8000000.0);
      assertUnit(sim.entities[10]->velocity.dy == -7900.0);
      assertUnit(sim.entities[10]->velocity.dy == 0.0);
      assertUnit(sim.entities[10]->angle.radians == 0.0);

      // teardown
      for (int i = 0; i < sim.entities.size(); i++)
      {
         delete sim.entities[i];
         sim.entities[i] = nullptr;
      }
   }

};
