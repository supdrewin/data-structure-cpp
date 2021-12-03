# Data Structure C++

This is the source code repository for my homework of data structure course 100% written in C++.

### Compile Guide

Supported Compiler:

* Clang
* GCC
* MinGW

Native build on Linux host

1. Compile pre-request:

   ```shell
   $ make lib GCC=1
   ```

   or with `libc++`:

   ```shell
   $ make lib
   ```

2. Compile all sub-project:

   ```shell
   $ make
   ```

   or using Clang:

   ```shell
   $ make TARGET=-llvm
   ```

Cross build on Linux host

1. Compile pre-request:

   ```shell
   $ make lib CROSS=1
   ```
2. Compile all sub-project:

   ```shell
   $ make TARGET=-cross
   ```

**NOTE:**

* `llvm` and `clang` is **requested** while compiling the library.
* I **haven't** compiled it under Windows yet, try it **on your risk**.
* The **cross-build** binary can work fine with _Windows(10 11)_.

### Test Guide

You can test it on `Linux` or `Wondows` host. Feel free to feedback if it's BUG.

Some program may not interactive and need to pass arguments.
