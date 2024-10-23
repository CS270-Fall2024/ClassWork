#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>

int main()
{
    DIR * dirPtr=opendir(".");
    if (dirPtr ==NULL){
        perror("Open dir");
        exit (1);
    }
    struct dirent *entry;
    while((entry = readdir(dirPtr))!=NULL)
    {
        printf("%s\n", entry->d_name);
    }
    closedir(dirPtr);

}