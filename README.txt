Installing GTest:

sudo aptitude install libgtest-dev
cd /usr/src/googletest/
sudo cmake .
sudo cmake --build . --target install

Building singlepowder:

Create directory singlepowder/build (if not exists).
In singlepowder/build/
rm -r *
cmake ..
make

Testing:

in singlepowder/bin/
./Test


