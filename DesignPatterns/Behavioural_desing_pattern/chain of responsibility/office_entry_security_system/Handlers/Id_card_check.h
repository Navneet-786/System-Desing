#ifndef EMPLOYEE_ID_CARD
#define EMPLOYEE_ID_CARD

#include <iostream>
#include "../Employee.h"
#include "Base_handler.h"
class IDCardHandler : public Handler
{
  Handler *next;

public:
  void setNextHandler(Handler *nextHandler) override
  {
    next = nextHandler;
  }

  bool check(Employee &e)
  {
    std::cout << "ID Card checking..." << std::endl;

    if (!e.hasIDCard)
    {
      std::cout << "NO ID Card | Entry denied" << std::endl;
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