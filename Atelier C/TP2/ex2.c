#include <stdio.h>
#include <stdlib.h>

typedef struct Valeur {
    int val,c;
} Valeur;

typedef struct cellule2 {
    Valeur el;
    struct cellule2 *next;
    struct cellule2 *previous;
} cell2;

typedef cell2 *Liste2;


void remplirM(int **m, int l, int c) {
    int i,j;

    for(i=0;i<l;i++) {
        for(j=0;j<c;j++) {
            printf("entre entier [%d,%d]",i,j);
            scanf("%d",&m[i][j]);
        }
    }
}

Liste2 * remplirT(Liste2 *t,int **m, int l, int c){
    int i,j;
    Liste2 pt,l2,q,p;
    int b = 0;
    
    
    for(i=0;i<l;i++) {
        q=(Liste2)malloc(sizeof(cell2));
        q->el.val = 0;
        q->el.c = j;
        q->next = NULL;
        q->previous = NULL;
        l2=q;
        p=l2;
    
        for(j=0;j<c;j++) {
            if(m[i][j] != 0) {
                q=(Liste2)malloc(sizeof(cell2));
                q->el.val = m[i][j];
                q->el.c = j;
                q->next = NULL;
                q->previous = p;
                p->next = q;
                p = p->next;
            }
        }
        t[i] = l2;
    }
    return t;
}

void afficheListe(Liste2 *t, int l) {
    Liste2 pt;
    int i;
    for(i = 0;i<l;i++) {
        printf("liste de la case du tableau %d \n",i);
        pt = t[i];

        pt = pt->next; // pour ignorer l'entête
        while(pt!=NULL) {

        printf("%d \n",pt->el.val);
            pt = pt->next;
        }
    }
}

void main() {
    Liste2 l2;
    Liste2 pt;
    int **m;
    Liste2 *t;
    int l,c;
    int i;

    printf("entre ligne: ");
    scanf("%d",&l);
    printf("entre colonne: ");
    scanf("%d",&c);

    m=(int**)malloc(l*sizeof(int*));
    t=(Liste2*)malloc(l*sizeof(Liste2));


    for(i=0;i<l;i++){
        m[i] = (int*)malloc(c*sizeof(int));
    }

    remplirM(m,l,c);
    t=remplirT(t,m,l,c);
    
    afficheListe(t,l);
    
}