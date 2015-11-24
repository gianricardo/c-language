# Contact List App

*by Lucas Camargo*

## About

"agenda" is a simple application to create and manage small contact lists in the terminal.
It supports storing names, birthdays, phone numbers, emails and twitter handles.
There are no dependencies besides the c standard library and support for extended `stdio` functionality.

## To build:
 - Create a build directory "build"
 - Run cmake for this directory
 - Run make
 
## Example:

    mkdir build
    cd build
    cmake -DBUILD_DOCUMENTATION=ON ..
    make
    make doc

This will also build the documentation.

**Important:** Remember to install graphviz in addition to doxygen! Or doxygen will fail and cry...