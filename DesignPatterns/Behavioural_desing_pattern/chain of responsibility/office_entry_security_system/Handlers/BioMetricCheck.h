#ifndef EMPLOYEE_BIOMETRIC
#define EMPLOYEE_BIOMETRIC

#include <iostream>
#include "../Employee.h"
#include "Base_handler.h"
class BiometricHandler : public Handler
{
  Handler *next;

public:
  void setNextHandler(Handler *nextHandler) override
  {
    next = nextHandler;
  }

  bool check(Employee &e)
  {
    std::cout << "Biometric checking..." << std::endl;

    if (!e.fingerPrintMatched)
    {
      std::cout << "NO Finger Print matched | Entry denied" << std::endl;
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