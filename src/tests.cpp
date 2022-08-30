#include "tests.h"

void test_strlen_f()
{
        const int STRING_SIZE = 50;
        
        char str[STRING_SIZE] = {};

        fgets(str, STRING_SIZE, stdin);
       
        fprintf(stderr, "strlen():   %zu\n", strlen(str));
        fprintf(stderr, "strlen_f(): %zu\n", strlen_f(str));
}

void test_strcpy_f()
{
        const int SRC_SIZE = 4;
        const int DEST_SIZE = 5;

        char src[SRC_SIZE] = "Cat";
        char dest1[DEST_SIZE] = "Cute";
        char dest2[DEST_SIZE] = {};

        memcpy(dest2, dest1, DEST_SIZE);

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
        char lhs[50] = {};
        char rhs[50] = {};

        scanf("%s %s", lhs, rhs);

        printf("srtcmp()  : %d\n", strcmp(lhs, rhs));
        printf("srtcmp_f(): %d\n", strcmp_f(lhs, rhs));
}

void test_strcat_f()
{
        char dest1[50] = {};
        char dest2[50] = {};
        char src[50] = {};

        scanf("%s %s", dest1, src);

        memcpy(dest2, dest1, 50);

        strcat(dest1, src);
        strcat_f(dest2, src);

        printf("srtcat():   %s\n", dest1);
        printf("strcat_f(): %s\n", dest2);
}

        
