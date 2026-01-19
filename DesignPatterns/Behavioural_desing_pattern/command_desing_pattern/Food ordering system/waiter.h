#ifndef WAITER_GIVE_ORDER
#define WAITER_GIVE_ORDER

#include <iostream>
#include "orders.h"
#include "logger.h"
#include <vector>
class Waiter
{
  std::vector<Order *> orders;
  Logger *lg;

public:
  Waiter() {

  };
  void AddOrder(Order *order)
  {
    orders.push_back(order);
  }

  void placeOrder()
  {

    // for (auto it : typeOfOrders)
    // {
    //   size_t pos = it.find("::");
    //   if (pos != std::string::npos)
    //   {
    //     std::string word = it.substr(pos + 2);
    //   }
    // }

    for (auto it : orders)
    {

      it->execute();
    }
  }
};

#endif