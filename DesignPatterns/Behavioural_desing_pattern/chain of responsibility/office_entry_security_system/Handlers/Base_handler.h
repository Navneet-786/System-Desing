#ifndef BASE_HANDLER
#define BASE_HANDLER

#include <iostream>
#include "../Employee.h"

class Handler
{
public:
  virtual void setNextHandler(Handler *next) = 0;
  virtual bool check(Employee &e) = 0;
  virtual ~Handler() = default;
};

#endif