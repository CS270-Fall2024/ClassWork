#include <stdio.h>
int main()
{
    char name[] ="Ekaterina Miller";
    double gps = 3.754321;
    printf("name: %10.4s\n", name+10);
    printf("gps: %-10.2f end\n", gps);
}