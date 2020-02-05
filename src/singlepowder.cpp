#include <iostream>
#include "singlepowderConfig.h"

int main(int argc, char** argv) {
  std::cout << "Hello World!\n";
  if (argc < 2) {
    //report version
    std::cout << argv[0] << " Version " << singlepowder_VERSION_MAJOR << "." << singlepowder_VERSION_MINOR << '\n';
    std::cout << "Usage: " << argv[0] << " number" << '\n';
  }
}
