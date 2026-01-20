#ifndef CREDITCARD_ADAPTER_H
#define CREDITCARD_ADAPTER_H

#include "../PaymentProcessor.h"
#include "../payment_services/CreditCartService.h"

class CreditCardAdapter : public PaymentProcessor
{
  CreditCardService *creditcard;

public:
  CreditCardAdapter(CreditCardService *p) : creditcard(p) {};

  void pay(double amount) override
  {
    creditcard->payWithCreditCard(amount);
  }
};

#endif