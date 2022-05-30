#include <stdio.h>
#include <stdlib.h>

typedef struct cellule {
    int el;
    struct cellule *next;
} cell;

typedef cell *file;

typedef struct {
    file t;
    file q;
} sfile;

sfile init() {
    sfile p;
    p.t = NULL;
    p.q = NULL;

    return p;
}

int fileVide(sfile p) {
    if(p.t == NULL) return 1;
    return 0;
}

sfile defiler(sfile p, int * e) {
    sfile f = p;
    file pt = p.t;
    file ptt = p.t;
    *e = p.t->el;
    pt = pt->next;
    free(ptt);

    f.t = pt;
    return f;
    
}

sfile enfiler(sfile p, int x) {
    file pt;


    pt = (file)malloc(sizeof(cell));
    pt->el = x;
    pt->next = NULL;

    if(fileVide(p)) {
        p.t = pt;
        p.q = pt;
    } else {
        p.q->next = pt;
        p.q = pt;
    }
    
return p;
}

void affiche(sfile p) {
    sfile pt = p;
    while(!fileVide(pt)) {
        printf("%d\n",pt.t->el);
        pt.t = pt.t->next;
    }
}


void main() {
    sfile p;
    int e;

    p = init();

    p = enfiler(p,5);


    p = defiler(p,&e);
    // p = defiler(p,&e);
    
   
    p = enfiler(p,155);

    p = defiler(p,&e);


  
        affiche(p);
    

}