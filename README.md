This is a demonstration of using cmake in C++ project, with features of

- [X] structured directory
- [X] unit tests
- [X] link to external libraries (using BLAS as example)
- [X] build executable binary and optionally static library
- [X] documentaion by Doxygen

# Directory structure

Combining the following examples:
- <https://github.com/dev-cafe/cmake-cookbook/tree/master/chapter-07/recipe-01/cxx-example>
- <https://github.com/dev-cafe/cmake-cookbook/tree/master/chapter-12/recipe-01/cxx-example>
- <https://github.com/dev-cafe/cmake-cookbook/tree/master/chapter-12/recipe-03/cxx-example>

```
├── cmake
├── docs
├── include
├── src
├── tests
├── CMakeLists.txt
└── README.md
```

- `cmake`: cmake load files
- `docs`: documentaion
- `include`: the header files with signatures of public functions, used when compiling other programs against this project library.
- `src`: source code
- `tests`: the unit test main functions.

# Build process

```shell
$ mkdir build && cd build
$ cmake ..
$ make
$ make test
$ make docs
```

The built docs will be under `build/docs/_build`. Open `html/index.html` to check the HTML documentaion.

# Trouble shooting

## Linking error when using BLAS/LAPCK compiled by gfortran

At linking stage

```
/usr/bin/ld: /home/minyez/local/programs/lapack-3.9.1/libblas.a(xerbla.o): in function `xerbla_':
xerbla.f:(.text+0x4a): undefined reference to `_gfortran_st_write'
/usr/bin/ld: xerbla.f:(.text+0x55): undefined reference to `_gfortran_string_len_trim'
/usr/bin/ld: xerbla.f:(.text+0x6c): undefined reference to `_gfortran_transfer_character_write'
/usr/bin/ld: xerbla.f:(.text+0x7c): undefined reference to `_gfortran_transfer_integer_write'
/usr/bin/ld: xerbla.f:(.text+0x84): undefined reference to `_gfortran_st_write_done'
/usr/bin/ld: xerbla.f:(.text+0x8f): undefined reference to `_gfortran_stop_string'
```

Solution: add `-lgfortran` to link libraries

## `relocation R_X86_64_32 against .rodata.str1.1 can not be used when making a shared object; recompile with -fPIC`

```
/usr/bin/ld: $HOME/local/programs/lapack-3.9.1/libblas.a(dgemv.o): relocation R_X86_64_32 against `.rodata.str1.1' can not be used when making a shared object; recompile with -fPIC
/usr/bin/ld: $HOME/local/programs/lapack-3.9.1/libblas.a(xerbla.o): relocation R_X86_64_32S against `.rodata.str1.1' can not be used when making a shared object; recompile with -fPIC
collect2: error: ld returned 1 exit status
make[2]: *** [src/CMakeFiles/cmake_cpp_example_lib.dir/build.make:133: libcmake_cpp_example_lib.so] Error 1
make[1]: *** [CMakeFiles/Makefile2:115: src/CMakeFiles/cmake_cpp_example_lib.dir/all] Error 2
make: *** [Makefile:103: all] Error 2
```

Does not work with `-fPIC` or `-fPIE`.
A quick solution is to disable the shared library.

## Undefined reference when compiling test executable without library

When turning off `USE_LIBRARY`,

```cmake
target_sources(test_mymath PRIVATE ${_sources})
```

where `_sources` is defined in `./src/CMakeLists.txt`. This will lead to linking error

```
/usr/bin/ld: CMakeFiles/test_mymath.dir/test_mymath.cpp.o: in function `main':
cmake-cpp-example/tests/test_mymath.cpp:19: undefined reference to `sum(int)'
/usr/bin/ld: cmake-cpp-example/tests/test_mymath.cpp:27: undefined reference to `dot(int, double*, double*)'
```

Solution: explicitly specify the source, by

```cmake
target_sources(test_mymath PRIVATE ../src/mymath.cpp)
```

# References

1. CMakeList.txt inside [FHI-aims](https://fhi-aims.org/) code
2. C++ examples in [cmake cookbook](https://github.com/dev-cafe/cmake-cookbook).
