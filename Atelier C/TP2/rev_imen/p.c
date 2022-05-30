#include <stdio.h>
#include <stdlib.h>

typedef struct pile {
    int info;
    struct pile *suiv;
} pile;

typedef pile * PILE;

PILE init() {
    PILE p;
    p = NULL;
    return p;
}

int pileVide(PILE p) {
    if(p == NULL) {
        return 1;
    } else {
        return 0;
    }
}

int sommet(PILE p) {
    return p->info;
}

PILE enpiler(PILE p, int e) {
    PILE p2;
    PILE pt = p;

    p2 = malloc(sizeof(pile));
    p2->info = e;
    p2->suiv = p;

    pt = p2;

    return pt;
}

PILE depiler(PILE p, int *e) {
     PILE pt = p;
    PILE ptt = p;
    *e = p->info;
    pt = pt->suiv;
    free(ptt);
    return pt;
}

void affiche(PILE p) {
    PILE pt;
    while(pt!=NULL) {
        printf("%d \n",pt->info);
        pt = pt->suiv;
    }
}

void main() {
    PILE p;
    int e;
    p = init();
    p = enpiler(p,5);
    p = enpiler(p,6);
    p = enpiler(p,7);
    p = enpiler(p,7);
    p = enpiler(p,7);
    p = enpiler(p,8);

    p = depiler(p,&e);

    affiche(p);    
}