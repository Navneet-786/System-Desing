#include <bits/stdc++.h>
using namespace std;

// discount interface
class DiscountStrategy
{
public:
  const virtual double applyDiscount(const double price) const = 0;
  virtual ~DiscountStrategy() {};
};

// student discount
class StudentDiscount : public DiscountStrategy
{
public:
  const double applyDiscount(const double price) const override
  {
    return price * 0.8; // 80% discount
  }
};

// teacher discount
class TeacherDiscount : public DiscountStrategy
{
public:
  const double applyDiscount(const double price) const override
  {
    return price * 0.7; // 70% discount
  }
};

// management discount
class ManagementDiscount : public DiscountStrategy
{
public:
  const double applyDiscount(const double price) const override
  {
    return price * 0.5;
  }
};

int main()
{
  DiscountStrategy *ds = new StudentDiscount();
  cout << "after student discount is :" << ds->applyDiscount(100) << endl;

  DiscountStrategy *ds1 = new TeacherDiscount();
  cout << "after Teacher discount is :" << ds1->applyDiscount(200) << endl;

  delete ds;
  delete ds1;
}