#include <stdio.h>
#include <stdlib.h>

struct Element {
    int val;
    struct Element *next;
};

typedef struct Element Liste;

void affiche(Liste *l){
while(l!=NULL){
     printf("%d \n",l->val);
    l=l->next;
   
    
}


}

void main(){
    Liste *l;
    Liste *p;
    Liste *m;
    Liste *elem;
    l=(Liste*)malloc(sizeof(Liste));
    p=(Liste*)malloc(sizeof(Liste));
    m=(Liste*)malloc(sizeof(Liste));
    elem=(Liste*)malloc(sizeof(Liste));
    l->val = 45;
    p->val = 12;
    m->val = 6;
    elem->val = 8;

    l->next = p;
    p->next = m;
elem->next=p->next;
p->next=elem;
    
    
    affiche(l);
}