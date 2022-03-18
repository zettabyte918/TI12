#include <stdio.h>
#include <stdlib.h>

void remplir(int **m, int l, int c) {
      int i,j;
    

    for(i=0;i<l;i++) {
        for(j=0;j<c;j++) {
            printf("entre entier [%d,%d]",i,j);
            scanf("%d",&m[i][j]);
        }
    }
}

void affiche(int **m, int l, int c) {
      int i,j;
    

    for(i=0;i<l;i++) {
        for(j=0;j<c;j++) {
            printf("[%d,%d]=%d \n",i,j,*(*(m+i)+j));
        }
    }
}


void main(){
    int **m;
    int l,c;
    int i;
    

    printf("entre ligne: ");
    scanf("%d",&l);
    printf("entre colonne: ");
    scanf("%d",&c);
    m=(int**)malloc(l*sizeof(int*));

    for(i=0;i<l;i++){
        m[i] = (int*)malloc(c*sizeof(int));
    }
    remplir(m,l,c);
    affiche(m,l,c);

    printf("%d",**m);

}