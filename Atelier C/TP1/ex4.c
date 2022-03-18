#include <stdio.h>

int strlen2(char *s) {
    int len = 0; 
    while(*s != '\0') {
        len++;
        *s++;
    }
    return len;
}

int main() {
    char *s = "Hossem";
    printf("longeur de %s est %d \n",s,strlen2(s));
    return 0;
}