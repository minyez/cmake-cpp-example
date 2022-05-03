This is a demonstration of using cmake in C++ project, with features of

- [X] structured directory
- [ ] unit tests
- [ ] link to external header files and libraries (using BLAS as example)
- [X] build executable binary and optionally static/dynamic library

# Directory structure

```
├── doc
├── include
├── src
├── CMakeLists.txt
└── README.md
```

- `doc`: documentaion
- `include`: the header files with signatures of public functions, used when compiling other programs against this project library.
- `src`: source code

# References

1. CMakeList.txt inside [FHI-aims](https://fhi-aims.org/) code
2. C++ examples in [cmake cookbook](https://github.com/dev-cafe/cmake-cookbook).
