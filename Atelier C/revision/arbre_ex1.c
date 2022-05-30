#include <stdio.h>
#include <stdlib.h>

typedef struct arbre {
    int value;
    struct arbre *g;
    struct arbre *d;
} arbre, *Arbre,

Arbre init() {
    Arbre a;
    a = NULL;
    return a;
}


//somme arbre
int somme(Arbre a) {
    if(!a) {
        return 0;
    } else {
        return (a->value + somme(a->g) + somme(a->d));
    }
}

//convert array to arbre
Arbre ajout(int x) {
    Arbre a;

    a = malloc(sizeof(arbre));
    a->value = x;
    a->g = a->d = NULL;

    return a;
}

Arbre convertListToArbre(int arr[], int i, int n) {
    arbre a;
    if(i<n) {
        a = ajout(arr[i]);
        a->g = convertListToArbre(arr,2*i+1,n);
        a->d = convertListToArbre(arr,2*i+1,n);
    }

    return a;

}

void convert(int arr[], int i, int n) {
    Arbre a;
    a = init();
    a = convertListToArbre(arr,i,n);
}




void main() {
    Arbre a;
    a=init();
}