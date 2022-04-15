#include <stdio.h>
#include <stdlib.h>

typedef struct cellule {
    int el;
    struct cellule *next;
} cell;

typedef cell *PILE;

PILE init() {
    PILE p;
    p = NULL;
    return p;
}

PILE empiler(PILE p, int el) {
    PILE p1;
    PILE pt = p;
    p1 = (PILE)malloc(sizeof(cell));
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

void affiche(PILE p) {
    PILE pt = p;
    while(!pileVide(pt)) {
        printf("%d\n",pt->el);
        pt = pt->next;
    }
}

void main() {
    PILE p;
    int e;
    p=(PILE)malloc(sizeof(cell));
    p = init();
    p = empiler(p,5);
    p = depiler(p,&e);
    affiche(p);
}
