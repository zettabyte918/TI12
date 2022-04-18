#include <stdio.h>
#include <stdlib.h>

typedef struct cellule {
    int el;
    struct cellule *next;
} cellule;

typedef cellule *PILE;

PILE init() {
    PILE p;
    p = NULL;
    return p;
}

PILE empiler(PILE p, int el) {
    PILE p1;
    PILE pt = p;
    p1 = (PILE)malloc(sizeof(cellule));
    p1->el = el;
    p1->next = p;
    pt = p1;
    return pt;
}

PILE depiler(PILE p, int * e) {
    PILE pt = p;
    PILE ptt = p;
    *e = p->el;
    pt = pt->next;
    free(ptt);
    return pt;
}

int pileVide(PILE p) {
    if(p == NULL) return 1;
    return 0;
}

void affiche(int * pt, int n) {
    for(int i=0;i<n;i++) {
        printf("%d \n",pt[i]);
    }
}

int * inverse(int * t, int n) {
    PILE p;
    int e;
    p=(PILE)malloc(sizeof(cellule));
    p = init();
    for(int i=0;i<n;i++) {
       p = empiler(p,t[i]); 
    }
    int i = 0;
    PILE pt = p;
    
    while(!pileVide(pt)) {
        t[i]=pt->el;
        i++;
        pt = pt->next;
    }

    return t;
}

void main() {
    int *pt;
    int n=5;
    int t[5]={10,20,30,40,50};

    pt = inverse(t,n);
    affiche(pt,n);
}
