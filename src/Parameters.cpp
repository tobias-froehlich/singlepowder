#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>
#include <vector>
#include "const.cpp"
#include "Parameters.h"
#include "utils.h"

Parameters::Parameters() {

}

Parameters::~Parameters() {

}

std::string Parameters::remove_comment(std::string line) {
  int first_pos = line.find(cCommentTag);
  return line.substr(0, first_pos);
}

std::string Parameters::get_parametername(std::string line) {
  std::vector< std::string > words{};
  words = utils::split(line, ' ');
  if (words.size() != 2) {
    throw std::invalid_argument("Line with parameter must consist of exactly 2 words");
  }
  return words[0];
}

float Parameters::read_float_parameter(std::string line) {
  std::vector< std::string > words{};
  line = remove_comment(line);
  words = utils::split(line, ' ');
  if (words.size() != 2) {
    throw std::invalid_argument("Line with parameter must consist of exactly 2 words");
  }
  try {
    return std::stof(words[1]);
  }
  catch (std::exception& ia) {
    throw std::invalid_argument("Parameter value must be a float.");
  }
}

int Parameters::read_int_parameter(std::string line) {
  std::vector< std::string > words{};
  line = remove_comment(line);
  words = utils::split(line, ' ');
  if (words.size() != 2) {
    throw std::invalid_argument("Line with parameter must consist of exactly 2 words");
  }
  try {
    return std::stoi(words[1]);
  }
  catch (std::exception& ia) {
    throw std::invalid_argument("Parameter value must be an int.");
  }
}

std::string Parameters::read_str_parameter(std::string line) {
  std::vector< std::string > words{};
  line = remove_comment(line);
  words = utils::split(line, ' ');
  if (words.size() != 2) {
    throw std::invalid_argument("Line with parameter must consist of exactly 2 words");
  }
  return words[1];
}
void Parameters::read_file(std::string filename) {
  std::ifstream reader;
  std::string line;
  std::string parametername = "";

  reader.open(filename.c_str());
  if ( ! reader ) {
    throw std::invalid_argument("File does not exist!");
  }

  while (getline(reader, line)) {
    parametername = get_parametername(line);
    if (parametername == "pixel_width") {
      zPixelWidth = read_float_parameter(line);
    }
    else if (parametername == "pixel_height") {
      zPixelHeight = read_float_parameter(line);
    }
    else if (parametername == "image_list_filename") {
      zImageListFilename = read_str_parameter(line);
    }
    else if (parametername == "detector_distance") {
      zDetectorDistance = read_float_parameter(line);
    }
  }
}

float Parameters::get_pixel_width() {
  return zPixelWidth;
}

float Parameters::get_pixel_height() {
  return zPixelHeight;
}

std::string Parameters::get_image_list_filename() {
  return zImageListFilename;
}

float Parameters::get_detector_distance() {
  return zDetectorDistance;
}
