#include <iostream>
#include <fstream>
#include <unistd.h>
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
  std::string line;
  std::vector< std::string > words;

  reader.open(filename.c_str());
  if ( ! reader ) {
    throw std::invalid_argument("File does not exist!");
  }
  while (getline(reader, line)) {
    if (line[7] == ':') {
      //std::cout << line << '\n';
    }
    else if (line[0] != '.') {
//      words = utils::split(line, ' ');
    }
  }
  reader.close();
}
