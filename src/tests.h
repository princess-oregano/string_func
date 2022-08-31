#ifdef __STDC_ALLOC_LIB__
#define __STDC_WANT_LIB_EXT2__ 1
#else
#define _POSIX_C_SOURCE 200809L
#endif

#ifndef TESTS_H
#define TESTS_H

#include "str_funcs.h"

const int STRING_SIZE = 50;

void test_strlen_f();
void test_strcpy_f();
void test_strchr_f();
void test_strcmp_f();
void test_strcat_f();
void test_getline_f();

#endif // TESTS_H

