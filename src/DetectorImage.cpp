#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "DetectorImage.h"
#include "utils.h"

DetectorImage::DetectorImage() {

}

DetectorImage::~DetectorImage() {

}

void DetectorImage::read_file(std::string filename) {
  std::ifstream reader;
  std::string line = "";
  std::vector< std::string > words{};
  std::vector< int > all_pixels{};
  std::vector< std::vector< int > > pixels{};
  int i = 0;
  int j = 0;

  reader.open(filename.c_str());
  if ( ! reader ) {
    throw std::invalid_argument("Detector-Image file does not exist!");
  }
  while (getline(reader, line)) {
    if (line[7] == ':') {
      words = utils::split(line, ' ');
      if (words[0] == "NROWS") {
        zNRows = std::stoi(words[2]);
      }
      else if (words[0] == "NCOLS") {
        zNCols = std::stoi(words[2]);
      }
    }
    else if (line[0] != '.') {
      for (std::string word : utils::split(line, ' ')){
//        std::cout << word << '\n';
        all_pixels.push_back(std::stoi(word));
      }
    }
  }
 
  zPixels = utils::rearrange_to_2index(all_pixels, zNRows, zNCols); 

  reader.close();
}



int DetectorImage::get_pixel(int pixel_x, int pixel_y) {
  if ((pixel_y < 0) || (pixel_y >= zNRows) || (pixel_x < 0) || (pixel_x >= zNCols)) {
    throw std::invalid_argument("Invalid pixel indizes");
  }
  return  zPixels[zNCols-1-pixel_y][pixel_x];
}

int DetectorImage::get_num_of_rows() {
  return zNRows;
}

int DetectorImage::get_num_of_cols() {
  return zNCols;
}
