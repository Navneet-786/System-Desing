#ifndef REMOTE
#define REMOTE

#include <iostream>
#include <vector>
#include "commands.h"

class Remote
{
  std::vector<Command *> commands;

public:
  void addCommand(Command *command)
  {
    // remember the sequence of commmands that you enter
    commands.push_back(command);
  }

  void executeTask(int index)
  {
    if (index < 0 || index == commands.size())
    {
      std::cout << "Not working" << std::endl;
      return;
    }

    commands[index]->execute();
  }
};

#endif