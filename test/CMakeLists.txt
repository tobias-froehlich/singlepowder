find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable( Test 
  test.cpp 
  ../src/utils.cpp
  ../src/DetectorImage.cpp
  ../src/Parameters.cpp
  ../src/Action.cpp
  ../src/List.cpp
  ../src/Geometry.cpp
  ../src/Diffractogram.cpp
  ../src/Integrator.cpp
)
target_link_libraries(Test ${GTEST_LIBRARIES} pthread)
