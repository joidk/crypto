#include "Crypto.h"

char symbols[3] = { 'R', 'G', 'B' }; 
unsigned int Crypto::RGB::matrix[3][3] = {{0, 2, 1},
                                          {2, 1, 0},
                                          {1, 0, 2}};

bool Crypto::RGB::convert() {
  this->strToDec();
  this->decToTern();
  this->ternToCodedRGB();

  return true;
}


Crypto::RGB::RGB(std::string mes_) {
  this->Nchars = mes_.size();
  this->msg = mes_;

  this->convert(); 
}

/*
 *  
 */
void Crypto::RGB::decToTern() {
    int* decmsg = this->decimalArray; 
    //int size = sizeof(decmsg) / sizeof(int);
    int termsg[this->Nchars][3];



    for(int j = 0; j < this->Nchars; ++j) {
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

    this->ternArray = termsg;
}

/*
 *
 */
void Crypto::RGB::ternToCodedRGB() {
  int r0, r1, r2;
  for(int i = 0; i < this->Nchars; i++) {
    r0 = ternArray[i][0];
    r1 = RGB::matrix[ ternArray[i][0] ][ ternArray[i][1] ];
    r2 = RGB::matrix[ r2 ][ ternArray[i][2] ];

    printf("(%c, %c, %c)\t", symbols[r0], symbols[r1], symbols[r2]); 
  }
}

/*
 *  Produces "cross" operation 
 */
unsigned int Crypto::RGB::dot(int i, int j) {
  return RGB::matrix[i][j];
}

/*
 *  Converts char to decimal
 */
void Crypto::RGB::strToDec() {
  unsigned int decArr[msg.size()];
  unsigned int n = msg.size();
  for(int i = 0; i < n; i++) {
    if('A' <= msg[i] && msg[i] <= 'Z')
      msg[i] = msg[i] - ('A' - 'a');

    decArr[i] = msg[i] - 'a';
    if(msg[i] < 'a' || msg[i] > 'z')
      decArr[i] = 26;
  }

  this->decimalArray = decArr;
}


