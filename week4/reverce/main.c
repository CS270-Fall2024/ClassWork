#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define SIZE 4096

int main()
{
    int fd;
    fd = open("test.txt", O_RDONLY);
    if (fd ==-1){
        perror("Opening file");
        exit(1);
    }
    printf("%d\n", fd);

    char buffer[SIZE];
    int numOFBytes = read(fd, buffer, SIZE);
    if (numOFBytes == -1){
        perror("Reading file");
        exit(1);
    }
    printf("numOFBytes = %d\n", numOFBytes);

    int start = numOFBytes-1;
    int end = start;
    char line[256];
    for (int i = numOFBytes-2; i>0; i--){
        if (buffer[i]!='\n'){
            start--;
        }else{
            strncpy(line, buffer+start, end-start);
            //printf("%s\n", line);
            if (write(1, buffer+start, start-end)==-1){
                perror("Writing to consol");
                exit(1);
            }
            end = start-1;
            start = end -1;
        }
    }
    start--;
    strncpy(line, buffer+start, end-start);
    printf("%s\n", line);

}