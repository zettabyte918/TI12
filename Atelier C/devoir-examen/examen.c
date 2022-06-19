#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1
typedef struct article {
    char lib[50];
    int qt;
    float prix;
} article;

typedef struct stock {
    article info;
    struct stock *suiv;
} stock;

typedef stock *ListeStock;

typedef struct arbre {
    article info;
    struct arbre *g;
    struct arbre *d;
} arbre;

typedef arbre *ArbreStock;


//2
article nouveauArticle() {
    article s;
    printf("lib: ");
    scanf("%s",s.lib);
    printf("prix: ");
    scanf("%f",&s.prix);
    printf("qt: ");
    scanf("%d",&s.qt);

    return s;
}

// 3
ListeStock ajoutTeteStock(ListeStock l, article a) {
    ListeStock pt = l;
    ListeStock art = malloc(sizeof(stock));
    art->info = a;
    art->suiv = NULL;

    if(l == NULL) {
        pt = art;
    } else {
        art->suiv = pt;
        pt = art;
    }
    return pt;
}

ListeStock vendre(ListeStock l, char lib[], int nbArt) {
    ListeStock pt = l;
    
    if(l == NULL) {
        return NULL;
    } else {
        while(strcmp(pt->info.lib,lib) != 0) {
            pt = pt->suiv;
        }

        if(strcmp(pt->info.lib,lib) == 0) {
            if(pt->info.qt <= nbArt) {
                printf("insuffisante par rapport au nombre demandé.");
            } else {
                pt->info.qt -= nbArt;
            }
        }
    }

    return l;

}

float prixStock(ListeStock l) {
    ListeStock pt = l;
    float sum;
    printf("%f",pt->info.prix);
    while(pt != NULL) {
        sum += pt->info.prix;
    }

    return sum;
}

ArbreStock insereArticle() {
    ArbreStock art;
    art=malloc(sizeof(arbre));

    printf("lib: ");
    scanf("%s",art->info.lib);
    printf("prix: ");
    scanf("%f",&art->info.prix);
    printf("qt: ");
    scanf("%d",&art->info.qt);

    art->g=NULL;
    art->d=NULL;

    return art;
}
ArbreStock creeArbreArticle(ArbreStock stock)
{
    char r[5];
    char oui[5] = "oui";
    char non[5] = "non";

    stock=insereArticle();

    printf("cree arbre gauche oui ou non: ");
    scanf("%s",r);
    if(strcmp(r,oui)==0) {
        stock->g=creeArbreArticle(stock->g);
    }

    printf("cree arbre droite oui ou non: ");
    scanf("%s",r);
    if(strcmp(r,oui)==0) {
        stock->d=creeArbreArticle(stock->d);
    }

    return stock;
}

void infixe(ArbreStock stock) {
    if(stock!=NULL) {
        infixe(stock->g);
            printf("%s|\n", stock->info.lib);
            printf("%f|\n", stock->info.prix);
            printf("%d|\n", stock->info.qt);
        infixe(stock->d);
    }
}

float prixStockArbre(ArbreStock stock) {
    if(stock==NULL) {
        return 0;
    } else {
        return stock->info.prix + prixStockArbre(stock->g) + prixStockArbre(stock->d);
    }
}


void main() {
    ArbreStock a = NULL;
    ListeStock l = NULL;

    printf("\n------- liste ------- \n");

    article l1 = nouveauArticle();
    article l2 = nouveauArticle();

    l = ajoutTeteStock(l,l1);
    l = ajoutTeteStock(l,l2);

    printf("le prix totale de la liste est: %f",prixStock(l));
    
    l = vendre(l,"pince",40); 

    printf("\n------- arbre ------- \n");

    a = creeArbreArticle(a);
    printf("le prix totale d'arbre est: %.2f",prixStockArbre(a));
    infixe(a);
}
