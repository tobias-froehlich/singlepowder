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
    throw std::invalid_argument("File does not exist!");
  }

  while (getline(reader, line)) {
    if ((utils::split(utils::remove_comment(line), ' ')).size() > 0) {
      zActions.push_back(new Action());
      zActions.back()->read_line(line);
      zActions.back()->set_datadirectory(zDataDirectory);
      zActions.back()->read_detectorimage();
    }
  }
}

std::vector<Action*> List::get_actions() {
  return zActions;
}
