#include <iostream>
#include <fstream>
#include <string>

#include "Crypto.h"
#include "RGBImage.h"

int main(int argc, char ** argv) {

  const char* saviorMsg = "you sent no arguments so i came to save the build";
  const char* str = argc == 2 ? argv[1]: saviorMsg;

  std::ifstream file("./docs/message.txt");
  Crypto::RGB key(file);

  RGBImage image("encoded.bmp", key.rgbcode());

  return 0;
}
