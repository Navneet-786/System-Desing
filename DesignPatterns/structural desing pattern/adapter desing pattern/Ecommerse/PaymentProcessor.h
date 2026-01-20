#ifndef PAYMENT_PROCESSOR
#define PAYMENT_PROCESSOR

#include <iostream>
#include <string>
class PaymentProcessor
{
public:
  virtual void pay(double amount) = 0;
  virtual ~PaymentProcessor() = default;
};

#endif