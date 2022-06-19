#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void main(int argc, char **argv) {
    int tube[2];
    char ch[50];
    char cht[50];
    pipe(tube);
    pid_t pid1,pid2;

    pid1 = fork();
    if(pid1 == 0) {
        for(int i=0;i<strlen(argv[1]);i++) {
            ch[i] = argv[]
        }
        write(tube[1],ch,strlen(ch));
        close(tube[1]);
    }

    wait(0);
    pid2 = fork()
    if(pid2 == 0) {
        read(tube[0],cht,strlen(ch));
        if(strcmp(cht,argv[1]) == 0) {
            printf("chaine est palindrome");
        } else {
            printf("chaine ne pas est palindrome");
            
        }
    }
}
