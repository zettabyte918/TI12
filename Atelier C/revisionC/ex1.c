#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
    int val;
    struct cell *next;
} cell;

typedef struct cell * Liste;

void remplir(int t[],int n){
    int i = 0;
    for(i=0;i<n;i++) {
        printf("entre la case %d: ",i);
        scanf("%d",&t[i]);
    }
}

Liste copier(int t[],int n) {
    Liste l,q,p;
    if(n==0) return NULL;
    else {
        q=(Liste)malloc(sizeof(Liste));
        q->val = t[0];
        q->next = NULL;
        l=q;
        p=l;
        for(int i=1;i<n;i++) {
            q=(Liste)malloc(sizeof(Liste));
            q->val = t[i];
            q->next = NULL;
            p->next = q;
            p = q;
        }
        

    }
}

void main() {
    Liste l;
    int t[30];
    int n=3;

    remplir(t,n);
    l=copier(t,n);
    

}
