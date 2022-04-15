TYPE CELLULE = ENREGISTREMENT
    el : entier
    suiv : *cellule
FIN ENREGISTREMENT

TYPE PILE = *cellule
TYPE LISTE = *cellule


Fonction Vide( P : *PILE)) : Booleen
Debut
    Vide = P->suiv=NULL
Fin

Fonction Depiler( P : *PILE) : Entier
Var
    q : *Cellule 
    X : entier
Debut
    X←P→suiv→el
    q←P→suiv
    P→suiv←P→suiv→suiv
    Liberer(q)
    Depiler ← X
Fin

Fonction Parenthese(L : LISTE) : Booleen
Var 
    i : entier
Debut
    i=0
    Tantque (not(Vide(L))) Faire
        X=Depiler(L)
        si(L='(') Alors
            i=i+1
        sinon si(L=')')
            i=i-1
        finsi
    Fin
    Parenthese ← i=0
Fin