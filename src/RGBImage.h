#pragma once

#include <string>
#include <cmath>

/*
 *  Bitmap generator for the RGB image
 */
struct RGBImage {
  static const int BYTES_PER_PIXEL   = 3;
  static const int FILE_HEADER_SIZE  = 14;
  static const int INFO_HEADER_SIZE  = 40;

  RGBImage(const char* filename, std::string RGBstring) {
    int strSize = RGBstring.size();
    int nlines = (int)sqrt(strSize) + 1;
    const int ROWS = nlines;  // height
    const int COLS = nlines;  // width
    unsigned char BMcode[COLS][ROWS][BYTES_PER_PIXEL];
   
    memset(BMcode, 0, sizeof(BMcode));
    
    int strIndx = 0;
    for(int i = 0; i < ROWS; i++)
      for(int j = 0; j < COLS; j++) {
        switch(RGBstring[strIndx]) {
          case 'R': BMcode[i][j][2] = (unsigned char)(255); break;
          case 'G': BMcode[i][j][1] = (unsigned char)(255); break;
          case 'B': BMcode[i][j][0] = (unsigned char)(255); break;
          default:  break;
        }
        strIndx++;
      }

    generate((unsigned char*) BMcode, ROWS, COLS, filename);
  }

  void generate(unsigned char* BMcode, int ROWS, int COLS, const char* filename) {
    int rowInBytes = COLS * BYTES_PER_PIXEL;
    unsigned char padding[3] = {0, 0, 0};
    int paddingSize = (4 - rowInBytes % 4) % 4;
    int bmpSingleRow = rowInBytes + paddingSize;

    FILE* imgFile = fopen(filename, "wb");

    //  write header file
    int fileSize = FILE_HEADER_SIZE + INFO_HEADER_SIZE + (bmpSingleRow * ROWS);
    unsigned char fileHeader[FILE_HEADER_SIZE] = {0};

    fileHeader[0]   = (unsigned char)('B');
    fileHeader[1]   = (unsigned char)('M');
    fileHeader[2]   = (unsigned char)(fileSize);
    fileHeader[3]   = (unsigned char)(fileSize >> 8);
    fileHeader[4]   = (unsigned char)(fileSize >> 16);
    fileHeader[5]   = (unsigned char)(fileSize >> 24);
    fileHeader[10]  = (unsigned char)(FILE_HEADER_SIZE + INFO_HEADER_SIZE);
 
    //  write info header
    unsigned char infoHeader[INFO_HEADER_SIZE] = {0};

    infoHeader[0]   = (unsigned char)(INFO_HEADER_SIZE);
    infoHeader[4]   = (unsigned char)(COLS);
    infoHeader[5]   = (unsigned char)(COLS >> 8);
    infoHeader[6]   = (unsigned char)(COLS >> 16);
    infoHeader[7]   = (unsigned char)(COLS >> 24);
    infoHeader[8]   = (unsigned char)(ROWS);
    infoHeader[9]   = (unsigned char)(ROWS >> 8);
    infoHeader[10]  = (unsigned char)(ROWS >> 16);
    infoHeader[11]  = (unsigned char)(ROWS >> 24);
    infoHeader[12]  = (unsigned char)(1);
    infoHeader[14]  = (unsigned char)(BYTES_PER_PIXEL * 8);
    
    //  write memory to file
    fwrite(fileHeader, 1, FILE_HEADER_SIZE, imgFile);
    fwrite(infoHeader, 1, INFO_HEADER_SIZE, imgFile);
    for(int i = 0; i < ROWS; i++) {
      fwrite(BMcode + i * rowInBytes, BYTES_PER_PIXEL, COLS, imgFile);
      fwrite(padding, 1, paddingSize, imgFile);
    }
    
    fclose(imgFile);
  }
};
