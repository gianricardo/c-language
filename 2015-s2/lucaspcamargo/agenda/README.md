====================
  Contact List App
====================
by Lucas Camargo

To build:
 - Create a build directory "build"
 - Run cmake for this directory
 - Run make
 
Example:
mkdir build
cd build
cmake -DBUILD_DOCUMENTATION=ON ..
make
make doc

This will also build the documentation.

Remember to install graphviz in addition to doxygen! Or doxygen will fail and cry...