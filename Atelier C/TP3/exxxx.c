#include <stdio.h>
#include <string.h>

void main(void) {
    char vert = 'v';
    char v = 'v';
    if(strcmp(&vert,&v)==0) {
        printf("yesss");
    }
}