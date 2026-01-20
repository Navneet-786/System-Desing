#ifndef STRIPE_SERVICE
#define STRIPE_SERVICE

#include <iostream>
#include <string>
class StripeService
{
public:
  void payWithStripe(double amount)
  {
    std::cout << "Paid " << amount << " using stripe\n";
  }
};

#endif