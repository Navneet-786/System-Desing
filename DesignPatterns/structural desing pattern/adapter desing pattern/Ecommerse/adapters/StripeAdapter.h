#ifndef STRIPE_ADAPTER_H
#define STRIPE_ADAPTER_H

#include "../PaymentProcessor.h"
#include "../payment_services/StripeService.h"

class StripeAdapter : public PaymentProcessor
{
  StripeService *stripe;

public:
  StripeAdapter(StripeService *p) : stripe(p) {};

  void pay(double amount) override
  {
    stripe->payWithStripe(amount);
  }
};

#endif