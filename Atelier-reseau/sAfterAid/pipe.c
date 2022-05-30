#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main() {
    char ch[6];
    int tube[2];
    pipe(tube); //create pipe

    // ecrire dans la pipe
    write(tube[1], "hossem",6);
    close(tube[1]);

    // lire la pipe
    read(tube[0],ch,6);

    // affiche pipe
    printf("%s\n",ch);
}