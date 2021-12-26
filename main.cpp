#include <iostream>
#include <istream>
#include <string>
#include <codecvt>

#include "Crypto.h"
#include "RGBImage.h"


struct FHandler {
  FHandler();

  /*
   *  Reads and parses data from file according to mode
   */
  static std::string readFrom( std::ifstream& file, std::string mode = "RGB") {
    if(!file) {
      printf("FILE NOT OPENED\n");
      return "";
    } else {
      file.clear();
      file.seekg(0, std::ios::beg);
    }

    std::string line, text;
    while(std::getline(file, line)) {
      parseLine(line);
      text.append(line);
      text.append("\n");
    }
  
    return text;
  }

  static void parseLine(std::string &line) { 
    //  handles accents in coded utf-8 and utf-16 - WHAT A FUCKING NIGHTMARE BUT IT'S DONE
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    std::wstring wtmp;
    for(auto& letter : converter.from_bytes(line)) {
      switch(letter) {
        case L'á': case L'à': case L'â': case L'ã':
        case L'Á': case L'À': case L'Â': case L'Ã':
          wtmp.push_back('a'); break;
        case L'é': case L'è': case L'ê':
        case L'É': case L'È': case L'Ê':
          wtmp.push_back('e'); break;
        case L'í': case L'ì': case L'î':
        case L'Í': case L'Ì': case L'Î':
          wtmp.push_back('i'); break;
        case L'ó': case L'ò': case L'ô': case L'õ':
        case L'Ó': case L'Ò': case L'Ô': case L'Õ':
          wtmp.push_back('o'); break;
        case L'ú': case L'ù': case L'û':
        case L'Ú': case L'Ù': case L'Û':
          wtmp.push_back('u'); break;
        case L'ç': case L'Ç': 
          wtmp.push_back('c'); break;
        default:
          wtmp.push_back(letter);
      } 
    }

    line = converter.to_bytes(wtmp);
    std::string tmpLine;
    for(int i = 0; i < line.size(); i++)
      if('a' <= line[i] && line[i] <= 'z')
       tmpLine.push_back(line[i]); 
      else if('A' <= line[i] && line[i] <= 'Z')
        tmpLine.push_back(line[i] - ('A' - 'a'));           //  converts to lowercase         
      else if(line[i] == ' ')
        tmpLine.push_back(' ');                             //  preserves spaces
      else if(line[i] == '.' || line[i] == '?' || line[i] == '!') {
        tmpLine.push_back('\n');
        if((i < line.size() - 1) && (line[i + 1] == ' '))   //  handles buffered space if it exists  
          i++;
      }

    line = tmpLine;
  }
};


int main(int argc, char ** argv) {
  
  const char* arg = (argc == 2) ? argv[1] : "./docs/message.txt";
  
  std::ifstream file(arg); 
  if(!file) {
    printf("File not opened...\n");
    return -1;
  }

  Crypto::RGB code(FHandler::readFrom(file));

  std::cout << code.message() << std::endl << code.rgbcode() << std::endl;
  RGBImage image("encoded.bmp", code.rgbcode());
  
  return 0;
}
