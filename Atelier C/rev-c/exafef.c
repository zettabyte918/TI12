#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//1
typedef struct Article
{
    char code[20];
    float prix;
    int qt;
} Article;
//2
typedef struct Cellule
{
    Article info;
    struct Cellule* suivant;
}Cellule, *Liste;
//3
Liste Ajouttete(Liste L,Article e)
{
    Liste Pn=malloc(sizeof(struct Cellule));
    Pn->info=e;
    Pn->suivant=L;
    L=Pn;
    return L;
}
//4
void commande(Liste L)
{
    Liste P=L;
    while(P!=NULL)
    {
        if(P->info.qt<10)
            printf("%s %f %d||",P->info.code,P->info.prix,P->info.qt);
        P=P->suivant;
    }
}
void afficher(Liste L)
{
    Liste P=L;
    printf("\n");
    while(P!=NULL)
    {
        printf("%s %f %d||",P->info.code,P->info.prix,P->info.qt);
        P=P->suivant;
    }
}
//5
struct Noeud
{
    Article info;
    struct Noeud *gauche;
    struct Noeud *droite;
};
typedef struct Noeud* Arbre;
//6
Arbre CreerNoeud()
{
    Arbre N;
    N=(Arbre)malloc(sizeof(struct Noeud));
    printf("\ndonner la valeur du Noued: ");
    scanf("%s",N->info.code);
    scanf("%f",&N->info.prix);
    scanf("%d",&N->info.qt);
    N->gauche=NULL;
    N->droite=NULL;
    return N;
}
Arbre CreerArbre(Arbre A)
{
    int rep;
    A=CreerNoeud();
    printf("Voulez créer un fils gauche de %s 0/1",A->info.code);
    scanf("%d",&rep);
    if(rep==1)
        A->gauche=CreerArbre(A->gauche);
    printf("Voulez créer un fils droite de %s 0/1",A->info.code);
    scanf("%d",&rep);
    if(rep==1)
        A->droite=CreerArbre(A->droite);
    return A;
}
//7
void pluscher(Arbre A,Article* max)
{
    if(A!=NULL)
    {
        if(A->info.prix>max->prix)
        {
            *max=A->info;
        }
        pluscher(A->gauche,max);
        pluscher(A->droite,max);
    }
}
//8
void articlecommandarbre(Arbre A)
{
    if(A!=NULL)
    {
        if(A->info.qt<10)
            printf("%s %f %d ||",A->info.code,A->info.prix,A->info.qt);
        articlecommandarbre(A->gauche);
        articlecommandarbre(A->droite);
    }
}
//9
void parcoursprefixe(Arbre A)
{
    if(A!=NULL)
    {
        printf("%s %f %d ||",A->info.code,A->info.prix,A->info.qt);
        parcoursprefixe(A->gauche); // infix
        parcoursprefixe(A->droite); // post fix
    }
}
//10
typedef struct Cellule* file;
//11
file enfiler(file f, Article e)
{
    file P=f;
    file Pn=malloc(sizeof(struct Cellule));
    Pn->info=e;
    Pn->suivant=NULL;
    if(f==NULL)
        f=Pn;
    else
    {
        while(P->suivant!=NULL)
        {
            P=P->suivant;
        }
        P->suivant=Pn;
    }
    return f;
}
file plus20(Arbre A,file f)
{
    if(A!=NULL)
    {
        if(A->info.prix>20)
            f=enfiler(f,A->info);
        f=plus20(A->gauche,f);
        f=plus20(A->droite,f);
    }
    return f;
}
void main()
{
    Article e1,e2,e3,e4,e5,e6;
    strcpy(e1.code,"123456");
    e1.prix=10.2;
    e1.qt=11;
    strcpy(e2.code,"1111");
    e2.prix=20;
    e2.qt=15;
    strcpy(e3.code,"15789");
    e3.prix=25.22;
    e3.qt=22;
    strcpy(e4.code,"452");
    e4.prix=10.2;
    e4.qt=0;
    strcpy(e5.code,"44444");
    e5.prix=3;
    e5.qt=3;
    strcpy(e6.code,"457");
    e6.prix=5;
    e6.qt=2;
    Liste L=NULL;
    L=Ajouttete(L,e1);
    L=Ajouttete(L,e2);
    L=Ajouttete(L,e3);
    L=Ajouttete(L,e4);
    L=Ajouttete(L,e5);
    L=Ajouttete(L,e6);
    afficher(L);
    Arbre A=NULL;
    A=CreerArbre(A);
    parcoursprefixe(A);
    Article max;
    pluscher(A,&max);
    printf("\nl'article le plus chere est %s %f",max.code,max.prix);
    file f=NULL;
    f=plus20(A,f);
    afficher(f);
}