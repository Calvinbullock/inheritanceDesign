#include "entity.h"
#include <math.h>

// orbit the GPS satelite //TODO: fix comments
void Entity::orbit(double time, Acceleration accel)
{
   position.add(accel, velocity, time);
   velocity.add(accel, time);
}

void Entity::rotate(double delta)
{
   angle.add(delta);

}
