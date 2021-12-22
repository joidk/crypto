#include "Crypto.h"

char Crypto::RGB::symbols[3] = { 'R', 'G', 'B' }; 
unsigned int Crypto::RGB::matrix[3][3] = {{0, 2, 1},
                                          {2, 1, 0},
                                          {1, 0, 2}};

/*
 * Convert string to RGBcode
 */
bool Crypto::RGB::convert() {
  strToDec();
  decToTern();
  ternToCodedRGB();
  //printf("%.*s \n", 3*Nchars, RGBcode);

  return true;
}

/*
 *  Constructor - reads strings as argument
 */ 
Crypto::RGB::RGB(std::string mes_) {
  Nchars = mes_.size();
  msg = mes_;

  convert(); 
}

/*
 *  Constructor - reads string from a File
 */
Crypto::RGB::RGB(std::ifstream& F) {
  std::string text;
  msg = "";

  while(getline(F,text))
    msg += text;
  Nchars = msg.size();

  convert();
}

/*
 *  Convert string to decimal
 */
void Crypto::RGB::strToDec() {
  int* decArr = new int[msg.size()];
  int size = msg.size();
  for(int i = 0; i < size; i++) {

    if('A' <= msg[i] && msg[i] <= 'Z')
      msg[i] = msg[i] - ('A' - 'a');

    decArr[i] = msg[i] - 'a';
    if(msg[i] < 'a' || msg[i] > 'z')
      decArr[i] = 26;
  }
  //static int cop[] = decArr;
  decimalArray = decArr;
}

/*
 *  Convert decimal to ternary 
 */
void Crypto::RGB::decToTern() {

  int* decmsg = decimalArray; 
  int* termsg = new int[Nchars*3];

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

/*
 *  Convert ternary to RGB code using a predefined dot product(matrix)
 */
void Crypto::RGB::ternToCodedRGB() {

  char* cRGBcode = new char[3*Nchars];
  for(int i = 0; i < 3*Nchars - 2; i+=3) {
    cRGBcode[i] = symbols[ ternArray[i] ];
    int r = RGB::matrix[ ternArray[i] ][ ternArray[i+1] ];
    cRGBcode[i+1] = symbols[ r ];
    cRGBcode[i+2] = symbols[ RGB::matrix[ r ][ ternArray[i+2] ] ];
  }
  RGBcode = cRGBcode;
}

/*
 *  Dot product used
 */ 
unsigned int Crypto::RGB::dot(int i, int j) {
  return RGB::matrix[i][j];
}

std::string Crypto::RGB::message() const {  return this->msg; }
std::string Crypto::RGB::rgbcode() const {  return std::string(this->RGBcode); }
