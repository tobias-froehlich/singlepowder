#include <iostream>
#include <gtest/gtest.h>
#include "../src/const.cpp"
#include "../src/utils.h"
#include "../src/DetectorImage.h"
#include "../src/Parameters.h"

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
  Parameters* parameters;
  std::string line = "hallo du # da # huhu";
  parameters = new Parameters();
  ASSERT_EQ(parameters->remove_comment(line), "hallo du ");
  line = "hallo du ";
  ASSERT_EQ(parameters->remove_comment(line), "hallo du ");
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
  ASSERT_FLOAT_EQ(parameters->get_detector_distance(), 80.0);
  delete parameters;
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
