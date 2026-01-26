// iterator in 2 ways
//  1. normal itertate
// 2. price filter (price > 500)

#include <iostream>
#include <vector>
using namespace std;

// book
class Book
{
  string name;
  double price;

public:
  Book(string n, double p) : name(n), price(p) {};

  // getter
  const string &getName() { return this->name; }
  const double &getPrice() { return this->price; }

  // setter
  void setPrice(const double newPrice)
  {
    this->price = newPrice;
    cout << "Price of book " << this->getName() << "update successfully \n"
         << endl;
  }
};

// Iterator Interface
class Iterator
{
public:
  virtual bool hasNext() = 0;
  virtual Book *next() = 0;
  virtual ~Iterator() = default;
};

// concrete Itertaor
class NormalIterator : public Iterator
{
  vector<Book *> books;
  int index = 0;

public:
  NormalIterator(vector<Book *> b)
  {
    this->books = b;
  }
  bool hasNext() override
  {
    return index < books.size();
  }

  Book *next() override
  {
    return books[index++];
  }
};

// filter Iterator
class PriceFilterIterator : public Iterator
{
  vector<Book *> books;
  int index = 0;

public:
  PriceFilterIterator(vector<Book *> b)
  {
    this->books = b;
  }
  bool hasNext() override
  {
    // you can not stop until you get price > 500
    while (index < books.size())
    {
      if (books[index]->getPrice() > 500)
      {
        return true;
      }
      index++;
    }
    return false;
  }

  Book *next()
  {
    return books[index++];
  }
};

// Library->collection
class IBookCollection
{
public:
  virtual Iterator *createIterator() = 0;
  virtual Iterator *createPriceFilterIterator() = 0;
  virtual ~IBookCollection() = default;
};

class Library : public IBookCollection
{
  vector<Book *> books;

public:
  Library()
  {
    cout << "Libary is created" << endl;
  };

  // add books
  void addBook(Book *b)
  {
    books.push_back(b);
  }

  // iterator (normal)
  Iterator *createIterator() override
  {
    return new NormalIterator(books);
  }

  Iterator *createPriceFilterIterator() override
  {
    return new PriceFilterIterator(books);
  }
};

int main()
{
  Library *lib = new Library();

  // create books and add them
  lib->addBook(new Book("Fairy in tail", 600));
  lib->addBook(new Book("Twinkle Twinkle litte start", 400));
  lib->addBook(new Book("Story of great Warrior", 750));
  lib->addBook(new Book("Land of fire", 500));
  lib->addBook(new Book("Justice for public", 300));

  // normal iterate
  Iterator *it1 = lib->createIterator();
  while (it1->hasNext())
  {
    Book *b = it1->next();
    cout << "Book: " << b->getName() << " || Price: " << b->getPrice() << endl;
  }

  // filter iterator
  cout << "\n\n\nBooks with price > 500" << endl
       << endl;
  Iterator *it2 = lib->createPriceFilterIterator();
  while (it2->hasNext())
  {
    Book *b = it2->next();
    cout << "Book: " << b->getName() << " || Price: " << b->getPrice() << endl;
  }

  delete lib;
}
