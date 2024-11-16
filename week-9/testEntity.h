/***********************************************************************
 * Header File:
 *    TEST EntityDerived
 * Author:
 *    Daniel Malasky, Calvin Bullock
 * Summary:
 *    All the unit tests for EntityDerived
 ************************************************************************/

#pragma once


#include "entity.h"
#include "unitTest.h"

/*******************************
* TEST EntityDerived
* A friend class for EntityDerived which contains the EntityDerived unit tests
********************************/
class TestEntity : public UnitTest
{
public:
   void run()
   {
      // getters
      getPosition();
      getVelocity();
      getIsBroken();
      getWidth();
      getAngle();

      // setters
      setPosition();
      setVelocity();
      setIsBroken();
      setWidth();
      setAngle();

      report("Entity");
   }

private:
    /*********************************************
    * name:  GET POSITION
    * input:  entity with position (10.0, 20.0)
    * output: position (10.0, 20.0)
    *********************************************/
   void getPosition() {
      // Setup
      Position pos(10.0, 20.0);
      Velocity vel(3.0, 4.0);
      Angle angle(45.0);
      EntityDerived entity(pos, vel, angle);

      // Exercise
      Position result = entity.getPosition();

      // Verify
      assertEquals(result.x, 10.0);
      assertEquals(result.y, 20.0);
   }

   /*********************************************
    * name:  GET VELOCITY
    * input:  entity with velocity (3.0, 4.0)
    * output: velocity (3.0, 4.0)
    *********************************************/
   void getVelocity() {
      // Setup
      Position pos(10.0, 20.0);
      Velocity vel(3.0, 4.0);
      Angle angle(45.0);
      EntityDerived entity(pos, vel, angle);

      // Exercise
      Velocity result = entity.getVelocity();

      // Verify
      assertEquals(result.dx, 3.0);
      assertEquals(result.dy, 4.0);
   }

   /*********************************************
    * name:  GET IS BROKEN
    * input:  entity with isBroken = true
    * output: isBroken = true
    *********************************************/
   void getIsBroken() {
      // Setup
      EntityDerived entity;
      entity.setIsBroken(true);

      // Exercise
      bool result = entity.getIsBroken();

      // Verify
      assertEquals(result, true);
   }

   /*********************************************
    * name:  GET WIDTH
    * input:  entity with width = 10.0
    * output: width = 10.0
    *********************************************/
   void getWidth() {
      // Setup
      Position pos(10.0, 20.0);
      Velocity vel(3.0, 4.0);
      Angle angle(45.0);
      EntityDerived entity(pos, vel, angle, false, 10);

      // Exercise
      double result = entity.getWidth();

      // Verify
      assertEquals(result, 10.0);
   }

   /*********************************************
    * name:  GET ANGLE
    * input:  entity with angle = 45.0 degrees
    * output: angle = 0.785398 degrees
    *********************************************/
   void getAngle() {
      // Setup
      Position pos(10.0, 20.0);
      Velocity vel(3.0, 4.0);
      Angle angle(45.0);
      EntityDerived entity(pos, vel, angle);

      // Exercise
      Angle result = entity.getAngle();

      // Verify
      assertEquals(result.radians, 0.785398);
   }

   /*********************************************
    * name:  SET POSITION
    * input:  entity with initial position, new position (50.0, 60.0)
    * output: entity with position (50.0, 60.0)
    *********************************************/
   void setPosition() {
      // Setup
      EntityDerived entity;
      Position newPos(50.0, 60.0);

      // Exercise
      entity.setPosition(newPos);

      // Verify
      assertEquals(entity.position.x, 50.0);
      assertEquals(entity.position.y, 60.0);
   }

   /*********************************************
    * name:  SET VELOCITY
    * input:  entity with initial velocity, new velocity (10.0, 15.0)
    * output: entity with velocity (10.0, 15.0)
   *********************************************/
   void setVelocity() {
      // Setup
      EntityDerived entity;
      Velocity newVel(10.0, 15.0);

      // Exercise
      entity.setVelocity(newVel);

      // Verify
      assertEquals(entity.velocity.dx, 10.0);
      assertEquals(entity.velocity.dy, 15.0);
   }

   /*********************************************
    * name:  SET IS BROKEN
    * input:  entity with initial isBroken state
    * output: entity with isBroken = true
    *********************************************/
   void setIsBroken() {
      // Setup
      EntityDerived entity;

      // Exercise
      entity.setIsBroken(true);

      // Verify
      assertUnit(entity.isBroken);
   }
   /*********************************************
    * name:  SET WIDTH
    * input:  entity with initial width
    * output: entity with width = 2
    *********************************************/
   void setWidth() {
      // Setup
      EntityDerived entity;

      // Exercise
      entity.setWidth(20.0);

      // Verify
      assertEquals(entity.width, 20.0);
   }

   /*********************************************
    * name:  SET ANGLE
    * input:  entity with initial angle, new angle = 90.0 degrees
    * output: entity with angle = 1.5708 radians
    *********************************************/
   void setAngle() {
      // Setup
      EntityDerived entity;
      Angle newAngle(90.0);

      // Exercise
      entity.setAngle(newAngle);

      // Verify
      assertEquals(entity.angle.radians, 1.5708);
   }
};
