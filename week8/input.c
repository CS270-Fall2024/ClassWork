#include <stdio.h>

int main()
{
    char name[20];
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your age: ");
    int age;
    scanf("%d", &age);
    printf("Hello %s, you are %d years old\n",name, age);
}