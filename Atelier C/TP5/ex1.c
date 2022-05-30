#include <stdio.h>
#include <stdlib.h>


typedef struct noeud {
    int info;
    struct noeud * g;
    struct noeud * d;
} noeud;

typedef noeud * arbre;

typedef struct file {
    arbre value;
    struct file *next;
} file, *File;


arbre cree_arbre(int info, arbre a1, arbre a2) {
    arbre a;
    a = malloc(sizeof(noeud));
    a->info = info;
    a->g = a1;
    a->d = a2;
    return a;
}

arbre detruit_arbre(arbre a) {
    if(a) {
        a->d = detruit_arbre(a->d);
        a->g = detruit_arbre(a->g);
        free(a);
    }
    return NULL;
}

void prefixe(arbre a) { 
    if(a!=NULL) {
        printf("%d ", a->info);
        prefixe(a->g);
        prefixe(a->d);
    }
}

void infixe(arbre a) {
    if(a!=NULL) {
        prefixe(a->g);
        printf("%d ", a->info);
        prefixe(a->d);
    }
}

int infixeCompare(arbre a1, arbre a2) { 
    if(a1!=NULL && a2!=NULL && a1->info == a2->info) {
        infixeCompare(a1->g,a2->g);
        infixeCompare(a1->d,a2->d);
    } else if(a1->info != a2->info) {
        return 0;
    }
}

void postfixe(arbre a) { 
    if(a!=NULL) {
        printf("{");
        if(a->d == NULL && a->g == NULL) printf("-");
        postfixe(a->g);
            printf(",");
            printf("%d", a->info);
            printf(",");
        if(a->d == NULL && a->g == NULL) printf("-");

        postfixe(a->d);
        printf("}");
    }
}

int feuille(arbre a) {
    if((a->d==NULL) && (a->g==NULL)) {
        return 1;
    } else {
        return 0;
    }
}

int nombre_de_noeuds(arbre a) {
    if(a==NULL) {
        return 0;
    } else {
        return 1 + nombre_de_noeuds(a->g) + nombre_de_noeuds(a->d);
    }
}

int compare(arbre a1, arbre a2) {
    if(!a1) {
        if(a2) {
            return 1;
        } else {
            return 0;
        }
    } else if(a2) {
        return 1;
    } else if(a1->info != a2->info) {
        return 1;
    } else {
        return compare(a1->g,a2->g) && compare(a2->d,a2->d);
    }
}

int isEmpty(File f) {
    return !f;
}

int verifSousArbre(arbre a1, arbre a2) {
    if(a1 == NULL) {
        if(a2 == NULL) {
            return 1;
        } else return 0;
    } else {
        if(a2 == NULL)  {
            return 1;
        } else {
            if(compare(a1,a2)==1) {
                return 1;
            } else {
                return (verifSousArbre(a1->g,a2) || verifSousArbre(a1->d,a2));
            }
        }
    }
}

File x_enfiler(File f, arbre e) {
    File F,pt;

    F=malloc(sizeof(file));
    F->value = e;
    F->next = NULL;

    if(isEmpty(f)) {
        f=F;
    } else {
        pt = f;
        while(!isEmpty(pt->next)) {
            pt=pt->next;
        }
        pt->next = F;
    }

    return f;
}

File x_defiler(File f, arbre *e) {
    if(f) {
        File temp = f;
        *e=f->value;
        f=f->next;
        free(temp);
    }
    return f;
}

void largeur(arbre a) {
    File f = NULL;
    arbre p;
    if(a) {
        f = x_enfiler(f,a);
        while(f) {
            f = x_defiler(f,&p);
            printf("%d",f->value);
            if(p->g) {
                f = x_enfiler(f,p->g);
            }
            if(p->d) {
                f = x_enfiler(f,p->d);
            }
        }
    }
}

void main() {
    arbre a1,a2,a3,a4,a5;
    a1 = cree_arbre(8,NULL,NULL);
    a2 = cree_arbre(9,NULL,NULL);
    a3 = cree_arbre(6,NULL,NULL);
    a4 = cree_arbre(7,a1,a2);
    a5 = cree_arbre(5,a4,a3);
    // a4 = detruit_arbre(a2);
    prefixe(a5);
    printf("\n");
    infixe(a5);
    printf("\n");
    postfixe(a5);
    printf("\n");
    printf("\n %d",verifSousArbre(a4,a1));
    largeur(a5);

    // printf("%d",compare(a5,a5));
}