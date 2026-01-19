#include <iostream>
#include <string>
#include "foodItems.h"
#include "orders.h"
#include "waiter.h"
#include "logger.h"
using namespace std;

int main()
{
  Waiter *waiter = new Waiter();
  Logger *log = new FileLogger();
  IPizza *pizza = new BasicPizza();
  pizza = new AddGarlic(pizza);
  pizza = new AddOnions(pizza);
  pizza = new AddCorn(pizza);

  Burgur *burgur = new BasicBurgur();
  burgur = new AddTomato(burgur);

  // command
  Order *pizzaOrder = new PizzaOrder(pizza, log);
  Order *burgurOrder = new BurgurOrder(burgur, log);
  waiter->AddOrder(pizzaOrder);
  waiter->AddOrder(burgurOrder);
  waiter->placeOrder();

  delete waiter;

  delete pizza;
}