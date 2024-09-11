/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief Reverce the files of input file
 *          If -c flag is present, reverse character in file as well
 * @date 2024-09-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define SIZE 4096

void reverseLine(char * str);

int main(int argc, char ** argv)
{
    int fd;
    int c = 0;
    if (argc >3 || argc < 2){
        printf("WRONG USE: %s [-c] <file>\n", argv[0]);
        exit(1);
    } 

    if (argc == 3 && strcmp(argv[1], "-c")==0){
        c = 1;
        fd = open(argv[2], O_RDONLY);   
    }else{
        fd = open(argv[1], O_RDONLY);   
    }

    if (fd ==-1){
        perror("Opening file");
        exit(1);
    }
    //read file. Assume file fit in the buffer FIX LATER
    char buffer[SIZE];
    int numOFBytes = read(fd, buffer, SIZE-1);
    if (numOFBytes == -1){
        perror("Reading file");
        exit(1);
    }
    //add '\n' at the end of buffer if it does not have it
    if (buffer[numOFBytes-1]!='\n'){
        buffer[numOFBytes] = '\n';
        numOFBytes++;
    }
    
    int start = numOFBytes-1;
    int end = start;
    char line[256];//assume line is less then 255 characters long
    for (int i = numOFBytes-2; i>-2; i--){
        if (i != -1 && buffer[i]!='\n'){
            start--;
        }else{
            strncpy(line, buffer+start, end-start+1);
            //printf("%s\n", line);
            if (c==1){
                reverseLine(line);
            }
            //write with '\n'
            if (write(1, line, end-start+1)==-1){
                perror("Writing to consol");
                exit(1);
            }
            end = i;
            start = end;
        }
    }

}

/**
 * @brief reverce each character in the string
 * 
 * @param str String with new line at the end
 */
void reverseLine(char * str){
    int i=0, 
        j = strlen(str)-2;
    while (i<j){
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}