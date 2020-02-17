#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>
#include <vector>
#include "const.cpp"
#include "DetectorImage.h"
#include "Action.h"
#include "List.h"
#include "utils.h"

List::List() {

}

List::~List() {
  for (Action* action : zActions) {
    delete action;
  }
}

void List::set_datadirectory(std::string datadirectory) {
  zDataDirectory = datadirectory;
}

std::string List::get_datadirectory() {
  return zDataDirectory;
}

void List::read_file(std::string filename) {
  std::ifstream reader;
  std::string line;

  reader.open(filename.c_str());
  if ( ! reader ) {
    throw std::invalid_argument("List file does not exist!");
  }
 
  // Parse the list file to count the number of images:
  zLength = 0;
  while (getline(reader, line)) {
    if ((utils::split(utils::remove_comment(line), ' ')).size() > 0) {
      zLength += 1;
    }
  }
  std::cout << "The list contains " << zLength <<
    " images to be read.\n";

  // Reset to file beginning:
  reader.clear();
  reader.seekg(0, std::ios::beg);

  // Parse again and read in the image files:
  int i = 0;
  while (getline(reader, line)) {
    if ((utils::split(utils::remove_comment(line), ' ')).size() > 0) {
      zActions.push_back(new Action());
      zActions.back()->read_line(line);
      zActions.back()->set_datadirectory(zDataDirectory);
      zActions.back()->read_detectorimage();
      i += 1;
      std::cout << i << " of " << zLength << " images read.\n";
    }
  }
  std::cout << "All " << zLength << " images read in successfully.\n";
  reader.close();
}

int List::get_length() {
  return zLength;
}

std::vector<Action*> List::get_actions() {
  return zActions;
}
