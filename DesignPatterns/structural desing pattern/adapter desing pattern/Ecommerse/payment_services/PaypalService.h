#ifndef PAYPAL_SERVICE
#define PAYPAL_SERVICE

#include <iostream>
#include <string>
class PayPalService
{
public:
  void payWithPayPay(double amount)
  {
    std::cout << "Paid " << amount << " using PayPal\n";
  }
};

#endif