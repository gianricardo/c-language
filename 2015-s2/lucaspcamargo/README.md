# Exercicios Linguagem C
Lucas Pires Camargo -- 11103082

## Building
I am using cmake as a build system. You will need it to generate the required makefiles.

Open a terminal in the directory that contains this file and create a new directory for a shadow build. Then execute cmake in that directory with the source directory as an argument. You can then execute make. Like this:

```
mkdir build-chtp
cd build-chtp
cmake ../chtp
make
```

After make is done, for every source file in the chtp folder there should be a corresponding executable in the build folder.