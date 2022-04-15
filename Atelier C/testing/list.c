#include <stdio.h>
#include <stdlib.h>

typedef struct cellule {
    int val;
    struct cellule * next;
} cellule;

typedef cellule * LIST;

void main() {
    LIST l,q,p;
    l=(LIST)malloc(sizeof(cellule));
    q=(LIST)malloc(sizeof(cellule));
    q->val = 5;
    q->next = NULL;
    l = q;
    p = l;
    
    printf("%d",l->val);
}