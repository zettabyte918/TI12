#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void main() {
    char ch[6];
    int tube[2];

    pipe(tube);

    write(tube[1],"i",1);
    write(tube[1],"s",1);
    write(tube[1],"e",1);
    write(tube[1],"t",1);
    write(tube[1],"n",1);
    close(tube[1]);

    read(tube[0],ch,5);

    printf("%s \n",ch);
}