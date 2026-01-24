#include <iostream>
#include <string>
using namespace std;

class OrderProcess
{
public:
  // template method-> define the fixec algorithm
  void processOrder()
  {
    selectItems();
    calculateBill();
    makePayment(); // this is varibale (UPI , CREDIT CARD, CASH, COD)
    generateInvoice();
    notify();
  }

protected:
  void selectItems()
  {
    cout << "Items are selected\n";
  }

  void calculateBill()
  {
    cout << "Bill is calculated" << endl;
  }

  virtual void makePayment() = 0; // as veriable , lets subclass decide how to implement

  void generateInvoice()
  {
    cout << "Invoice is generated" << endl;
  }

  void notify()
  {
    cout << "notify to user" << endl;
  }
};

class UPIOrder : public OrderProcess
{
public:
  void makePayment()
  {
    cout << "Payment is done via UPI" << endl;
  }
};

class CreditCardOrder : public OrderProcess
{
public:
  void makePayment()
  {
    cout << "Payment is done via CreditCard" << endl;
  }
};

class CODOrder : public OrderProcess
{
public:
  void makePayment()
  {
    cout << "Payment is done via COD" << endl;
  }
};

// client code
int main()
{
  OrderProcess *order1 = new UPIOrder();

  order1->processOrder();
  cout << endl
       << endl;

  OrderProcess *order2 = new CODOrder();
  order2->processOrder();

  delete order1;
  delete order2;
}