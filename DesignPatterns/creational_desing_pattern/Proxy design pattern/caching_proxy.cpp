#include <iostream>
#include <unordered_map>
using namespace std;

class Database
{
public:
  virtual string getData(int id) = 0;
  virtual ~Database() = default;
};

class RealDatabase : public Database
{
public:
  string getData(int id)
  {
    cout << "fetching data from db..." << endl;
    return "UserData";
  }
};

class DbProxy : public Database
{
  Database *realDb;
  unordered_map<int, string> cache;

public:
  DbProxy(Database *db) : realDb(db) {};

  string getData(int id)
  {
    // first check into cache
    if (cache.count(id))
    {
      cout << "Returning cached data\n";
      return cache[id];
    }
    // if not in cache then call actual object
    string res = realDb->getData(id);
    cache[id] = res;
    return res;
  }

  ~DbProxy()
  {
    delete realDb;
  }
};

int main()
{
  Database *db = new RealDatabase();

  Database *dbproxy = new DbProxy(db);

  cout << dbproxy->getData(2);
}