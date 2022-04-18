TYPE CELLULE = ENREGISTREMENT
    el : entier
    suiv : *cellule
FIN ENREGISTREMENT

TYPE PILE = *cellule

Procedure Init( P : *PILE))
Debut
    P→suiv←NULL
Fin

Fonction Vide( P : PILE)) : Booleen
Debut
    Vide = P->suiv=NULL
Fin

Procedure Empiler( P : *Pile ; X : Entier)
Var
    q : *Cellule
Debut
    q←Allouer(1)
    q→el←X
    q→suiv←P→suiv
    P→suiv←q
Fin

Fonction Depiler( P : *Pile) : Entier
Var
    q : *Cellule 
    X : Entier
Debut
    X←P→suiv→el
    q←P→suiv
    P→suiv←P→suiv→suiv
    Liberer(q)
    Depiler = X
Fin

Fonction Copy(P1:*PILE, P2:*PILE) : PILE
Var 
    X,I : entier
    T : Tab
Debut
    {i=0}
    Tantque (not(Vide(P1))) Faire
        X=Depiler(P1)
        Empiler(P1,X)
        T[i] = X
        i=i+1
    Fin
    
    Pour j de 1 a i Faire
        Empiler(P2,T[I])
    Fin
Fin

