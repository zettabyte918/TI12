#include <stdio.h>
#include <stdlib.h>

typedef struct cellule {
    int el;
    struct cellule *next;
} cell;
typedef cell *Liste;


void remplir(int *t, int n){
    int i;
    for(i=0;i<n;i++) {
        printf("case %d:",i);
        scanf("%d",t);
        t++;
    }
}

void affiche(int *t,int n){
    int i;
    for(i=0;i<n;i++){
        printf("case%d = %d \n",i,*t);
        t++;
    }
}

Liste copy(int t[], int n){
    Liste p,q,l;
    int *pt;
    if(!n) return NULL;
    else {
        q=(Liste)malloc(sizeof(cell));
        pt=t;
        q->el = *pt;
        q->next = NULL;
        l=q;
        p=l;
        for(pt=t+1;pt<t+n;pt++){
            q=(Liste)malloc(sizeof(cell));
            q->el = *pt;
            q->next = NULL;
            p->next = q;
            p = p->next;
        }
    }
return l;
}

void affichListe(Liste l) {
    Liste pt = l;
    while(pt!=NULL) {
            printf("%d \n",pt->el);
            pt=pt->next;
        }
}

int somme(Liste l){
   Liste pt = l;
   int s=0;
    while(pt!=NULL) {
        s=s+(pt->el);
        pt=pt->next;
    }
return s;
}

int main(){
    int t[30];
    int n;
    Liste l;

    printf("entrer n: ");
    scanf("%d",&n);
    remplir(t,n);
    //affiche(t,n);
    l=copy(t,n);
    //affichListe(l);
    printf("somme=%d",somme(l));
    return 0;
}