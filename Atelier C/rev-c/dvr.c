#include <stdio.h>
#include <stdlib.h>

typedef struct med {
    char nom[20];
    int qt;
    int prix;
    struct med * suiv;
} med;

typedef med * ListStock;

typedef struct arbre {
    med info;
    struct arbre *droite;
    struct arbre *gauche;
} arbre;

typedef arbre * Arbre;

Arbre creer()
{
    Arbre N;
    N=malloc(sizeof(arbre));
    printf("\ndonner la valeur du Noued: ");
    scanf("%s",N->info.code);
    scanf("%f",&N->info.prix);
    scanf("%d",&N->info.qt);
    N->gauche=NULL;
    N->droite=NULL;
    return N;
}

void parcoursinfix(Arbre A)
{
    if(A!=NULL)
    {
        parcoursprefixe(A->gauche); // pre
        printf("%s %f %d ||",A->info.code,A->info.prix,A->info.qt);
        parcoursprefixe(A->droite); // post fix
    }
}

float prixStock(Arbre A)
{
    if(A==NULL) {
        return NULL;
    } else {
        return a->prix + prixStock(a->gauche) + prixStock(a->droite);
    }
}

med nouveauMedicament(char nom[],int qt, int prix) {
    med a = malloc(sizeof(med));
    
    printf("nom: ");
    scanf("%s",a.nom);

    printf("prix: ");
    scanf("%d",&a.nom);

    printf("nom: ");
    scanf("%d",&a.nom);
    a.suiv = NULL;
    return a;

}

ListStock ajoutTeteStock(ListStock l, med a, ) {
    ListStock pt = l;
    if(l == NULL) {
        l=med;
    } else {
        med.suiv = l;
        l = med;
    }

    return l;
}

ListStock vendre(ListStock l, char lib[], int NbBoites) {

}

float prixStock(ListStock l) {
    ListStock pt = l;
    float sum = 0;
    while(pt!=NULL) {
        sum +=pt->prix;
        pt = pt->suiv;
    }
    return sum;
}



void main() {

}



