#ifndef _TAB_DYN_2D
#define _TAB_DYN_2D

//#include "Case.h"

class TableauDynamique2D{
public:


    /* fonctions membres */
    /* ================= */
    TableauDynamique2D (); // Constructeur par défaut
    /* Postcondition : le tableau a 1 emplacement alloué mais vide (taille utilisée nulle) */

    //TableauDynamique2D (const TableauDynamique2D& t); // Constructeur par copie
    /* Precondition : le tableau t est initialisé */
    /* Postcondition : les deux tableaux contiennent des séquences d'ElementTD identiques (copie de t) */

    ~TableauDynamique2D (); // Destructeur
    /* Postcondition : la mémoire allouée dynamiquement est libérée. */

	void afficher();
};

#endif
