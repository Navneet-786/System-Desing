#include <bits/stdc++.h>
using namespace std;

class Doctor
{
public:
  virtual void treatPatient() = 0;
  virtual ~Doctor() {};
};

class SurgeonDoctor : public Doctor
{
public:
  virtual void surgery() = 0;
};

class Surgeon : public SurgeonDoctor
{
public:
  void treatPatient() override
  {
    cout << "Surgeon is treating patient...." << endl;
  }

  void surgery() override
  {
    cout << "surgeon can do surgury" << endl;
  }
};

class GeneralPhysician : public Doctor
{
public:
  void treatPatient() override
  {
    cout << "doctor can do treatment" << endl;
  }
};

int main()
{
  SurgeonDoctor *d1 = new Surgeon();
  d1->surgery();
  d1->treatPatient();

  Doctor *d2 = new GeneralPhysician();
  d2->treatPatient();

  delete d1;
  delete d2;
}

// BREAK LSP
//  class Doctor
//  {
//  public:
//    virtual void treatPatient() = 0;
//    virtual void surguryPatient() = 0;
//  };

// class Surgeon : public Doctor
// {
// public:
//   void treatPatient() override
//   {
//     cout << "Doctor is treating patient...." << endl;
//   }

//   void surguryPatient() override
//   {
//     cout << "doctor can do surgury" << endl;
//   }
// };

// class GeneralPhysician : public Doctor
// {
// public:
//   void treatPatient() override
//   {
//     cout << "Doctor is treating patient...." << endl;
//   }

//   void surguryPatient() override
//   {
//     throw runtime_error("not possiblt");
//     // cout << "doctor can not do surgury" << endl;
//   }
// };

// int main()
// {
//   Doctor *d1 = new Surgeon();
//   d1->surguryPatient();

//   Doctor *d2 = new GeneralPhysician();
//   d2->surguryPatient();

//   delete d1;
//   delete d2;
// }