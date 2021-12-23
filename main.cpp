#include <iostream>
#include <fstream>
#include <string>

#include "Crypto.h"
#include "RGBImage.h"

int main(int argc, char ** argv) {

  const char* str = (argc == 2) ? argv[1]: "you passed no arguments so i came here to save you";
  
  std::ifstream file("./docs/message.txt");
  Crypto::RGB code(file);
  
  RGBImage image("encoded.bmp", code.rgbcode());
  
  return 0;
}
