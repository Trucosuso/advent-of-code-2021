#pragma once

class Submarine
{
private:
  int x;
  int y;
  int aim;

public:
  Submarine (const int &x = 0, const int &y = 0, const int &aim = 0);

  // Getters
  inline const int &
  getX () const
  {
    return this->x;
  }
  inline const int &
  getY () const
  {
    return this->y;
  }

  // Setters
  void setX (const int &x);
  void setY (const int &y);

  // Methods
  void oldForward (int distance);
  void oldDown (int distance);
  void oldUp (int distance);

  void forward (int distance);
  void down (int change);
  void up (int change);
};
