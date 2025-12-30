#include <bits/stdc++.h>
using namespace std;

// product class
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

  // get name
  string getName()
  {
    return this->name;
  }

  // get price
  int getPrice()
  {
    return this->price;
  }
};

// cart class
class ShoppingCart
{
  // create a vector of products
  vector<Product *> cart;

public:
  ShoppingCart()
  {
    cout << "Welcome to Shopping new Cart" << endl;
  }

  // method to return cart
  const vector<Product *> &getCartList()
  {
    return cart;
  }

  // add product to cart
  void addPrductToCart(Product *p)
  {
    this->cart.push_back(p);
  }

  // calculate the total
  double calculateTotal()
  {
    double total = 0;
    for (auto it : this->cart)
    {
      total += it->getPrice();
    }

    return total;
  }
};

// generate Invoice
class CartInvoicePrinter
{
  ShoppingCart *cart;

public:
  CartInvoicePrinter(ShoppingCart *sc)
  {
    this->cart = sc;
  }

  // print invoice
  void printInvoice()
  {
    for (auto it : cart->getCartList())
    {
      cout << it->getName() << " : " << it->getPrice() << endl;
    }
    cout << "---------------------------------" << endl;
    cout << "Total: " << cart->calculateTotal() << endl;
    cout << "---------------------------------" << endl;
  }
};

// create an abstract class to create multiple instance of db so that they follow OCP
class DbPersistence
{
  ShoppingCart *sc;

public:
  virtual void save(ShoppingCart *sc) = 0;
};

class SaveToMongo : public DbPersistence
{

public:
  void save(ShoppingCart *sc) override
  {
    cout << "saving cart to MongoDb...." << endl;
  }
};

class SaveToMySQl : public DbPersistence
{

public:
  void save(ShoppingCart *sc) override
  {
    cout << "saving cart to MySQl...." << endl;
  }
};

class SaveToFile : public DbPersistence
{

public:
  void save(ShoppingCart *sc) override
  {
    ofstream file("cart.txt", ios::app);

    if (!file.is_open())
    {
      cout << "File open failed!" << endl;
      return;
    }

    for (auto it : sc->getCartList())
    {
      string data = it->getName() + " : " + to_string(it->getPrice());

      file << data << endl;
    }
    file.close();

    cout << "saving cart to FIle...." << endl;
  }
};

int main()
{
  ShoppingCart *sc = new ShoppingCart();

  Product *p1 = new Product("Laptop", 50000);
  sc->addPrductToCart(p1);

  Product *p2 = new Product("Mouse", 50);
  sc->addPrductToCart(p2);

  Product *p3 = new Product("keyboard", 2000);
  sc->addPrductToCart(p3);

  // cart Invoice generate
  CartInvoicePrinter *printer = new CartInvoicePrinter(sc);

  printer->printInvoice();

  // saving cart to different db instance
  DbPersistence *db = new SaveToMySQl();
  DbPersistence *mongodb = new SaveToMongo();
  DbPersistence *saveFile = new SaveToFile();

  db->save(sc);
  mongodb->save(sc);
  saveFile->save(sc);
}
