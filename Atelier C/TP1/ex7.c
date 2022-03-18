#include <stdio.h>

typedef struct PERSONNE {
    char nom[20];
    char prenom[20];
    int age;
} PERSONNE;

void remplir(PERSONNE *p) {
    printf("Nom: ");
    scanf("%s",p->nom);
    printf("Prenom: ");
    scanf("%s",p->prenom);
    printf("Age: ");
    scanf("%d",&p->age);
}

void affiche(PERSONNE p1, PERSONNE p2) {
    printf("le moins agee est: %s %s",
        p1.age > p2.age 
            ? p1.nom, p1.prenom
            : p1.nom, p1.prenom
    );
}

void main(){
    PERSONNE p1,p2;
    remplir(&p1);
    remplir(&p2);
    compare(p1,p2);
}