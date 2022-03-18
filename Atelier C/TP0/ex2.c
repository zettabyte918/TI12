#include <stdio.h>

typedef struct RATIONNEL {
    int num;
    int dum;
} RATIONNEL;

RATIONNEL saisir() {
    RATIONNEL tmp;
    printf("entre num: ");
    scanf("%d",&tmp.num);
    do {
        printf("entre dum: ");
        scanf("%d",&tmp.dum);
    } while(tmp.dum == 0);
    return tmp;
}

int pgcd(int a, int b) {
    if (b != 0)
       return pgcd(b, a%b);
    else 
       return a;
}

RATIONNEL somme(RATIONNEL n1, RATIONNEL n2){
    RATIONNEL s;
    
}

void main(){
    RATIONNEL n1,n2,s;
    n1 = saisir();
    n2 = saisir();
    //s = somme(n1,n2);
    printf("%d",pgcd(6,3));
}