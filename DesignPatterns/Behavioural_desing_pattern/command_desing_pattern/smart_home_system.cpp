#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

// components->Light , Fan, TV
class Light
{
public:
  void on()
  {
    cout << "Light ON...." << endl;
  }

  void off()
  {
    cout << "Light Off...." << endl;
  }
};

class Fan
{
public:
  void on()
  {
    cout << "Fan ON...." << endl;
  }

  void off()
  {
    cout << "Fan Off...." << endl;
  }
};

class Television
{
  int volume = 0;

public:
  void volumeIncrease()
  {
    this->volume++;
    cout << "Current Tv volume is : " << this->volume << endl;
  }

  void volumeDecrease()
  {
    if (this->volume > 0)
    {
      this->volume--;
    }
    cout << "Current Tv volume is : " << this->volume << endl;
  }

  void on()
  {
    cout << "TV ON...." << endl;
  }

  void off()
  {
    cout << "Tv Off...." << endl;
  }
};

// make the command interface
class ICommand
{
public:
  virtual void execute() = 0;
  virtual ~ICommand() = default;
};

// light command
class LightOnCommand : public ICommand
{
  shared_ptr<Light> light;

public:
  LightOnCommand(shared_ptr<Light> li)
  {
    this->light = li;
  }
  void execute() override
  {
    light->on();
  }
};

class LightOffCommand : public ICommand
{
  shared_ptr<Light> light;

public:
  LightOffCommand(shared_ptr<Light> li)
  {
    this->light = li;
  }
  void execute() override
  {
    light->off();
  }
};

// fan command
class FanOnCommand : public ICommand
{
  shared_ptr<Fan> fan;

public:
  FanOnCommand(shared_ptr<Fan> f1)
  {
    this->fan = f1;
  }
  void execute() override
  {
    fan->on();
  }
};

class FanOffCommand : public ICommand
{
  shared_ptr<Fan> fan;

public:
  FanOffCommand(shared_ptr<Fan> f1)
  {
    this->fan = f1;
  }
  void execute() override
  {
    fan->off();
  }
};

// tv command
class TVOnCommand : public ICommand
{
  shared_ptr<Television> tv;

public:
  TVOnCommand(shared_ptr<Television> tv)
  {
    this->tv = tv;
  }

  void execute() override
  {
    tv->on();
  }
};
class TVOffCommand : public ICommand
{
  shared_ptr<Television> tv;

public:
  TVOffCommand(shared_ptr<Television> tv)
  {
    this->tv = tv;
  }

  void execute() override
  {
    tv->off();
  }
};

// volume  handle command
class TvVolumeDownCommand : public ICommand
{
  shared_ptr<Television> tv;

public:
  TvVolumeDownCommand(shared_ptr<Television> t) : tv(t) {}

  void execute() override
  {
    tv->volumeDecrease();
  }
};

class TvVolumeUpCommand : public ICommand
{
  shared_ptr<Television> tv;

public:
  TvVolumeUpCommand(shared_ptr<Television> t) : tv(t) {}

  void execute() override
  {
    tv->volumeIncrease();
  }
};

// remote with invoke these command to operate the applicances
class RemoteController
{
  int noOfDevices = 0;
  vector<weak_ptr<ICommand>> devices;

public:
  RemoteController()
  {
    cout << "Remote is activated..." << endl;
  }

  void setCommand(int index, shared_ptr<ICommand> c)
  {
    // make sure index is correct or not

    if (this->noOfDevices - index > 1)
    {
      cout << "Please select the correct button for command setting.." << endl;
      return;
    }
    this->noOfDevices++;
    devices.resize(noOfDevices);

    if (index >= 0 && index < noOfDevices && c != nullptr)
    {
      // check if already there is command
      shared_ptr<ICommand> temp = devices[index].lock();
      // if already there is command just replace it as command delete is not responsibility of remote
      devices[index] = c;
    }
  }

  void pressButton(int index)
  {
    if (index < 0 || index >= noOfDevices)
    {
      cout << "No Button exist...\n";
      return;
    }

    auto currCommand = devices[index].lock();
    if (!currCommand)
    {
      cout << "No command assigned\n";
      return;
    }

    currCommand->execute();
  }
};

int main()
{
  // remote
  unique_ptr<RemoteController> remote = make_unique<RemoteController>();

  // devices
  auto l1 = make_shared<Light>();
  auto f1 = make_shared<Fan>();
  auto tv1 = make_shared<Television>();

  // commands
  auto lightOnCommand = make_shared<LightOnCommand>(l1);
  auto fanOnCommand = make_shared<FanOnCommand>(f1);
  auto tvOnCommand = make_shared<TVOnCommand>(tv1);

  auto lightOffCommand = make_shared<LightOffCommand>(l1);
  auto fanOffCommand = make_shared<FanOffCommand>(f1);
  auto tvOffCommand = make_shared<TVOffCommand>(tv1);

  // set the commands in remote
  remote->setCommand(0, lightOnCommand);
  remote->setCommand(1, lightOffCommand);

  remote->setCommand(2, fanOnCommand);
  remote->setCommand(3, fanOffCommand);

  remote->setCommand(4, tvOnCommand);
  remote->setCommand(5, tvOffCommand);
  // when new feature is added and new command comes
  // you have to create only commmds and register into remote
  // follow OCP
  auto volumnDownHandleCommand = make_shared<TvVolumeDownCommand>(tv1);
  auto volumnUpHandleCommand = make_shared<TvVolumeUpCommand>(tv1);

  remote->setCommand(6, volumnUpHandleCommand);
  remote->setCommand(7, volumnDownHandleCommand);

  // light toggle
  remote->pressButton(0);
  remote->pressButton(1);

  // fan toggle
  remote->pressButton(2);
  remote->pressButton(3);

  // tv volumn toggle
  remote->pressButton(6);
  remote->pressButton(6);

  // tv volumn toggle
  remote->pressButton(4);
  remote->pressButton(5);
}