#include <iostream>
#include <string>
#include <vector>
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
    for(int y = 0; y < num_of_rows; y++) {
      for(int x = 0; x < num_of_cols; x++) {
        mask->set_pixel(
          x,
          y,
          (float)action->get_detectorimage()->get_pixel(x, y)
        );
      }
    }
  }

  int num_of_images = list->get_actions().size();
  float value;
  for(int y = 0; y < num_of_rows; y++) {
    for(int x = 0; x < num_of_cols; x++) {
      value = mask->get_pixel(x, y);
      if (value < num_of_images*0.1) {
        value = 0.0;
      }
      else {
        value = num_of_images / value;
      }
      mask->set_pixel(x, y, value);
    }
  }

  mask->write_file(output_filename);

  delete list;
  delete mask; 
}
