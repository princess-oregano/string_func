#ifdef __STDC_ALLOC_LIB__
#define __STDC_WANT_LIB_EXT2__ 1
#else
#define _POSIX_C_SOURCE 200809L
#endif

#ifndef STR_FUNCS_H
#define STR_FUNCS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t   strlen_f(const char *str);
char    *strcpy_f(char *dest, const char *src);
char    *strchr_f(const char *str, int ch);
int      strcmp_f(const char *lhs, const char *rhs);
char    *strcat_f(char *dest, const char *src);
ssize_t getline_f(char **lineptr, size_t *n, FILE *stream);

#endif // STR_FUNCS_H

