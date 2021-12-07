#include "submarine.h"

Submarine::Submarine (const int &x, const int &y) : x (x), y (y) {}

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
Submarine::forward (const int distance)
{
  this->x += distance;
}

void
Submarine::down (const int distance)
{
  this->y += distance;
}

void
Submarine::up (const int distance)
{
  this->y -= distance;
}
