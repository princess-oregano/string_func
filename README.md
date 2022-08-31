# string_func
Implementations of some string functions.

## Table of contents
* [Prerequisites](#prerequisites)
* [Available functions](#available-functions)
* [Installation and setup](#installation-and-setup)
* [Usage](@usage)

## Prerequisites
* `git`
* `make`
* `g++`

## Available functions implementations
* strlen_f() for strlen()
* strcpy_f() for strcpy()
* strchr_f() for strchr()
* strcmp_f() for strcmp()
* strcat_f() for strcat()
* getline_f() for getline()

## Installation and setup
1. Download all source files into one folder:
```
$ git clone https://github.com/tyvia/string_func
```
2. Open the subfolder with source files and build with Make:
```
$ cd string_func/
$ make all
```
This way the program for testing functions will automatically run.

3. You can run the testing program `string` again from the folder, where it was built:
```
$ ./string
```
4. To remove all object files type this:
```
$ make clean
```
5. To remove all files built by make type this:
```
$ make distclean
```

## Usage
After you start the program, you will see a menu with 6 options, each option is corresponding to a function test.
To choose an option, print a letter corresponding to it, and hit `<Enter>`.
To exit a program type any character other than integer numbers.

