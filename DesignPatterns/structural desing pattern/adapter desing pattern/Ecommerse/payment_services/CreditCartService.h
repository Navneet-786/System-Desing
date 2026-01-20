#ifndef CREDITCARD_SERVICE
#define CREDITCARD_SERVICE

#include <iostream>
#include <string>
class CreditCardService
{
public:
  void payWithCreditCard(double amount)
  {
    std::cout << "Paid " << amount << " using creditCard\n";
  }
};

#endif