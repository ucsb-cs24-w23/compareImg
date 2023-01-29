# Compare images using opencv!

This is a C++ program/library that can compare absolute difference of images by calling opencv library.

## Why I worte this program?

True, we can just use opencv directly, but the installation and configuration of opencv can be time consuming, and configure it in the autograder environment is not really good idea. This program packaged required opencv library into the binary it generates, enabling the program to run on computers that doesn't have opencv lib installed. Although the binary can be 20M+ large, I think it is still a good way to integrate opencv features into the autograder program.

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
