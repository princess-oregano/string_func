#include "tests.h"

void test_strlen_f()
{

        char str[STRING_SIZE] = {};

        fgets(str, STRING_SIZE, stdin);

        fprintf(stderr, "strlen():   %zu\n", strlen(str));
        fprintf(stderr, "strlen_f(): %zu\n", strlen_f(str));
}

void test_strcpy_f()
{
        char src[STRING_SIZE] = "Cat";
        char dest1[STRING_SIZE] = "Cute";
        char dest2[STRING_SIZE] = {};

        memcpy(dest2, dest1, STRING_SIZE);

        strcpy(dest1, src);
        strcpy_f(dest2, src);

        printf("strcpy():  %s\n", dest1);
        printf("strcpy_f():%s\n", dest2);
}

void test_strchr_f()
{
        int target = 'a';
        char str[] = "Cat";

        printf("strchr():   %p\n", strchr(str, target));
        printf("strchr_f(): %p\n", strchr_f(str, target));
}

void test_strcmp_f()
{
        char lhs[STRING_SIZE] = {};
        char rhs[STRING_SIZE] = {};

        scanf("%s %s", lhs, rhs);

        printf("srtcmp()  : %d\n", strcmp(lhs, rhs));
        printf("srtcmp_f(): %d\n", strcmp_f(lhs, rhs));
}

void test_strcat_f()
{
        char dest1[STRING_SIZE] = {};
        char dest2[STRING_SIZE] = {};
        char src[STRING_SIZE] = {};

        scanf("%s %s", dest1, src);

        memcpy(dest2, dest1, STRING_SIZE);

        strcat(dest1, src);
        strcat_f(dest2, src);

        printf("srtcat():   %s\n", dest1);
        printf("strcat_f(): %s\n", dest2);
}


