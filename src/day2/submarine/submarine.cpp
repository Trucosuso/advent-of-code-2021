#include "submarine.h"

Submarine::Submarine (const int &x, const int &y, const int &aim) : x (x), y (y), aim (aim) {}

// Setters
void
Submarine::setX (const int &x)
{
  this->x = x;
}

void
Submarine::setY (const int &y)
{
  this->y = y;
}

// Methods
void
Submarine::oldForward (const int distance)
{
  this->x += distance;
}

void
Submarine::oldDown (const int distance)
{
  this->y += distance;
}

void
Submarine::oldUp (const int distance)
{
  this->y -= distance;
}

void
Submarine::forward (const int distance)
{
  this->x += distance;
  this->y += this->aim * distance;
}

void
Submarine::down (const int change)
{
  this->aim += change;
}

void
Submarine::up (const int change)
{
  this->aim -= change;
}