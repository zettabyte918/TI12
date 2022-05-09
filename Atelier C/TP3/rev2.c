#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cellule Cellule;

struct Cellule{
    int val;
    struct Cellule* suivant;
};
typedef struct Cellule *pile;

void creer_pile(pile *P){
    P=NULL;
}

int vide_pile(pile P){
    if(P == NULL){
        return 1;
    }else{
        return 0;
    }
}

int sommet_pile(pile P){
    return P->val;
}

void empiler_pile(pile *P,int x){
    pile C;
    C=malloc(sizeof(struct Cellule));
    C->val=x;
    C->suivant=(*P);
    (*P)=C;
}

void depiler_pile(pile *P){
    pile C;
    C = *P;
    *P= (*P)->suivant;
    free(C);
}



void afficheReverse(pile p) {
    pile pt = p;
    pile p2;

    p2=malloc(sizeof(Cellule));
    creer_pile(&p2);
    
    while(pt->suivant !=NULL) {
        empiler_pile(&p2,pt->val);
        pt=pt->suivant;
    }

    while(p2->suivant !=NULL) {
        printf("%d\n",p2->val);
        p2=p2->suivant;
    }
}

void saisirPile(pile *p){
    int rep = 1;
    int val = 0;
    while(rep) {
        printf("entre un nombre: ");
        scanf("%d",&val);
        empiler_pile(p,val);
        printf("continue 1:oui 0:non ? ");
        scanf("%d",&rep);
    }
}

void ranger(pile *p) {
    pile pPair,pImpaire;
    pile pt;

    pPair=malloc(sizeof(Cellule));
    pImpaire=malloc(sizeof(Cellule));
    creer_pile(&pPair);
    creer_pile(&pImpaire);
    
    pt = *p;
    while(pt->suivant != NULL) {
        if(pt->val % 2 == 0) {
            empiler_pile(&pPair,pt->val);
        } else {
            empiler_pile(&pImpaire,pt->val);
        }
        pt = pt->suivant;
    }

    while((*p) != NULL) {
        depiler_pile(p);
        (*p) = (*p)->suivant;
    }

    
    // add pair to pile 1
    pt = pPair;
    while(pt->suivant != NULL) {
        empiler_pile(p,pt->val);
        printf("pair:%d \n",pt->val);
        pt = pt->suivant;
    }

    //add impaire to pile 1
    pt = pImpaire;
    while(pt->suivant != NULL) {
        empiler_pile(p,pt->val);
        printf("imapaire:%d \n",pt->val);
        pt = pt->suivant;
    }
}

void affiche(pile p) {
    pile pt = p;
    while(pt->suivant !=NULL){
        printf("%d\n",pt->val);
        pt = pt->suivant;
    }
}

void main(){
    pile p,pt;
    p=malloc(sizeof(Cellule));
    creer_pile(&p);


    
    saisirPile(&p);
    affiche(p);
    afficheReverse(p);
    ranger(&p);
}