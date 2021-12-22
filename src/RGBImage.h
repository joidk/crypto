#pragma once

#include <string>
#include <cmath>

struct RGBImage {
  static const int BYTES_PER_PIXEL   = 3;
  static const int FILE_HEADER_SIZE  = 14;
  static const int INFO_HEADER_SIZE  = 40;

  RGBImage(const char* filename, std::string RGBstring) {
    int strSize = RGBstring.size();
    int nlines = (int)sqrt(strSize) + 1;
    const int height = nlines;
    const int width = nlines;
    unsigned char BMcode[width][height][BYTES_PER_PIXEL];
   
    memset(BMcode, 0, sizeof(BMcode));
    
    int x = 0;
    for(int i = 0; i < height; i++)
      for(int j = 0; j < width; j++) {
        if(RGBstring[x] == 'R')
          BMcode[i][j][2] = (unsigned char)(255);
        else if(RGBstring[x] == 'G')
          BMcode[i][j][1] = (unsigned char)(255);
        else if(RGBstring[x] == 'B')
          BMcode[i][j][0] = (unsigned char)(255);
        x++;
      }

    generate((unsigned char*) BMcode, width, height, filename);
  }

  void generate(unsigned char* BMcode, int width, int height, const char* filename) {
    int widthInBytes = width * BYTES_PER_PIXEL;
    unsigned char padding[3] = {0, 0, 0};
    int paddingSize = (4 - (widthInBytes) % 4) % 4;

    int stride = widthInBytes + paddingSize;

    FILE* imgFile = fopen(filename, "wb");

    //  write header file
    int fileSize = FILE_HEADER_SIZE + INFO_HEADER_SIZE + (stride * height);
    unsigned char fileHeader[FILE_HEADER_SIZE] = {0};

    fileHeader[ 0] = (unsigned char)('B');
    fileHeader[ 1] = (unsigned char)('M');
    fileHeader[ 2] = (unsigned char)(fileSize);
    fileHeader[ 3] = (unsigned char)(fileSize >>  8);
    fileHeader[ 4] = (unsigned char)(fileSize >> 16);
    fileHeader[ 5] = (unsigned char)(fileSize >> 24);
    fileHeader[10] = (unsigned char)(FILE_HEADER_SIZE + INFO_HEADER_SIZE);
 
    fwrite(fileHeader, 1, FILE_HEADER_SIZE, imgFile);
 
    unsigned char infoHeader[INFO_HEADER_SIZE] = {0};
 
    //  write info header
    infoHeader[ 0] = (unsigned char)(INFO_HEADER_SIZE);
    infoHeader[ 4] = (unsigned char)(width      );
    infoHeader[ 5] = (unsigned char)(width >>  8);
    infoHeader[ 6] = (unsigned char)(width >> 16);
    infoHeader[ 7] = (unsigned char)(width >> 24);
    infoHeader[ 8] = (unsigned char)(height      );
    infoHeader[ 9] = (unsigned char)(height >>  8);
    infoHeader[10] = (unsigned char)(height >> 16);
    infoHeader[11] = (unsigned char)(height >> 24);
    infoHeader[12] = (unsigned char)(1);
    infoHeader[14] = (unsigned char)(BYTES_PER_PIXEL*8);
 
    fwrite(infoHeader, 1, INFO_HEADER_SIZE, imgFile);
 
    for (int i = 0; i < height; i++) {
      fwrite(BMcode + i * widthInBytes, BYTES_PER_PIXEL, width, imgFile);
      fwrite(padding, 1, paddingSize, imgFile);
    }
    
    fclose(imgFile);
  }
};
