#include <stdio.h>
#include <stdlib.h>

typedef struct cellule {
    int el;
    struct cellule *next;
} cell;

typedef cell *file;



file init() {
    file p;
    p = NULL;
    return p;
}

int fileVide(file p) {
    if(p == NULL) return 1;
    return 0;
}

file defiler(file p, int * e) {
    file pt = p;
    file ptt = p;
    *e = p->el;
    pt = pt->next;
    free(ptt);
    return pt;
}

file enfiler(file p, int x) {
    file pt,pp;

    pp = p;
    pt = (file)malloc(sizeof(cell));
    pt->el = x;
    pt->next = NULL;

    if(fileVide(p)) {
        p = pt;
    } else {
        while(pp->next != NULL) {
            pp = pp->next;
        }
        pp->next = pt;
    }
return p;
}

void affiche(file p) {
    file pt = p;
    while(!fileVide(pt)) {
        printf("%d\n",pt->el);
        pt = pt->next;
    }
}


void main() {
    file p;
    int e;

    p = init();


    p = enfiler(p,5);
    p = enfiler(p,6);
    p = enfiler(p,7);
    p = enfiler(p,8);

    // p = defiler(p,&e);

    affiche(p);
}