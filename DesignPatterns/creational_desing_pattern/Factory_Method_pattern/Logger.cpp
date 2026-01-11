#include <bits/stdc++.h>
using namespace std;

// create a interface of logger class
class Logger
{
public:
  virtual void log(string msg) const = 0;
  virtual ~Logger() = default;
};

// concrete classes
// file logger
class FileLogger : public Logger
{
public:
  void log(string msg) const
  {
    cout << "[File Log ]: " << msg << endl;
  }
};

// console logger
class ConsoleLogger : public Logger
{
public:
  void log(string msg) const
  {
    cout << "[console Log ]: " << msg << endl;
  }
};

// Factory Method (interface)
class LoggerFactory
{

public:
  virtual unique_ptr<Logger> createLog() = 0;
  virtual ~LoggerFactory() = default;
};

// File Logger Factory
class FileLoggerFactory : public LoggerFactory
{
public:
  unique_ptr<Logger> createLog()
  {
    return make_unique<FileLogger>();
  }
};

// console logger factory
class ConsoleLoggerFactory : public LoggerFactory
{
public:
  unique_ptr<Logger> createLog()
  {
    return make_unique<ConsoleLogger>();
  }
};

int main()
{

  // factory log
  unique_ptr<LoggerFactory> factory = make_unique<FileLoggerFactory>();
  unique_ptr<Logger> lg = factory->createLog();

  lg->log("This is file log");

  // console log
  unique_ptr<LoggerFactory> factory2 = make_unique<ConsoleLoggerFactory>();
  unique_ptr<Logger> lg1 = factory2->createLog();
  lg1->log("this is Console log");
}
