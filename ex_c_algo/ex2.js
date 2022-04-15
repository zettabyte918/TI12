TYPE CELLULE = ENREGISTREMENT
    el : entier
    suiv : *cellule
FIN ENREGISTREMENT

TYPE PILE = *cellule

Procedure Init( P : *PILE))
Debut
    P→suiv←NULL
Fin

Fonction Vide( P : *PILE)) : Booleen
Debut
    Vide ← P->suiv=NULL
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
    X : entier
Debut
    X←P→suiv→el
    q←P→suiv
    P→suiv←P→suiv→suiv
    Liberer(q)
    Depiler ← X
Fin

Fonction Palindrome(CH: chaine) : Booleen
Var 
    i : entier
    P : *Cellule
Debut
    P←Allouer(1)
    Init(P)

    Pour i de 1 a long(CH) Faire
        Empiler(P,CH[i])
    Fin

    i=1
    Tantque (not(Vide(P))) Faire
        X=Depiler(P)
        si(X <> T[i]) Alors
            Palindrome ← faux
        sinon
            i=i+1
        Finsi
    Fin
Fin