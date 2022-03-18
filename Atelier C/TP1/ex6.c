#include <stdio.h>



void remplir(int *t, int n) {
    int *p;
    for(p=t;p<t+n;p++) {
        printf("donner un element: ");
        scanf("%d",p);
    }
}

void calculSomme(int *somme, int *t, int n) {
    int *p;
    *somme=0;
    for(p=t;p<t+n;p++) {
        *somme=(*somme)+*p;
    }
}

int main() {
    int t[30];
    int n;
    int somme;

    printf("entre n: ");
    scanf("%d",&n);
    remplir(t,n);
    calculSomme(&somme,t,n);
    printf("somme=%d",somme);
    return 0;
}