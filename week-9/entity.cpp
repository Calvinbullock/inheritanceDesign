#include "entity.h"
#include <math.h>

// orbit the GPS satelite //TODO: fix comments
void Entity::orbit(double time, double grav, Acceleration accel)
{
   velocity.add(accel, time);

   position.add(accel, velocity, time);
}

void Entity::rotate(double delta)
{
   angle.add(delta);

}
