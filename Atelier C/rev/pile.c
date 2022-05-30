#include <stdio.h>
#include<stdlib.h>
typedef struct cellule{
    int val;
    struct cellule *suivant;
}cellule;
typedef struct cellule *pile;

void creer_pile(pile *p){
    *p=malloc(sizeof(cellule));
*p=NULL;
}
int vide_pile(pile p){
    if (p==NULL)
    return 1;
    else return 0;
}
int sommet_pile(pile p){
    return p->val;
}
void empiler_pile(pile *p,int x){
    pile l;
    l=malloc(sizeof(cellule));
    l->suivant=*p;
    l->val=x;
    *p=l;
}
void depiler_pile(pile p){
    pile l;
    l=p;
    p=p->suivant;
    free(l);
}
void afficher_pile(pile *p){
    pile pl;
    int x;
    pile pt=*p;
    creer_pile(&pl);
    while(!vide_pile(pt)){
        x=sommet_pile(pt);
        empiler_pile(&pl,x);
        printf("%d",x);
        depiler_pile(pt);
    }

}
void afficher_pile_Rev(pile p){
    pile pt=p;
    int x;
    while(!vide_pile(pt)){
        x=sommet_pile(pt);
        printf("%d",x);
        depiler_pile(pt);
    }
}
void ranger_pair_impair(pile *p){
    pile pt,pPair,pImpair;
    creer_pile(&pPair);
    creer_pile(&pImpair);
    pt=*p;
    while(!vide_pile(pt)){
        if (sommet_pile(pt)%2==0){
            empiler_pile(&pPair,sommet_pile(pt));
        }
        else {
            empiler_pile(&pImpair,sommet_pile(pt));
        }
        depiler_pile(pt);
    }
}
void main(){
    pile p;
    int x,s,i;
    creer_pile(&p);
    printf("entrer LE NOMBRE DESIRÉ ");
    scanf("%d",&x);
    for (i=0;i<=x;i++){
        printf("donner la valeur");
        scanf("%d",&s);
        empiler_pile(&p,s);
    }
    afficher_pile_Rev(p);
    afficher_pile(&p);
    ranger_pair_impair(&p);
}