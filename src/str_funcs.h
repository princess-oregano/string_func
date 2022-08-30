#ifndef STR_FUNCS_H
#define STR_FUNCS_H

#include <stdio.h>
#include <string.h>

size_t strlen_f(const char *str);
char  *strcpy_f(char *dest, const char *src);
char  *strchr_f(const char *str, int target);
int    strcmp_f(const char *lhs, const char *rhs);
char  *strcat_f(char *dest, const char *src);

#endif // STR_FUNCS_H 

