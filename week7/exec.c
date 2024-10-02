#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main()
{
    pid_t pid = fork();
    if (pid <0){
        perror("Creating fork");
    }else if (pid == 0){//child
        char * list[] ={"ls", "-l", NULL};
        execvp(list[0], list);
        printf("I am child and I am done with my work\n");
    }else{//parant
        wait(NULL);
        printf("Child is done\n");
    }
}