#ifndef jeuIA
#define jeuIA

//#include "IHM/dessine.h"
#include <math.h>

void afficherTableau(int tblJeu[13][13], int tailleTbl);

int checkEmplacementLibre(int tblJeu[13][13], int xFinal, int yFinal);

int checkAucuneLiberte(int x ,int y,int tbl[13][13]);

void tourIA(int tblJeu[13][13]);

void transformePion(int xFinal,int yFinal,int tblJeu[13][13]);

void checkEnnemieAutour(int tourJoueur,int xFinal,int yFinal);

void draw_win(int nbLigne);

void mouse_clicked(int bouton, int x, int y);

void key_pressed(KeySym code, char c, int x_souris, int y_souris);

void placerHoshi(int nbLigne);

int coupSuicide(int tourJoueur, int x ,int y,int tbl[13][13]);


#endif
