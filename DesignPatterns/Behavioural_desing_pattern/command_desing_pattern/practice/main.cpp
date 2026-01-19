#include <iostream>
#include "init.h"
#include "remote.h"
using namespace std;

int main()
{
  Remote *remote = new Remote();
  Initialize *init = new Initialize(remote);

  remote->executeTask(0);
  remote->executeTask(1);
  remote->executeTask(2);
  remote->executeTask(4);
  remote->executeTask(4);
  remote->executeTask(5);
  remote->executeTask(3);
  delete init;
  delete remote;
}