#include "Crypto.h"

<<<<<<< HEAD
char symbols[3] = { 'R', 'G', 'B' }; 
unsigned int Crypto::RGB::matrix[3][3] = {{0, 2, 1},
                                          {2, 1, 0},
                                          {1, 0, 2}};

bool Crypto::RGB::convert() {
  strToDec();

  for (int i = 0; i < Nchars; ++i) {
    std::cout << decimalArray[i] << std::endl;
  }

 /* decToTern();
  for (int i = 0; i < 3*Nchars; ++i) {
    std::cout << ternArray[i] << std::endl;
  }
  ternToCodedRGB();
*/
  return true;
}


Crypto::RGB::RGB(std::string mes_) {
  Nchars = mes_.size();
  msg = mes_;

  convert(); 
}
=======
char Crypto::RGB::symbols[3]            = { 'R', 'G', 'B' };
unsigned int Crypto::RGB::matrix[3][3]  = { {0, 2, 1},
                                            {2, 1, 0},
                                            {1, 0, 2} };
>>>>>>> 2612c0e6eec9add63047bc54ea708046d1cf3150

/*
 *  Produces operation 
 */
<<<<<<< HEAD
void Crypto::RGB::decToTern() {
    
  for (int i = 0; i < Nchars; ++i) {
    std::cout << decimalArray[i] << std::endl;
  }
  std::cout << std::endl;

    int* decmsg = decimalArray; 
    //int size = sizeof(decmsg) / sizeof(int);
    int termsg[Nchars*3];

    for(int j = 0; j < Nchars; ++j) {
        int i = 2;
        do {
            if(decmsg[j] != 0) {
                termsg[j*3+i] = decmsg[j] % 3;
                decmsg[j] = (int)decmsg[j] / 3;
            } else
              termsg[j*3+i] = 0;
            --i;
        } while(i > -1);
    }

    ternArray = termsg;
=======
unsigned int Crypto::RGB::dot(int i, int j) {
  return RGB::matrix[i][j];
>>>>>>> 2612c0e6eec9add63047bc54ea708046d1cf3150
}

/*
 *  Checks if a certain number is RGB codable
 */
<<<<<<< HEAD
void Crypto::RGB::ternToCodedRGB() {
  /*int r0, r1, r2;
  for(int i = 0; i < this->Nchars; i++) {
    r0 = ternArray[i][0];
    r1 = RGB::matrix[ ternArray[i][0] ][ ternArray[i][1] ];
    r2 = RGB::matrix[ r2 ][ ternArray[i][2] ];

    printf("(%c, %c, %c)\t", symbols[r0], symbols[r1], symbols[r2]); 
  }*/
=======
bool isCodable(int num) {
  int csize = sizeof(Crypto::RGB::symbols) / sizeof(*Crypto::RGB::symbols);
  for(int i = 0; i < csize; i++)
    if(num == Crypto::RGB::symbols[i])
      return true;
  return false;
}

void Crypto::RGB::showDot() {
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j ++)
      printf("\t<%d, %d> = %d\n", i, j, Crypto::RGB::matrix[i][j]);
>>>>>>> 2612c0e6eec9add63047bc54ea708046d1cf3150
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
<<<<<<< HEAD
void Crypto::RGB::strToDec() {
  int decArr[msg.size()];
  int n = msg.size();
  for(int i = 0; i < n; i++) {
=======
void Crypto::charToDec() {
  unsigned int decArr[msg.size()], size = msg.size();
  for(int i = 0; i < size; i++) {
>>>>>>> 2612c0e6eec9add63047bc54ea708046d1cf3150
    if('A' <= msg[i] && msg[i] <= 'Z')
      msg[i] = msg[i] - ('A' - 'a');

    decArr[i] = msg[i] - 'a';
    if(msg[i] < 'a' || msg[i] > 'z')
      decArr[i] = 26;
  }
}

<<<<<<< HEAD
  static int* cop = decArr;
  decimalArray = cop;

=======
char* Crypto::RGB::getCode() {
  printf("%d, %d, %d\n", this->ternary[0], this->ternary[1], this->ternary[2]);
  //printf("[%c, %c, %c]", code[2], code[1], code[0]);
  return this->code;
>>>>>>> 2612c0e6eec9add63047bc54ea708046d1cf3150
}


