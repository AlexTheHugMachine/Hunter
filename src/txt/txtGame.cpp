#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "WinTxt.h"

#include "../core/Game.h"

void txtAff (WinTXT & win, const Game & g) {
	const Terrain& ter = g.getTerrain();
	const Player& play = g.getPlayerPos();
	const Ennemy& enn = g.getEnnemiesPosition();

	win.clear();

    // Affichage des murs et des pastilles
	for(int x=0;x<ter.getDimX();++x)
		for(int y=0;y<ter.getDimY();++y)
			win.print(x,y,ter.getDim(x,y));

    // Affichage de Pacman
	win.print(play.getX(),play.getY(),'P');
	// Affichage du Fantome
	win.print(enn.getX(),enn.getY(),'E');

	win.draw();
}

void txtBoucle (Game & g) {
	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    WinTXT win (g.getTerrain().getDimX(),g.getTerrain().getDimY());

	bool ok = true;
	int c;

	do {
	    txtAff(win,g);

        #ifdef _WIN32
        Sleep(100);
		#else
		usleep(100000);
        #endif // WIN32

		//g.UpdateGame();            Fonction qui fait bouger les ennemies tout seuls

		c = win.getCh();
		switch (c) {
			case 'k':
				g.actionClavier('g');
				break;
			case 'm':
				g.actionClavier('d');
				break;
			case 'l':
				g.actionClavier('h');
				break;
			case 'o':
				g.actionClavier('b');
				break;
			case 'q':
				ok = false;
				break;
		}

	} while (ok);

}
