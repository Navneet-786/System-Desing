#include <iostream>
#include <memory>
using namespace std;

// request object
struct Request
{
  string token;
  string user;
  string role;
};

// handler interface
class IAuthHandler
{

public:
  IAuthHandler() {};

  // set the next handler
  virtual void setNextHandler(IAuthHandler *handler) = 0;

  virtual bool handle(string request) = 0;

  virtual ~IAuthHandler() = default;
};

// token validator handler
class TokenHandler : public IAuthHandler
{
private:
  IAuthHandler *nextHandler;

public:
  // set the next handler
  void setNextHandler(IAuthHandler *next) override
  {
    nextHandler = next;
  }

  bool handle(string request) override
  {
    cout << "token validating..." << endl;

    // if token is not valid
    if (request != "valid_token")
    {
      cout << "Invalid Token" << endl;
      return false;
    }

    if (nextHandler)
    {
      return nextHandler->handle(request);
    }

    return true;
  }
};

// user validation handler
class UserValidationHandler : public IAuthHandler
{
private:
  IAuthHandler *nextHandler;

public:
  void setNextHandler(IAuthHandler *next) override
  {
    nextHandler = next;
  }

  bool handle(string request) override
  {
    cout << "User validation...\n";

    // if token is not valid
    if (request != "valid_token")
    {
      cout << "Invalid Token" << endl;
      return false;
    }

    if (nextHandler)
    {
      return nextHandler->handle(request);
    }

    return true;
  }
};

// role validation handler
class RoleValidationHandler : public IAuthHandler
{
private:
  IAuthHandler *nextHandler;

public:
  void setNextHandler(IAuthHandler *next) override
  {
    nextHandler = next;
  }

  bool handle(string request) override
  {
    cout << "Role validation...\n";

    // if token is not valid
    if (request != "valid_token")
    {
      cout << "Invalid Token" << endl;
      return false;
    }

    if (nextHandler)
    {
      return nextHandler->handle(request);
    }

    return true;
  }
};

int main()
{
  // create Handler
  IAuthHandler *token = new TokenHandler();
  IAuthHandler *user = new UserValidationHandler();
  IAuthHandler *role = new RoleValidationHandler();

  // make a chain
  token->setNextHandler(user);
  user->setNextHandler(role);

  // -------------request start-------------------
  bool res = token->handle("valid_token");
  if (res)
  {
    cout << "Access Granted" << endl;
  }
  else
  {
    cout << "Access Denied" << endl;
  }

  delete token;
  delete user;
  delete role;
}