#ifndef ORDER_ITEMS
#define ORDER_ITEMS

#include <iostream>
#include <string>
#include "product.h"
class OrderItem
{
private:
  Product *product;
  int qty;

public:
  OrderItem(Product *prod, int qty) : product(prod), qty(qty) {};

  double getCost() const
  {
    return this->product->getProductAmount() * this->qty;
  }

  void showItem() const
  {
    product->getProductDetal();
    std::cout << "Qty: " << qty << "  Cost: " << getCost() << std::endl;
  }
};

#endif