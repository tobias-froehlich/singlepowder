#include <iostream>
#include <gtest/gtest.h>
#include "../src/DetectorImage.h"
#include "../src/utils.h"
#include "../src/utils.cpp"

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

TEST(DetectorImage, create_and_delete) {
  DetectorImage* detector_image;
  detector_image = new DetectorImage();
  delete detector_image;
}


TEST(DetectorImage, read_file_file_missing) {
  DetectorImage* detector_image;
  detector_image = new DetectorImage();
  ASSERT_THROW(detector_image->read_file("hallowelt"), std::invalid_argument);
  delete detector_image;
}

TEST(DetectorImage, read_file) {
  DetectorImage* detector_image;
  detector_image = new DetectorImage();
  detector_image->read_file("../../test/testdata/AR506a_apex001_01_0001.out");
  delete detector_image;
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
