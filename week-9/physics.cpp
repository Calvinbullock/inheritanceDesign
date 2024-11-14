
/******************************************************************
* GET GRAVITY : magnitude of acceleration due to gravity at an altitude
*
* gh = magnitude of acceleration due to gravity at an altitude(h)
* g = gravity at sea level : 9.80665 m / s2
* r = radius of the earth : 6, 378, 000 m
* h = height above the earth in meters

* gh = g * ((r/(r+h)) * (r/(r+h)))
*********************************************************/
double getGravity(double g, double r, double h)
{
   return g * ((r / (r + h)) * (r / (r + h)));
}

/****************************************************
* GET DIRECTION GRAVITY: direction of the pull of gravity, in radians
*
* xe = horizontal position of the center of the earth: 0 m
* ye = vertical position of the center of the earth: 0 m
* xs = horizontal position of the satellite in meters
* ys = vertical position of the satellite in meters
*
* d = atan(xe - xs, ye - ys)
*****************************************************/
double getDirectionGravity(double xe, double ye, double xs, double ys)
{
   return atan2(xe - xs, ye - ys);
}

/**********************************************
* GETDDX: get horizontal component of acceleration
*
* ddx = horizontal component of acceleration
* a = total acceleration
* angle = angle(0° is up) of the direction of acceleration
*
* ddx = a * sin(angle)
*********************************************************/
double getDDX(double a, double angle)
{
   return a * sin(angle);
}

/**********************************************
* GETDDY: get vertical component of acceleration
*
* ddy = vertical component of acceleration
* a = total acceleration
* angle = angle (0° is up) of the direction of acceleration
*
* ddy = a * cos(angle)
*********************************************************/
double getDDY(double a, double angle)
{
   return a * cos(angle);
}

/********************************************************
* GET AXIS DISTANCE : horizontal or vertical position at time t(m)
*
* x0 = initial horizontal position (m)
* dx = horizontal component of velocity (m/s)
* ddx = horizontal component of acceleration (m/s2)
* t = time (s)
*
* * xt = horizontal position at time t (m)
*
* xt = x0 + dx * t + ½ * ddx * t^2
*********************************************************/
double getAxisDistance(double x0, double dx, double ddx, double t)
{
   return x0 + dx * t + (1/2) * ddx * (t * t);
}


/********************************************************
* GET AXIS VELOCITY : horizontal or vertical velocity at time t(m/s)
*
* dx0 = initial horizontal velocity(m / s)
* ddx = horizontal component of acceleration(m / s2)
* t = time(s)
*
* dxt = horizontal velocity at time t(m / s)
*
* dxt = dx0 + ddx t
*********************************************************/
double getAxisVelocity(double dx0, double ddx, double t)
{
   return dx0 + (ddx * t);
}


// Gravity
double gravity = getGravity(GRAVITY_SEA_LEVEL, RADIUS_EARTH, EARTH_SURFACE);
double gravityAngle = getDirectionGravity(0.0, 0.0, currXPos, currYPos);

// Acceleration
double ddx = getDDX(gravity, gravityAngle);
double ddy = getDDY(gravity, gravityAngle);

// Velocity
DX = getAxisVelocity(DX, ddx, TIME);
DY = getAxisVelocity(DY, ddy, TIME);

// new distance
double xPos = getAxisDistance(currXPos, DX, ddx, TIME);
double yPos = getAxisDistance(currYPos, DY, ddy, TIME);

// orbit the GPS satelite
pDemo->ptGPS.setMetersX(getAxisDistance(currXPos, DX, ddx, TIME));
pDemo->ptGPS.setMetersY(getAxisDistance(currYPos, DY, ddy, TIME));



