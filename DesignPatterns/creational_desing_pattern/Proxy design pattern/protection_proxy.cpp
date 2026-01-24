#include <iostream>
#include <string>
using namespace std;

// admin dashboard can access to only admin
class AdminPannel
{
public:
  virtual void deleteUser() = 0;
};

class RealAdminPannel : public AdminPannel
{
public:
  void deleteUser() override
  {
    cout << "user deleted..." << endl;
  }
};

class AdminPannelproxy : public AdminPannel
{
  bool isAdmin;
  AdminPannel *realAdminPannel;

public:
  AdminPannelproxy(bool isAdmin, AdminPannel *pannel) : isAdmin(isAdmin), realAdminPannel(pannel) {};

  void deleteUser() override
  {
    if (!isAdmin)
    {
      cout << "Access Denied:  Only For Admin" << endl;
      return;
    }
    realAdminPannel->deleteUser();
  }
  ~AdminPannelproxy()
  {
    delete realAdminPannel;
  }
};

int main()
{
  AdminPannel *realAdminPannel = new RealAdminPannel();

  // normal user
  AdminPannel *adminProxy = new AdminPannelproxy(false, realAdminPannel);

  adminProxy->deleteUser();

  // admin
  AdminPannel *adminProxy1 = new AdminPannelproxy(true, realAdminPannel);
  adminProxy1->deleteUser();
}
