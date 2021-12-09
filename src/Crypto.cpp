#include "Crypto.h"

/*
 *  Show message on screen
 */
void Crypto::showMsg() {
  std::cout << "MESSAGE:\t" << this->msg << std::endl;
}


/*
 *  Converts char to decimal
 */
void Crypto::charToDec() {
  
  unsigned int decArr[msg.size()], size = msg.size();
  for(int i = 0; i < size; i++) {
    if('A' <= msg[i] && msg[i] <= 'Z')
      msg[i] = msg[i] - ('A' - 'a');
    
    decArr[i] = msg[i] - 'a';
    if(msg[i] < 'a' || msg[i] > 'z')
      decArr[i] = 26;
  }
  //printf("%d %c  :  sChar: %d \n", msg[1], msg[1], sChar);
}

char* Crypto::RGB::getCode() {
  printf("%d, %d, %d\n", this->ternary[0], this->ternary[1], this->ternary[2]);
  //printf("[%c, %c, %c]", code[2], code[1], code[0]);
  return this->code;
}
