#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main() {
    pid_t p1;
    pid_t p2;


    printf("je suis le grand pere %d\n",getpid());
    p1 = fork();

    if (p1 == 0) {
        printf("je suis le fils 1 est mon pid est %d\n",getpid());
        p2 = fork();
            if (p2 == 0) {
                printf("je suis le fils 2 est mon pid est %d \n",p2);
                printf("je suis le pere de la fils 1 est mon pid est %d \n",getpid());
                printf("je suis le grand pere de la fils 2 est mon pid est %d \n",getppid());
            } else {

            }
            
    }

    


}