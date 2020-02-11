#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>
#include <vector>
#include "const.cpp"
#include "DetectorImage.h"
#include "Action.h"
#include "utils.h"

Action::Action() {
  zDetectorImage = new DetectorImage();
}

Action::~Action() {
  delete zDetectorImage;
}

void Action::read_line(std::string line) {
  std::vector< std::string > words = utils::split(line, ' ');
  if (words.size() != 6) {
    throw std::invalid_argument("Line in list must have exactly 6 words.");
  }
  for (int i=1; i<6; i++) {
    try {
      std::stof(words[i]);
    }
    catch (std::exception& ia) {
      throw std::invalid_argument("Parameter values (twoteta, theta, chi, detectordistance, scantime) in list must be floats.");
    }
  }
  zDataFilename = words[0];
  zTwotheta = std::stof(words[1]);
  zTheta = std::stof(words[2]);
  zChi = std::stof(words[3]);
  zDetectordistance = std::stof(words[4]);
  zScantime = std::stof(words[5]);
}

std::string Action::get_data_filename() {
  return zDataFilename;
}

float Action::get_twotheta() {
  return zTwotheta;
}

float Action::get_theta() {
  return zTheta;
}

float Action::get_chi() {
  return zChi;
}

float Action::get_detectordistance() {
  return zDetectordistance;
}

float Action::get_scantime() {
  return zScantime;
}

void Action::set_datadirectory(std::string datadirectory) {
  zDataDirectory = datadirectory;
}

std::string Action::get_datadirectory() {
  return zDataDirectory;
}

void Action::read_detectorimage() {
  zDetectorImage->read_file(zDataDirectory + zDataFilename);
  
}

DetectorImage* Action::get_detectorimage() {
  return zDetectorImage;
}
