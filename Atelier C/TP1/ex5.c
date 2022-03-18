#include <stdio.h>
#include <string.h>

void occur(char *ch, char c) {
    char *p = strchr(ch,c);
    printf("%s",p);
}

int main() {
    char ch[20];
    char c;
    printf("entre une chaine: ");
    scanf("%s",ch);
    printf("entre une caractere: ");
    scanf(" %c",&c);
    occur(ch,c);

    return 0;
}