#ifndef PRODUCT_ECOMM_CART
#define PRODUCT_ECOMM_CART

#include <iostream>
#include <string>
#include "Order.h"
#include <vector>
#include <unordered_map>
#include "Product.h"
#include "OrderItem.h"
class Cart
{
  std::unordered_map<Product *, int> products;
  static int orderCounter;

public:
  Cart() {};

  void addToCart(Product *product, int qt)
  {
    if (products.count(product))
    {
      products[product] += qt;
      std::cout << "Product added to cart.." << std::endl;
    }
    else
    {
      products[product] = qt;
    }
  }

  void removeFromCart(Product *prod, int qt)
  {

    if (products.count(prod))
    {
      if (products[prod] - qt > 0)
      {
        products[prod] -= qt;
      }
      else
      {
        products.erase(prod);
        std::cout << "product removed from cart" << std::endl;
      }
    }
  }

  void viewCart()
  {
    std::cout << "\nYour Cart is \n"
              << std::endl;

    double totalAmount = 0;
    for (auto it : products)
    {

      it.first->getProductDetal();
      totalAmount += it.first->getProductAmount() * it.second;
      std::cout << "Product qty: " << it.second << std::endl
                << std::endl;
    }
    std::cout << "\nTotal Pay : Rs. " << totalAmount << std::endl;
  }

  bool isEmpty()
  {
    if (products.size() == 0)
      return true;
    return false;
  }

  // generate Order
  Order generateOrder()
  {
    if (isEmpty())
    {
      throw std::runtime_error("Cart is empty, cannot generate order");
    }

    std::vector<OrderItem> orderItems;
    for (auto &it : products)
    {
      orderItems.emplace_back(it.first, it.second);
    }

    products.clear();
    return Order(++orderCounter, orderItems);
  }
};

int Cart::orderCounter = 0;

#endif