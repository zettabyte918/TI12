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

PILE empiler(PILE p, int el) {
    PILE p1;
    PILE pt = p;
    p1 = (PILE)malloc(sizeof(cell));
    p1->el = el;
    p1->next = p;
    pt = p1;
    return pt;
}

int pileVide(PILE p) {
    if(p == NULL) return 1;
    return 0;
}

int * inverse(PILE p, int t[],int n){
    t[0]=55;
    printf("%d",t[0]);
    return t;
}

void main() {
    PILE p;
    int t[10];
    int n = 9;
    int e;
    p=(PILE)malloc(sizeof(cell));
    p = init();
    t=inverse(p,t,n);
    
    
}
