#ifndef jeu19
#define jeu19

//#include "IHM/dessine.h"
#include <math.h>

void afficherTableau(int tblJeu[19][19], int tailleTbl);

int checkEmplacementLibre(int tblJeu[19][19], int xFinal, int yFinal);

int checkAucuneLiberte(int x ,int y,int tbl[19][19]);

void tourIA(int tblJeu[19][19]);

void transformePion(int xFinal,int yFinal,int tblJeu[19][19]);

void checkEnnemieAutour(int tourJoueur,int xFinal,int yFinal);

void draw_win(int nbLigne);

void mouse_clicked(int bouton, int x, int y);

void key_pressed(KeySym code, char c, int x_souris, int y_souris);

void placerHoshi(int nbLigne);

int coupSuicide(int tourJoueur, int x ,int y,int tbl[19][19]);


#endif
