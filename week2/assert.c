#include <stdio.h>
//#define NDEBUG
#include <assert.h> 
#include <ctype.h>

/**
 * @brief Return the greatest common divisor of positive integers i and j.
 *
 * NOTE: Precondition of this function that i and j MUST be positive
 */
int gcd(int i, int j)
{
    assert(i > 0);
    assert(j > 0);
    printf("In gcd\n");
    //kjfdkjnv
    return 0;
}

int main() 
{ 
    gcd(1,3);
    gcd(1,-3);
    return 0;
}
