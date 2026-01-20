#include <iostream>
#include <string>
using namespace std;

class ChopVegeTable
{
public:
  void chop()
  {
    cout << "chopping vegetables\n";
  }
};

class CookingPanner
{
public:
  void cook()
  {
    cout << "paneer is cooking" << endl;
  }
};

class PrepareSauces
{
public:
  void prepare()
  {
    cout << "sauces are preapreing" << endl;
  }
};

class PlatingDish
{
public:
  void plating()
  {
    cout << "dishes are plating" << endl;
  }
};

// facade
class Waiter
{
  ChopVegeTable veg;
  CookingPanner cookPanner;
  PrepareSauces prepareSauces;
  PlatingDish plating;

public:
  void prepareOrder()
  {
    cout << "waiter taken order\n";
    veg.chop();
    cookPanner.cook();
    prepareSauces.prepare();
    plating.plating();
    cout << "Order is ready\n";
  }
};

int main()
{
  Waiter waiter;
  waiter.prepareOrder();
}