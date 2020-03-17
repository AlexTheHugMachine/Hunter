#ifndef _TAB_DYN_2D
#define _TAB_DYN_2D

#include "Case.h"

class TableauDynamique2D{
public:
    /* données membres */
    /* =============== */
    /* (ne sont pas censées être connues par l'utilisateur,
        si on avait pu ne pas les faire figurer dans l'interface, on l'aurait fait)
    */
    unsigned int capacite;
    unsigned int taille_utilisee;
    Case * ad;

    /* fonctions membres */
    /* ================= */
    TableauDynamique2D (); // Constructeur par défaut
    /* Postcondition : le tableau a 1 emplacement alloué mais vide (taille utilisée nulle) */

    TableauDynamique2D (const TableauDynamique2D& t); // Constructeur par copie
    /* Precondition : le tableau t est initialisé */
    /* Postcondition : les deux tableaux contiennent des séquences d'ElementTD identiques (copie de t) */

    ~TableauDynamique2D (); // Destructeur
    /* Postcondition : la mémoire allouée dynamiquement est libérée. */

	void vider ();
    /* Postcondition : la mémoire allouée dynamiquement est libérée.
	                   le tableau a 1 emplacement alloué mais vide (taille utilisée nulle) */

    void ajouterElement (Case e);
    /* Postcondition : l'élément e est ajouté dans le premier emplacement inutilisé du tableau,
                       la taille est incrémentée de 1. Doublement de la capacité si nécessaire. */

    Case valeurIemeElement (unsigned int indice) const;
    /* Precondition : 0 <= indice < taille_utilisee */
    /* Resultat : retourne l'ElementTD à l'indice en paramètre */

    void modifierValeurIemeElement (Case e, unsigned int indice);
    /* Precondition : 0 <= indice < taille_utilisee */
    /* Postcondition : l'ElementTD à l'indice en paramètre vaut e */

    void afficher () const;
    /* Postcondition : les éléments du tableau sont affichés sur la sortie standard (espacement entre les éléments)
                       en utilisant la procédure d'affichage de ElementTD */

    void supprimerElement (unsigned int indice);
    /* Precondition : le tableau est non vide, et 0 <= indice < taille_utilisee */
    /* Postcondition : la taille utilisée du tableau est décrémentée de 1.
                       si taille_utilisee < capacite/3, alors on divise la capacité par 2. */

    void insererElement (Case e, unsigned int indice);
    /* Precondition : 0 <= indice < taille_utilisee */
    /* Postcondition : e est inséré à l'indice en paramètre et la taille utilisée est incrémentée de 1 */

    void trier ();
    /* Postcondition : le tableau est trié dans l'ordre croissant des valeurs des éléments */

    int rechercherElement (Case e) const;
    /* Precondition : le tableau est trié dans l'ordre croissant */
    /* Résultat : indice de l'emplacement qui contient un ElementTD égal à e,
                  -1 si le tableau ne contient pas d'élément égal à e */

};

#endif
