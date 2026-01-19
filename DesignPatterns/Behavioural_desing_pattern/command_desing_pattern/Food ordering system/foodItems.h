#ifndef FOOD_ITEMS_AT_RES
#define FOOD_ITEMS_AT_RES

#include <iostream>
#include <string>

// pizza interface

class IPizza
{
public:
  virtual double getCost() = 0;
  virtual std::string create() = 0;

  virtual ~IPizza() = default;
};

// basic pizza class
class BasicPizza : public IPizza
{
public:
  double getCost() override
  {
    return 50;
  }

  std::string create() override
  {
    return "Basic Pizza is created";
  }
};

// decorator
class PizzaDecorator : public IPizza
{
protected:
  IPizza *pizza;

public:
  PizzaDecorator(IPizza *pizza) : pizza(pizza) {};
};

// toppings
class AddOnions : public PizzaDecorator
{
public:
  AddOnions(IPizza *pizza) : PizzaDecorator(pizza) {};
  double getCost() override
  {
    return pizza->getCost() + 20;
  }

  std::string create() override
  {
    return pizza->create() + " + onions ";
  }
};

class AddCorn : public PizzaDecorator
{
public:
  AddCorn(IPizza *pizza) : PizzaDecorator(pizza) {};

  double getCost() { return pizza->getCost() + 25; }
  std::string create()
  {
    return pizza->create() + " + Corn ";
  }
};

class AddGarlic : public PizzaDecorator
{
public:
  AddGarlic(IPizza *pizza) : PizzaDecorator(pizza) {};

  double getCost() { return pizza->getCost() + 30; }
  std::string create()
  {
    return pizza->create() + " + Garlic ";
  }
};

// BURGUR
class Burgur
{
public:
  virtual std::string create() = 0;
  virtual double getCost() = 0;
  virtual ~Burgur() = default;
};

class BasicBurgur : public Burgur
{
public:
  std::string create() override
  {
    return "basic burgur ";
  }
  double getCost()
  {
    return 30;
  }
};

// decorator
class BurgurDecorator : public Burgur
{
protected:
  Burgur *burgur;

public:
  BurgurDecorator(Burgur *b) : burgur(b) {};
};

class AddCheese : public BurgurDecorator
{
public:
  AddCheese(Burgur *b) : BurgurDecorator(b) {};
  std::string create()
  {
    return burgur->create() + " cheese ";
  }
  double getCost()
  {
    return burgur->getCost() + 25;
  }
};

class AddTomato : public BurgurDecorator
{
public:
  AddTomato(Burgur *b) : BurgurDecorator(b) {};
  std::string create()
  {
    return burgur->create() + " Tomato ";
  }
  double getCost()
  {
    return burgur->getCost() + 15;
  }
};
#endif