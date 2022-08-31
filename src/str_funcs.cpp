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
        size_t size_dest = strlen(dest);

        for (size_t i = size_dest; *src != '\0'; i++, src++)
                dest[i] = *src;

        return dest;
}

ssize_t getline_f(char **lineptr, size_t *n, FILE *stream)
{
        char *ptr_ch = NULL;
        char *max_ptr_ch = NULL;
        size_t buf_size = *n;
        size_t max_buf_size = 0;
        int i = 0;

        if (*lineptr == NULL || *n == 0) {
                buf_size = 3;
                max_buf_size = 2 * buf_size;
                if((*lineptr = (char *) calloc(buf_size, sizeof(char))) == NULL)
                        return -1;
        }

        for (ptr_ch = *lineptr, max_ptr_ch = *lineptr + buf_size; ; i++) {
                int ch = fgetc(stream);

                if (ch == EOF)
                        return -1;

                *ptr_ch++ = (char) ch;

                if (ch == '\n') {
                        *ptr_ch = '\0';
                        return ptr_ch - *lineptr;
                }
 
                if (ptr_ch + 2 >= max_ptr_ch) {
                        max_buf_size = 2 * buf_size;
                        ssize_t delta = ptr_ch - *lineptr;
                        char *new_lineptr = NULL;

                        if ((new_lineptr = (char *) realloc(*lineptr, (max_buf_size * sizeof(char)))) == NULL)
                                return -1;

                        buf_size = max_buf_size;
                        *lineptr = new_lineptr;
                        ptr_ch = new_lineptr + delta;
                        max_ptr_ch = new_lineptr + max_buf_size;
                }
        }

        // Unreachable.
}
