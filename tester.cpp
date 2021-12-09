#include <iostream>

#include "Crypto.h"

int main(int argc, char ** argv) {
  
  Crypto key(argc == 2 ? argv[1]: "isto é um teste");
 
  key.showMsg();
  key.charToDec();

  int tern[3] = {0, 0, 2};
  Crypto::RGB let(tern);
  let.getCode();

  return 0;
}
