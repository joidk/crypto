#pragma once

#include <string>
#include <iostream>

class Crypto {
  public:
    //Crypto(std::string message) : msg(message) {;}
    Crypto(std::string message);
    ~Crypto() = default;
    
    void showMsg();
    void charToDec();
      
  class RGB {
    public:
      RGB(int* num) : ternary(num) {;}
      char* getCode();
      static unsigned int matrix[3][3];// = {{0, 2, 1}, {2, 1, 0}, {1, 0, 2}};
      unsigned int dot(int, int);

      void showDot();

    private:
      int* ternary;
      char code[3];
  };

  private:
    std::string msg;
    //RGB rgb;
};
