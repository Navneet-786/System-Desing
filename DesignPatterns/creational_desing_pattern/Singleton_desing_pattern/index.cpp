#include <bits/stdc++.h>
#include <mutex>
using namespace std;

class Singleton
{
  // make cionstructor private
  Singleton() {};
  // no copy constructor
  Singleton(const Singleton &) = delete;
  // no assignment constructor
  Singleton &operator=(Singleton &) = delete;

  // this instance hold the singleton object refrence
  static Singleton *instance;
  string name;
  static mutex mx;

public:
  static Singleton *getInstance(string name)
  {
    if (instance == nullptr)
    {

      instance = new Singleton();
      instance->name = name;
    }

    return instance;
  }

  void print()
  {
    cout << this->name << endl;
  }
};

mutex Singleton::mx;

// initialize with null value
Singleton *Singleton ::instance = nullptr;

int main()
{
  Singleton *s = Singleton::getInstance("Rohan");
  s->print(); // Rohan
  Singleton *s1 = Singleton::getInstance("Sohan");
  s1->print(); // Rohan
}