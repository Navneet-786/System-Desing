
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Employee Interface
class IEmployee
{
public:
  virtual void showDetails() = 0;
  virtual ~IEmployee() = default;
};

// developer
class Developer : public IEmployee
{
  string name;
  string department;

public:
  Developer(string name, string dep) : name(name), department(dep) {}; // constructor

  void showDetails() override
  {
    cout << "Developer (" << this->department << " ) :  " << this->name << endl;
  }

  // read
  // const string getName() const { return this->name; }
  // const string getDepartment() const { return this->department; }
};

// manager
class Manager : public IEmployee
{
  string name; // manager name
  string department;
  vector<IEmployee *> team;

public:
  Manager(string name, string dep) : name(name), department(dep) {};

  void addEmployee(IEmployee *emp)
  {
    team.push_back(emp);
  }

  void showDetails() override
  {
    cout << "----Manager (" << this->department << " ) :  " << this->name << "------" << endl
         << endl;

    for (auto it : team)
    {
      it->showDetails();
    }
  }
};

int main()
{
  Manager *CEO = new Manager("Navneet", "Company Owner");

  IEmployee *hr = new Manager("Priyanshu", "HR");
  CEO->addEmployee(hr);

  IEmployee *emp1 = new Developer("Mohan", "elastic search");
  IEmployee *emp2 = new Developer("Ruhi", "Cloud Handler");
  IEmployee *emp3 = new Developer("Sohan", "API Handler");

  IEmployee *emp4 = new Developer("Sonu", "UI");
  IEmployee *emp5 = new Developer("Monu", "UX");
  IEmployee *emp6 = new Developer("Ruchi", "Product analyst");
  Manager *manager1 = new Manager("Rohan", "backend");
  CEO->addEmployee(manager1);
  manager1->addEmployee(emp1);
  manager1->addEmployee(emp2);
  manager1->addEmployee(emp3);

  Manager *manager2 = new Manager("Rupesh", "Frontend");
  CEO->addEmployee(manager2);
  manager2->addEmployee(emp4);
  manager2->addEmployee(emp5);
  manager2->addEmployee(emp6);

  CEO->showDetails();
}
