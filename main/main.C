#include <iostream>

#include "Crypto.h"

int main(int argc, char ** argv) {
  
  Crypto key(argc == 2 ? argv[1]: "isto é um teste");
  key.showMsg();
  key.charToDec();
  return 0;
}
