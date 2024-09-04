/**
 * @file reverse.c
 * Reverse module implementation file.
 * @author Glass and Ables
 * @date   September 3, 2020
 */
#include "reverse.h"

/**
 * Function reverse string from before to after
 *
 * @param before a pointer to the source string
 * @param after  a pointer to the reversed string
 */
void reverse(const char *before, char *after)
{
    int i, j, len;
    len = strlen(before);

    for (j = len - 1, i = 0; j >= 0; --j, ++i)
        after[i] = before[j];

    after[len] = '\0';  // terminate reversed string
}
