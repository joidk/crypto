#pragma once

#include <string>
#include <iostream>

class Crypto {
  public:
    Crypto(std::string message) : msg(message) {;}
    ~Crypto() = default;
    
    void showMsg();
    void charToDec();
    
  class RGB {
    public:
      RGB(int* num) : ternary(num) {;}
      char* getCode();
      
    private:
      int* ternary;
      char code[3];
  };

  private:
    std::string msg;
};
