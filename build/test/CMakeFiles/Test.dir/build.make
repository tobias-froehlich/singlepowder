# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/froehlich/singlepowder

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/froehlich/singlepowder/build

# Include any dependencies generated for this target.
include test/CMakeFiles/Test.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/Test.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/Test.dir/flags.make

test/CMakeFiles/Test.dir/test.cpp.o: test/CMakeFiles/Test.dir/flags.make
test/CMakeFiles/Test.dir/test.cpp.o: ../test/test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/froehlich/singlepowder/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/Test.dir/test.cpp.o"
	cd /home/froehlich/singlepowder/build/test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Test.dir/test.cpp.o -c /home/froehlich/singlepowder/test/test.cpp

test/CMakeFiles/Test.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test.dir/test.cpp.i"
	cd /home/froehlich/singlepowder/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/froehlich/singlepowder/test/test.cpp > CMakeFiles/Test.dir/test.cpp.i

test/CMakeFiles/Test.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test.dir/test.cpp.s"
	cd /home/froehlich/singlepowder/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/froehlich/singlepowder/test/test.cpp -o CMakeFiles/Test.dir/test.cpp.s

test/CMakeFiles/Test.dir/test.cpp.o.requires:

.PHONY : test/CMakeFiles/Test.dir/test.cpp.o.requires

test/CMakeFiles/Test.dir/test.cpp.o.provides: test/CMakeFiles/Test.dir/test.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/Test.dir/build.make test/CMakeFiles/Test.dir/test.cpp.o.provides.build
.PHONY : test/CMakeFiles/Test.dir/test.cpp.o.provides

test/CMakeFiles/Test.dir/test.cpp.o.provides.build: test/CMakeFiles/Test.dir/test.cpp.o


test/CMakeFiles/Test.dir/__/src/utils.cpp.o: test/CMakeFiles/Test.dir/flags.make
test/CMakeFiles/Test.dir/__/src/utils.cpp.o: ../src/utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/froehlich/singlepowder/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/CMakeFiles/Test.dir/__/src/utils.cpp.o"
	cd /home/froehlich/singlepowder/build/test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Test.dir/__/src/utils.cpp.o -c /home/froehlich/singlepowder/src/utils.cpp

test/CMakeFiles/Test.dir/__/src/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test.dir/__/src/utils.cpp.i"
	cd /home/froehlich/singlepowder/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/froehlich/singlepowder/src/utils.cpp > CMakeFiles/Test.dir/__/src/utils.cpp.i

test/CMakeFiles/Test.dir/__/src/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test.dir/__/src/utils.cpp.s"
	cd /home/froehlich/singlepowder/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/froehlich/singlepowder/src/utils.cpp -o CMakeFiles/Test.dir/__/src/utils.cpp.s

test/CMakeFiles/Test.dir/__/src/utils.cpp.o.requires:

.PHONY : test/CMakeFiles/Test.dir/__/src/utils.cpp.o.requires

test/CMakeFiles/Test.dir/__/src/utils.cpp.o.provides: test/CMakeFiles/Test.dir/__/src/utils.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/Test.dir/build.make test/CMakeFiles/Test.dir/__/src/utils.cpp.o.provides.build
.PHONY : test/CMakeFiles/Test.dir/__/src/utils.cpp.o.provides

test/CMakeFiles/Test.dir/__/src/utils.cpp.o.provides.build: test/CMakeFiles/Test.dir/__/src/utils.cpp.o


test/CMakeFiles/Test.dir/__/src/DetectorImage.cpp.o: test/CMakeFiles/Test.dir/flags.make
test/CMakeFiles/Test.dir/__/src/DetectorImage.cpp.o: ../src/DetectorImage.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/froehlich/singlepowder/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object test/CMakeFiles/Test.dir/__/src/DetectorImage.cpp.o"
	cd /home/froehlich/singlepowder/build/test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Test.dir/__/src/DetectorImage.cpp.o -c /home/froehlich/singlepowder/src/DetectorImage.cpp

test/CMakeFiles/Test.dir/__/src/DetectorImage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test.dir/__/src/DetectorImage.cpp.i"
	cd /home/froehlich/singlepowder/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/froehlich/singlepowder/src/DetectorImage.cpp > CMakeFiles/Test.dir/__/src/DetectorImage.cpp.i

test/CMakeFiles/Test.dir/__/src/DetectorImage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test.dir/__/src/DetectorImage.cpp.s"
	cd /home/froehlich/singlepowder/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/froehlich/singlepowder/src/DetectorImage.cpp -o CMakeFiles/Test.dir/__/src/DetectorImage.cpp.s

test/CMakeFiles/Test.dir/__/src/DetectorImage.cpp.o.requires:

.PHONY : test/CMakeFiles/Test.dir/__/src/DetectorImage.cpp.o.requires

test/CMakeFiles/Test.dir/__/src/DetectorImage.cpp.o.provides: test/CMakeFiles/Test.dir/__/src/DetectorImage.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/Test.dir/build.make test/CMakeFiles/Test.dir/__/src/DetectorImage.cpp.o.provides.build
.PHONY : test/CMakeFiles/Test.dir/__/src/DetectorImage.cpp.o.provides

test/CMakeFiles/Test.dir/__/src/DetectorImage.cpp.o.provides.build: test/CMakeFiles/Test.dir/__/src/DetectorImage.cpp.o


test/CMakeFiles/Test.dir/__/src/Parameters.cpp.o: test/CMakeFiles/Test.dir/flags.make
test/CMakeFiles/Test.dir/__/src/Parameters.cpp.o: ../src/Parameters.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/froehlich/singlepowder/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object test/CMakeFiles/Test.dir/__/src/Parameters.cpp.o"
	cd /home/froehlich/singlepowder/build/test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Test.dir/__/src/Parameters.cpp.o -c /home/froehlich/singlepowder/src/Parameters.cpp

test/CMakeFiles/Test.dir/__/src/Parameters.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test.dir/__/src/Parameters.cpp.i"
	cd /home/froehlich/singlepowder/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/froehlich/singlepowder/src/Parameters.cpp > CMakeFiles/Test.dir/__/src/Parameters.cpp.i

test/CMakeFiles/Test.dir/__/src/Parameters.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test.dir/__/src/Parameters.cpp.s"
	cd /home/froehlich/singlepowder/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/froehlich/singlepowder/src/Parameters.cpp -o CMakeFiles/Test.dir/__/src/Parameters.cpp.s

test/CMakeFiles/Test.dir/__/src/Parameters.cpp.o.requires:

.PHONY : test/CMakeFiles/Test.dir/__/src/Parameters.cpp.o.requires

test/CMakeFiles/Test.dir/__/src/Parameters.cpp.o.provides: test/CMakeFiles/Test.dir/__/src/Parameters.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/Test.dir/build.make test/CMakeFiles/Test.dir/__/src/Parameters.cpp.o.provides.build
.PHONY : test/CMakeFiles/Test.dir/__/src/Parameters.cpp.o.provides

test/CMakeFiles/Test.dir/__/src/Parameters.cpp.o.provides.build: test/CMakeFiles/Test.dir/__/src/Parameters.cpp.o


test/CMakeFiles/Test.dir/__/src/Action.cpp.o: test/CMakeFiles/Test.dir/flags.make
test/CMakeFiles/Test.dir/__/src/Action.cpp.o: ../src/Action.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/froehlich/singlepowder/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object test/CMakeFiles/Test.dir/__/src/Action.cpp.o"
	cd /home/froehlich/singlepowder/build/test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Test.dir/__/src/Action.cpp.o -c /home/froehlich/singlepowder/src/Action.cpp

test/CMakeFiles/Test.dir/__/src/Action.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test.dir/__/src/Action.cpp.i"
	cd /home/froehlich/singlepowder/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/froehlich/singlepowder/src/Action.cpp > CMakeFiles/Test.dir/__/src/Action.cpp.i

test/CMakeFiles/Test.dir/__/src/Action.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test.dir/__/src/Action.cpp.s"
	cd /home/froehlich/singlepowder/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/froehlich/singlepowder/src/Action.cpp -o CMakeFiles/Test.dir/__/src/Action.cpp.s

test/CMakeFiles/Test.dir/__/src/Action.cpp.o.requires:

.PHONY : test/CMakeFiles/Test.dir/__/src/Action.cpp.o.requires

test/CMakeFiles/Test.dir/__/src/Action.cpp.o.provides: test/CMakeFiles/Test.dir/__/src/Action.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/Test.dir/build.make test/CMakeFiles/Test.dir/__/src/Action.cpp.o.provides.build
.PHONY : test/CMakeFiles/Test.dir/__/src/Action.cpp.o.provides

test/CMakeFiles/Test.dir/__/src/Action.cpp.o.provides.build: test/CMakeFiles/Test.dir/__/src/Action.cpp.o


test/CMakeFiles/Test.dir/__/src/List.cpp.o: test/CMakeFiles/Test.dir/flags.make
test/CMakeFiles/Test.dir/__/src/List.cpp.o: ../src/List.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/froehlich/singlepowder/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object test/CMakeFiles/Test.dir/__/src/List.cpp.o"
	cd /home/froehlich/singlepowder/build/test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Test.dir/__/src/List.cpp.o -c /home/froehlich/singlepowder/src/List.cpp

test/CMakeFiles/Test.dir/__/src/List.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test.dir/__/src/List.cpp.i"
	cd /home/froehlich/singlepowder/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/froehlich/singlepowder/src/List.cpp > CMakeFiles/Test.dir/__/src/List.cpp.i

test/CMakeFiles/Test.dir/__/src/List.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test.dir/__/src/List.cpp.s"
	cd /home/froehlich/singlepowder/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/froehlich/singlepowder/src/List.cpp -o CMakeFiles/Test.dir/__/src/List.cpp.s

test/CMakeFiles/Test.dir/__/src/List.cpp.o.requires:

.PHONY : test/CMakeFiles/Test.dir/__/src/List.cpp.o.requires

test/CMakeFiles/Test.dir/__/src/List.cpp.o.provides: test/CMakeFiles/Test.dir/__/src/List.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/Test.dir/build.make test/CMakeFiles/Test.dir/__/src/List.cpp.o.provides.build
.PHONY : test/CMakeFiles/Test.dir/__/src/List.cpp.o.provides

test/CMakeFiles/Test.dir/__/src/List.cpp.o.provides.build: test/CMakeFiles/Test.dir/__/src/List.cpp.o


test/CMakeFiles/Test.dir/__/src/Geometry.cpp.o: test/CMakeFiles/Test.dir/flags.make
test/CMakeFiles/Test.dir/__/src/Geometry.cpp.o: ../src/Geometry.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/froehlich/singlepowder/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object test/CMakeFiles/Test.dir/__/src/Geometry.cpp.o"
	cd /home/froehlich/singlepowder/build/test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Test.dir/__/src/Geometry.cpp.o -c /home/froehlich/singlepowder/src/Geometry.cpp

test/CMakeFiles/Test.dir/__/src/Geometry.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test.dir/__/src/Geometry.cpp.i"
	cd /home/froehlich/singlepowder/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/froehlich/singlepowder/src/Geometry.cpp > CMakeFiles/Test.dir/__/src/Geometry.cpp.i

test/CMakeFiles/Test.dir/__/src/Geometry.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test.dir/__/src/Geometry.cpp.s"
	cd /home/froehlich/singlepowder/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/froehlich/singlepowder/src/Geometry.cpp -o CMakeFiles/Test.dir/__/src/Geometry.cpp.s

test/CMakeFiles/Test.dir/__/src/Geometry.cpp.o.requires:

.PHONY : test/CMakeFiles/Test.dir/__/src/Geometry.cpp.o.requires

test/CMakeFiles/Test.dir/__/src/Geometry.cpp.o.provides: test/CMakeFiles/Test.dir/__/src/Geometry.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/Test.dir/build.make test/CMakeFiles/Test.dir/__/src/Geometry.cpp.o.provides.build
.PHONY : test/CMakeFiles/Test.dir/__/src/Geometry.cpp.o.provides

test/CMakeFiles/Test.dir/__/src/Geometry.cpp.o.provides.build: test/CMakeFiles/Test.dir/__/src/Geometry.cpp.o


test/CMakeFiles/Test.dir/__/src/Diffractogram.cpp.o: test/CMakeFiles/Test.dir/flags.make
test/CMakeFiles/Test.dir/__/src/Diffractogram.cpp.o: ../src/Diffractogram.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/froehlich/singlepowder/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object test/CMakeFiles/Test.dir/__/src/Diffractogram.cpp.o"
	cd /home/froehlich/singlepowder/build/test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Test.dir/__/src/Diffractogram.cpp.o -c /home/froehlich/singlepowder/src/Diffractogram.cpp

test/CMakeFiles/Test.dir/__/src/Diffractogram.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test.dir/__/src/Diffractogram.cpp.i"
	cd /home/froehlich/singlepowder/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/froehlich/singlepowder/src/Diffractogram.cpp > CMakeFiles/Test.dir/__/src/Diffractogram.cpp.i

test/CMakeFiles/Test.dir/__/src/Diffractogram.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test.dir/__/src/Diffractogram.cpp.s"
	cd /home/froehlich/singlepowder/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/froehlich/singlepowder/src/Diffractogram.cpp -o CMakeFiles/Test.dir/__/src/Diffractogram.cpp.s

test/CMakeFiles/Test.dir/__/src/Diffractogram.cpp.o.requires:

.PHONY : test/CMakeFiles/Test.dir/__/src/Diffractogram.cpp.o.requires

test/CMakeFiles/Test.dir/__/src/Diffractogram.cpp.o.provides: test/CMakeFiles/Test.dir/__/src/Diffractogram.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/Test.dir/build.make test/CMakeFiles/Test.dir/__/src/Diffractogram.cpp.o.provides.build
.PHONY : test/CMakeFiles/Test.dir/__/src/Diffractogram.cpp.o.provides

test/CMakeFiles/Test.dir/__/src/Diffractogram.cpp.o.provides.build: test/CMakeFiles/Test.dir/__/src/Diffractogram.cpp.o


test/CMakeFiles/Test.dir/__/src/Integrator.cpp.o: test/CMakeFiles/Test.dir/flags.make
test/CMakeFiles/Test.dir/__/src/Integrator.cpp.o: ../src/Integrator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/froehlich/singlepowder/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object test/CMakeFiles/Test.dir/__/src/Integrator.cpp.o"
	cd /home/froehlich/singlepowder/build/test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Test.dir/__/src/Integrator.cpp.o -c /home/froehlich/singlepowder/src/Integrator.cpp

test/CMakeFiles/Test.dir/__/src/Integrator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test.dir/__/src/Integrator.cpp.i"
	cd /home/froehlich/singlepowder/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/froehlich/singlepowder/src/Integrator.cpp > CMakeFiles/Test.dir/__/src/Integrator.cpp.i

test/CMakeFiles/Test.dir/__/src/Integrator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test.dir/__/src/Integrator.cpp.s"
	cd /home/froehlich/singlepowder/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/froehlich/singlepowder/src/Integrator.cpp -o CMakeFiles/Test.dir/__/src/Integrator.cpp.s

test/CMakeFiles/Test.dir/__/src/Integrator.cpp.o.requires:

.PHONY : test/CMakeFiles/Test.dir/__/src/Integrator.cpp.o.requires

test/CMakeFiles/Test.dir/__/src/Integrator.cpp.o.provides: test/CMakeFiles/Test.dir/__/src/Integrator.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/Test.dir/build.make test/CMakeFiles/Test.dir/__/src/Integrator.cpp.o.provides.build
.PHONY : test/CMakeFiles/Test.dir/__/src/Integrator.cpp.o.provides

test/CMakeFiles/Test.dir/__/src/Integrator.cpp.o.provides.build: test/CMakeFiles/Test.dir/__/src/Integrator.cpp.o


# Object files for target Test
Test_OBJECTS = \
"CMakeFiles/Test.dir/test.cpp.o" \
"CMakeFiles/Test.dir/__/src/utils.cpp.o" \
"CMakeFiles/Test.dir/__/src/DetectorImage.cpp.o" \
"CMakeFiles/Test.dir/__/src/Parameters.cpp.o" \
"CMakeFiles/Test.dir/__/src/Action.cpp.o" \
"CMakeFiles/Test.dir/__/src/List.cpp.o" \
"CMakeFiles/Test.dir/__/src/Geometry.cpp.o" \
"CMakeFiles/Test.dir/__/src/Diffractogram.cpp.o" \
"CMakeFiles/Test.dir/__/src/Integrator.cpp.o"

# External object files for target Test
Test_EXTERNAL_OBJECTS =

test/Test: test/CMakeFiles/Test.dir/test.cpp.o
test/Test: test/CMakeFiles/Test.dir/__/src/utils.cpp.o
test/Test: test/CMakeFiles/Test.dir/__/src/DetectorImage.cpp.o
test/Test: test/CMakeFiles/Test.dir/__/src/Parameters.cpp.o
test/Test: test/CMakeFiles/Test.dir/__/src/Action.cpp.o
test/Test: test/CMakeFiles/Test.dir/__/src/List.cpp.o
test/Test: test/CMakeFiles/Test.dir/__/src/Geometry.cpp.o
test/Test: test/CMakeFiles/Test.dir/__/src/Diffractogram.cpp.o
test/Test: test/CMakeFiles/Test.dir/__/src/Integrator.cpp.o
test/Test: test/CMakeFiles/Test.dir/build.make
test/Test: /usr/lib/libgtest.a
test/Test: test/CMakeFiles/Test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/froehlich/singlepowder/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable Test"
	cd /home/froehlich/singlepowder/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/Test.dir/build: test/Test

.PHONY : test/CMakeFiles/Test.dir/build

test/CMakeFiles/Test.dir/requires: test/CMakeFiles/Test.dir/test.cpp.o.requires
test/CMakeFiles/Test.dir/requires: test/CMakeFiles/Test.dir/__/src/utils.cpp.o.requires
test/CMakeFiles/Test.dir/requires: test/CMakeFiles/Test.dir/__/src/DetectorImage.cpp.o.requires
test/CMakeFiles/Test.dir/requires: test/CMakeFiles/Test.dir/__/src/Parameters.cpp.o.requires
test/CMakeFiles/Test.dir/requires: test/CMakeFiles/Test.dir/__/src/Action.cpp.o.requires
test/CMakeFiles/Test.dir/requires: test/CMakeFiles/Test.dir/__/src/List.cpp.o.requires
test/CMakeFiles/Test.dir/requires: test/CMakeFiles/Test.dir/__/src/Geometry.cpp.o.requires
test/CMakeFiles/Test.dir/requires: test/CMakeFiles/Test.dir/__/src/Diffractogram.cpp.o.requires
test/CMakeFiles/Test.dir/requires: test/CMakeFiles/Test.dir/__/src/Integrator.cpp.o.requires

.PHONY : test/CMakeFiles/Test.dir/requires

test/CMakeFiles/Test.dir/clean:
	cd /home/froehlich/singlepowder/build/test && $(CMAKE_COMMAND) -P CMakeFiles/Test.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/Test.dir/clean

test/CMakeFiles/Test.dir/depend:
	cd /home/froehlich/singlepowder/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/froehlich/singlepowder /home/froehlich/singlepowder/test /home/froehlich/singlepowder/build /home/froehlich/singlepowder/build/test /home/froehlich/singlepowder/build/test/CMakeFiles/Test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/Test.dir/depend

