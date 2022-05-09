#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t fils1;
    pid_t fils2;
    fils1 = fork();
    if(fils1 == -1) {
        printf("error fils 1");
        exit(-1);
    }
    
    
        printf("dans la fils1 de id %d \n",fils1);
        printf("dans la pere de fils1 de id %d \n",getppid());
    

    return 0;


}