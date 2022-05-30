#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct file {
    char value;
    int x_value;
    struct file *next;
} file, *File;


File init() {
    File f;
    f = NULL;
    return f;
}

char sommet(File f) {
    return f->value;
}

int x_sommet(File f) {
    return f->x_value;
}

char sommetNext(File f) {
    return f->next->value;
}

int isEmpty(File f) {
    return !f;
}

int isEmptyNext(File f) {
    return !f->next;
}

File defiler(File f, char *e) {
    if(f) {
        File temp = f;
        *e=f->value;
        f=f->next;
        free(temp);
    }
    return f;
}

File x_defiler(File f, int *e) {
    if(f) {
        File temp = f;
        *e=f->x_value;
        f=f->next;
        free(temp);
    }
    return f;
}

File x_enfiler(File f, int e) {
    File F,pt;

    F=malloc(sizeof(file));
    F->x_value = e;
    F->next = NULL;

    if(isEmpty(f)) {
        f=F;
    } else {
        pt = f;
        while(!isEmpty(pt->next)) {
            pt=pt->next;
        }
        pt->next = F;
    }

    return f;
}

File enfiler(File f, char e) {
    File F,pt;

    F=malloc(sizeof(file));
    F->value = e;
    F->next = NULL;

    if(isEmpty(f)) {
        f=F;
    } else {
        pt = f;
        while(!isEmpty(pt->next)) {
            pt=pt->next;
        }
        pt->next = F;
    }

    return f;
}
void printFile(File f) {
    while(!isEmpty(f))
        printf("[%c]\n",sommet(f)), f=f->next;
}

File parenthese(char *eq) {
    File f;
    f = init(); 

    for(int i = 0; i < (int)strlen(eq); i++) {
        if(eq[i]=='(' || eq[i]==')')
            f = enfiler(f,eq[i]);
    }

    return f;
}

File nombres(char *eq) {
    File f;
    f = init(); 

    for(int i = 0; i < (int)strlen(eq); i++) {
        if(eq[i] >= '0' && eq[i] <= '9')
            f = enfiler(f,eq[i]);
    }

    return f;
}

File operateurs(char *eq) {
    File f;
    f = init(); 

    for(int i = 0; i < (int)strlen(eq); i++) {
        if(eq[i] == '+' || eq[i] == '-' || eq[i] == '*' || eq[i] == '/' || eq[i] == '%')
            f = enfiler(f,eq[i]);
    }

    return f;
}

int calculerSimple(int x1, char e, int x2) {    
    switch(e) {
        case '+':
            printf("\033[0;31m%d%c%d=\033[0;37m%d\n",x1,e,x2,x1+x2);    
            return x1+x2;
            break;
        case '-':
            printf("\033[0;31m%d%c%d=\033[0;37m%d\n",x1,e,x2,x1-x2);    
            return x1-x2;
            break;
        case '*':
            printf("\033[0;31m%d%c%d=\033[0;37m%d\n",x1,e,x2,x1*x2);    
            return x1*x2;
            break;
        case '/':
            printf("\033[0;31m%d%c%d=\033[0;37m%d\n",x1,e,x2,x1/x2);    
            return x1/x2;
            break;
    }
}

int calculer(int x1, File *o, int x2) {
    char e;

    *o = defiler(*o,&e);

    switch(e) {
        case '+':
            printf("\033[0;31m%d%c%d=\033[0;37m%d\n",x1,e,x2,x1+x2);    
            return x1+x2;
            break;
        case '-':
            printf("\033[0;31m%d%c%d=\033[0;37m%d\n",x1,e,x2,x1-x2);    
            return x1-x2;
            break;
        case '*':
            printf("\033[0;31m%d%c%d=\033[0;37m%d\n",x1,e,x2,x1*x2);    
            return x1*x2;
            break;
        case '/':
            printf("\033[0;31m%d%c%d=\033[0;37m%d\n",x1,e,x2,x1/x2);    
            return x1/x2;
            break;
    }
}

int evaluer(File p, File n, File o) {
    int x1 = 0;
    int x2 = 0;
    int x = 0;
    char e;
    char pr;

    File pt = p;
    File nt = n;
    File ot = o;

    File res = init();

    while(!isEmpty(pt)) {
        if(sommet(pt) == '(' && !isEmptyNext(pt) && sommetNext(pt) == ')') {
            if(isEmpty(res)) {
                nt = defiler(nt,&e);
                x1 = atoi(&e);
                nt = defiler(nt,&e);
                x2 = atoi(&e);

                x = calculer(x1,&ot,x2);
                res = x_enfiler(res,x);
            } else {
                nt = defiler(nt,&e);
                x1 = atoi(&e);
                nt = defiler(nt,&e);
                x2 = atoi(&e);

                //operateur suivant
                ot = defiler(ot,&e);
                
                // calculer expresion et ajouter dans la file res avec operatuer suivant
                x = calculer(x1,&ot,x2);
                res = x_defiler(res,&x1);

                // calculer expresion et ajouter dans la file res
                x = calculerSimple(x1,e,x);
                res = x_enfiler(res,x);
                
            }
            pt = defiler(pt,&pr);
            pt = defiler(pt,&pr);
        } else if(pr == ')' && sommet(pt) == ')') {
            nt = defiler(nt,&e);
            x1 = atoi(&e);
            res = x_defiler(res,&x2);

            x = calculer(x2,&ot,x1);
            res = x_enfiler(res,x);

            pt = defiler(pt,&pr);
            

        } else {
            pt = defiler(pt,&e);
        }
    }

    return x_sommet(res);
}

void main() {
    int x = 0;
    File p,n,o,res;
    // char eq[50] = "(((4+5)*7)-9)/(4+2)";
    char eq[50] = "(5+(5+5)+(5+5))";

    //initialisation des files
    p = init();
    n = init();
    o = init();

    // former les file a partir de la chaine 
    p = parenthese(eq);
    n = nombres(eq);
    o = operateurs(eq);
    
    //evaluer l'expression
    x = evaluer(p,n,o);

    //afficher la resultat
    printf("\n\033[0;32m%s = %d\n\n",eq,x);
}