#include <iostream>

#include "Crypto.h"
#include <string>

int main(int argc, char ** argv) {

  const char* str = argc == 2 ? argv[1]: "isto é um teste";  
  Crypto::RGB key(str);
  return 0;
}
