/**
 * @file main2.c
 *
 * Check if a string is a palindrome.
 *
 * @author Glass and Ables
 * @date   September 3, 2020
 */
#include <stdio.h>
#include "palindrome.h"

int main(int argc, char *argv[]) 
{ 
    printf("palindrome (\"cat\") = %d\n", palindrome("cat"));
    printf("palindrome (\"noon\") = %d\n", palindrome("noon"));
    return 0; 
}
