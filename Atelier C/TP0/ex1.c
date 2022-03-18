#include <stdio.h>
#include <math.h>

typedef struct POINT {
    int x;
    int y;
} POINT;

POINT saisir() {
    POINT p;
    printf("x=");
    scanf("%d",&p.x);
    printf("y=");
    scanf("%d",&p.y);
    return p;
}

POINT translation(POINT p1,int dx, int dy) {
    POINT p;
    p.x=p1.x + dx;
    p.y=p1.y + dy;
    return p;
}

void affiche(POINT p) {
    printf("\n x=%d \ny=%d \n",p.x,p.y);
}

void distance(POINT p1, POINT p2){
    float p;
    p=sqrt(pow(p2.x-p1.x,2)+pow(p2.y-p1.y,2));
    printf("dist=%lf \n",p);
}

POINT segment(POINT p1, POINT p2){
    POINT x;
    x.x = (p1.x + p2.x) / 2;
    x.y = (p1.y + p2.y) / 2;
    return x;
}

void main() {
    POINT p1;
    POINT p2;
    POINT p3;
    p1 = saisir();
    affiche(p1);
    p2 = translation(p1,2,3);
    affiche(p2);
    distance(p1,p2);
    p3 = segment(p1,p2);
    affiche(p3);
}