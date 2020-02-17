#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>
#include <vector>
#include "const.cpp"
#include "utils.h"
#include "Parameters.h"

Parameters::Parameters() {

}

Parameters::~Parameters() {

}

std::string Parameters::get_parametername(std::string line) {
  std::vector< std::string > words{};
  words = utils::split(utils::remove_comment(line), ' ');
  if (words.size() != 2) {
    throw std::invalid_argument("Line with parameter must consist of exactly 2 words");
  }
  return words[0];
}

float Parameters::read_float_parameter(std::string line) {
  std::vector< std::string > words{};
  line = utils::remove_comment(line);
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
  line = utils::remove_comment(line);
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
  line = utils::remove_comment(line);
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
    throw std::invalid_argument("Parameter file does not exist!");
  }

  while (getline(reader, line)) {
    // Empty lines and lines with comment only are ignored.
    if ((utils::split(utils::remove_comment(line), ' ')).size() > 0) {
      parametername = get_parametername(line);
      if (parametername == "pixel_width") {
        zPixelWidth = read_float_parameter(line);
      }
      else if (parametername == "pixel_height") {
        zPixelHeight = read_float_parameter(line);
      }
      else if (parametername == "centre_pixel_x") {
        zCentrePixelX = read_float_parameter(line);
      }
      else if (parametername == "centre_pixel_y") {
        zCentrePixelY = read_float_parameter(line);
      }
      else if (parametername == "angle_min") {
        zAngleMin = read_float_parameter(line);
      }
      else if (parametername == "angle_max") {
        zAngleMax = read_float_parameter(line);
      }
      else if (parametername == "step") {
        zStep = read_float_parameter(line);
      }
      else if (parametername == "image_list_filename") {
        zImageListFilename = read_str_parameter(line);
      }
      else if (parametername == "data_directory") {
        zDataDirectory = read_str_parameter(line);
      }
      else if (parametername == "output_filename") {
        zOutputFilename = read_str_parameter(line);
      }
      else if (parametername == "output_format") {
        zOutputFormat = read_str_parameter(line);
      }
    }
  }
}

float Parameters::get_pixel_width() {
  return zPixelWidth;
}

float Parameters::get_pixel_height() {
  return zPixelHeight;
}

float Parameters::get_centre_pixel_x() {
  return zCentrePixelX;
}

float Parameters::get_centre_pixel_y() {
  return zCentrePixelY;
}

float Parameters::get_angle_min() {
  return zAngleMin;
}

float Parameters::get_angle_max() {
  return zAngleMax;
}

float Parameters::get_step() {
  return zStep;
}

std::string Parameters::get_image_list_filename() {
  return zImageListFilename;
}

std::string Parameters::get_data_directory() {
  return zDataDirectory;
}

std::string Parameters::get_output_filename() {
  return zOutputFilename;
}

std::string Parameters::get_output_format() {
  return zOutputFormat;
}
