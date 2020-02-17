#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
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
  zSumOfWeights.clear();
  zSumOfWeightedCounts.clear();
  zSumOfSquareweightedCounts.clear();
  zIntensities.clear();
  zErrors.clear();
  float angle = angle_min;
  while ((angle < angle_max) || (utils::float_equal(angle, angle_max))) {
    zLength += 1;
    zAngles.push_back(angle);
    zSumOfWeights.push_back(0.0);
    zSumOfWeightedCounts.push_back(0.0);
    zSumOfSquareweightedCounts.push_back(0.0);
    zIntensities.push_back(0.0);
    zErrors.push_back(0.0);
    angle = angle_min + zLength * step;
  }
  zAngleMin = zAngles.front();
  zAngleMax = zAngles.back();
  zStep = step;
}

void Diffractogram::set_output_format(std::string output_format) {
  zOutputFormat = output_format;
  if ((zOutputFormat != "standard") && (zOutputFormat != "detailed")) {
    throw std::invalid_argument("output format not known.");
  }
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

float Diffractogram::get_sum_of_weights(int index) {
  if ((index < 0) || (index >= zLength)) {
    throw std::invalid_argument("Index of diffractogram entry out of range.");
  }
  return zSumOfWeights[index]; 
}

float Diffractogram::get_sum_of_weighted_counts(int index) {
  if ((index < 0) || (index >= zLength)) {
    throw std::invalid_argument("Index of diffractogram entry out of range.");
  }
  return zSumOfWeightedCounts[index]; 
}

float Diffractogram::get_sum_of_squareweighted_counts(int index) {
  if ((index < 0) || (index >= zLength)) {
    throw std::invalid_argument("Index of diffractogram entry out of range.");
  }
  return zSumOfSquareweightedCounts[index];
}

float Diffractogram::get_intensity(int index) {
  if ((index < 0) || (index >= zLength)) {
    throw std::invalid_argument("Index of diffractogram entry out of range.");
  }
  return zIntensities[index];
}

float Diffractogram::get_error(int index) {
  if ((index < 0) || (index >= zLength)) {
    throw std::invalid_argument("Index of diffractogram entry out of range.");
  }
  return zErrors[index];
}

void Diffractogram::add_counts(float angle, int counts, float weight) {
  int index = std::round((angle - zAngleMin)/zStep);
  if ((index >= 0) && (index < zLength)) {
    zSumOfWeights[index] += weight;
    zSumOfWeightedCounts[index] += weight * (float)counts;
    zSumOfSquareweightedCounts[index] += utils::square(weight) * (float)counts;
  }
}

void Diffractogram::calculate_intensities_and_errors() {
  for (int i = 0; i < zLength; i++) {
    zIntensities[i] = zSumOfWeightedCounts[i] / zSumOfWeights[i];
    zErrors[i] = std::sqrt(zSumOfSquareweightedCounts[i]) / zSumOfWeights[i];
  }
}

void Diffractogram::write_file(std::string filename) {
  std::ofstream file(filename.c_str());
  int columnwidth = 0;
  int precision = 0;
  if (!(file.is_open())) {
    throw std::invalid_argument("Cannot open file for writing.");
  }
  if (zOutputFormat == "detailed") {
    columnwidth = 29;
    precision = 10;
    file << std::fixed;
    file << "#";
    file << std::setw(columnwidth-1) << "angle ";
    file << std::setw(columnwidth) << "sum_of_weights ";
    file << std::setw(columnwidth) << "sum_of_weighted_counts ";
    file << std::setw(columnwidth) << "sum_of_squareweighted_counts ";
    file << std::setw(columnwidth) << "intensity ";
    file << std::setw(columnwidth) << "error ";
    file << "\n";
    for(int i = 0; i < zLength; i++) {
      file << std::setw(columnwidth-1) << std::setprecision(precision) << zAngles[i] << " ";
      file << std::setw(columnwidth-1) << std::setprecision(precision) << zSumOfWeights[i] << " ";
      file << std::setw(columnwidth-1) << std::setprecision(precision) << zSumOfWeightedCounts[i] << " ";
      file << std::setw(columnwidth-1) << std::setprecision(precision) << zSumOfSquareweightedCounts[i] << " ";
      file << std::setw(columnwidth-1) << std::setprecision(precision) << zIntensities[i] << " ";
      file << std::setw(columnwidth-1) << std::setprecision(precision) << zErrors[i] << " ";
      file << '\n';
    }
  }
  else if (zOutputFormat == "standard") {
    columnwidth = 12;
    precision = 3;
    file << std::fixed;
    file << "#";
    file << std::setw(columnwidth-1) << "angle ";
    file << std::setw(columnwidth) << "intensity ";
    file << "\n";
    for(int i = 0; i < zLength; i++) {
      file << std::setw(columnwidth-1) << std::setprecision(precision) << zAngles[i] << " ";
      file << std::setw(columnwidth-1) << std::setprecision(precision) << zIntensities[i] << " ";
      file << '\n';
    }
  }
  file.close();
}
