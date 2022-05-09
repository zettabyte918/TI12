#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void main(int argc, char **argv) {
pid_t pid;	
	for(int i = 0; i<atoi(argv[1]) ; i++) {
		pid = fork();
		if(pid == 0) {
			printf("je suis le fils %d\n",getpid());
			exit(1);
		}
	}
}
