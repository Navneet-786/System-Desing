#include <iostream>
#include <string>
#include "Employee.h"
#include "./Handlers/AccessLevelCheck.h"
#include "./Handlers/Base_handler.h"
#include "./Handlers/BioMetricCheck.h"
#include "./Handlers/Id_card_check.h"
#include "./Handlers/TimeValidationChecking.h"
using namespace std;

int main()
{
  // crete employee
  Employee emp{true, false, true, true};

  // create Handlers and connect them in chain
  Handler *idCard = new IDCardHandler();
  Handler *biometricHandler = new BiometricHandler();
  Handler *access = new AccessHandler();
  Handler *timeValidate = new TimeValidationHandler();

  idCard->setNextHandler(biometricHandler);
  biometricHandler->setNextHandler(access);
  access->setNextHandler(timeValidate);

  cout << "\n--- Employee Trying to Enter ---\n";
  idCard->check(emp);

  delete idCard;
  delete biometricHandler;
  delete access;
  delete timeValidate;
}