#ifndef ORDER_BY_WAITER_TO_CHIEF
#define ORDER_BY_WAITER_TO_CHIEF

#include <iostream>
#include "foodItems.h"
#include "logger.h"
class Order
{
public:
  virtual void execute() = 0;
  virtual std::string getType() = 0;
  virtual ~Order() = default;
};

// pizza order
class PizzaOrder : public Order
{
  IPizza *pizza;
  Logger *lg;

public:
  PizzaOrder(IPizza *p, Logger *lg) : pizza(p), lg(lg) {};

  std::string getType() override
  {
    return "std::pizza";
  }

  void execute() override
  {
    std::string desc = pizza->create();
    double cost = pizza->getCost();

    lg->log(desc + "|| price: " + std::to_string(cost) + "\n\n");

    std::cout
        << desc << std::endl;
    std::cout << "Total Cost: " << cost << std::endl;

    // logg this order
  }
};

// pizza order
class BurgurOrder : public Order
{
  Burgur *burgur;
  Logger *lg;

public:
  BurgurOrder(Burgur *p, Logger *lg) : lg(lg), burgur(p) {};

  std::string getType() override
  {
    return "std::burgur";
  }

  void execute() override
  {
    std::string desc = burgur->create();
    double cost = burgur->getCost();

    lg->log(desc + "|| price: " + std::to_string(cost) + "\n\n");
    std::cout << desc << std::endl;
    std::cout << "Total Cost: " << cost << std::endl;

    // logg this order
  }
};

#endif
