#include <stdio.h>
#include <stdlib.h>

struct article {
    int prix;
} article;

typedef struct arbre {
    struct article info;
    struct arbre * right;
    struct arbre * left;
} arbre, *Arbre;

Arbre initArbre() {
    return NULL;
}

Arbre creeNoeud(int prix) {
    Arbre a = malloc(sizeof(arbre));
    a->info.prix = prix;
    a->left = NULL;
    a->right = NULL;
    return a;
}


Arbre creeArbre(Arbre left, Arbre right, int prix) {
    Arbre a = creeNoeud(prix);
    a->left = left;
    a->right = right;
    return a;
}

void 

void main() {
    Arbre a1 = creeNoeud(5);
    Arbre a2 = creeNoeud(10);

    Arbre a = creeArbre(a1,a2,69);

    

    printf("%d\n",a->left->info.prix);
}
