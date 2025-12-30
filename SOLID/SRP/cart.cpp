#include <bits/stdc++.h>
using namespace std;

// crete Product class
class Product
{
  string name;
  int price;

public:
  // constructor
  Product(string name, int price)
  {
    this->name = name;
    this->price = price;
  }

  // gettter name
  string getName()
  {
    return this->name;
  }
  // setter name
  string setName(string newName)
  {
    this->name = newName;
    cout << "Name has been updated" << endl;
  }

  // getter price
  int getPrice()
  {
    return this->price;
  }
  // set price
  void setPrice(int p)
  {
    this->price = p;
  }
};

class ShoppingCart
{
  vector<Product *> products;

public:
  ShoppingCart()
  {
    cout << "Shopping cart created..." << endl;
  }
  // add product
  void addProduct(Product *p)
  {
    products.push_back(p);
  }

  // return the vector of products (products reference)
  const vector<Product *> &getProducts()
  {
    return products;
  }

  // calculate total price of products
  double calculateTotal()
  {
    double total = 0;
    for (auto it : products)
    {
      total += it->getPrice();
    }

    return total;
  }
};

// cart invoice genereator
class ShoppingCartPrinter
{
  ShoppingCart *cart; // shopping cart instance

public:
  // constructor
  ShoppingCartPrinter(ShoppingCart *sc)
  {
    this->cart = sc;
  }

  void printInvoice()
  {
    cout << "shopping cart Invoice" << endl;
    for (auto p : cart->getProducts())
    {
      cout << p->getName() << " : " << p->getPrice() << endl;
    }
    cout << "--------------------------------------" << endl;
    cout << "Total: " << cart->calculateTotal() << endl;
    cout << "--------------------------------------" << endl;
  }
};

class ShoppingCartStorage
{
  ShoppingCart *cart;

public:
  ShoppingCartStorage(ShoppingCart *cart)
  {
    this->cart = cart;
  }

  void saveToDb()
  {
    cout << "Saving shopping cart to Database...." << endl;
  }
};

int main()
{
  // create an instance of shopping Crat
  ShoppingCart *cart = new ShoppingCart();

  Product *p1 = new Product("Laptop", 50000);
  cart->addProduct(p1);

  Product *p2 = new Product("Speaker", 2000);
  cart->addProduct(p2);

  Product *p3 = new Product("Mouse", 100);
  cart->addProduct(p3);

  // print the invoice
  ShoppingCartPrinter *printer = new ShoppingCartPrinter(cart);
  printer->printInvoice(); // this print invoice

  // after printing save to db
  ShoppingCartStorage *db = new ShoppingCartStorage(cart);

  db->saveToDb();
}