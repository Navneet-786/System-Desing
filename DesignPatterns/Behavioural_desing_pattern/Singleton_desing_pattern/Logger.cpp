#include <bits/stdc++.h>
using namespace std;

// make it Singleton class
class Logger
{
  // constructor
  Logger() {};

  // close the assignment and copy constructor
  Logger(const Logger &) = delete;
  Logger &operator=(const Logger &) = delete;

public:
  static Logger &getInstance()
  {
    static Logger instance; // this is thread safe
    return instance;
  }

  // mehtod to log
  void log(const string &msg)
  {
    cout << "[Log]: " << msg << endl;
  }
};

// services
class OrderService
{
public:
  void placeOrder()
  {
    Logger::getInstance().log("Order is Placed....");
  }
};

class Userservice
{
public:
  void createUser()
  {
    Logger::getInstance().log("user is  created..");
  }
};

int main()
{
  unique_ptr<OrderService> o = make_unique<OrderService>();
  o->placeOrder();

  unique_ptr<Userservice> u = make_unique<Userservice>();
  u->createUser();
}