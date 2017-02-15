#ifndef jeu9
#define jeu9

//#include "IHM/dessine.h"
#include <math.h>

void afficherTableau(int tblJeu[9][9], int tailleTbl);

int checkEmplacementLibre(int tblJeu[9][9], int xFinal, int yFinal);

int checkAucuneLiberte(int x ,int y,int tbl[9][9]);

void tourIA(int tblJeu[9][9]);

void transformePion(int xFinal,int yFinal,int tblJeu[9][9]);

void checkEnnemieAutour(int tourJoueur,int xFinal,int yFinal);

void draw_win(int nbLigne);

void mouse_clicked(int bouton, int x, int y);

void key_pressed(KeySym code, char c, int x_souris, int y_souris);

void placerHoshi(int nbLigne);

int coupSuicide(int tourJoueur, int x ,int y,int tbl[9][9]);


#endif
