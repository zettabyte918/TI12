#include<stdio.h>

#include<stdlib.h>

#include<string.h>

struct cellule {
  char info;
  struct cellule * suiv;
};
typedef struct cellule * liste;
liste remplir(liste l, char s) {
  liste pt, p;
  pt = (liste) malloc(sizeof(struct cellule));
  pt -> info = s;
  pt -> suiv = NULL;
  if (l == NULL) {
    l = pt;
  } else {

    p = l;
    while (p -> suiv != NULL) {
      p = p -> suiv;
    }
    p -> suiv = pt;
  }
  return l;
}

int main() {
  liste l, p;
  char ch[30];
  int i;
  l = NULL;
  printf("taper une chaine: ");
  scanf("%s", ch);
//   printf("%s", ch);
  for (i = 0; i < strlen(ch); i++) {
    l = remplir(l, ch[i]);
  }
  p = l;

  for(i=0;i<strlen(ch);i++)
  {
    printf("%c",p->info);
    p=p->suiv;
  }

  return 0;
}