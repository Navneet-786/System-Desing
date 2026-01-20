#ifndef PRODUCT_ECOMM
#define PRODUCT_ECOMM

#include <iostream>
#include <string>
class Product
{
  std::string name;
  double amount;

public:
  Product(std::string name, double amount) : name(name), amount(amount) {};

  void getProductDetal()
  {
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Price: " << this->amount << std::endl;
  }

  const std::string &getProductName() { return this->name; }
  const double &getProductAmount() { return this->amount; }

  void setNewAmount(const double &newAmount)
  {
    this->amount = newAmount;
  }
};

#endif