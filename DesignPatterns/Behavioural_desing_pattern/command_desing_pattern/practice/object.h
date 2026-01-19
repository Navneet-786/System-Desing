#ifndef OBJECTS
#define OBJECTS

#include <iostream>
// light
class Light
{
public:
  void on()
  {
    std::cout << "---BULB ON---" << std::endl;
  }
  void off()
  {
    std::cout << "---BULB OFF---" << std::endl;
  }
};

// fan
class Fan
{
  int speed;

public:
  Fan() : speed(0) {};

  // on
  // off
  void on()
  {
    std::cout << "---FAN ON---" << std::endl;
  }
  void off()
  {
    std::cout << "---FAN OFF---" << std::endl;
  }
  // speedup
  void speedUp()
  {
    if (speed == 5)
    {
      this->speed = 0;
    }
    else
    {
      this->speed++;
    }
    std::cout << "currentSpeed: " << speed << std::endl;
  }
  // speeddown
  void speedDown()
  {
    if (speed == 0)
    {
      this->speed = 5;
    }
    else
    {
      this->speed--;
    }

    std::cout << "currentSpeed: " << speed << std::endl;
  }
};

#endif