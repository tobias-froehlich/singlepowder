#include <iostream>
#include <string>
#include <vector>
#include <chrono>
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
  auto timepoint0 = std::chrono::high_resolution_clock::now();

  // Read the parameter file:
  zParameters->read_file(parameterfilename);

  // Pass the geometric parameters to zGeometry:
  zGeometry->set_pixel_width(zParameters->get_pixel_width());
  zGeometry->set_pixel_height(zParameters->get_pixel_height());
  zGeometry->set_centre_pixel_x(zParameters->get_centre_pixel_x());
  zGeometry->set_centre_pixel_y(zParameters->get_centre_pixel_y());

  // Pass the data directory to zList:
  zList->set_datadirectory(zParameters->get_data_directory());

  auto timepoint1 = std::chrono::high_resolution_clock::now();

  // Read the list file, and zList calls the zActions
  // to read the image files:
  zList->read_file(zParameters->get_image_list_filename());

  auto timepoint2 = std::chrono::high_resolution_clock::now();

  // initialize zDiffractogram:
  zDiffractogram->init(
    zParameters->get_angle_min(),
    zParameters->get_angle_max(),
    zParameters->get_step()
  );
  zDiffractogram->set_output_format(zParameters->get_output_format());

  // Loop over all images and all pixels to collect
  // the counts etc.:
  std::vector<Action*> actions = zList->get_actions();

  DetectorImage* detectorimage;
  int counts;
  float angle;
  float weight;

  auto timepoint3 = std::chrono::high_resolution_clock::now();

  int i = 0;
  for (Action* action : actions) {
    i += 1;
    std::cout << "Processing image " << i << " of " << zList->get_length() << "\n";
    detectorimage = action->get_detectorimage();
    weight = action->get_weight();
    zGeometry->set_detector_distance(action->get_detectordistance());
    zGeometry->set_twotheta(action->get_twotheta());
    for (int y=0; y<512; y++) {
      for (int x=0; x<512; x++) {
        counts = detectorimage->get_pixel(x, y);
        angle = zGeometry->calculate_powderangle(x, y);
        zDiffractogram->add_counts(angle, counts, weight);
      }
    }
  }

  auto timepoint4 = std::chrono::high_resolution_clock::now();

  // Calculate intensities with error propagation:
  zDiffractogram->calculate_intensities_and_errors();

  // Write output file:
  zDiffractogram->write_file(zParameters->get_output_filename());
  std::cout << "Outputfile written successfully.\n";

  auto timepoint5 = std::chrono::high_resolution_clock::now();


  std::cout << "time for reading list and images: " << std::chrono::duration_cast<std::chrono::milliseconds>(timepoint2 - timepoint1).count() << " milliseconds\n";
  std::cout << "time processing the images: " << std::chrono::duration_cast<std::chrono::milliseconds>(timepoint4 - timepoint3).count() << " milliseconds\n";
  std::cout << "total time: " << std::chrono::duration_cast<std::chrono::milliseconds>(timepoint5 - timepoint0).count() << " milliseconds\n";

}
