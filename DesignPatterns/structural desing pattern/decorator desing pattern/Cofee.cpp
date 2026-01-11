#include <iostream>
#include <string>
using namespace std;

// bevarages
class Beverages
{
public:
  virtual string create() = 0;
  virtual int getAmount() = 0;
  virtual ~Beverages() = default;
};

// cofee
class SimpleCoffee : public Beverages
{
public:
  string create() override
  {
    return "Simple Coffee ";
  }

  int getAmount() override
  {
    return 50;
  }
};

// decorator interface
class CoffeeDecorator : public Beverages
{
protected:
  Beverages *beverage;

public:
  CoffeeDecorator(Beverages *bev) : beverage(bev) {};
};

// adding milk to given beverages(coffee)
class MilkCofee : public CoffeeDecorator
{
public:
  MilkCofee(Beverages *bev) : CoffeeDecorator(bev) {};

  string create()
  {
    return beverage->create() + " + Milk";
  };
  int getAmount()
  {
    return beverage->getAmount() + 20;
  };
};

class CreamCoffee : public CoffeeDecorator
{
public:
  CreamCoffee(Beverages *bev) : CoffeeDecorator(bev) {};

  string create()
  {
    return beverage->create() + " +  Cream";
  };
  int getAmount()
  {
    return beverage->getAmount() + 30;
  };
};

int main()
{
  Beverages *b = new SimpleCoffee();
  b = new MilkCofee(b);
  cout << b->create() << endl;
  cout << b->getAmount() << endl;

  b = new CreamCoffee(b);
  cout << b->create() << endl;
  cout << b->getAmount() << endl;

  delete b;
}
