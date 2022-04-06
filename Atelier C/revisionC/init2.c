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

Liste remplireListe(Liste *l,int n) {
    Liste *q=*l;
    q=(Liste*)malloc(sizeof(Liste));
    Liste *p;
    if(!n) return NULL;
    else if (n==1) {
        q->val=6;
        q->next=NULL;
        l=q;
        p=l;
    } else {
        for (int i=1;i<n;i++){
            q=(Liste*)malloc(sizeof(Liste));
            q->val=i;
            q->next=NULL;
            p->next = q;
            p = p->next;
        }
    }
    return l;
}

void main(){
    Liste *l;
    int n=6;
    l=remplireListe(l,n);
    
    
    affiche(l);
}