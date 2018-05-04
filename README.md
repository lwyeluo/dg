# DG

[![Build Status](https://travis-ci.org/mchalupa/dg.svg?branch=master)](https://travis-ci.org/mchalupa/dg)

Dg is a library which implements dependence graphs for programs.
It contains a set of generic templates that can be specialized to user's needs.
Dg can be used for different analyses, optimizations or program slicing
(we currently use it for the last one in our tool called Symbiotic:
https://github.com/staticafi/symbiotic). As a part of dg, you can find
pointer analyses, reaching definitions analysis and a static slicer
for LLVM.

Whole project is under developement and lacks documentation for now,
so in the case of need, contact us by an e-mail (below).

## LLVM DependenceGraph && llvm-slicer

We have implemented a dependence graph for LLVM and a static slicer for LLVM.

### Requirements & Compilation

LLVM DependenceGraph needs LLVM 3.4 or higher.
Clone the repository to your machine:

```
git clone https://github.com/tum-i22/dg.git
cd dg
```

Once you have the project cloned, you need to configure it.
Fully manual configuration would look like this:

```
cmake -DLLVM_SRC_PATH=/path/to/src -DLLVM_BUILD_PATH=/path/to/build -DLLVM_DIR=path/to/llvm/share/llvm/cmake .
```

LLVM\_DIR is an environment variable used by LLVM to find cmake config files
(it points to the build or install directory),
LLVM\_SRC\_DIR is a variable that tells cmake where to look for llvm's sources
and it is used to override include paths. The same holds for LLVM\_BUILD\_PATH
that is used to override library paths. Usually, you don't need to specify
all these variables. When LLVM is installed on your system in standard paths,
the configuration should look just like:

```
cmake .
```

If there is any collision (i.e. there are more versions of LLVM installed),
you may need to define the LLVM\_DIR variable to point to the directory where
are the config files of the desired version ($PREFIX/share/llvm/cmake
or $PREFIX/lib/cmake/llvm/ for newer versions).
If you have LLVM compiled from sources, but not installed anywhere,
you may need to use LLVM\_SRC\_PATH and LLVM\_BUILD\_PATH variables too.
For the last case, suppose you have LLVM built in /home/user/llvm-build from
sources in /home/user/llvm-src. Then the following configuration should work:

```
cmake -DLLVM_SRC_PATH=/home/user/llvm-src -DLLVM_BUILD_PATH=/home/user/llvm-build -DLLVM_DIR=/home/user/llvm-build/share/llvm/cmake .
```

After configuring the project, usual make takes place:

```
make -j4
```
Installing dg in your machine

```
make install
```


