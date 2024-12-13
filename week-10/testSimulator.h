

#pragma once

#include "angle.h"
#include "entity.h"
#include "position.h"
#include "simulator.h"
#include "unitTest.h"
#include "velocity.h"
#include <cmath>
#include <vector>

/*******************************
* TEST SIMULATOR
********************************/
class TestSimulator: public UnitTest
{
public:
   void run()
   {
      initializeSatellites();

      // collision
      collision_horizontalFar();
      collision_horizontalClose();
      collision_horizontalContact();
      collision_verticalFar();
      collision_verticalClose();
      collision_verticalContact();
      collision_diagonalFar();
      collision_diagonalClose();
      collision_diagonalContact();

      report("Simulator");
   }

private:
   /****************************************
   * COLLISION HORIZONTAL FAR
   * Test Satellites are instantiated with
   *  correct values.
   *****************************************/
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
      assertUnit(sim.entities[0]->position.x == -450 * Position::metersFromPixels);
      assertUnit(sim.entities[0]->position.y == 450 * Position::metersFromPixels);
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
      assertUnit(sim.entities[3]->velocity.dx == 1940.00);
      assertUnit(sim.entities[3]->velocity.dy == 3360.18);
      assertUnit(sim.entities[3]->angle.radians == 0.0);

      // GPS satellite 4
      assertUnit(sim.entities[4]->position.x == 0.0);
      assertUnit(sim.entities[4]->position.y == -26560000.0);
      assertUnit(sim.entities[4]->velocity.dx == 3880.0);
      assertUnit(sim.entities[4]->velocity.dy == 0.0);
      assertUnit(sim.entities[4]->angle.radians == 0.0);

      // GPS satellite 5
      assertUnit(sim.entities[5]->position.x == -23001634.72);
      assertUnit(sim.entities[5]->position.y == -13280000.0 );
      assertUnit(sim.entities[5]->velocity.dx == 1940.00);
      assertUnit(sim.entities[5]->velocity.dy == -3360.18);
      assertUnit(sim.entities[5]->angle.radians == 0.0);

      // GPS satellite 6
      assertUnit(sim.entities[6]->position.x == -23001634.72);
      assertUnit(sim.entities[6]->position.y == 13280000.0 );
      assertUnit(sim.entities[6]->velocity.dx == -1940.00);
      assertUnit(sim.entities[6]->velocity.dy == -3360.18);
      assertUnit(sim.entities[6]->angle.radians == 0.0);

      // initial Hubble satellite
      assertUnit(sim.entities[7]->position.x == 0.0);
      assertUnit(sim.entities[7]->position.y == -42164000.0);
      assertUnit(sim.entities[7]->velocity.dx == 3100.0);
      assertUnit(sim.entities[7]->velocity.dy == 0.0);
      assertUnit(sim.entities[7]->angle.radians == 0.0);

      // sputnik
      assertUnit(sim.entities[8]->position.x == -36515095.13);
      assertUnit(sim.entities[8]->position.y == 21082000.0);
      assertUnit(sim.entities[8]->velocity.dx == 2050.0);
      assertUnit(sim.entities[8]->velocity.dy == 2684.68);
      assertUnit(sim.entities[8]->angle.radians == 0.0);

      // starlink
      assertUnit(sim.entities[9]->position.x == 0.0);
      assertUnit(sim.entities[9]->position.y == -13020000.0);
      assertUnit(sim.entities[9]->velocity.dx == 5800.0);
      assertUnit(sim.entities[9]->velocity.dy == 0.0);
      assertUnit(sim.entities[9]->angle.radians == 0.0);

      // Dragon
      assertUnit(sim.entities[10]->position.x == 0.0);
      assertUnit(sim.entities[10]->position.y == 8000000.0);
      assertUnit(sim.entities[10]->velocity.dx == -7900.0);
      assertUnit(sim.entities[10]->velocity.dy == 0.0);
      assertUnit(sim.entities[10]->angle.radians == 0.0);

      // teardown
      for (int i = 0; i < sim.entities.size(); i++)
      {
         delete sim.entities[i];
         sim.entities[i] = nullptr;
      }
   }

   /****************************************
   * COLLISION HORIZONTAL FAR
   * Input: pos1(50, 0), pos2(-50, 0)
   * Output: isBroken = false (both), entities.size = 2
   *****************************************/
   void collision_horizontalFar()
   {
      // set up
      Simulator sim;
      Angle a;
      a.radians = 0.0;
      Velocity vel;
      vel.dx = 0.0;
      vel.dy = 0.0;
      Position pos1;
      pos1.x = 50.0;
      pos1.y = 0.0;
      sim.entities.push_back(new EntityDerived(pos1, vel, a));
      sim.entities[0]->radius = 10.0;
      Position pos2;
      pos2.x = -50.0;
      pos2.y = 0.0;
      sim.entities.push_back(new EntityDerived(pos2, vel, a));
      sim.entities[1]->radius = 10.0;

      // exercise
      for (int i = 0; i < 2; i++) {
         sim.checkCollision(i);
      }

      // verify
      assertEquals(sim.entities.size(), 2);

      assertUnit(sim.entities[0]->isBroken == false);
      assertUnit(sim.entities[0]->position.x == 50.0);
      assertUnit(sim.entities[0]->position.y == 0.0);
      assertUnit(sim.entities[0]->velocity.dx == 0.0);
      assertUnit(sim.entities[0]->velocity.dy == 0.0);
      assertUnit(sim.entities[0]->angle.radians == 0.0);
      assertUnit(sim.entities[0]->radius == 10.0);

      assertUnit(sim.entities[1]->isBroken == false);
      assertUnit(sim.entities[1]->position.x == -50.0);
      assertUnit(sim.entities[1]->position.y == 0.0);
      assertUnit(sim.entities[1]->velocity.dx == 0.0);
      assertUnit(sim.entities[1]->velocity.dy == 0.0);
      assertUnit(sim.entities[1]->angle.radians == 0.0);
      assertUnit(sim.entities[1]->radius == 10.0);

      // tear down
      delete sim.entities[0];
      delete sim.entities[1];
      sim.entities[0] = nullptr;
      sim.entities[1] = nullptr;
   }


   /****************************************
   * COLLISION HORIZONTAL CLOSE
   * Input: pos1(10, 0), pos2(-10, 0)
   * Output: isBroken = false (both), entities.size = 2
   *****************************************/
   void collision_horizontalClose()
   {
      // set up
      Simulator sim;
      Angle a;
      a.radians = 0.0;
      Velocity vel;
      vel.dx = 0.0;
      vel.dy = 0.0;
      Position pos1;
      pos1.x = 10.0;
      pos1.y = 0.0;
      sim.entities.push_back(new EntityDerived(pos1, vel, a));
      sim.entities[0]->radius = 10.0;
      Position pos2;
      pos2.x = -10.0;
      pos2.y = 0.0;
      sim.entities.push_back(new EntityDerived(pos2, vel, a));
      sim.entities[1]->radius = 10.0;

      // exercise
      for (int i = 0; i < 2; i++) {
         sim.checkCollision(i);
      }

      // verify
      assertEquals(sim.entities.size(), 2);

      assertUnit(sim.entities[0]->isBroken == false);
      assertUnit(sim.entities[0]->position.x == 10.0);
      assertUnit(sim.entities[0]->position.y == 0.0);
      assertUnit(sim.entities[0]->velocity.dx == 0.0);
      assertUnit(sim.entities[0]->velocity.dy == 0.0);
      assertUnit(sim.entities[0]->angle.radians == 0.0);
      assertUnit(sim.entities[0]->radius == 10.0);

      assertUnit(sim.entities[1]->isBroken == false);
      assertUnit(sim.entities[1]->position.x == -10.0);
      assertUnit(sim.entities[1]->position.y == 0.0);
      assertUnit(sim.entities[1]->velocity.dx == 0.0);
      assertUnit(sim.entities[1]->velocity.dy == 0.0);
      assertUnit(sim.entities[1]->angle.radians == 0.0);
      assertUnit(sim.entities[1]->radius == 10.0);

      // tear down
      delete sim.entities[0];
      delete sim.entities[1];
      sim.entities[0] = nullptr;
      sim.entities[1] = nullptr;
   }


   /****************************************
   * COLLISION HORIZONTAL CONTACT
   * Input: pos1(5, 0), pos2(-5, 0)
   * Output: entities.size = 0
   *****************************************/
   void collision_horizontalContact()
   {
      // set up
      Simulator sim;
      Angle a;
      a.radians = 0.0;
      Velocity vel;
      vel.dx = 0.0;
      vel.dy = 0.0;
      Position pos1;
      pos1.x = 5.0;
      pos1.y = 0.0;
      sim.entities.push_back(new EntityDerived(pos1, vel, a));
      sim.entities[0]->radius = 10.0;
      Position pos2;
      pos2.x = -5.0;
      pos2.y = 0.0;
      sim.entities.push_back(new EntityDerived(pos2, vel, a));
      sim.entities[1]->radius = 10.0;

      // exercise
      for (int i = 0; i < 2; i++) {
         sim.checkCollision(i);
      }

      // verify
      assertEquals(sim.entities.size(), 0);
   }

   /****************************************
   * COLLISION VERTICAL FAR
   * Input: pos1(0, 50), pos2(0, -50)
   * Output: isBroken = false (both), entities.size = 2
   *****************************************/
   void collision_verticalFar()
   {
      // set up
      Simulator sim;
      Angle a;
      a.radians = 0.0;
      Velocity vel;
      vel.dx = 0.0;
      vel.dy = 0.0;
      Position pos1;
      pos1.x = 0.0;
      pos1.y = 50.0;
      sim.entities.push_back(new EntityDerived(pos1, vel, a));
      sim.entities[0]->radius = 10.0;
      Position pos2;
      pos2.x = 0.0;
      pos2.y = -50.0;
      sim.entities.push_back(new EntityDerived(pos2, vel, a));
      sim.entities[1]->radius = 10.0;

      // exercise
      for (int i = 0; i < 2; i++) {
         sim.checkCollision(i);
      }

      // verify
      assertEquals(sim.entities.size(), 2);

      assertUnit(sim.entities[0]->isBroken == false);
      assertUnit(sim.entities[0]->position.x == 0.0);
      assertUnit(sim.entities[0]->position.y == 50.0);
      assertUnit(sim.entities[0]->velocity.dx == 0.0);
      assertUnit(sim.entities[0]->velocity.dy == 0.0);
      assertUnit(sim.entities[0]->angle.radians == 0.0);
      assertUnit(sim.entities[0]->radius == 10.0);

      assertUnit(sim.entities[1]->isBroken == false);
      assertUnit(sim.entities[1]->position.x == 0.0);
      assertUnit(sim.entities[1]->position.y == -50.0);
      assertUnit(sim.entities[1]->velocity.dx == 0.0);
      assertUnit(sim.entities[1]->velocity.dy == 0.0);
      assertUnit(sim.entities[1]->angle.radians == 0.0);
      assertUnit(sim.entities[1]->radius == 10.0);

      // tear down
      delete sim.entities[0];
      delete sim.entities[1];
      sim.entities[0] = nullptr;
      sim.entities[1] = nullptr;
   }

   /****************************************
   * COLLISION VERTICAL CLOSE
   * Input: pos1(0, 10), pos2(0, -10)
   * Output: isBroken = false (both), entities.size = 2
   *****************************************/
   void collision_verticalClose()
   {
      // set up
      Simulator sim;
      Angle a;
      a.radians = 0.0;
      Velocity vel;
      vel.dx = 0.0;
      vel.dy = 0.0;
      Position pos1;
      pos1.x = 0.0;
      pos1.y = 10.0;
      sim.entities.push_back(new EntityDerived(pos1, vel, a));
      sim.entities[0]->radius = 10.0;
      Position pos2;
      pos2.x = 0.0;
      pos2.y = -10.0;
      sim.entities.push_back(new EntityDerived(pos2, vel, a));
      sim.entities[1]->radius = 10.0;

      // exercise
      for (int i = 0; i < 2; i++) {
         sim.checkCollision(i);
      }

      // verify
      assertEquals(sim.entities.size(), 2);

      assertUnit(sim.entities[0]->isBroken == false);
      assertUnit(sim.entities[0]->position.x == 0.0);
      assertUnit(sim.entities[0]->position.y == 10.0);
      assertUnit(sim.entities[0]->velocity.dx == 0.0);
      assertUnit(sim.entities[0]->velocity.dy == 0.0);
      assertUnit(sim.entities[0]->angle.radians == 0.0);
      assertUnit(sim.entities[0]->radius == 10.0);

      assertUnit(sim.entities[1]->isBroken == false);
      assertUnit(sim.entities[1]->position.x == 0.0);
      assertUnit(sim.entities[1]->position.y == -10.0);
      assertUnit(sim.entities[1]->velocity.dx == 0.0);
      assertUnit(sim.entities[1]->velocity.dy == 0.0);
      assertUnit(sim.entities[1]->angle.radians == 0.0);
      assertUnit(sim.entities[1]->radius == 10.0);

      // tear down
      delete sim.entities[0];
      delete sim.entities[1];
      sim.entities[0] = nullptr;
      sim.entities[1] = nullptr;
   }


   /****************************************
   * COLLISION VERTICAL CONTACT
   * Input: pos1(0, 5), pos2(0, -5)
   * Output: entities.size = 0
   *****************************************/
   void collision_verticalContact()
   {
      // set up
      Simulator sim;
      Angle a;
      a.radians = 0.0;
      Velocity vel;
      vel.dx = 0.0;
      vel.dy = 0.0;
      Position pos1;
      pos1.x = 0.0;
      pos1.y = 5.0;
      sim.entities.push_back(new EntityDerived(pos1, vel, a));
      sim.entities[0]->radius = 10.0;
      Position pos2;
      pos2.x = 0.0;
      pos2.y = -5.0;
      sim.entities.push_back(new EntityDerived(pos2, vel, a));
      sim.entities[1]->radius = 10.0;

      // exercise
      for (int i = 0; i < 2; i++) {
         sim.checkCollision(i);
      }

      // verify
      assertEquals(sim.entities.size(), 0);
   }

   /****************************************
   * COLLISION DIAGONAL FAR
   * Input: pos1(10, 10), pos2(-10, -10)
   * Output: isBroken = false (both), entities.size = 2
   *****************************************/
   void collision_diagonalFar()
   {
      // set up
      Simulator sim;
      Angle a;
      a.radians = 0.0;
      Velocity vel;
      vel.dx = 0.0;
      vel.dy = 0.0;
      Position pos1;
      pos1.x = 10.0;
      pos1.y = 10.0;
      sim.entities.push_back(new EntityDerived(pos1, vel, a));
      sim.entities[0]->radius = 10.0;
      Position pos2;
      pos2.x = -10.0;
      pos2.y = -10.0;
      sim.entities.push_back(new EntityDerived(pos2, vel, a));
      sim.entities[1]->radius = 10.0;

      // exercise
      for (int i = 0; i < 2; i++) {
         sim.checkCollision(i);
      }

      // verify
      assertEquals(sim.entities.size(), 2);

      assertUnit(sim.entities[0]->isBroken == false);
      assertUnit(sim.entities[0]->position.x == 10.0);
      assertUnit(sim.entities[0]->position.y == 10.0);
      assertUnit(sim.entities[0]->velocity.dx == 0.0);
      assertUnit(sim.entities[0]->velocity.dy == 0.0);
      assertUnit(sim.entities[0]->angle.radians == 0.0);
      assertUnit(sim.entities[0]->radius == 10.0);

      assertUnit(sim.entities[1]->isBroken == false);
      assertUnit(sim.entities[1]->position.x == -10.0);
      assertUnit(sim.entities[1]->position.y == -10.0);
      assertUnit(sim.entities[1]->velocity.dx == 0.0);
      assertUnit(sim.entities[1]->velocity.dy == 0.0);
      assertUnit(sim.entities[1]->angle.radians == 0.0);
      assertUnit(sim.entities[1]->radius == 10.0);

      // tear down
      delete sim.entities[0];
      delete sim.entities[1];
      sim.entities[0] = nullptr;
      sim.entities[1] = nullptr;
   }

   /****************************************
   * COLLISION DIAGONAL CLOSE
   * Input: pos1(7.07, 7.07), pos2(-7.07, -7.07)
   *        7.07 = rounded value of 10 / sqrt(2)
   * Output: isBroken = false (both), entities.size = 2
   *****************************************/
   void collision_diagonalClose()
   {
      // set up
      double positionValue = 10.0 / sqrt(2.0); // anti redundant math
      Simulator sim;
      Angle a;
      a.radians = 0.0;
      Velocity vel;
      vel.dx = 0.0;
      vel.dy = 0.0;
      Position pos1;
      pos1.x = positionValue;
      pos1.y = positionValue;
      sim.entities.push_back(new EntityDerived(pos1, vel, a));
      sim.entities[0]->radius = 10.0;
      Position pos2;
      pos2.x = -positionValue;
      pos2.y = -positionValue;
      sim.entities.push_back(new EntityDerived(pos2, vel, a));
      sim.entities[1]->radius = 10.0;

      // exercise
      for (int i = 0; i < 2; i++) {
         sim.checkCollision(i);
      }

      // verify
      assertEquals(sim.entities.size(), 2);

      assertUnit(sim.entities[0]->isBroken == false);
      assertUnit(sim.entities[0]->position.x == positionValue);
      assertUnit(sim.entities[0]->position.y == positionValue);
      assertUnit(sim.entities[0]->velocity.dx == 0.0);
      assertUnit(sim.entities[0]->velocity.dy == 0.0);
      assertUnit(sim.entities[0]->angle.radians == 0.0);
      assertUnit(sim.entities[0]->radius == 10.0);

      assertUnit(sim.entities[1]->isBroken == false);
      assertUnit(sim.entities[1]->position.x == -positionValue);
      assertUnit(sim.entities[1]->position.y == -positionValue);
      assertUnit(sim.entities[1]->velocity.dx == 0.0);
      assertUnit(sim.entities[1]->velocity.dy == 0.0);
      assertUnit(sim.entities[1]->angle.radians == 0.0);
      assertUnit(sim.entities[1]->radius == 10.0);

      // tear down
      delete sim.entities[0];
      delete sim.entities[1];
      sim.entities[0] = nullptr;
      sim.entities[1] = nullptr;
   }


   /****************************************
   * COLLISION DIAGONAL CONTACT
   * Input: pos1(5, 5), pos2(-5, -5)
   * Output: entities.size = 0
   *****************************************/
   void collision_diagonalContact()
   {
      // set up
      Simulator sim;
      Angle a;
      a.radians = 0.0;
      Velocity vel;
      vel.dx = 0.0;
      vel.dy = 0.0;
      Position pos1;
      pos1.x = 5.0;
      pos1.y = 5.0;
      sim.entities.push_back(new EntityDerived(pos1, vel, a));
      sim.entities[0]->radius = 10.0;
      Position pos2;
      pos2.x = -5.0;
      pos2.y = -5.0;
      sim.entities.push_back(new EntityDerived(pos2, vel, a));
      sim.entities[1]->radius = 10.0;

      // exercise
      for (int i = 0; i < 2; i++) {
         sim.checkCollision(i);
      }

      // verify
      assertEquals(sim.entities.size(), 0);
   }

};

