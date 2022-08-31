#include "str_funcs.h"
#include <stdlib.h>

/*
 * -----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 * |    |  A  |  B  |  C  |  D  | \0  |     |     |     |     |     |     |
 * -----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 * len =   1  -> 2  -> 3  -> 4  -> ^
 *                                 |
 *                            END OF CYCLE
 */
size_t strlen_f(const char *str)
{
        size_t len = 0;

        for (len = 0; str[len] != '\0'; len++)
                ;

        return len;
}

/*
 * -----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 * |    |  A  |  B  |  C  |  D  | \0  |     |     |  a  |  b  |  c  | \0  |     |
 * -----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 *         ^     ^     ^     ^                       |     |     |     |
 *         |_____|_____|_____|_______________________|     |     |     |
 *               |_____|_____|_____________________________|     |     |
 *                     |_____|___________________________________|     |
 *                           |_________________________________________|
 *                                            copied
 */
char *strcpy_f(char *dest, const char *src)
{
        int i = 0;

        for (i = 0; src[i] != '\0'; i++)
                dest[i] = src[i];

        dest[i] = '\0';

        return dest;
}

/*
 * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 * |     |     |     |  A  |  B  |  C  |  D  | \0  |     |     |     |     |     |     |
 * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 *                      ^     ^     ^
 *           compared   |     |     | <- cycle stopped
 *                      C     C     C
 */
char *strchr_f(const char *str, int target)
{
        while (*str != (char) target) {
                if (!*str++) {
                        return NULL;
                }
        }

        return (char *) str;
}

/*
 * -----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 * |    |  A  |  B  |  C  |  D  | \0  |     |     |  A  |  B  |  E  | \0  |     |
 * -----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 *         ^     ^     ^                             |     |     |
 *         |_____|_____|_____________________________|     |     |
 *               |_____|___________________________________|     |
 *                     |_________________________________________|
 *                                       compared
 */
int strcmp_f(const char *lhs, const char *rhs)
{
        for ( ; *lhs != '\0' && *rhs != '\0' && *lhs == *rhs; lhs++, rhs++)
                ;

        return (*lhs - *rhs);
}

/*
 *
 *
 * -----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 * |    |  A  |  B  |  C  |  D  |  E  |  F  |  G  | \0  |     |     |     |  E  |  F  |  G  | \0  |     |
 * -----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 * -----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 * |    |  A  |  B  |  C  |  D  | \0  |     |     |     |     |     |     |  E  |  F  |  G  | \0  |     |
 * -----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 *                                 ^     ^     ^     ^                       |     |     |     |
 *                                 |_____|_____|_____|_______________________|     |     |     |
 *                                       |_____|_____|_____________________________|     |     |
 *                                             |_____|___________________________________|     |
 *                                                   |_________________________________________|
 *                                                                     copied
 */
char *strcat_f(char *dest, const char *src)
{
        int size_dest = (int) strlen(dest);
        int size_src  = (int) strlen(src);
        int i = 0;
        int j = 0;

        for (i = size_dest, j = 0; j <= size_src; i++, j++)
                dest[i] = src[j];

        return dest;
}

ssize_t getline_f(char **lineptr, size_t *n, FILE *stream)
{
        char ch = 0;
        char *ptr_ch = NULL;
        size_t add_buf_size = 10;
        size_t buf_size = *n + add_buf_size;
        size_t max_buf_size = buf_size + add_buf_size;
        int i = 0;

        if (*lineptr == NULL || *n == 0) {
                buf_size = 3;
                if((*lineptr = (char *) calloc(buf_size, sizeof(char))) == NULL)
                        return -1;
        }

        for (ptr_ch = *lineptr; ; i++) {
                int ch = fgetc(stream);

                if (ch == EOF)
                        return -1;

                *ptr_ch++ = ch;

                if (ch == '\n') {
                        *ptr_ch = '\0';
                        return ptr_ch - *lineptr;
                }
 
                if (buf_size + 2 >= max_buf_size) {
                        buf_size = max_buf_size;
                        max_buf_size += add_buf_size;
                        ssize_t delta = ptr_ch - *lineptr;
                        char *n_lineptr = NULL;

                        n_lineptr = (char *) realloc(*lineptr, (buf_size * sizeof(char)));

                        *lineptr = n_lineptr;
                        ptr_ch = n_lineptr + delta;
                }
        }
}
