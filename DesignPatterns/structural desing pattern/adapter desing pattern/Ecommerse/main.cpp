#include <iostream>
#include <string>
#include "Product.h"
#include "Cart.h"
#include "PaymentProcessor.h"
#include "Order.h"
#include "payment_services/PaypalService.h"
#include "payment_services/StripeService.h"
#include "payment_services/CreditCartService.h"
#include "adapters/CreditCardAdapter.h"
#include "adapters/PayPalAdapter.h"
#include "adapters/StripeAdapter.h"

using namespace std;
int main()
{
  // create products
  Product phone("Phone", 20000);
  Product shirt("Shirt", 900);
  Product watch("Watch", 1500);
  Product mirror("Mirror", 100);

  Cart cart;
  cart.addToCart(&phone, 2);
  cart.addToCart(&shirt, 1);
  cart.addToCart(&mirror, 2);
  cart.addToCart(&watch, 1);

  cart.viewCart();

  // create service
  CreditCardService creditcard;
  PayPalService paypal;
  StripeService stripe;

  // adapters
  CreditCardAdapter creditCardAdp(&creditcard);
  PayPalAdapter paypalAdp(&paypal);
  StripeAdapter stripeAdp(&stripe);

  Order order = cart.generateOrder();
  order.payNow(&stripeAdp);
}