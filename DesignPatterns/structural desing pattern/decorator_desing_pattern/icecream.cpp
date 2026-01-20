#include <iostream>
#include <string>
using namespace std;

// interface
class Icecream
{

public:
  virtual string getDesc() = 0;
  virtual double cost() = 0;
  virtual ~Icecream() = default;
};

class BasicIcecream : public Icecream
{
public:
  string getDesc() override
  {
    return "Basic Icecream ";
  }
  double cost() override
  {
    return 20;
  }
};

// decorator interface
class IcreCreamDecorator : public Icecream
{
protected:
  Icecream *icecream;

public:
  IcreCreamDecorator(Icecream *ice) : icecream(ice) {};
};

class AddChocolate : public IcreCreamDecorator
{
public:
  AddChocolate(Icecream *ice) : IcreCreamDecorator(ice) {};

  string getDesc() override
  {
    return icecream->getDesc() + " + Chocolate ";
  }

  double cost()
  {
    return icecream->cost() + 20;
  }
};

class AddCaramel : public IcreCreamDecorator
{
public:
  AddCaramel(Icecream *ice) : IcreCreamDecorator(ice) {};

  string getDesc()
  {
    return icecream->getDesc() + " + caramel ";
  }
  double cost()
  {
    return icecream->cost() + 30;
  }
};

int main()
{
  Icecream *icecream = new BasicIcecream();

  icecream = new AddCaramel(new AddChocolate(icecream));
  cout << icecream->getDesc() << endl;
  cout << icecream->cost();

  delete icecream;
}
