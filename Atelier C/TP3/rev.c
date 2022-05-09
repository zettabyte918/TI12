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

int pileVide(PILE p) {
    if(p == NULL) return 1;
    return 0;
}

void affiche(PILE p) {
    int e;
    PILE pt = p;

    // declaration pile 2
    PILE p2;
    p2=(PILE)malloc(sizeof(cellule));

    // remplir pile 2
    while(!pileVide(pt)) {
        p2 = empiler(p2,pt->el);
        pt = pt->next;
    }

    // affiche pile 2
    while(!pileVide(p2)) {
        printf("%d \n",p2->el);
        p2 = p2->next;
    }
}

void main() {
    PILE p;
    p=(PILE)malloc(sizeof(cellule));
    // initialistaion pile 1
    p = init();
    // remplir pile 1
    p = empiler(p,1);
    p = empiler(p,2);
    p = empiler(p,3);
    p = empiler(p,4);
    p = empiler(p,5);
    
    affiche(p);
    
    
}