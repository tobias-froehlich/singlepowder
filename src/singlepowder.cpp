#include <iostream>
#include <vector>
#include <string>
#include "singlepowderConfig.h"
#include "const.cpp"
#include "utils.h"
#include "DetectorImage.h"
#include "Parameters.h"
#include "Action.h"
#include "List.h"
#include "Geometry.h"
#include "Diffractogram.h"
#include "Integrator.h"

int main(int argc, char** argv) {
  std::cout << "Hello World!\n";
  if (argc != 2) {
    //report version
    std::cout << argv[0] << " Version " << singlepowder_VERSION_MAJOR << "." << singlepowder_VERSION_MINOR << '\n';
    std::cout << "Usage: " << argv[0] << " number" << '\n';
  }
  else {
    Integrator* integrator;
    integrator = new Integrator();

    integrator->integrate(argv[1]);

    delete integrator;
  }
}
