#pragma once

#include <string>
#include <iostream>

/*
 *  Class with cryptography algorithms
 */
class Crypto {
  public:
    Crypto(std::string msg_) : msg(msg_) {;}
    ~Crypto() = default;
    
    void showMsg();
    void charToDec();
      
  class RGB {
    public:
      //RGB(std::string message);
      RGB(int* num) : ternary(num) {;}
      ~RGB() = default;

      static unsigned int matrix[3][3];
      static char symbols[3];
      
      unsigned int dot(int, int);
      char* getCode();

      void showDot();

    private:
      int* ternary;
      char code[3];
  };

  private:
    std::string msg;
    //RGB rgb;

  protected:
    class FileHandler {
      public:
        FileHandler(std::string filename) : fname(filename) {;}
        ~FileHandler() = default;

      private:
        std::string fname;
    };
};
