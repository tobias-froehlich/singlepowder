Installing GTest:

sudo aptitude install libgtest-dev
cd /usr/src/googletest/
sudo cmake .
sudo cmake --build . --target install

Building singlepowder:

in singlepowder/build/
rm -r *
cmake ..
make

Testing:

in singlepowder/build/test
./Test


