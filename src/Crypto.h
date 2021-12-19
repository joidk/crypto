#pragma once

#include <string>
#include <iostream>
#include <fstream>

/*
 *  Class with cryptography algorithms
 */
class Crypto {
  public:
    Crypto() = default;
    ~Crypto() = default;
    
      
  class RGB {
    public:
      RGB(std::string mes_); // Constructor - reads strings as argument
      RGB(std::ifstream& F); // Constructor - reads string from a File
      ~RGB() = default;
      
      bool convert(); //  Convert string to RGBcode
      void strToDec(); // Convert string to decimal
      void decToTern(); //  Convert decimal to ternary
      void ternToCodedRGB(); // Convert ternary to RGB code using a predefined dot product(matrix)
      unsigned int dot(int, int); //  Dot product used

      static unsigned int matrix[3][3];
      static char symbols[3];

    private:
      std::string msg; // message as string
      int Nchars; // message's size
      int* decimalArray; // message as decimal
      int* ternArray; // message as ternary
      char* RGBcode; // message as RGBcode

  };

};
