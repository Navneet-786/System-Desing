#ifndef EMPLOYEE_ACCESS_LEVEL
#define EMPLOYEE_ACCESS_LEVEL

#include <iostream>
#include "../Employee.h"
#include "Base_handler.h"
class AccessHandler : public Handler
{
  Handler *next;

public:
  void setNextHandler(Handler *nextHandler) override
  {
    next = nextHandler;
  }

  bool check(Employee &e)
  {
    std::cout << "access checking..." << std::endl;

    if (!e.isAdmin)
    {
      std::cout << "Access Level is too low | Entry denied" << std::endl;
      return false;
    }

    if (next)
    {
      return next->check(e);
    }

    return true;
  }
};
#endif