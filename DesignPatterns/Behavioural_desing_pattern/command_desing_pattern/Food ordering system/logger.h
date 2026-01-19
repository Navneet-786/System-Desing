#ifndef LOGGER_SERVICE
#define LOGGER_SERVICE

#include <string>
#include <iostream>
#include <fstream>
class Logger
{
public:
  virtual void log(const std::string &str) = 0;
  virtual ~Logger() = default;
};

class FileLogger : public Logger
{
public:
  void log(const std::string &str)
  {
    std::fstream f("orders.txt", std::ios::app);

    std::string s = "[Log] : " + str;
    f << s << std::endl;

    f.close();
  }
};

#endif