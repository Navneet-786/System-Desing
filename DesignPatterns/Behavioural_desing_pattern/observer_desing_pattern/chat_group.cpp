#include <bits/stdc++.h>
using namespace std;

// interface for observer
class Observer
{
public:
  virtual void update(const string &msg) = 0;
  virtual ~Observer() {};
};

// publisher interface
class Publisher
{
public:
  virtual void subscribe(Observer *obj) = 0;
  virtual void unsubscribe(Observer *obj) = 0;
  virtual void notify() = 0;

  virtual ~Publisher() {};
};

// create GroupChat
class GroupChat : public Publisher
{
  vector<Observer *> members;
  vector<string> messages;

public:
  void subscribe(Observer *obj) override
  {
    this->members.push_back(obj);
  }

  void unsubscribe(Observer *obj) override
  {
    // remove from group
    auto it = find(members.begin(), members.end(), obj);
    if (it != members.end())
    {
      // then erase
      members.erase(it);
    }
  }

  void notify() override
  {
    // notify all members
    for (auto &member : members)
    {
      member->update(messages.back());
    }
  }

  void sendMessage(const string &msg)
  {
    messages.push_back(msg);
    notify();
  }
};

// create Friend ->which will memeber of group
class Friend : public Observer
{
  string name;

public:
  Friend(const string &name) : name(name) {};

  void update(const string &incomminMsg)
  {
    cout << name << " received a message: " << incomminMsg << endl;
  }
};

int main()
{
  // create group
  GroupChat chat;

  Friend f1("Rohan");
  Friend f2("Mohan");
  Friend f3("sohan");

  chat.subscribe(&f1);
  chat.subscribe(&f2);
  chat.subscribe(&f3);

  chat.sendMessage("this is new message here...");
}