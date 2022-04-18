#include <stdio.h>
#include <stdlib.h>

typedef struct cellule {
    int el;
    struct cellule *next;
} cell;

typedef cell *PILE;

PILE depiler(PILE p, int * e) {
    PILE pt = p;
    PILE ptt = p;
    *e = p->el;
    pt = pt->next;
    free(ptt);
    return pt;
}

PILE init() {
    PILE p;
    p = NULL;
    return p;
}

int pileVide(PILE p) {
    if(p == NULL) return 1;
    return 0;
}

int calp(PILE p, int * x) {
    if(pileVide(p))
        return x;
    calp(p,*x+depiler(p,x));
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

void main() {
    PILE p;
    int e = 0;
    p=(PILE)malloc(sizeof(cell));
    p = init();
    p = empiler(p,5);
    p = empiler(p,5);
    p = empiler(p,5);
    p = empiler(p,5);
    printf("%d",calp(p,&e));
}