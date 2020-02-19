#include <iostream>
#include <gtest/gtest.h>
#include "../src/const.cpp"
#include "../src/utils.h"
#include "../src/DetectorImage.h"
#include "../src/Parameters.h"
#include "../src/Action.h"
#include "../src/List.h"
#include "../src/Geometry.h"
#include "../src/Diffractogram.h"
#include "../src/Mask.h"
#include "../src/Integrator.h"

TEST(utils, split) {
  std::string str;
  std::vector< std::string > words;


  str = "eins zwei drei";
  words = {"eins", "zwei", "drei"};
  ASSERT_EQ(utils::split(str, ' '), words);

  str = " eins  zwei   drei ";
  words = {"eins", "zwei", "drei"};
  ASSERT_EQ(utils::split(str, ' '), words);

  str = "eins,zwei,drei";
  words = {"eins", "zwei", "drei"};
  ASSERT_EQ(utils::split(str, ','), words);
}

TEST(utils, split_equal) {
  std::string str;
  std::vector< std::string > words;

  str = "abcdef";
  words = {"abc", "def"};
  ASSERT_EQ(utils::split_equal(str, 3), words);

  str = "abcdef";
  words = {"ab", "cd", "ef"};
  ASSERT_EQ(utils::split_equal(str, 2), words);

  str = "abcdef";
  words = {"abcd", "ef"};
  ASSERT_EQ(utils::split_equal(str, 4), words);

  str = "";
  words = {};
  ASSERT_EQ(utils::split_equal(str, 4), words);
}

TEST(utils, rearrange_to_2index) {
  std::vector< int > values { 1, 2, 3, 4, 5 };
  ASSERT_THROW(utils::rearrange_to_2index(values, 2, 3), std::invalid_argument);
  ASSERT_THROW(utils::rearrange_to_2index(values, 2, 2), std::invalid_argument);
  
  values = { 1, 2, 3, 4, 5, 6};
  std::vector< std::vector< int > > result {{1, 2}, {3, 4}, {5, 6}};
  ASSERT_EQ(utils::rearrange_to_2index(values, 3, 2), result);
 

  values = { 1, 2, 3, 4, 5, 6};
  result = {{1, 2, 3}, {4, 5, 6}};
  ASSERT_EQ(utils::rearrange_to_2index(values, 2, 3), result);

}

TEST(utils, remove_comment) {
  std::string line = "hallo du # da # huhu";
  ASSERT_EQ(utils::remove_comment(line), "hallo du ");
  line = "hallo du ";
  ASSERT_EQ(utils::remove_comment(line), "hallo du ");
}

TEST(utils, square) {
  ASSERT_FLOAT_EQ(utils::square(3.0), 9.0);
  ASSERT_FLOAT_EQ(utils::square(-4.0), 16.0);
}

TEST(utils, float_equal) {
  ASSERT_TRUE(utils::float_equal(1.2345, 1.2345));
  ASSERT_FALSE(utils::float_equal(1.2345, 1.2346));
  ASSERT_TRUE(utils::float_equal(1.0, 1.0));
}

TEST(DetectorImage, create_and_delete) {
  DetectorImage* detector_image;
  detector_image = new DetectorImage();
  delete detector_image;
}

TEST(DetectorImage, read_file_file_missing) {
  DetectorImage* detector_image;
  detector_image = new DetectorImage();
  ASSERT_THROW(detector_image->read_file("not_existing_file.out"), std::invalid_argument);
  delete detector_image;
}

TEST(DetectorImage, read_file) {
  DetectorImage* detector_image;
  detector_image = new DetectorImage();
  detector_image->read_file("../../test/testdata/AR506a_apex001_01_0001.out");
  detector_image->read_file("../../test/testdata/TD015S001apex004_01_0001.out");
  ASSERT_EQ(detector_image->get_num_of_rows(), 512);
  ASSERT_EQ(detector_image->get_num_of_cols(), 512);
  delete detector_image;
}

TEST(DetectorImage, get_pixel) {
  DetectorImage* detector_image;
  detector_image = new DetectorImage();
  detector_image->read_file("../../test/testdata/AR506a_apex001_01_0001.out");
  ASSERT_EQ(detector_image->get_pixel(0, 511), 44);
  ASSERT_EQ(detector_image->get_pixel(1, 511), 31);
  ASSERT_EQ(detector_image->get_pixel(511, 511), 79);
  ASSERT_EQ(detector_image->get_pixel(511, 0), 8);
  ASSERT_EQ(detector_image->get_pixel(360, 341), 47);
  ASSERT_THROW(detector_image->get_pixel(-1, 0), std::invalid_argument);
  ASSERT_THROW(detector_image->get_pixel(512, 0), std::invalid_argument);
  ASSERT_THROW(detector_image->get_pixel(0, -1), std::invalid_argument);
  ASSERT_THROW(detector_image->get_pixel(0, 512), std::invalid_argument);
  delete detector_image;
}

TEST(Parameters, create_and_delete) {
  Parameters* parameters;
  parameters = new Parameters();
  delete parameters;
}

TEST(Parameters, small_functions) {
  std::string line = "";
  Parameters* parameters;
  parameters = new Parameters();
  line = "hallo 1.257 137.5";
  ASSERT_THROW(parameters->get_parametername(line), std::invalid_argument);
  line = "hallo 1.257";
  ASSERT_EQ(parameters->get_parametername(line), "hallo");
  line = "hallo 1.257 # comment";
  ASSERT_EQ(parameters->get_parametername(line), "hallo");
  line = "hallo abc";
  ASSERT_THROW(parameters->read_float_parameter(line), std::invalid_argument);
  line = "hallo 1.257";
  ASSERT_FLOAT_EQ(parameters->read_float_parameter(line), 1.257);
  line = "hallo 1.257 # this is a comment";
  ASSERT_FLOAT_EQ(parameters->read_float_parameter(line), 1.257);
  line = "hallo abc";
  ASSERT_THROW(parameters->read_int_parameter(line), std::invalid_argument);
  line = "hallo 1257";
  ASSERT_EQ(parameters->read_float_parameter(line), 1257);
  line = "hallo 1257 # this is a comment";
  ASSERT_EQ(parameters->read_float_parameter(line), 1257);
  line = "hallo blumentopf";
  ASSERT_EQ(parameters->read_str_parameter(line), "blumentopf");
  line = "hallo blumentopf # this is a comment";
  ASSERT_EQ(parameters->read_str_parameter(line), "blumentopf");

  delete parameters;
}

TEST(Parameters, read_file) {
  Parameters* parameters;
  parameters = new Parameters();
  ASSERT_THROW(parameters->read_file("not_existing_file.txt"), std::invalid_argument);
  parameters->read_file("../../test/testdata/parameters.txt");
  ASSERT_FLOAT_EQ(parameters->get_pixel_width(), 0.12);
  ASSERT_FLOAT_EQ(parameters->get_pixel_height(), 0.12);
  ASSERT_FLOAT_EQ(parameters->get_centre_pixel_x(), 258.0);
  ASSERT_FLOAT_EQ(parameters->get_centre_pixel_y(), 266.0);
  ASSERT_FLOAT_EQ(parameters->get_angle_min(), 5.0);
  ASSERT_FLOAT_EQ(parameters->get_angle_max(), 10.0);
  ASSERT_FLOAT_EQ(parameters->get_step(), 0.1);
  ASSERT_EQ(parameters->get_image_list_filename(), "../../test/testdata/images.txt");
  ASSERT_EQ(parameters->get_data_directory(), "../../test/testdata/");
  ASSERT_EQ(parameters->get_mask_filename(), "../../test/testdata/mask.txt");
  ASSERT_EQ(parameters->get_output_filename(), "../../test/testdata/output.txt");
  ASSERT_EQ(parameters->get_output_format(), "detailed");
  delete parameters;
}

TEST(Action, create_and_delete) {
  Action* action;
  action = new Action();
  delete action;
}

TEST(Action, read_line) {
  std::string line = "";
  Action* action;
  action = new Action();
  line = "eins zwei drei";
  ASSERT_THROW(action->read_line(line), std::invalid_argument);
  line = "eins zwei drei vier fuenf sechs sieben acht";
  ASSERT_THROW(action->read_line(line), std::invalid_argument);
  line = "eins zwei 3.0 4.0 5.0 6.0 7.0";
  ASSERT_THROW(action->read_line(line), std::invalid_argument);
  line = "eins 2.0 drei 4.0 5.0 6.0 7.0";
  ASSERT_THROW(action->read_line(line), std::invalid_argument);
  line = "eins 2.0 3.0 vier 5.0 6.0 7.0";
  ASSERT_THROW(action->read_line(line), std::invalid_argument);
  line = "eins 2.0 3.0 4.0 fuenf 6.0 7.0";
  ASSERT_THROW(action->read_line(line), std::invalid_argument);
  line = "eins 2.0 3.0 4.0 5.0 sechs 7.0";
  ASSERT_THROW(action->read_line(line), std::invalid_argument);
  line = "eins 2.0 3.0 4.0 5.0 6.0 sieben";
  ASSERT_THROW(action->read_line(line), std::invalid_argument);
  line = "eins 2.0 3.0 4.0 5.0 6.0 7.0";
  action->read_line(line);
  ASSERT_FLOAT_EQ(action->get_twotheta(), 2.0);
  ASSERT_FLOAT_EQ(action->get_theta(), 3.0);
  ASSERT_FLOAT_EQ(action->get_chi(), 4.0);
  ASSERT_FLOAT_EQ(action->get_detectordistance(), 5.0);
  ASSERT_FLOAT_EQ(action->get_scantime(), 6.0);
  ASSERT_FLOAT_EQ(action->get_weight(), 7.0);
  delete action;
}

TEST(Action, datadirectory) {
  Action* action;
  action = new Action();
  action->set_datadirectory("/hallo/welt/");
  ASSERT_EQ(action->get_datadirectory(), "/hallo/welt/");
  delete action;
}

TEST(Action, read_detectorimage) {
  Action* action;
  action = new Action();
  action->read_line("TD015S001apex004_01_0001.out    0.000000    0.000000    0.000000    80.000000    60.000000  1.0000");
  action->set_datadirectory("../../test/testdata/");
  action->read_detectorimage();
  ASSERT_EQ(action->get_detectorimage()->get_pixel(385, 371), 406);
  delete action;
}

TEST(List, create_and_delete) {
  List* list;
  list = new List();
  delete list;
}

TEST(List, datadirectory) {
  List* list;
  list = new List();
  list->set_datadirectory("/hallo/welt/");
  ASSERT_EQ(list->get_datadirectory(), "/hallo/welt/");
  delete list;
}

TEST(List, read_file) {
  List* list;
  list = new List();
  ASSERT_THROW(list->read_file("does_no_exist.txt"), std::invalid_argument);
  list->set_datadirectory("../../test/testdata/");
  list->read_file("../../test/testdata/images.txt");
  ASSERT_FLOAT_EQ(list->get_actions()[0]->get_twotheta(), 0.0);
  ASSERT_FLOAT_EQ(list->get_actions()[0]->get_theta(), 0.0);
  ASSERT_FLOAT_EQ(list->get_actions()[0]->get_chi(), 0.0);
  ASSERT_FLOAT_EQ(list->get_actions()[0]->get_detectordistance(), 80.0);
  ASSERT_FLOAT_EQ(list->get_actions()[0]->get_scantime(), 60.0);
  ASSERT_FLOAT_EQ(list->get_actions()[1]->get_twotheta(), 0.0);
  ASSERT_FLOAT_EQ(list->get_actions()[1]->get_theta(), 0.0);
  ASSERT_FLOAT_EQ(list->get_actions()[1]->get_chi(), 10.0);
  ASSERT_FLOAT_EQ(list->get_actions()[1]->get_detectordistance(), 80.0);
  ASSERT_FLOAT_EQ(list->get_actions()[1]->get_scantime(), 60.0);
  ASSERT_EQ(list->get_actions()[0]->get_detectorimage()->get_pixel(385, 371), 406);
  ASSERT_EQ(list->get_actions()[1]->get_detectorimage()->get_pixel(297, 439), 38);
  delete list;
}

TEST(Geometry, create_and_delete) {
  Geometry* geometry;
  geometry = new Geometry();
  delete geometry;
}

TEST(Geometry, set_and_get) {
  Geometry* geometry;
  geometry = new Geometry();
  geometry->set_detector_distance(80.0);
  geometry->set_pixel_width(2.0);
  geometry->set_pixel_height(3.0);
  geometry->set_centre_pixel_x(200.0);
  geometry->set_centre_pixel_y(300.0);
  geometry->set_twotheta(35.0);
  ASSERT_FLOAT_EQ(geometry->get_detector_distance(), 80.0);
  ASSERT_FLOAT_EQ(geometry->get_pixel_width(), 2.0);
  ASSERT_FLOAT_EQ(geometry->get_pixel_height(), 3.0);
  ASSERT_FLOAT_EQ(geometry->get_centre_pixel_x(), 200.0);
  ASSERT_FLOAT_EQ(geometry->get_centre_pixel_y(), 300.0);
  ASSERT_FLOAT_EQ(geometry->get_twotheta(), 35.0);
  delete geometry;
}

TEST(Geometry, calculate_powderangle) {
  Geometry* geometry;
  geometry = new Geometry();

  geometry->set_detector_distance(80.0);
  geometry->set_pixel_width(1.0);
  geometry->set_pixel_height(1.0);
  geometry->set_centre_pixel_x(256.0);
  geometry->set_centre_pixel_y(256.0);
  geometry->set_twotheta(0.0);
  ASSERT_FLOAT_EQ(geometry->calculate_powderangle(256, 256), 0.0);

  geometry->set_detector_distance(80.0);
  geometry->set_pixel_width(1.0);
  geometry->set_pixel_height(1.0);
  geometry->set_centre_pixel_x(256.0);
  geometry->set_centre_pixel_y(256.0);
  geometry->set_twotheta(90.0);
  ASSERT_FLOAT_EQ(geometry->calculate_powderangle(256, 256), 90.0);
  geometry->set_twotheta(-90.0);
  ASSERT_FLOAT_EQ(geometry->calculate_powderangle(256, 256), 90.0);
  geometry->set_twotheta(180.0);
  ASSERT_FLOAT_EQ(geometry->calculate_powderangle(256, 256), 180.0);
  geometry->set_twotheta(-180.0);
  ASSERT_FLOAT_EQ(geometry->calculate_powderangle(256, 256), 180.0);
  geometry->set_twotheta(35.0);
  ASSERT_FLOAT_EQ(geometry->calculate_powderangle(256, 256), 35.0);
  geometry->set_twotheta(-35.0);
  ASSERT_FLOAT_EQ(geometry->calculate_powderangle(256, 256), 35.0);

  geometry->set_detector_distance(80.0);
  geometry->set_pixel_width(1.0);
  geometry->set_pixel_height(1.0);
  geometry->set_centre_pixel_x(256.0);
  geometry->set_centre_pixel_y(256.0);
  geometry->set_twotheta(70.0);
  ASSERT_FLOAT_EQ(geometry->calculate_powderangle(256, 256), 70.0);
  ASSERT_FLOAT_EQ(geometry->calculate_powderangle(266, 256), 62.8749836511);
  ASSERT_FLOAT_EQ(geometry->calculate_powderangle(256, 266), 70.1609547636);
  ASSERT_FLOAT_EQ(geometry->calculate_powderangle(266, 266), 63.0979690188);


  geometry->set_detector_distance(80.0);
  geometry->set_pixel_width(2.0);
  geometry->set_pixel_height(5.0);
  geometry->set_centre_pixel_x(256.0);
  geometry->set_centre_pixel_y(256.0);
  geometry->set_twotheta(70.0);
  ASSERT_FLOAT_EQ(geometry->calculate_powderangle(256, 256), 70.0);
  ASSERT_FLOAT_EQ(geometry->calculate_powderangle(261, 256), 62.8749836511);
  ASSERT_FLOAT_EQ(geometry->calculate_powderangle(256, 258), 70.1609547636);
  ASSERT_FLOAT_EQ(geometry->calculate_powderangle(261, 258), 63.0979690188);

  geometry->set_detector_distance(160.0);
  geometry->set_pixel_width(4.0);
  geometry->set_pixel_height(10.0);
  geometry->set_centre_pixel_x(256.0);
  geometry->set_centre_pixel_y(256.0);
  geometry->set_twotheta(70.0);
  ASSERT_FLOAT_EQ(geometry->calculate_powderangle(256, 256), 70.0);
  ASSERT_FLOAT_EQ(geometry->calculate_powderangle(261, 256), 62.8749836511);
  ASSERT_FLOAT_EQ(geometry->calculate_powderangle(256, 258), 70.1609547636);
  ASSERT_FLOAT_EQ(geometry->calculate_powderangle(261, 258), 63.0979690188);

  delete geometry;
}

TEST(Diffractogram, create_and_delete) {
  Diffractogram* diffractogram;
  diffractogram = new Diffractogram();
  delete diffractogram;
}

TEST(Diffractogram, init) {
  Diffractogram* diffractogram;
  diffractogram = new Diffractogram();
 
  ASSERT_THROW(diffractogram->set_output_format("invalidformat"), std::invalid_argument);

  ASSERT_THROW(diffractogram->init(0.0, 10.0, -0.1), std::invalid_argument);
  ASSERT_THROW(diffractogram->init(0.0, 10.0, 0.0), std::invalid_argument);

  diffractogram->init(0.0, 1.0, 0.1);
  ASSERT_EQ(diffractogram->get_length(), 11);
  ASSERT_FLOAT_EQ(diffractogram->get_angle_min(), 0.0);
  ASSERT_FLOAT_EQ(diffractogram->get_angle_max(), 1.0);
  ASSERT_FLOAT_EQ(diffractogram->get_step(), 0.1);
  ASSERT_THROW(diffractogram->get_angle(-1), std::invalid_argument);
  ASSERT_THROW(diffractogram->get_angle(11), std::invalid_argument);
  ASSERT_FLOAT_EQ(diffractogram->get_angle(0), 0.0);
  ASSERT_FLOAT_EQ(diffractogram->get_angle(10), 1.0);
  ASSERT_THROW(diffractogram->get_num_of_pixels(-1), std::invalid_argument);
  ASSERT_THROW(diffractogram->get_num_of_pixels(11), std::invalid_argument);
  ASSERT_EQ(diffractogram->get_num_of_pixels(0), 0);
  ASSERT_EQ(diffractogram->get_num_of_pixels(10), 0);
  ASSERT_THROW(diffractogram->get_sum_of_weights(-1), std::invalid_argument);
  ASSERT_THROW(diffractogram->get_sum_of_weights(11), std::invalid_argument);
  ASSERT_FLOAT_EQ(diffractogram->get_sum_of_weights(0), 0.0);
  ASSERT_FLOAT_EQ(diffractogram->get_sum_of_weights(10), 0.0);
  ASSERT_THROW(diffractogram->get_sum_of_weighted_counts(-1), std::invalid_argument);
  ASSERT_THROW(diffractogram->get_sum_of_weighted_counts(11), std::invalid_argument);
  ASSERT_FLOAT_EQ(diffractogram->get_sum_of_weighted_counts(0), 0.0);
  ASSERT_FLOAT_EQ(diffractogram->get_sum_of_weighted_counts(10), 0.0);
  ASSERT_THROW(diffractogram->get_sum_of_squareweighted_counts(-1), std::invalid_argument);
  ASSERT_THROW(diffractogram->get_sum_of_squareweighted_counts(11), std::invalid_argument);
  ASSERT_FLOAT_EQ(diffractogram->get_sum_of_squareweighted_counts(0), 0.0);
  ASSERT_FLOAT_EQ(diffractogram->get_sum_of_squareweighted_counts(10), 0.0);
  ASSERT_THROW(diffractogram->get_intensity(-1), std::invalid_argument);
  ASSERT_THROW(diffractogram->get_intensity(11), std::invalid_argument);
  ASSERT_FLOAT_EQ(diffractogram->get_error(0), 0.0);
  ASSERT_FLOAT_EQ(diffractogram->get_error(10), 0.0);

  diffractogram->init(0.0, 1.09, 0.1);
  ASSERT_EQ(diffractogram->get_length(), 11);
  ASSERT_FLOAT_EQ(diffractogram->get_angle_min(), 0.0);
  ASSERT_FLOAT_EQ(diffractogram->get_angle_max(), 1.0);
  ASSERT_FLOAT_EQ(diffractogram->get_step(), 0.1);
  ASSERT_THROW(diffractogram->get_angle(-1), std::invalid_argument);
  ASSERT_THROW(diffractogram->get_angle(11), std::invalid_argument);
  ASSERT_FLOAT_EQ(diffractogram->get_angle(0), 0.0);
  ASSERT_FLOAT_EQ(diffractogram->get_angle(10), 1.0);
  ASSERT_THROW(diffractogram->get_num_of_pixels(-1), std::invalid_argument);
  ASSERT_THROW(diffractogram->get_num_of_pixels(11), std::invalid_argument);
  ASSERT_EQ(diffractogram->get_num_of_pixels(0), 0);
  ASSERT_EQ(diffractogram->get_num_of_pixels(10), 0);
  ASSERT_THROW(diffractogram->get_sum_of_weights(-1), std::invalid_argument);
  ASSERT_THROW(diffractogram->get_sum_of_weights(11), std::invalid_argument);
  ASSERT_FLOAT_EQ(diffractogram->get_sum_of_weights(0), 0.0);
  ASSERT_FLOAT_EQ(diffractogram->get_sum_of_weights(10), 0.0);
  ASSERT_THROW(diffractogram->get_sum_of_weighted_counts(-1), std::invalid_argument);
  ASSERT_THROW(diffractogram->get_sum_of_weighted_counts(11), std::invalid_argument);
  ASSERT_FLOAT_EQ(diffractogram->get_sum_of_weighted_counts(0), 0.0);
  ASSERT_FLOAT_EQ(diffractogram->get_sum_of_weighted_counts(10), 0.0);
  ASSERT_THROW(diffractogram->get_sum_of_squareweighted_counts(-1), std::invalid_argument);
  ASSERT_THROW(diffractogram->get_sum_of_squareweighted_counts(11), std::invalid_argument);
  ASSERT_FLOAT_EQ(diffractogram->get_sum_of_squareweighted_counts(0), 0.0);
  ASSERT_FLOAT_EQ(diffractogram->get_sum_of_squareweighted_counts(10), 0.0);
  ASSERT_THROW(diffractogram->get_intensity(-1), std::invalid_argument);
  ASSERT_THROW(diffractogram->get_intensity(11), std::invalid_argument);
  ASSERT_FLOAT_EQ(diffractogram->get_error(0), 0.0);
  ASSERT_FLOAT_EQ(diffractogram->get_error(10), 0.0);

  diffractogram->init(5.0, 10.0, 0.5);
  ASSERT_EQ(diffractogram->get_length(), 11);
  ASSERT_FLOAT_EQ(diffractogram->get_angle_min(), 5.0);
  ASSERT_FLOAT_EQ(diffractogram->get_angle_max(), 10.0);
  ASSERT_FLOAT_EQ(diffractogram->get_step(), 0.5);
  ASSERT_THROW(diffractogram->get_angle(-1), std::invalid_argument);
  ASSERT_THROW(diffractogram->get_angle(11), std::invalid_argument);
  ASSERT_FLOAT_EQ(diffractogram->get_angle(0), 5.0);
  ASSERT_FLOAT_EQ(diffractogram->get_angle(10), 10.0);
  ASSERT_THROW(diffractogram->get_num_of_pixels(-1), std::invalid_argument);
  ASSERT_THROW(diffractogram->get_num_of_pixels(11), std::invalid_argument);
  ASSERT_EQ(diffractogram->get_num_of_pixels(0), 0);
  ASSERT_EQ(diffractogram->get_num_of_pixels(10), 0);
  ASSERT_THROW(diffractogram->get_sum_of_weights(-1), std::invalid_argument);
  ASSERT_THROW(diffractogram->get_sum_of_weights(11), std::invalid_argument);
  ASSERT_FLOAT_EQ(diffractogram->get_sum_of_weights(0), 0.0);
  ASSERT_FLOAT_EQ(diffractogram->get_sum_of_weights(10), 0.0);
  ASSERT_THROW(diffractogram->get_sum_of_weighted_counts(-1), std::invalid_argument);
  ASSERT_THROW(diffractogram->get_sum_of_weighted_counts(11), std::invalid_argument);
  ASSERT_FLOAT_EQ(diffractogram->get_sum_of_weighted_counts(0), 0.0);
  ASSERT_FLOAT_EQ(diffractogram->get_sum_of_weighted_counts(10), 0);
  ASSERT_THROW(diffractogram->get_sum_of_squareweighted_counts(-1), std::invalid_argument);
  ASSERT_THROW(diffractogram->get_sum_of_squareweighted_counts(11), std::invalid_argument);
  ASSERT_FLOAT_EQ(diffractogram->get_sum_of_squareweighted_counts(0), 0.0);
  ASSERT_FLOAT_EQ(diffractogram->get_sum_of_squareweighted_counts(10), 0);
  for(int i=0; i<diffractogram->get_length(); i++) {
    ASSERT_EQ(diffractogram->get_num_of_pixels(i), 0);
    ASSERT_FLOAT_EQ(diffractogram->get_sum_of_weights(i), 0.0);
    ASSERT_FLOAT_EQ(diffractogram->get_sum_of_weighted_counts(i), 0.0);
    ASSERT_FLOAT_EQ(diffractogram->get_sum_of_squareweighted_counts(i), 0.0);
  }
  diffractogram->add_counts(4.7499, 5, 1.0);
  for(int i=0; i<diffractogram->get_length(); i++) {
    ASSERT_EQ(diffractogram->get_num_of_pixels(i), 0);
    ASSERT_FLOAT_EQ(diffractogram->get_sum_of_weights(i), 0.0);
    ASSERT_FLOAT_EQ(diffractogram->get_sum_of_weighted_counts(i), 0.0);
    ASSERT_FLOAT_EQ(diffractogram->get_sum_of_squareweighted_counts(i), 0.0);
    ASSERT_FLOAT_EQ(diffractogram->get_intensity(i), 0.0);
    ASSERT_FLOAT_EQ(diffractogram->get_error(i), 0.0);
  }
  diffractogram->add_counts(10.2501, 5, 1.0);
  for(int i=0; i<diffractogram->get_length(); i++) {
    ASSERT_EQ(diffractogram->get_num_of_pixels(i), 0);
    ASSERT_FLOAT_EQ(diffractogram->get_sum_of_weights(i), 0.0);
    ASSERT_FLOAT_EQ(diffractogram->get_sum_of_weighted_counts(i), 0.0);
    ASSERT_FLOAT_EQ(diffractogram->get_sum_of_squareweighted_counts(i), 0.0);
    ASSERT_FLOAT_EQ(diffractogram->get_intensity(i), 0.0);
    ASSERT_FLOAT_EQ(diffractogram->get_error(i), 0.0);
  }
  diffractogram->add_counts(4.7501, 5, 0.5);
  ASSERT_EQ(diffractogram->get_num_of_pixels(0), 1);
  ASSERT_FLOAT_EQ(diffractogram->get_sum_of_weights(0), 0.5);
  ASSERT_FLOAT_EQ(diffractogram->get_sum_of_weighted_counts(0), 2.5);
  ASSERT_FLOAT_EQ(diffractogram->get_sum_of_squareweighted_counts(0), 1.25);
  ASSERT_FLOAT_EQ(diffractogram->get_intensity(0), 0.0);
  ASSERT_FLOAT_EQ(diffractogram->get_error(0), 0.0);
  diffractogram->add_counts(4.7501, 3, 1.0);
  ASSERT_EQ(diffractogram->get_num_of_pixels(0), 2);
  ASSERT_FLOAT_EQ(diffractogram->get_sum_of_weights(0), 1.5);
  ASSERT_FLOAT_EQ(diffractogram->get_sum_of_weighted_counts(0), 5.5);
  ASSERT_FLOAT_EQ(diffractogram->get_sum_of_squareweighted_counts(0), 4.25);
  ASSERT_FLOAT_EQ(diffractogram->get_intensity(0), 0.0);
  ASSERT_FLOAT_EQ(diffractogram->get_error(0), 0.0);
  diffractogram->add_counts(10.2499, 7, 0.2);
  ASSERT_EQ(diffractogram->get_num_of_pixels(10), 1);
  ASSERT_FLOAT_EQ(diffractogram->get_sum_of_weights(10), 0.2);
  ASSERT_FLOAT_EQ(diffractogram->get_sum_of_weighted_counts(10), 1.4);
  ASSERT_FLOAT_EQ(diffractogram->get_sum_of_squareweighted_counts(10), 0.28);
  ASSERT_FLOAT_EQ(diffractogram->get_intensity(10), 0.0);
  ASSERT_FLOAT_EQ(diffractogram->get_error(10), 0.0);

  delete diffractogram;
}

TEST(Diffractogram, calculate_intentsites_and_errors) {
  Diffractogram* diffractogram;
  diffractogram = new Diffractogram();

  diffractogram->init(0.0, 10.0, 0.1);
  diffractogram->add_counts(0.0, 5, 0.5);
  diffractogram->add_counts(0.0, 3, 1.0);
  diffractogram->calculate_intensities_and_errors();
  ASSERT_FLOAT_EQ(diffractogram->get_intensity(0), 3.6666666666666);
  ASSERT_FLOAT_EQ(diffractogram->get_error(0), 1.37436854187);

  delete diffractogram;
}

TEST(Diffractogram, write_file) {
  Diffractogram* diffractogram;
  diffractogram = new Diffractogram();
  diffractogram->init(5.0, 10.0, 0.1);
  ASSERT_THROW(diffractogram->write_file("notexisting_path/output.txt"), std::invalid_argument);
  diffractogram->add_counts(7.0, 5, 0.5);
  diffractogram->add_counts(7.0, 3, 0.3);
  diffractogram->write_file("../../test/testdata/output.txt");
  delete diffractogram;
}

TEST(Integrator, create_and_delete) {
  Integrator* integrator;
  integrator = new Integrator();
  delete integrator;
}

TEST(Integrator, integrate) {
  Integrator* integrator;
  integrator = new Integrator();
  integrator->integrate("../../test/testdata/parameters.txt");
  delete integrator;
}

TEST(Mask, create_and_delete) {
  Mask* mask;
  mask = new Mask();
  delete mask;
}

TEST(Mask, read_file) {
  Mask* mask;
  mask = new Mask();
  ASSERT_THROW(mask->read_file("notexsistingfile.txt"), std::invalid_argument);
  ASSERT_THROW(mask->read_file("../../test/testdata/wrong_mask.txt"), std::invalid_argument);
  mask->read_file("../../test/testdata/mask.txt");
  ASSERT_THROW(mask->get_pixel(-1, 0), std::invalid_argument);
  ASSERT_THROW(mask->get_pixel(512, 0), std::invalid_argument);
  ASSERT_THROW(mask->get_pixel(0, -1), std::invalid_argument);
  ASSERT_THROW(mask->get_pixel(0, 512), std::invalid_argument);
  ASSERT_FLOAT_EQ(mask->get_pixel(0, 2), 5.0);
  ASSERT_FLOAT_EQ(mask->get_pixel(3, 0), 4.0);
  ASSERT_FLOAT_EQ(mask->get_pixel(2, 6), 6.0);
  delete mask;
}

TEST (Mask, write_file) {
  Mask* mask;
  mask = new Mask();
  mask->read_file("../../test/testdata/mask.txt");
  ASSERT_THROW(mask->write_file("../../test/nonexisting_directory/file.txt"), std::invalid_argument);
  mask->write_file("../../test/testdata/outputmask.txt");
  delete mask;
}

TEST(Mask, init) {
  Mask* mask;
  mask = new Mask();
  mask->init(10, 20);
  ASSERT_THROW(mask->get_pixel(-1, 0), std::invalid_argument);
  ASSERT_THROW(mask->get_pixel(0, -1), std::invalid_argument);
  ASSERT_THROW(mask->get_pixel(10, 0), std::invalid_argument);
  ASSERT_THROW(mask->get_pixel(0, 20), std::invalid_argument);
  mask->get_pixel(0,0);
  mask->get_pixel(9, 19);
  delete mask;
}

TEST(Mask, set_pixel) {
  Mask* mask;
  mask = new Mask();
  mask->init(10, 20);
  ASSERT_THROW(mask->set_pixel(-1, 0, 0.0), std::invalid_argument);
  ASSERT_THROW(mask->set_pixel(0, -1, 0.0), std::invalid_argument);
  ASSERT_THROW(mask->set_pixel(10, 0, 0.0), std::invalid_argument);
  ASSERT_THROW(mask->set_pixel(0, 20, 0.0), std::invalid_argument);
  mask->set_pixel(5, 6, 1.23);
  ASSERT_FLOAT_EQ(mask->get_pixel(5, 6), 1.23);
  delete mask;
}
int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
