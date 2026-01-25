#ifndef EMPLOYEE_TIME
#define EMPLOYEE_TIME

#include <iostream>
#include "../Employee.h"
#include "Base_handler.h"
class TimeValidationHandler : public Handler
{
  Handler *next;

public:
  void setNextHandler(Handler *nextHandler) override
  {
    next = nextHandler;
  }

  bool check(Employee &e)
  {
    std::cout << "office time checking..." << std::endl;

    if (!e.officeTime)
    {
      std::cout << "Outside office hours | Entry denied" << std::endl;
      return false;
    }

    std::cout << " All checks passed. Gate Opened \n";
    return true;
  }
};
#endif