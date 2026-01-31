#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MenuComponent
{
public:
  virtual void showItem() = 0;
  virtual ~MenuComponent() = default;
};

// leasf nodes
class MenuItem : public MenuComponent
{
  string name;
  double price;

public:
  MenuItem(const string name, const double price) : name(name), price(price) {};

  void showItem() override
  {
    cout << "  Dish: " << name << " | Price: " << price << endl;
  }
};

class Menu : public MenuComponent
{
  string name;
  vector<MenuComponent *> menu;

public:
  Menu(const string name) : name(name) {};

  void addMenuItem(MenuComponent *item)
  {
    menu.push_back(item);
  }

  void showItem() override
  {
    cout << "\nmenu:  " << name << endl;
    for (auto it : menu)
    {
      it->showItem();
    }
  }
};

// client code
int main()
{
  MenuComponent *dish1 = new MenuItem("Rice Paneer", 400);
  MenuComponent *dish2 = new MenuItem("Rajma Rice", 350);
  MenuComponent *dish3 = new MenuItem("Biriyani", 200);
  MenuComponent *dish4 = new MenuItem("Chowmine", 50);
  MenuComponent *dish5 = new MenuItem("Goolgappe", 20);

  Menu *dinnerMenu = new Menu("Dinner");
  dinnerMenu->addMenuItem(dish1);
  dinnerMenu->addMenuItem(dish2);

  Menu *mainMenu = new Menu("Main Menu");
  mainMenu->addMenuItem(dish3);
  mainMenu->addMenuItem(dish4);
  mainMenu->addMenuItem(dish5);
  mainMenu->addMenuItem(dinnerMenu);

  mainMenu->showItem();
}