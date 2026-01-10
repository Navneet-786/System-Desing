#include <bits/stdc++.h>
using namespace std;

// order items(interface)
class Order
{
public:
  virtual void prepare() = 0;
  virtual void pack() = 0;
  virtual void deliver() = 0;
  virtual ~Order() = default;
};

// concreate class

// Pizza types

// MargheritaPizza (PIZZA TYPE)
class MargheritaPizza : public Order
{
public:
  void prepare()
  {
    cout << "MargheritaPizza is prepareing..." << endl;
  }

  void pack()
  {
    cout << "MargheritaPizza is packing..." << endl;
  }

  void deliver()
  {
    cout << "MargheritaPizza is delivered..." << endl;
  }
};

// FarmhousePizza (PIZZA TYPE)
class FarmhousePizza : public Order
{
public:
  void prepare()
  {
    cout << "FarmhousePizza is prepareing..." << endl;
  }

  void pack()
  {
    cout << "FarmhousePizza is packing..." << endl;
  }

  void deliver()
  {
    cout << "FarmhousePizza is delivered..." << endl;
  }
};

// Burgur
// VegBurger (BURGUR TYPES)
class VegBurger : public Order
{
public:
  void prepare() override
  {
    cout << "Preparing Veg Burger\n";
  }
  void pack() override
  {
    cout << "Packing Veg Burger\n";
  }
  void deliver() override
  {
    cout << "Delivering Veg Burger\n";
  }
};
// chicken burgur (BURGUR TYPES)
class ChickenBurger : public Order
{
public:
  void prepare() override
  {
    cout << "Preparing Chicken Burger\n";
  }
  void pack() override
  {
    cout << "Packing Chicken Burger\n";
  }
  void deliver() override
  {
    cout << "Delivering Chicken Burger\n";
  }
};

// Factory abstarct class
class OrderFactory
{
public:
  virtual unique_ptr<Order> createOrder(string type) = 0;
  virtual ~OrderFactory() = default;
};

// Break OCP
//  // Pizza Factory
//  class PizzaOrderFactory : public OrderFactory
//  {
//  public:
//    unique_ptr<Order> createOrder(string &type)
//    {
//      if (type == "Margherita")
//      {
//        return make_unique<MargheritaPizza>();
//      }
//      else if (type == "Farmhouse")
//      {
//        return make_unique<FarmhousePizza>();
//      }
//      else
//      {
//        return nullptr;
//      }
//    }
//  };

// // Burgur factory
// class BurgurOrderFactory : public OrderFactory
// {
// public:
//   unique_ptr<Order> createOrder(string &type)
//   {
//     if (type == "veg")
//     {
//       return make_unique<VegBurger>();
//     }
//     else if (type == "chicken")
//     {
//       return make_unique<ChickenBurger>();
//     }
//     else
//     {
//       return nullptr;
//     }
//   }
// };

// OCP followed
class PizzaOrderFactory : public OrderFactory
{
  // creator is alias
  using creator = function<unique_ptr<Order>()>;
  // create a registery{key: value}
  //  key-> string
  //  value-> function which create object and return
  unordered_map<string, creator> registry;

public:
  PizzaOrderFactory()
  {
    registry["Margherita"] = []()
    {
      return make_unique<MargheritaPizza>();
    };

    registry["Farmhouse"] = []()
    {
      return make_unique<FarmhousePizza>();
    };
  }

  unique_ptr<Order> createOrder(string type) override
  {
    // check if pizza exist in registry or not
    if (registry.count(type))
    {
      // yes present
      return registry[type](); // call the method
    }

    throw runtime_error("Unknown pizza type");
  }
};

class BurgurOrderFactory : public OrderFactory
{
  using creator = function<unique_ptr<Order>()>;
  unordered_map<string, creator> registry;

public:
  BurgurOrderFactory()
  {
    registry["VegBurgur"] = []()
    {
      return make_unique<VegBurger>();
    };

    registry["ChickenBurgur"] = []()
    {
      return make_unique<ChickenBurger>();
    };

    // in future if new burgur add then only register here
  }

  unique_ptr<Order> createOrder(string type) override
  {
    if (registry.count(type))
    {
      return registry[type]();
    }
    throw runtime_error("Unknown Burgur type..");
  }
};

int main()
{
  unique_ptr<OrderFactory> factory = make_unique<PizzaOrderFactory>();
  string choice = "Farmhouse";
  unique_ptr<Order> pizza1 = factory->createOrder(choice);

  pizza1->prepare();
  pizza1->pack();
  pizza1->deliver();

  unique_ptr<OrderFactory> factory1 = make_unique<BurgurOrderFactory>();
  unique_ptr<Order> burgur1 = factory1->createOrder("VegBurgur");

  burgur1->prepare();
  burgur1->pack();
  burgur1->deliver();
}
