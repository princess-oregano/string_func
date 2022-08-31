#include "tests.h"
#include <stdlib.h>

void test_strlen_f()
{
        char str[STRING_SIZE] = {};

        printf("Enter a line:\n");
        fgets(str, STRING_SIZE, stdin);
        str[strlen(str)-1] = '\0';
        
        fprintf(stderr, "strlen():   %zu\n", strlen(str));
        fprintf(stderr, "strlen_f(): %zu\n", strlen_f(str));
}

void test_strcpy_f()
{
        char src[STRING_SIZE] = {};
        char dest1[STRING_SIZE] = {};
        char dest2[STRING_SIZE] = {};

        printf("Enter a line to copy:\n");
        fgets(src, STRING_SIZE, stdin);
        src[strlen(src)-1] = '\0';
        printf("Enter a destination line:\n");
        fgets(dest1, STRING_SIZE, stdin);
        dest1[strlen(dest1)-1] = '\0';
        
        memcpy(dest2, dest1, STRING_SIZE);

        strcpy(dest1, src);
        strcpy_f(dest2, src);

        printf("strcpy():  %s\n", dest1);
        printf("strcpy_f():%s\n", dest2);
}

void test_strchr_f()
{
        char target = '\0';
        char str[STRING_SIZE] = {};

        printf("Enter a line:\n");
        fgets(str, STRING_SIZE, stdin);
        str[strlen(str)-1] = '\0';
        target = '\0';

        while (getchar() != '\n')
                ;

        printf("strchr():   %p\n", strchr(str, target));
        printf("strchr_f(): %p\n", strchr_f(str, target));
}

void test_strcmp_f()
{
        char lhs[STRING_SIZE] = {};
        char rhs[STRING_SIZE] = {};

        printf("Enter the first line:\n");
        fgets(lhs, STRING_SIZE, stdin);
        lhs[strlen(lhs)-1] = '\0';
        printf("Enter the second line:\n");
        fgets(rhs, STRING_SIZE, stdin);
        rhs[strlen(rhs)-1] = '\0';

        printf("srtcmp()  : %d\n", strcmp(lhs, rhs));
        printf("srtcmp_f(): %d\n", strcmp_f(lhs, rhs));
}

void test_strcat_f()
{
        char dest1[STRING_SIZE] = {};
        char dest2[STRING_SIZE] = {};
        char src[STRING_SIZE] = {};

        printf("Enter the first line:\n");
        fgets(dest1, STRING_SIZE, stdin);
        dest1[strlen(dest1)-1] = '\0';
        printf("Enter the second line:\n");
        fgets(src, STRING_SIZE, stdin);
        src[strlen(src)-1] = '\0';

        memcpy(dest2, dest1, STRING_SIZE);

        strcat(dest1, src);
        strcat_f(dest2, src);

        printf("srtcat():   %s\n", dest1);
        printf("strcat_f(): %s\n", dest2);
}

void test_getline_f()
{
        char *lineptr = NULL;
        size_t n = 0;

        printf("Enter a line:\n");
        getline_f(&lineptr, &n, stdin);
        printf("%s", lineptr);
        free(lineptr);
}

