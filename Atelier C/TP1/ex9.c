#include <stdio.h>
#include <stdlib.h>

void remplir(int *tab, int *p,int n) {
    for(p=tab;p<tab+n;p++){
        printf("entre un entier");
        scanf("%d",p);
    }
}

void main(){
    int *tab,*p;
    int n;
    tab=(int*)malloc(n*sizeof(int));

    printf("entre n: ");
    scanf("%d",&n);
    remplir(tab,p,n);
    printf("%d",*tab++);
}