#include <stdio.h>
#include <stdlib.h>
typedef struct liste {
int info ;
struct liste *suiv;
}liste;

typedef liste *LISTE;

LISTE copy(int t[], int n){
    LISTE p,q,l;
    int *pt;
    if(!n) return NULL;
    else {
        q=malloc(sizeof(liste));
        pt=t;
        q->info = *pt;
        q->suiv = NULL;
        l=q;
        p=l;
        for(pt=t+1;pt<t+n;pt++){
            q=malloc(sizeof(liste));
            q->info = *pt;
            q->suiv = NULL;
            p->suiv = q;
            p = p->suiv;
        }
    }
return l;
}

int longeur(LISTE l){
    LISTE p;
    p=l;
    int i=0;
    while(p!=NULL){
        i++;
        p=p->suiv;
    }return i;
}
int recherche(LISTE l,int x){
    LISTE p;
    p=l;
    
    while(p!=NULL){
        if(p->info==x) {
            break;
        }
        p=p->suiv;
    }
    if (p->info==x)
    return 1;
    else return 0;
}
void minMAX(LISTE l){
    int min=l->info;
    int max=l->info;
    LISTE p=l;
    p=p->suiv;
    while (p!=NULL){
       if (p->info<min){
           min=p->info;
       } 
       if (p->info>max){
           max=p->info;
       }
    }
    printf("max= %d\n",max);
    printf("min= %d\n",min);
}

int main()
{
    int t[10] = {1,5,6,7,9};
    LISTE L;
    L=malloc(sizeof(liste));
    L=copy(t,5);
    printf("%d",recherche(L,10));
    
    return(0);
}