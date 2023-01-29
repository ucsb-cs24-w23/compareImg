# Compare images using opencv!

This is a C++ program/library that can compare absolute difference of images by calling opencv library.

## Program version:

In master branch, will generate binary executable for command line operations.

Usage:

```{bash}
git clone <this-repo>
cmake .
make
CompareImg <inputFile1> <inputFile2>
```

## Library version:

In lib branch, will generate .so file for other cpp programs to link dynamically.

*I tried to make .a library but failed*

Usage:

```{bash}
git clone <this-repo>
git checkout lib
cmake .
make
```

To test the lib, use the test.cpp under test folder.

```{bash}
cd test
cp ../libcompare-img.so ./lib/libcompare-img.so
cmake .
make
```

Please open issues and pull requests if you have any thoughts or suggestions on this program!

Happy studying!
