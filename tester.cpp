#include <iostream>

#include "Crypto.h"

int main(int argc, char ** argv) {
  
  Crypto crypto(argc == 2 ? argv[1] : "isto é um teste");
 
  crypto.showMsg();
  crypto.charToDec();

  int tern[3] = {0, 0, 2};
  Crypto::RGB rgb(tern);
  rgb.getCode();

  rgb.showDot(); 
  return 0;
}
