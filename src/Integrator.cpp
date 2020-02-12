#include <string>
#include <vector>
#include "const.cpp"
#include "utils.h"
#include "Parameters.h"
#include "DetectorImage.h"
#include "Action.h"
#include "List.h"
#include "Geometry.h"
#include "Diffractogram.h"
#include "Integrator.h"

Integrator::Integrator() {
  zParameters = new Parameters();
  zList = new List();
  zGeometry = new Geometry();
  zDiffractogram = new Diffractogram();
}

Integrator::~Integrator() {
  delete zParameters;
  delete zList;
  delete zGeometry;
  delete zDiffractogram;
}

void Integrator::integrate(std::string parameterfilename) {
  zParameters->read_file(parameterfilename);

  zGeometry->set_pixel_width(zParameters->get_pixel_width());
  zGeometry->set_pixel_height(zParameters->get_pixel_height());
  zGeometry->set_centre_pixel_x(zParameters->get_centre_pixel_x());
  zGeometry->set_centre_pixel_y(zParameters->get_centre_pixel_y());

  zList->set_datadirectory(zParameters->get_data_directory());
  zList->read_file(zParameters->get_image_list_filename());

  zDiffractogram->init(
    zParameters->get_angle_min(),
    zParameters->get_angle_max(),
    zParameters->get_step()
  );

  std::vector<Action*> actions = zList->get_actions();
  DetectorImage* detectorimage;
  int counts;
  float angle;
  for (Action* action : actions) {
    detectorimage = action->get_detectorimage();
    zGeometry->set_detector_distance(action->get_detectordistance());
    zGeometry->set_twotheta(action->get_twotheta());
    for (int y=0; y<512; y++) {
      for (int x=0; x<512; x++) {
        counts = detectorimage->get_pixel(x, y);
        angle = zGeometry->calculate_powderangle(x, y);
        zDiffractogram->add_counts(angle, counts);
      }
    }
  }
  zDiffractogram->write_file(zParameters->get_output_filename());
}
