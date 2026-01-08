#include <bits/stdc++.h>
using namespace std;

// Payment Interface
class PaymentStrategy
{
public:
  virtual void pay(const double amount) const = 0;
  ~PaymentStrategy() {};
};

// Different  strategy

// paytem
class Paytm : public PaymentStrategy
{
public:
  void pay(const double amount) const override
  {
    cout << amount << " is paid by paytm" << endl;
  }
};

// Gpay
class Gpay : public PaymentStrategy
{
public:
  void pay(const double amount) const override
  {
    cout << amount << " is paid by Gapy" << endl;
  }
};

// cash

class Cash : public PaymentStrategy
{
public:
  void pay(const double amount) const override
  {
    cout << amount << " is paid by Cash" << endl;
  }
};

// create a factory method to centralize object creation
class PaymentFactory
{
public:
  virtual const PaymentStrategy *create() const = 0;
  ~PaymentFactory() {};
};

// factory subclasses
class PaytmFactory : public PaymentFactory
{
public:
  const PaymentStrategy *create() const override
  {
    return new Paytm();
  }
};

// Gpay subclass
class GpayFactory : public PaymentFactory
{
public:
  const PaymentStrategy *create() const override
  {
    return new Gpay();
  }
};

// cash factory
class CashFactory : public PaymentFactory
{
public:
  const PaymentStrategy *create() const override
  {
    return new Cash();
  }
};

int main()
{
  PaymentFactory *pf1 = new PaytmFactory();
  const PaymentStrategy *ps1 = pf1->create();
  ps1->pay(200);

  PaymentFactory *pf2 = new CashFactory();
  const PaymentStrategy *ps2 = pf2->create();
  ps2->pay(1000);

  delete ps1;
  delete pf1;
  delete ps2;
}
