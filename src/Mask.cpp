#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "utils.h"
#include "Mask.h"

Mask::Mask() {

}

Mask::~Mask() {

}

void Mask::read_file(std::string filename) {
  std::ifstream reader;
  std::string line = "";
  std::vector< std::string > words{};
  std::vector< float > pixelrow{};

  reader.open(filename.c_str());
  if (!reader) {
    throw std::invalid_argument("Mask file does not exist!");
  }
  zPixels.clear();
  while (getline(reader, line)) {
    words = utils::split(line, ' ');
    if (words.size() > 0) {
      pixelrow.clear();
      for (std::string word : words) {
        pixelrow.push_back(std::stoi(word));
      }
      zPixels.push_back(pixelrow);
    }
  }
  zNRows = zPixels.size();
  zNCols = zPixels.front().size();
  for ( std::vector < float > row : zPixels ) {
    if (row.size() != zNCols) {
      throw std::invalid_argument("The Mask must have the same number of pixels in each row.");
    }
  }
}

float Mask::get_pixel(int pixel_x, int pixel_y) {
  if ( (pixel_x < 0) || (pixel_x >= zNCols) 
    || (pixel_y < 0) || (pixel_y >= zNRows) ) {
    throw std::invalid_argument("Pixel index for Mask out of range.");
  }
  return zPixels[pixel_y][pixel_x];
}
