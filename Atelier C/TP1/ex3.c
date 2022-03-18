#include <stdio.h>

void scase(char *ch1, char *ch2) {
    //printf("%d", *ch1 - 32 < 70);
    while(*ch1 != '\0') {
        if((int) *ch1 >= 64 && (int) *ch1 <= 96) {
            *ch2 = *ch1+32;
            *ch2++;
        } else if((int) *ch1 >= 97 && (int) *ch1 <= 129) {
            *ch2 = *ch1-32;
            *ch2++;
        }
        *ch1++;
        *ch2='\0';
    }
}

int main() {
    char ch1[] = "abcdefghijKLMnopqrstuvwxyz";
    char ch2[30];
    scase(ch1, ch2);
    printf("ch1 = %s , ch2= %s \n", ch1, ch2);
    return 0;
}