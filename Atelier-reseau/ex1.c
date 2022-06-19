#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/wait.h>

void main(int argc, char **argv) {
    pid_t pid;
    for(int i=0;i<atoi(argv[1]);i++) {
        pid = fork();
        if(pid == 0) {
            printf("je suis le fils %d et mon pid = %d \n",i,getpid());
            exit(0);
        }
        wait(0);
    }
}