#include <iostream>
#include <fstream>
#include <string>

#include "Crypto.h"

int main(int argc, char ** argv) {

  const char* str = argc == 2 ? argv[1]: "isto e um teste";  
  std::ifstream F("a.txt");
  Crypto::RGB key(F);
  Crypto::RGB chain(str);
  return 0;
}
