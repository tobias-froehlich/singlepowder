#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include "const.cpp"
#include "utils.h"
#include "Mask.h"

Mask::Mask() {

}

Mask::~Mask() {

}

void Mask::init(int num_of_cols, int num_of_rows) {
  std::vector<float> row;
  zPixels.clear();
  row.clear();
  for(int i = 0; i < num_of_cols; i++) {
    row.push_back(0.0);    
  }
  for(int j = 0; j < num_of_rows; j++) {
    zPixels.push_back(row);
  }
  zNRows = num_of_rows;
  zNCols = num_of_cols;
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
        pixelrow.push_back(std::stof(word));
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

int Mask::get_num_of_cols() {
  return zNCols;
}

int Mask::get_num_of_rows() {
  return zNRows;
}

float Mask::get_pixel(int pixel_x, int pixel_y) {
  if ( (pixel_x < 0) || (pixel_x >= zNCols) 
    || (pixel_y < 0) || (pixel_y >= zNRows) ) {
    throw std::invalid_argument("Pixel index for Mask out of range.");
  }
  return zPixels[pixel_y][pixel_x];
}

void Mask::set_pixel(int pixel_x, int pixel_y, float value) {
  if ( (pixel_x < 0) || (pixel_x >= zNCols) 
    || (pixel_y < 0) || (pixel_y >= zNRows) ) {
    throw std::invalid_argument("Pixel index for Mask out of range.");
  }
  zPixels[pixel_y][pixel_x] = value;
}

void Mask::write_file(std::string filename) {
  std::ofstream file;
  
  file.open(filename.c_str());
  if (!file) {
    throw std::invalid_argument("Cannot open file for writing!");
  }
  file << std::fixed;
  for(std::vector<float> row : zPixels) {
    for(float pixel : row) {
      file << std::setprecision(cMaskFloatPrecision) << pixel << " ";
    }
    file << '\n';
  }
  file.close();
}
