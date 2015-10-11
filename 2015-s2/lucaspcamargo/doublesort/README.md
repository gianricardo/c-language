# doublesort
Lucas Pires Camargo -- 11103082

## About
Sorts a list of doubles. Usage:
```
./doublesort in.txt out.txt
```

## Building
I am using cmake as a build system. You will need it to generate the required makefiles.

Open a terminal in the directory that contains this file and create a new directory for a shadow build. Then execute cmake in that directory with the source directory as an argument. You can then execute make. Like this:

```
mkdir build
cd build
cmake -DBUILD_DOCUMENTATION=ON ..
make
make doc
```

After make is done, for every source file in the chtp folder there should be a corresponding executable in the build folder.
The documentation should be accessible in `build/doc/html/index.html`. Remember that Doxygen and Graphviz should be installed for the last step.