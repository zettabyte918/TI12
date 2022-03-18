#include <stdio.h>

void afficher( char *p) {
    int i=0;

    while (*p  != '\0') {
        if(*p != ' ') {
            printf("%c",*p);
        }
        *p++;
    }
}

int main() {
char *chaine = "bonjour TP 1 : Les pointeurs les amis";

    afficher(chaine);
    return 0;
}