#include <bits/stdc++.h>
using namespace std;

// payment strategy
class PaymentStrategy
{
public:
  virtual void pay(double amount) const = 0;
  virtual ~PaymentStrategy() = default;
};

//concrete strategies
// paytm
class Paytm : public PaymentStrategy
{
public:
  void pay(double amount) const
  {
    cout << amount << " is paid via Paytm" << endl;
  }
};

// Gpay
class Gpay : public PaymentStrategy
{
public:
  void pay(double amount) const
  {
    cout << amount << " is paid via Gpay" << endl;
  }
};

// cash
class Cash : public PaymentStrategy
{
public:
  void pay(double amount) const
  {
    cout << amount << " is paid via Cash" << endl;
  }
};

// payment context
class PaymentContext
{
  unique_ptr<PaymentStrategy> strategy;

public:
  // constructor
  PaymentContext(unique_ptr<PaymentStrategy> p) : strategy(move(p)) {};

  void setStrategy(unique_ptr<PaymentStrategy> p)
  {
    strategy = move(p);
  }

  void pay(double amount)
  {
    strategy->pay(amount);
  }
};

int main()
{
  PaymentContext pctx(make_unique<Paytm>());
  pctx.pay(300);

  pctx.setStrategy(make_unique<Cash>());
  pctx.pay(1000);
}
