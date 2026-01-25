#include <iostream>

using namespace std;

// Laptop->cpu/ram (mandatory)//
// optional-> SSD, OS , GPU

// object representation
class Laptop
{
public:
  string cpu;
  int ram;
  bool ssd = false;
  bool gpu = false;
  bool os = false;
  bool warranty = false;

  void showConfig()
  {
    cout << "CPU: " << cpu << endl;
    cout << "RAM: " << ram << "GB\n";
    cout << "SSD: " << ssd << endl;
    cout << "GPU: " << gpu << endl;
    cout << "OS: " << os << endl;
    cout << "Warranty: " << warranty << endl;
  }
};

// object conctruction
class LaptopBuilder
{
private:
  Laptop laptop; // direct object create

public:
  LaptopBuilder(string cpu, int ram)
  {
    laptop.cpu = cpu;
    laptop.ram = ram;
  }

  // adding ssd
  LaptopBuilder &addSSD()
  {
    laptop.ssd = true;
    return *this;
  }

  // Add GPU
  LaptopBuilder &addGPU()
  {
    laptop.gpu = true;
    return *this;
  }

  // add OS
  LaptopBuilder &addOS()
  {
    laptop.os = true;
    return *this;
  }

  LaptopBuilder &addWarranty()
  {
    laptop.warranty = true;
    return *this;
  }

  Laptop build()
  {

    // good practice is to check and validate
    // before returing object
    if (laptop.cpu.empty() || laptop.ram <= 0)
    {
      throw runtime_error("Invalid laptop configuration");
    }
    return laptop;
  }
};

int main()
{
  Laptop laptop1 = LaptopBuilder("i7")
                       .addOS()
                       .addGPU()
                       .addSSD()
                       .build();

  laptop1.showConfig();
}