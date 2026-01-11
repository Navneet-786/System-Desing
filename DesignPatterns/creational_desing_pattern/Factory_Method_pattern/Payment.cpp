#include <bits/stdc++.h>
using namespace std;

// payment interface
class Payment
{
public:
  virtual void pay(double amount) = 0;
  virtual ~Payment() = default;
};

// concrete class
//  NetBanking
class Netbanking : public Payment
{
public:
  void pay(double amount) override
  {
    cout << amount << " is paid by Netbanking" << endl;
  }
};

// cash
class Cash : public Payment
{
public:
  void pay(double amount) override
  {
    cout << amount << " is paid by cash" << endl;
  }
};

// Creditcard
class CreditCard : public Payment
{
public:
  void pay(double amount) override
  {
    cout << amount << " is paid by credit card" << endl;
  }
};

// ==================FACTORY==============================

// let create payment factory and lets child decide the type of object
class PaymentFactory
{
public:
  virtual unique_ptr<Payment> createPayment(const string &type) = 0;
  virtual ~PaymentFactory() = default;
};

// there are 2 categories offline and online payment methods
class OnlinePaymentFactory : public PaymentFactory
{
  using creator = function<unique_ptr<Payment>()>;
  // create a online registry
  unordered_map<string, creator> registery;

public:
  // constructor
  OnlinePaymentFactory()
  {
    // initialize the registery
    registery["Netbanking"] = []()
    {
      return make_unique<Netbanking>();
    };

    registery["Creditcard"] = []()
    {
      return make_unique<CreditCard>();
    };
  }

  unique_ptr<Payment> createPayment(const string &type) override
  {
    if (registery.count(type))
    {
      return registery[type]();
    }

    throw runtime_error("No such payment exist");
  }
};

// offline payment factory
class OfflinePaymentFactory : public PaymentFactory
{
  using creator = function<unique_ptr<Payment>()>;
  unordered_map<string, creator> registery;

public:
  // constructor -> initialze our registery
  OfflinePaymentFactory()
  {
    registery["Cash"] = []()
    {
      return make_unique<Cash>();
    };
  }

  unique_ptr<Payment> createPayment(const string &type) override
  {
    if (registery.count(type))
    {
      return registery[type]();
    }

    throw runtime_error("No such method exist");
  }
};

// // NetbankingFactory
// class NetbankingFactory : public OnlinePaymentFactory
// {
// public:
//   unique_ptr<Payment> createPayment()
//   {
//     return make_unique<Netbanking>();
//   }
// };

// // Cash
// class CashFactory : public OfflinePaymentFactory
// {
// public:
//   unique_ptr<Payment> createPayment()
//   {
//     return make_unique<Cash>();
//   }
// };

// // credit card
// class CreditCardFactory : public OnlinePaymentFactory
// {
// public:
//   unique_ptr<Payment> createPayment()
//   {
//     return make_unique<CreditCard>();
//   }
// };

int main()
{
  unique_ptr<PaymentFactory> p1 = make_unique<OnlinePaymentFactory>();
  string type = "Netbanking";
  unique_ptr<Payment> payment = p1->createPayment(type);
  payment->pay(40000);

  // pay via cash
  unique_ptr<PaymentFactory> p2 = make_unique<OfflinePaymentFactory>();
  type = "Cash";
  unique_ptr<Payment> payment1 = p2->createPayment(type);
  payment1->pay(1200);
}