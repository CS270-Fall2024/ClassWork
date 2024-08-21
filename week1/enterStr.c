#include <stdio.h>
#include <stdlib.h>
int main()
{
    int size;
    char * buffer;
    printf("Enter the size of input: ");
    scanf("%d", &size);
    buffer = malloc(sizeof(char)*(size+1));
    printf("Please, enter the string: ");
    getchar();//remove /n from the buffer
    fgets(buffer, size+1, stdin);
    printf("You entered: %s", buffer);
    free(buffer);
}