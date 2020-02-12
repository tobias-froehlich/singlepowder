#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>
#include "const.cpp"
#include "Vector.h"

Vector::Vector() {

}

Vector::~Vector() {

}

void Vector::set_components(float component1, float component2, float component3) {
  zComponent1 = component1;
  zComponent2 = component2;
  zComponent3 = component3;
}

float Vector::get_component1() {
  return zComponent1;
}

float Vector::get_component2() {
  return zComponent2;
}

float Vector::get_component3() {
  return zComponent3;
}


