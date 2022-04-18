#include <stdio.h>
#include <stdlib.h>

typedef struct cellule {
    int el;
    struct cellule * next;
} cellule;

typedef cellule * PILE;

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

PILE depilerkelt(PILE p, int k) {
    int e;
    for(int i=0;i<k;i++) {
        p = depiler(p,&e);
    }

    return p;
}

int pileVide(PILE p) {
    if(p == NULL) return 1;
    return 0;
}

void affiche(PILE p) {
    PILE pt = p;
    while(!pileVide(pt)) {
        printf("%d\n",pt->el);
        pt = pt->next;
    }
}

PILE depilerJusqua(PILE p, int element) {
    int e;

    while(!pileVide(p) && p->el != element) {
        p = depiler(p,&e);
    }

    return p;
}

void main() {
    PILE p;
    p=(PILE)malloc(sizeof(cellule));
    p = init();
    p = empiler(p,1);
    p = empiler(p,2);
    p = empiler(p,3);
    p = empiler(p,4);
    p = empiler(p,5);
    //dépiler k éléments si la pile contient au moins k éléments, sinon elle dépile toute la pile.
    p = depilerkelt(p,2);

    //dépiler jusqu’à l’élément elt. L’élément elt n’est pas dépilé. Si l’élément n’appartient pas à la pile, alors on dépile toute la pile.
    p = depilerJusqua(p,3);
    
    affiche(p);
    
    
}