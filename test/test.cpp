#include <iostream>
#include <gtest/gtest.h>
#include "../src/const.cpp"
#include "../src/utils.h"
#include "../src/DetectorImage.h"
#include "../src/Parameters.h"
#include "../src/Action.h"
#include "../src/List.h"

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
  ASSERT_EQ(parameters->get_image_list_filename(), "images.txt");
  ASSERT_EQ(parameters->get_data_directory(), "/home/froehlich/TD015S001apex004/");
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
  line = "eins zwei drei vier fuenf sechs sieben";
  ASSERT_THROW(action->read_line(line), std::invalid_argument);
  line = "eins zwei 3.0 4.0 5.0 6.0";
  ASSERT_THROW(action->read_line(line), std::invalid_argument);
  line = "eins 2.0 drei 4.0 5.0 6.0";
  ASSERT_THROW(action->read_line(line), std::invalid_argument);
  line = "eins 2.0 3.0 vier 5.0 6.0";
  ASSERT_THROW(action->read_line(line), std::invalid_argument);
  line = "eins 2.0 3.0 4.0 fuenf 6.0";
  ASSERT_THROW(action->read_line(line), std::invalid_argument);
  line = "eins 2.0 3.0 4.0 5.0 sechs";
  ASSERT_THROW(action->read_line(line), std::invalid_argument);
  line = "eins 2.0 3.0 4.0 5.0 6.0";
  action->read_line(line);
  ASSERT_FLOAT_EQ(action->get_twotheta(), 2.0);
  ASSERT_FLOAT_EQ(action->get_theta(), 3.0);
  ASSERT_FLOAT_EQ(action->get_chi(), 4.0);
  ASSERT_FLOAT_EQ(action->get_detectordistance(), 5.0);
  ASSERT_FLOAT_EQ(action->get_scantime(), 6.0);
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
  action->read_line("TD015S001apex004_01_0001.out    0.000000    0.000000    0.000000    80.000000    60.000000");
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
  list->read_file("../../test/testdata/list.txt");
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

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
