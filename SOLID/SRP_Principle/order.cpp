#include <bits/stdc++.h>
using namespace std;

class Item
{
  string name;
  double price;

public:
  Item(string name, double price) : name(name), price(price) {};

  string getName() { return this->name; }
  double getPrice() { return this->price; }
};

// database
class Database
{
public:
  void save()
  {
    cout << "Ordder is saved...." << endl;
  }
};

// order
class Order
{
  vector<Item *> items;
  double total;

public:
  Order()
  {
    cout << "Order is creating..." << endl;
  }

  // add items
  void addItem(Item *item)
  {
    items.push_back(item);
    this->total += item->getPrice();

    cout
        << item->getName() << " added successsfully" << endl;

    // delete item;
  }

  vector<Item *> getItems() { return items; }
  double getTotal() { return total; }

  ~Order()
  {
    for (auto it : items)
    {
      delete it;
    }
  }
};

// invoice
class Invoice
{
public:
  void generateInvoice(Order *order)
  {
    cout << "----------INVOICE----------\n";
    int counter = 0;
    for (auto it : order->getItems())
    {

      cout << "product Name : " << it->getName() << endl;
      cout << "product price : " << it->getPrice() << endl
           << endl;
      counter++;
    }

    cout << "------------------------------" << endl;
    cout << "Total: " << order->getTotal() << endl;
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
  inv->generateInvoice(oder);

  Database *db = new Database();
  db->save();

  delete it1;
  delete it2;
  delete it3;
}