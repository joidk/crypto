#include "Crypto.h"

unsigned int Crypto::RGB::matrix[3][3] = {{0, 2, 1},
                                          {2, 1, 0},
                                          {1, 0, 2}};

/*
 *  
 *
void Crypto::RGB::decToTer(int* decmsg) {
    int size = sizeof(decmsg) / sizeof(int);
    int termsg[size][3];

    for(int j = 0; j < size; ++j) {
        int i = 2;
        do {
            if(decmsg[j] != 0) {
                termsg[j][i] = decmsg[j] % 3;
                decmsg[j] = (int)decmsg[j] / 3;
            } else
              termsg[j][i] = 0;
            --i;
        } while(i > -1);
    }
*/
/*
 *  Produces "cross" operation 
 */
unsigned int Crypto::RGB::dot(int i, int j) {
  return RGB::matrix[i][j];
}

void Crypto::RGB::showDot() {
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j ++)
      printf("\t<%d, %d> = %d\n", i, j, Crypto::RGB::matrix[i][j]);
}

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
}

char* Crypto::RGB::getCode() {
  printf("%d, %d, %d\n", this->ternary[0], this->ternary[1], this->ternary[2]);
  //printf("[%c, %c, %c]", code[2], code[1], code[0]);
  return this->code;
}


