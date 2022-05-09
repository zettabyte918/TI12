#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main() {
pid_t pid1,pid2;
	pid1 = fork();
	if(pid1 = 0) {
		for(int i=1;i<=100;i++) {
		printf("fils 1 %d\n",i);	
		}
	}

	pid2 = fork();
	if(pid2 == 0) {
		for(int i=101;i<=200;i++) {
			printf("fils 2 %d\n",i);
		}
	}
}
