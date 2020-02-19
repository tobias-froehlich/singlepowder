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
#include "Mask.h"
#include "Integrator.h"
#include "MaskMaker.h"

int main(int argc, char** argv) {
  std::cout << argc << "\n";
  if ((argc == 3) && (std::string(argv[1]) == "integrate")){
    Integrator* integrator;
    integrator = new Integrator();
    integrator->integrate(argv[2]);
    delete integrator;
  }
  else if ((argc == 5) && (std::string(argv[1]) == "make_mask")) {
    MaskMaker* maskmaker;
    maskmaker = new MaskMaker();
    maskmaker->make_mask(argv[2], argv[3], argv[4]);
    delete maskmaker;
  }
  else {
    std::cout << argv[0] << " Version " << singlepowder_VERSION_MAJOR << "." << singlepowder_VERSION_MINOR << '\n';
    std::cout << "Usage: " << argv[0] << " number" << '\n';
  }
}
