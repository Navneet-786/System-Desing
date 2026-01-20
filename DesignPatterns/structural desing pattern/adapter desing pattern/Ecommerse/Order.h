#ifndef PRODUCT_ECOMM_ORDER
#define PRODUCT_ECOMM_ORDER

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Product.h"
#include "OrderItem.h"

#include "PaymentProcessor.h"

class Order
{
  int orderId;
  std::vector<OrderItem> items;
  bool isPaid;

public:
  Order(int id, std::vector<OrderItem> orderItems)
      : orderId(id), isPaid(false), items(orderItems) {};

  void showOrder()
  {
    std::cout << "\nOrder ID: " << orderId << std::endl;
    double total = 0;
    for (auto &item : items)
    {
      item.showItem();
      total += item.getCost();
    }

    std::cout << "Total Amount: " << total << std::endl;
  }

  double calculateTotalAmount()
  {
    double totalAmount = 0;
    for (auto it : items)
    {
      totalAmount += it.getCost();
        }
    return totalAmount;
  }

  void payNow(PaymentProcessor *processor)
  {
    if (isPaid)
    {
      std::cout << "Order already paid!\n";
      throw std::runtime_error("Cart is empty");
    }
    std::cout << std::endl;

    double amount = calculateTotalAmount();
    processor->pay(amount);
    isPaid = true;
    std::cout << "Order payment successful \n";
  }
};

#endif