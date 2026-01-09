#include <bits/stdc++.h>
using namespace std;

class Teacher
{
  string name;
  string dep;
  int age;

public:
  Teacher(string name, string dep, int age) : name(name), dep(dep), age(age) {}

  string getName() const { return this->name; };
  string getDep() const { return this->dep; }
  int getAge() const { return this->age; }
};

class School
{
  vector<const Teacher *> teachers;
  string name;

public:
  School(string name) : name(name) {};

  // get school name
  string getSchoolName() const { return this->name; }

  // add teacher
  void addTeacher(const Teacher &t)
  {
    teachers.push_back(&t);
  }

  // get All Teacher
  const vector<const Teacher *> &getAllTeachers() const
  {
    return this->teachers;
  }

  // print all Teachers
  void printTeacher() const
  {
    for (auto it : this->getAllTeachers())
    {
      cout << "Name: " << it->getName() << endl;
      cout << "Dep: " << it->getDep() << endl;
      cout << "age: " << it->getAge() << endl;
      cout << endl;
    }
  }
};

int main()
{
  School sc("Mahrishi vidya Mandir");
  cout << sc.getSchoolName();

  cout << endl
       << endl;

  Teacher t1("Rohan", "science", 20);
  Teacher t2("Mohan", "Geography", 24);
  sc.addTeacher(t1);
  sc.addTeacher(t2);

  sc.printTeacher();
}