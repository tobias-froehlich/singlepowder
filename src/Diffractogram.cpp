#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>
#include <vector>
#include <cmath>
#include "const.cpp"
#include "utils.h"
#include "Diffractogram.h"

Diffractogram::Diffractogram() {

}

Diffractogram::~Diffractogram() {

}

void Diffractogram::init(float angle_min, float angle_max, float step) {
  if ((step < 0) || (utils::float_equal(step, 0))) {
    throw std::invalid_argument("Angle step must be positive.");
  }
  zLength = 0;
  zAngles.clear();
  zNumOfPixels.clear();
  zCounts.clear();
  float angle = angle_min;
  while ((angle < angle_max) || (utils::float_equal(angle, angle_max))) {
    zLength += 1;
    zAngles.push_back(angle);
    zNumOfPixels.push_back(0);
    zCounts.push_back(0);
    angle = angle_min + zLength * step;
  }
  zAngleMin = zAngles.front();
  zAngleMax = zAngles.back();
  zStep = step;
}

int Diffractogram::get_length() {
  return zLength;
}

float Diffractogram::get_angle_min() {
  return zAngleMin;
}

float Diffractogram::get_angle_max() {
  return zAngleMax;
}

float Diffractogram::get_step() {
  return zStep;
}

float Diffractogram::get_angle(int index) {
  if ((index < 0) || (index >= zLength)) {
    throw std::invalid_argument("Index of diffractogram entry out of range.");
  }
  return zAngles[index];
}

int Diffractogram::get_num_of_pixels(int index) {
  if ((index < 0) || (index >= zLength)) {
    throw std::invalid_argument("Index of diffractogram entry out of range.");
  }
  return zNumOfPixels[index]; 
}

int Diffractogram::get_counts(int index) {
  if ((index < 0) || (index >= zLength)) {
    throw std::invalid_argument("Index of diffractogram entry out of range.");
  }
  return zCounts[index]; 
}

void Diffractogram::add_counts(float angle, int counts) {
  int index = std::round((angle - zAngleMin)/zStep);
  if ((index >= 0) && (index < zLength)) {
    zNumOfPixels[index] += 1;
    zCounts[index] += counts;
  }
}

void Diffractogram::write_file(std::string filename) {
  std::ofstream file(filename.c_str());
  if (!(file.is_open())) {
    throw std::invalid_argument("Cannot open file for writing.");
  }
  for(int i = 0; i < zLength; i++) {
    file << zAngles[i] << " " << zNumOfPixels[i] << " " << zCounts[i] << '\n';
  }
  file.close();
}
