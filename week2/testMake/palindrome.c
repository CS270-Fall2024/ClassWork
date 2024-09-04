/**
 * @file palindrome.c
 * Palindrome module implementation file.
 * @author Glass and Ables
 * @date   September 3, 2020
 */
#include "palindrome.h"

/**
 * Determines if str is a palindrome or not by
 * returning 0 for false and 1 for true.
 *
 * @param str a pointer to the source string
 */
int palindrome(const char *str)
{
    char reversedStr[100];
    reverse(str, reversedStr);              // Reverse original
    return (strcmp(str, reversedStr) == 0); // Compare the two
}
