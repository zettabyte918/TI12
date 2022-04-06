#include <stdio.h>
#include <stdlib.h>

typedef struct cellule {
    int el;
    struct cellule *next;
} cell;

typedef struct cellule2 {
    int el;
    struct cellule2 *next;
    struct cellule2 *previous;
} cell2;


typedef cell *Liste;
typedef cell2 *Liste2;


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

int somme(Liste2 l){
   Liste2 pt = l;
   int s=0;
    while(pt!=NULL) {
        s=s+(pt->el);
        pt=pt->next;
    }
return s;
}

Liste2 paire(int *t, int n){
    Liste2 l2,pt2,q;
    int *pt;
    int i=0;
    int b=0;
    if(!n) return NULL;
    else {
        pt=t;
        while(!b) {
            if(*pt % 2 != 0) {
                b=1;
            } else {
                pt++;
            }
            i++;
        }
        q=(Liste2)malloc(sizeof(cell2));
        q->el = *pt;
        q->next = NULL;
        q->previous = NULL;
        l2=q;
        pt2=l2;
        printf("==%d \n",l2->el);
        for(pt=t+i;pt<t+n;pt++){
            if(*pt % 2 != 0) {
                q=(Liste2)malloc(sizeof(cell2));
                q->el = *pt;
                q->next = NULL;
                q->previous = pt2;
                pt2->next = q;
                pt2 = pt2->next;
            }
        }
    }
    return l2;
}

int main(){
    int t[30];
    int n;
    Liste l;
    Liste2 l2;

    printf("entrer n: ");
    scanf("%d",&n);
    remplir(t,n);
    //affiche(t,n);
    //l=copy(t,n);
    //affichListe(l);
    l2=paire(t,n);
    printf("somme=%d",somme(l2));
    return 0;
}