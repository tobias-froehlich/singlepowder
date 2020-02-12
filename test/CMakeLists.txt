find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable( Test 
  test.cpp 
  ../src/utils.cpp
  ../src/Vector.cpp
  ../src/DetectorImage.cpp
  ../src/Parameters.cpp
  ../src/Action.cpp
  ../src/List.cpp
)
target_link_libraries(Test ${GTEST_LIBRARIES} pthread)
