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

int main()
{
  PaymentStrategy *ps = new Paytm();
  ps->pay(200);

  PaymentStrategy *ps2 = new Cash();
  ps2->pay(1000);

  delete ps;
  delete ps2;
}
