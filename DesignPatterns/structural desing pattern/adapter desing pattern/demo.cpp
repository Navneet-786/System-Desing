#include <iostream>
#include <string>
#include <memory>
using namespace std;

// third party service
class PaymentService
{
public:
  virtual void pay() = 0;
  virtual ~PaymentService() = default;
};

// third party subclass
class NetBanking : public PaymentService
{
public:
  void pay()
  {
    cout << "payment done of 100 ruppes" << endl;
  }
};

// system interface
class UserSystem
{
public:
  virtual void getResponse() = 0;
  virtual ~UserSystem() = default;
};

// we need to communicate 2 different interface
class PaymentAdapter : public UserSystem
{
  shared_ptr<PaymentService> payment;

public:
  PaymentAdapter(shared_ptr<PaymentService> ptr) : payment(ptr) {};
  void getResponse()
  {
    payment->pay();
  }
};

class Client
{
  shared_ptr<UserSystem> systemm;

public:
  Client(shared_ptr<UserSystem> s) : systemm(s) {};
  void makePayment()
  {
    systemm->getResponse(); // ✅ valid
  }
};

int main()
{
  shared_ptr<PaymentService> service = make_shared<NetBanking>();
  shared_ptr<UserSystem> systemm = make_shared<PaymentAdapter>(service);

  Client c(systemm);
  c.makePayment();
}