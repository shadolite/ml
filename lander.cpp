/***********************************************************************
 * Source File:
 *    Lander: Class definition for lander object
 * Author:
 *    Amy Chambers
 * Summary:
 *    Everythibng needed for manipulation of the lander object.
 ************************************************************************/

#include "lander.h"
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

//float const Lander::gravity = 0.1;
Lander::Lander()  
{
   lPoint.setX(170.0);
   lPoint.setY(170.0);
   velocity.setDx(0.0);
   velocity.setDy(0.0);
   setAlive(true);
   setLanded(false);
   setFuel(500);   
}
Lander::Lander(Point lPoint, Velocity velocity, bool alive,
               bool landed, int fuel, bool thrust, float gravity) :
      lPoint(170.0, 170.0), velocity(0.2, 0.0), alive(true),
      landed(false), fuel(500), thrust(true), gravity(0.1)
{
   setPoint(lPoint);
   setVelocity(velocity);
   setAlive(alive);
   setLanded(landed);
   setFuel(fuel);
   setThrust(thrust);
   setGravity(gravity);
}

/******************************************
 * setThrust
 * Set initial thrust capabilities
 *****************************************/
void Lander::setThrust(bool thrust)
{
   this->thrust = thrust;
}

/******************************************
 * setVelocity
 * Set initial velocity
 *****************************************/
void Lander::setVelocity(Velocity velocity)
{
   this->velocity = velocity;
}

/******************************************
 * setGravity
 * Set gravity
 *****************************************/
void Lander::setGravity(float gravity)
{
   this->gravity = gravity;
}

/******************************************
 * setPoint
 * Set initial point
 *****************************************/
void Lander::setPoint(Point lPoint)
{
   this->lPoint = lPoint;
}

/******************************************
 * getPoint
 * Return current point
 *****************************************/
Point Lander::getPoint() const
{
   return lPoint;
}

/******************************************
 * getVelocity
 * Return current velocity
 *****************************************/
Velocity Lander::getVelocity() const
{
   return velocity;
}

/******************************************
 * isAlive
 * Return alive status
 *****************************************/
bool Lander::isAlive()
{
   return alive;
}

/******************************************
 * isLanded
 * Return landed status
 *****************************************/
bool Lander::isLanded()
{
   return landed;
}

/******************************************
 * getFuel
 * Return remaining fuel
 *****************************************/
int Lander::getFuel()
{
   return fuel;
}

/******************************************
 * canThrust
 * Return thrust capability
 *****************************************/
bool Lander::canThrust()
{
   return thrust;
}

/******************************************
 * setLanded
 * Set landed status
 *****************************************/
void Lander::setLanded(const bool landed)
{
   this->landed = landed;
}

/******************************************
 * setAlive
 * Set alive status
 *****************************************/
void Lander::setAlive(const bool alive)
{
   this->alive = alive;
}

/******************************************
 * setFuel
 * Set remaining amount of fuel
 *****************************************/
void Lander::setFuel(const int fuel)
{
   this->fuel = fuel;
}

/******************************************
 * applyGravity
 * Apply gravity to lander object
 *****************************************/
void Lander::applyGravity(const float gravity)
{
   velocity.setDy(velocity.getDy() - gravity);
}

/******************************************
 * applyThrustLeft
 * Apply left thrust to velocity
 *****************************************/
void Lander::applyThrustLeft()
{
   if (alive && Lander::canThrust() && !landed)
   {
      fuel--;
      velocity.setDx(velocity.getDx() + 0.1); 
   };
   
}

/******************************************
 * applyThrustRight
 * Apply right thrust to velocity
 *****************************************/
void Lander::applyThrustRight()
{
   if (alive && Lander::canThrust() && !landed)
   {
      fuel--;
      velocity.setDx(velocity.getDx() - 0.1); 
   };   
}

/******************************************
 * applyThrustBottom
 * Apply bottom thrust to velocity
 *****************************************/
void Lander::applyThrustBottom()
{
   if (alive && Lander::canThrust() && !landed)
   {
      fuel -= 3;
      velocity.setDy(velocity.getDy() + 0.3); 
   };
}

/******************************************
 * advance
 * Advance the lander with velocity and gravity
 *****************************************/
void Lander::advance()
{
   lPoint.setX(lPoint.getX() + velocity.getDx());
   lPoint.setY(lPoint.getY() + velocity.getDy());
}

/******************************************
 * draw
 * Draw lander on screen
 *****************************************/
void Lander::draw()
{
    drawLander(lPoint);
}
