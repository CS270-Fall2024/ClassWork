#include <stdio.h>
int main(){
    char *cptr;
    char buffer[5];
    char test;

    printf("Enter some stuff:\n");
    cptr = fgets(buffer, 5, stdin);
    if(cptr != NULL)
    {
        printf("You typed: %s\n", cptr);
    }
    int t = scanf("%c", &test);
    if(t != 0)
    {
        printf("You typed: %c\n", test);
    }    
}

