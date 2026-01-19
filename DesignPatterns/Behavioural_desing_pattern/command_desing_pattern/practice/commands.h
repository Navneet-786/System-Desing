#ifndef COMMANDS
#define COMMANDS

#include <iostream>
#include "object.h"

// command interface
class Command
{
public:
  virtual void execute() = 0;
  virtual ~Command() = default;
};

// light commands

class LightOnCommand : public Command
{
  Light *light;

public:
  LightOnCommand(Light *l1) : light(l1) {};

  void execute() override
  {
    light->on();
  }
};

class LightOffCommand : public Command
{
  Light *light;

public:
  LightOffCommand(Light *l1) : light(l1) {};

  void execute() override
  {
    light->off();
  }
};

// fan commands

class FanOnCommand : public Command
{
  Fan *fan;

public:
  FanOnCommand(Fan *fan) : fan(fan) {};
  void execute() override
  {
    fan->on();
  }
};

class FanOffCommand : public Command
{
  Fan *fan;

public:
  FanOffCommand(Fan *fan) : fan(fan) {};
  void execute() override
  {
    fan->off();
  }
};

class FanSpeedUpCommand : public Command
{
  Fan *fan;

public:
  FanSpeedUpCommand(Fan *fan) : fan(fan) {};
  void execute() override
  {
    fan->speedUp();
  }
};

class FanSpeedDownCommand : public Command
{
  Fan *fan;

public:
  FanSpeedDownCommand(Fan *fan) : fan(fan) {};
  void execute() override
  {
    fan->speedDown();
  }
};

#endif