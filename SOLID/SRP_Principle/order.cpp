#include <bits/stdc++.h>
using namespace std;

// Item clas to create items
class Item
{
  string name;
  double price;

public:
  Item(string name, double price) : name(name), price(price) {};

  string getName() const { return this->name; }
  double getPrice() const { return this->price; }
};

// order->only add items
class Order
{
  vector<const Item *> items;
  double total;

public:
  Order() : total(0)
  {

    cout << "Order is creating..." << endl;
  }

  // add items
  void addItem(const Item *item)
  {
    items.push_back(item);
    total += item->getPrice();

    cout
        << item->getName() << " added successsfully" << endl;
  }

  const vector<const Item *> &getItems() const
  {
    return items;
  }

  double getTotal() const
  {
    return total;
  }
};

// database class -> to save to db
class OrderRepository
{
public:
  void save(const Order &order)
  {
    cout << "Ordder is saved...." << endl;
  }
};

// invoice-> print invoice
class Invoice
{
public:
  void generateInvoice(const Order &order)
  {
    cout << "----------INVOICE----------\n";
    int counter = 0;
    for (auto it : order.getItems())
    {

      cout << "product Name : " << it->getName() << endl;
      cout << "product price : " << it->getPrice() << endl
           << endl;
      counter++;
    }

    cout << "------------------------------" << endl;
    cout << "Total: " << order.getTotal() << endl;
    cout << "no of items: " << counter << endl;
    cout << "------------------------------" << endl;
  }
};

int main()
{
  Item *it1 = new Item("Burgur", 200);
  Item *it2 = new Item("pizza", 100);
  Item *it3 = new Item("Chocolate", 50);

  Order *oder = new Order();
  oder->addItem(it1);
  oder->addItem(it2);
  oder->addItem(it3);

  Invoice *inv = new Invoice();
  inv->generateInvoice(*oder);

  OrderRepository *db = new OrderRepository();
  db->save(*oder);

  delete it1;
  delete it2;
  delete it3;

  delete inv;
  delete db;
  delete oder;
}