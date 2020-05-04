/** @file WinTxt.h
 */
#ifndef WINTXT_H
#define WINTXT_H

/** @brief This class handls the display of the game in the terminal
 */
class WinTXT {
    private :
        int dimx;
        int dimy;
        char* win;

    public :
        /**
         * @brief Constructeur de la classe WinTXT
         * @param dx Dimension sur l'axe x de la fenêtre
         * @param dy Dimension sur l'axe y de la fenêtre
         * @return Revoie une fenêtre dans le terminal
         */
        WinTXT(int dx, int dy);
        /**
         * @brief Destructeur par défaut de la classe WinTXT
         */
        ~WinTXT();
        /**
         * @brief Procédure effaçant tout ce qu'il y a dans la fenêtre
         * @param c Caractère ' ' (ou espace)
         * @return Affiche la fenêtre remplie du caractère ' ', donc vide
         */
        void clear(char c=' ');
        /**
         * @brief Procédure permettant de remplir un tableau de taille de la fenêtre avec le caractère donné en paramètre et aux indices x et y
         * @param x Position sur l'axe x
         * @param y Position sur l'axe y
         * @param c Caractère à afficher aux positions x et y
         * @return Affiche un tableau rempli du caractère c en fonction de x et y
         */
        void print(int x, int y, char c);
         /**
         * @brief Procédure affichant un caractère à des coordonnées rentrées en paramètre
         * @param x Position sur l'axe x
         * @param y Position sur l'axe y
         * @param c pointeur sur un caractère à afficher aux positions x et y
         * @return Affiche le caractère dans la fenêtre à l'aide du tableau rempli
         */
        void print (int x, int y, char* c);
        void draw (int x=0, int y=0);
        /**
         * @brief Procédure permettant de mettre en pause le jeu
         * @return Affiche le texte "Appuyer sur une touche" lorsque le joueur met en pause le jeu
         */
        void pause();
        /**
         * @brief Permet de lire un caractere si une touche a été pressée
         */
        char getCh();
};

void termClear ();

#endif