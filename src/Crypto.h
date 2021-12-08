#pragma once

#include <string>
#include <iostream>

class Crypto {  
  public:
    Crypto(std::string message) : msg(message) {;}
    ~Crypto() = default;
    
    void showMsg();
    void charToDec();

  private:
    std::string msg;
};
