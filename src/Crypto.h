#pragma once

#include <string>
#include <iostream>

/*
 *  Class with cryptography algorithms
 */
class Crypto {
  public:
    Crypto() = default;
    ~Crypto() = default;
    
      
  class RGB {
    public:
      RGB(std::string mes_);
      ~RGB() = default;

      static unsigned int matrix[3][3];
      static char symbols[3];
      
      void decToTern();
      void ternToCodedRGB();
      unsigned int dot(int, int);
      char* getCode();
      void strToDec();

      bool convert();

    private:
      char code[3];
      int* decimalArray;
      int Nchars;
      int* ternArray;
      char* RGBcode;
      std::string msg;
  };

};
