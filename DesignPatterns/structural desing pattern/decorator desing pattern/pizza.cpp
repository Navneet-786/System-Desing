#include <bits/stdc++.h>
using namespace std;

class IFoodItem
{
public:
  // description
  virtual string getDescription() = 0;
  virtual int getCost() = 0;
  virtual ~IFoodItem() = default;
};

// create Pizza
class Pizza : public IFoodItem
{
public:
  string getDescription() override
  {
    return "Plain Pizza ";
  }

  int getCost() override
  {
    return 100; // base price
  }
};

// for more options -> we are creating decorator class

class DecorateFood : public IFoodItem
{
protected:
  IFoodItem *food;

public:
  DecorateFood(IFoodItem *f) : food(f) {};
};

// adding cheese
class Cheese : public DecorateFood
{
public:
  Cheese(IFoodItem *f) : DecorateFood(f) {};

  string getDescription() override
  {
    return food->getDescription() + " + Cheese";
  }

  int getCost() override
  {
    return food->getCost() + 30; // base price
  }
};

// adding Olives
class Olives : public DecorateFood
{

public:
  Olives(IFoodItem *f) : DecorateFood(f) {};

  string getDescription() override
  {

    return food->getDescription() + " + Olives";
  }

  int getCost() override
  {
    return food->getCost() + 50; // base price
  }
};

int main()
{
  IFoodItem *order = new Pizza();

  order = new Cheese(order);
  order = new Olives(order);

  cout << "Description: " << order->getDescription() << endl;
  cout << "Total Cost: " << order->getCost() << endl;

  delete order;
}