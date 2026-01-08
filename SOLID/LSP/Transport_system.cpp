#include <bits/stdc++.h>
using namespace std;

// Interface->all vehicle
class Vehicle
{
public:
  virtual void move() = 0;
  ~Vehicle() {};
};

// We separated optional behaviors into specialized abstractions instead of forcing all subclasses to implement them
class EngineVehicle : public Vehicle
{
public:
  virtual void startEngine() = 0;
};

// Car
class Car : public EngineVehicle
{
public:
  void move() override
  {
    cout << "car is moving..." << endl;
  }

  void startEngine() override
  {
    cout << "Car engine is starting" << endl;
  }
};

// class Bycycle
class Bicycle : public Vehicle
{
public:
  void move() override
  {
    cout << "Bicycle is moving..." << endl;
  }

  // Bicycle have no engine
  // void startEngine() override
  // {
  //   throw runtime_error("No Engine");
  // }
};

int main()
{
  EngineVehicle *v1 = new Car();
  v1->startEngine();
  v1->move();

  Vehicle *v2 = new Bicycle();
  // v2->startEngine();  wrong
  v2->move();

  delete v1;
  delete v2;
}
