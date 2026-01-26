// Let's say we have a collection of employees in a company, and we want to iterate over the employees to calculate their total salary. However, the employees are stored in different types of collections (arrays, lists, etc.), and we want to iterate over them without exposing the underlying collection types.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// create Employee class
class Employee
{
  string name;
  double salary;

public:
  Employee(string name, double s) : name(name), salary(s) {};

  // getter
  string getName() { return this->name; }
  double getSalary() { return this->salary; }

  // setter
  void setSalary(double s)
  {
    this->salary = s;
  }
};

// create an iterator interface
class Iterator
{
public:
  virtual bool hasNext() = 0;
  virtual Employee *next() = 0;
  virtual ~Iterator() = default;
};

// EmplyeeCollectionInterface
class EmployeeCollectionInterface
{
public:
  virtual Iterator *createIterator() = 0;
  virtual ~EmployeeCollectionInterface() = default;
};

class EmployeeVectorCollection : public EmployeeCollectionInterface
{
  vector<Employee *> employees;

public:
  EmployeeVectorCollection() {};

  void addEmployee(Employee *emp)
  {
    employees.push_back(emp);
  }

  vector<Employee *> &getEmployees()
  {
    return this->employees;
  }

  Iterator *createIterator() override;
};

// concreate Iterator
class VectorIterator : public Iterator
{
  vector<Employee *> emp;

  int index = 0;

public:
  VectorIterator(vector<Employee *> e) : emp(e) {};

  bool hasNext()
  {
    return index < emp.size();
  }

  Employee *next()
  {
    return emp[index++];
  }
};

Iterator *EmployeeVectorCollection::createIterator()
{
  return new VectorIterator(employees);
}

int main()
{
  EmployeeVectorCollection *collection = new EmployeeVectorCollection();

  collection->addEmployee(new Employee("Rohan", 40000));
  collection->addEmployee(new Employee("Sohan", 50000));
  collection->addEmployee(new Employee("Mohan", 30000));
  collection->addEmployee(new Employee("Ruby", 45000));

  Iterator *it = collection->createIterator();

  int totalSalary = 0;
  while (it->hasNext())
  {
    totalSalary += it->next()->getSalary();
  }
  cout << "Total Salary = " << totalSalary << endl;
}