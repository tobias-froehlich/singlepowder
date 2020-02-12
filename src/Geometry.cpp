#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>
#include <vector>
#include <cmath>
#include "const.cpp"
#include "utils.h"
#include "Geometry.h"

Geometry::Geometry() {

}

Geometry::~Geometry() {

}

void Geometry::set_detector_distance(float detector_distance) {
  zDetectorDistance = detector_distance;
}

float Geometry::get_detector_distance() {
  return zDetectorDistance;
}

void Geometry::set_pixel_width(float pixel_width) {
  zPixelWidth = pixel_width;
}

float Geometry::get_pixel_width() {
  return zPixelWidth;
}

void Geometry::set_pixel_height(float pixel_height) {
  zPixelHeight = pixel_height;
}

float Geometry::get_pixel_height() {
  return zPixelHeight;
}

void Geometry::set_centre_pixel_x(float centre_pixel_x) {
  zCentrePixelX = centre_pixel_x;
}

float Geometry::get_centre_pixel_x() {
  return zCentrePixelX;
}

void Geometry::set_centre_pixel_y(float centre_pixel_y) {
  zCentrePixelY = centre_pixel_y;
}

float Geometry::get_centre_pixel_y() {
  return zCentrePixelY;
}

void Geometry::set_twotheta(float twotheta) {
  zTwotheta = twotheta;
}

float Geometry::get_twotheta() {
  return zTwotheta;
}

float Geometry::calculate_powderangle(int pixel_x, int pixel_y) {
  float delta_x = ((float)pixel_x - zCentrePixelX) * zPixelWidth;
  float delta_y = ((float)pixel_y - zCentrePixelY) * zPixelHeight;
  float cos = std::cos(zTwotheta * cPiOver180);
  float sin = std::sin(zTwotheta * cPiOver180);
  float numerator = zDetectorDistance * (zDetectorDistance * cos + delta_x * sin);
  float denominator = std::sqrt(
    (
      utils::square(zDetectorDistance * cos + delta_x * sin) 
      + utils::square(zDetectorDistance * sin - delta_x * cos)
      + utils::square(delta_y)
    )
  ) * zDetectorDistance;
  float fraction = numerator / denominator;
  float powderangle = std::acos(fraction) * c180OverPi;
}
