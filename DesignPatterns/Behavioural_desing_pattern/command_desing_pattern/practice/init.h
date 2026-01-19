#ifndef INIT
#define INIT

#include <iostream>
#include "remote.h"
#include "commands.h"
#include "object.h"
class Initialize
{
  Remote *remote;

public:
  Initialize(Remote *remote)
  {
    this->remote = remote;
    // creating objects
    Light *light = new Light();
    Fan *fan = new Fan();

    // comands
    Command *lightOn = new LightOnCommand(light);
    Command *lightOff = new LightOffCommand(light);

    Command *fanOn = new FanOnCommand(fan);
    Command *fanOff = new FanOffCommand(fan);
    Command *fanSpeedUp = new FanSpeedUpCommand(fan);
    Command *fanSpeedDown = new FanSpeedDownCommand(fan);

    remote->addCommand(lightOn);
    remote->addCommand(lightOff);

    remote->addCommand(fanOn);
    remote->addCommand(fanOff);
    remote->addCommand(fanSpeedUp);
    remote->addCommand(fanSpeedDown);
  }

  ~Initialize()
  {
  }
};

#endif