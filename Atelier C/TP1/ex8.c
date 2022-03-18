#include <stdio.h>
#include <string.h>

int palindrom(char *ch) {
    int l = strlen(ch);
    char *p=ch+l-1;
    char *q=ch;
    int test = 0;
    
    
            
        while(!test && q < ch+l/2) {
            printf("%c-%c\n",*q,*p);
            if(*p != *q) {
                test=1;
            } else {
                p--;
                q++;
            } 
        }
    return !test;
}

void main() {
    char *ch = "radar";

    printf("%s est: %s",ch,palindrom(ch) ? "palindrome" : "nest pas palaindrom");

}