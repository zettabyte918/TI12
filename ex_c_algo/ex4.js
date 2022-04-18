TYPE CELLULE = ENREGISTREMENT
    el : entier
    suiv : *cellule
FIN ENREGISTREMENT

TYPE PILE = *cellule


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

Fonction CalculePile(P : *PILE, X : entier) : Entier
Debut
    si(Vide(P)) Alors
        CalculePile ← X
    sinon 
        CalculePile(P,X + Depiler(P,X))
Fin