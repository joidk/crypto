#include "Crypto.h"

char Crypto::RGB::symbols[3] = { 'R', 'G', 'B' }; 
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

/*
 *  Produces operation 
 */
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
  }

unsigned int Crypto::RGB::dot(int i, int j) {
  return RGB::matrix[i][j];
}

/*
 *  Checks if a certain number is RGB codable
 */

void Crypto::RGB::ternToCodedRGB() {
  /*int r0, r1, r2;
  for(int i = 0; i < this->Nchars; i++) {
    r0 = ternArray[i][0];
    r1 = RGB::matrix[ ternArray[i][0] ][ ternArray[i][1] ];
    r2 = RGB::matrix[ r2 ][ ternArray[i][2] ];

    printf("(%c, %c, %c)\t", symbols[r0], symbols[r1], symbols[r2]); 
  */}

bool isCodable(int num) {
  int csize = sizeof(Crypto::RGB::symbols) / sizeof(*Crypto::RGB::symbols);
  for(int i = 0; i < csize; i++)
    if(num == Crypto::RGB::symbols[i])
      return true;
  return false;
}

/*
 *  Converts char to decimal
 */
void Crypto::RGB::strToDec() {
  static int decArr[msg.size()], size = msg.size();
  for(int i = 0; i < size; i++) {

    if('A' <= msg[i] && msg[i] <= 'Z')
      msg[i] = msg[i] - ('A' - 'a');

    decArr[i] = msg[i] - 'a';
    if(msg[i] < 'a' || msg[i] > 'z')
      decArr[i] = 26;
  }
  //static int cop[] = decArr;
  decimalArray = decArr;

  for (int i = 0; i < Nchars; ++i) {
    std::cout << decimalArray[i] << std::endl;
  }
}


