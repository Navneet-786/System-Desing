#ifndef PAYPAL_ADAPTER_H
#define PAYPAL_ADAPTER_H

#include "../PaymentProcessor.h"
#include "../payment_services/PaypalService.h"

class PayPalAdapter : public PaymentProcessor
{
  PayPalService *paypal;

public:
  PayPalAdapter(PayPalService *p) : paypal(p) {};

  void pay(double amount) override
  {
    paypal->payWithPayPay(amount);
  }
};

#endif