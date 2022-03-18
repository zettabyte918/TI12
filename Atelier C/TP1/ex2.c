#include <stdio.h>

void calcul(int a, int b, int *somme, int *difference) {
    *somme = a+b;
    *difference = a-b;
}

int main() {
    int a=12, b=45; int somme, difference;
    calcul(a,b, &somme, &difference);
    printf("a+b=%d , a-b=%d\n", somme, difference);
    return 0;
}