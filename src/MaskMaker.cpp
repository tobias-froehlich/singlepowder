#include <iostream>
#include <string>
#include <vector>
#include "const.cpp"
#include "utils.h"
#include "DetectorImage.h"
#include "Action.h"
#include "List.h"
#include "Mask.h"
#include "MaskMaker.h"

MaskMaker::MaskMaker() {
  
}

MaskMaker::~MaskMaker() {

}

void MaskMaker::make_mask(std::string data_directory,
                          std::string list_filename,
                          std::string output_filename) {
  List* list;
  Mask* mask;
  list = new List();
  mask = new Mask();

  list->set_datadirectory(data_directory);
  list->read_file(list_filename);


  int num_of_cols = list->get_actions().front()->get_detectorimage()->get_num_of_cols();
  int num_of_rows = list->get_actions().front()->get_detectorimage()->get_num_of_rows();
  mask->init(num_of_cols, num_of_rows);

  for(Action* action : list->get_actions()) {
    for(int y = 1; y < num_of_rows-1; y++) {
      for(int x = 1; x < num_of_cols-1; x++) {
        mask->set_pixel(
          x,
          y,
          mask->get_pixel(x, y) + (float)action->get_detectorimage()->get_pixel(x, y)
        );
      }
    }
  }

  int num_of_images = list->get_actions().size();
  float value;
  for(int y = 0; y < num_of_rows; y++) {
    for(int x = 0; x < num_of_cols; x++) {
      value = mask->get_pixel(x, y);
      if (value < cFloatDelta) {
        value = 0.0;
      }
      else {
        value = num_of_images / value * 100;
      }
      mask->set_pixel(x, y, value);
    }
  }

  mask->write_file(output_filename);

  delete list;
  delete mask; 
}

void MaskMaker::multiply_masks(std::string input_filename_1,
                               std::string input_filename_2,
                               std::string output_filename) {
  Mask* mask1;
  Mask* mask2;
  Mask* mask3;
  
  mask1 = new Mask();
  mask2 = new Mask();
  mask3 = new Mask();

  mask1->read_file(input_filename_1);
  mask2->read_file(input_filename_2);

  if (    (mask1->get_num_of_cols() != mask2->get_num_of_cols())
       || (mask1->get_num_of_rows() != mask2->get_num_of_rows()) ) {
    throw std::invalid_argument("Masks need to have the same size for multiplying");
  }

  int num_of_cols = mask1->get_num_of_cols();
  int num_of_rows = mask1->get_num_of_rows();

  mask3->init(num_of_cols, num_of_rows);

  for ( int y=0; y<num_of_rows; y++) {
    for ( int x=0; x<num_of_cols; x++) {
      mask3->set_pixel(
        x,
        y,
        mask1->get_pixel(x, y) * mask2->get_pixel(x, y)
      );
    }
  }

  mask3->write_file(output_filename);

  delete mask1;
  delete mask2;
  delete mask3;
}
