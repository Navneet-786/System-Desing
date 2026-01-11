#include <bits/stdc++.h>
using namespace std;

// --------------------------BUTTON--------------------
// Button-> [light button , dark button]

class Button // interface
{
public:
  virtual void create() = 0;
  virtual ~Button() = default;
};

// concrete button classes
class LightButton : public Button
{
public:
  void create() override
  {
    cout << "Light Button created..." << endl;
  }
};

class DarkButton : public Button
{
public:
  void create() override
  {
    cout << "Dark Button created..." << endl;
  }
};

// --------------------CHECKBOX-----------------------------

// checkbox-> [light checkbox , dark checkbox]
class CheckBox
{
public:
  virtual void create() = 0;
  virtual ~CheckBox() = default;
};

// concrete button classes
class LightCheckbox : public CheckBox
{
public:
  void create() override
  {
    cout << "Light CheckBox created..." << endl;
  }
};

class DarkCheckbox : public CheckBox
{
public:
  void create() override
  {
    cout << "Dark checkbox created..." << endl;
  }
};

// --------------------TEXT FIELD-----------------------------

// TextField-> [light field , dark field]
class TextField
{
public:
  virtual void create() = 0;
  virtual ~TextField() = default;
};

// concrete button classes
class LightTextField : public TextField
{
public:
  void create() override
  {
    cout << "Light TextField created..." << endl;
  }
};

class DarkTextField : public TextField
{
public:
  void create() override
  {
    cout << "Dark TextField created..." << endl;
  }
};

// -----------------------------THEMES FACTORY-------------------------
class ThemeFactory
{
public:
  virtual unique_ptr<Button> createButton() = 0;
  virtual unique_ptr<CheckBox> createCheckbox() = 0;
  virtual unique_ptr<TextField> createTextField() = 0;

  virtual ~ThemeFactory() = default;
};

// light theme factory
class LightThemeFactory : public ThemeFactory
{
public:
  // light button
  unique_ptr<Button> createButton() override
  {
    return make_unique<LightButton>();
  }

  // light checkbox
  unique_ptr<CheckBox> createCheckbox() override
  {
    return make_unique<LightCheckbox>();
  }

  // light textField
  unique_ptr<TextField> createTextField() override
  {
    return make_unique<LightTextField>();
  }
};

// Dark theme factory
class DarkThemeFactory : public ThemeFactory
{
public:
  // Dark button
  unique_ptr<Button> createButton() override
  {
    return make_unique<DarkButton>();
  }

  // Dark checkbox
  unique_ptr<CheckBox> createCheckbox() override
  {
    return make_unique<DarkCheckbox>();
  }

  // Dark textField
  unique_ptr<TextField> createTextField() override
  {
    return make_unique<DarkTextField>();
  }
};

int main()
{
  unique_ptr<ThemeFactory> theme1 = nullptr;

  int choice = 0; // default light theme
  cout << "select the theme you want" << endl;
  cout << "1. Dark Theme" << endl;
  cout << "2. Light Theme" << endl;

  cout << endl;
  cin >> choice;
  cout << endl;

  switch (choice)
  {
  case 1:
    theme1 = make_unique<DarkThemeFactory>();
    break;

  case 2:
    theme1 = make_unique<LightThemeFactory>();
    break;

  default:
    cout << "No  theme is Available" << endl;
    return 0;
    break;
  }

  unique_ptr<Button> button1 = theme1->createButton();
  unique_ptr<CheckBox> checkbox1 = theme1->createCheckbox();
  unique_ptr<TextField> textfield1 = theme1->createTextField();

  button1->create();
  checkbox1->create();
  textfield1->create();
}
