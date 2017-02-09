#include "dessine.h"
#include <math.h>

#define tailleCoteCarre 40

int tblJeu[13][13]= {0};
int tourJoueur = 1;

void afficherTableau(int tblJeu[13][13], int tailleTbl)
{
	int i,j;
	for(i=0; i<tailleTbl; i++)
	{
		for(j=0; j<tailleTbl; j++)
		{
			printf("%d",tblJeu[i][j]);
		}
		printf("\n");
	}
}

int checkEmplacementLibre(int tblJeu[13][13], int xFinal, int yFinal)
{
	if(tblJeu[((int)yFinal)-1][((int)xFinal)-1]==0)
		return 1;
	else
		return 0;
}


void checkEnnemieAutour(int tourJoueur,int xFinal,int yFinal)
{
	int tourAdverse;
	
	if(tourJoueur==1)
		tourAdverse=2;
	else
		tourAdverse=1;
	
	printf("----------fonc checkEnnemieAutour--------------\n");
	printf(" tour joueur : %d || tour adverse : %d \n",tourJoueur,tourAdverse);
	printf(" posY fonc check ennemie: %d \n", (int)yFinal);
	printf(" posX fonc check ennemie : %d \n", (int)xFinal);
	printf("-----------------------------------------------\n");
	
	//check des 4 positions adjacentes au pion placé (Nord Est Sud Ouest)
	//xFinal; yFinal - 1;
	if(tblJeu[(((int)yFinal)-1)-1][(((int)xFinal)-1)] == tourAdverse) // Nord
	{
		printf("WOW YA UN PION ADVERSE AU NORD \n");
	}
	//xFinal+1; yFinal;
	if(tblJeu[(((int)yFinal)-1)][(((int)xFinal)-1)+1] == tourAdverse) // Est
	{
		printf("WOW YA UN PION ADVERSE A L'EST \n");
	}
	//xFinal; yFinal+1;
	if( tblJeu[(((int)yFinal)-1)+1][(((int)xFinal)-1)] == tourAdverse ) // Sud
	{
		printf("WOW YA UN PION ADVERSE AU SUD \n");
	}						
	//xFinal-1; yFinal;
	if(tblJeu[(((int)yFinal)-1)][(((int)xFinal)-1)-1] == tourAdverse) // Ouest
	{
		printf("WOWd YA UN PION ADVERSE A L'OUEST \n");
	}	
}


int checkAucuneLiberte(int xFinal,int yFinal,int tblJeu[13][13])
{
	int nord, sud, est, ouest;
	
	nord = checkEmplacementLibre(tblJeu, (((int)yFinal)-1), ((int)xFinal));
	est = checkEmplacementLibre(tblJeu, ((int)yFinal), (((int)xFinal)+1));
	sud = checkEmplacementLibre(tblJeu, (((int)yFinal)+1), ((int)xFinal));	
	ouest = checkEmplacementLibre(tblJeu, ((int)yFinal), (((int)xFinal)-1));
	
	if (nord == 0 && est == 0 && sud == 0 && ouest == 0)
		return 1;
	else
		return 0;
}



/**
 * Mettre ici son code pour dessiner dans la fenetre
 * 1er affichage + redessine si resize
 */
void draw_win(int nbLigne)
{	
	// ici on va dessiner les lignes cadrillage 19 13 9 
	
	int tailleTot = tailleCoteCarre*nbLigne;
	int x0=tailleCoteCarre;
	int y0=tailleCoteCarre;
	int i;
	for(i=0;i<nbLigne;i++)
	{
		line(x0+i*tailleCoteCarre,y0,x0+i*tailleCoteCarre,tailleTot);
		line(x0,y0+i*tailleCoteCarre,tailleTot,y0+i*tailleCoteCarre);
	}
}



/**
 * on a cliqué a la souris:
 * bouton: 1,2,3,4,5,... : gauche, milieu, droit, molette, ...
 * x,y position
 */
void mouse_clicked(int bouton, int x, int y)
{
	printf("\n#########--|| mouse_clicked ||--#########\n");
	//printf("\nBouton %d presse au coord. %d,%d \n",bouton,x,y);
	
	
	//on calcule la l'intersection selectionné
	double xFinal= x;
	double yFinal= y;
	
	xFinal /=tailleCoteCarre; //on divise par le cotes carre
	yFinal /=tailleCoteCarre;
	xFinal = round(xFinal); // et on arrondit 
	yFinal = round(yFinal);
	
	printf("x : %f y :%f \n",xFinal,yFinal);

	//vérification que le clic est dans la grille de jeu
	if( xFinal < 1 || xFinal > 13 || yFinal < 1 || yFinal > 13 )
	{
		printf("vous avez cliquer hors de la zone \n");
		
	}else
	{
		if (checkEmplacementLibre(tblJeu, xFinal, yFinal)==1)
		{
			if(tourJoueur == 1) // noir
			{
				//on affiche le point sur l'intersection caculée (traitement)
				color( 0.0,0.0,0.0);		
				tblJeu[((int)yFinal)-1][((int)xFinal)-1] = 1; // /!\  coord y correspond aux ordonnées donc les lignesTBL [y][] ET coord x corresponf aux  absices donc les colonesTBL [][x]				
				checkEnnemieAutour(tourJoueur,xFinal,yFinal);
				tourJoueur=2;
			}else
			{
				if(tourJoueur == 2) // blanc
				{
					//on affiche le point sur l'intersection caculée (traitement)
					color( 1.0,1.0,1.0);		
					tblJeu[((int)yFinal)-1][((int)xFinal)-1] = 2; // /!\  coord y correspond aux ordonnées donc les lignesTBL [y][] ET coord x corresponf aux  absices donc les colonesTBL [][x]
					checkEnnemieAutour(tourJoueur,xFinal,yFinal);
					tourJoueur=1;
				}
			}
			filled_circle(xFinal*tailleCoteCarre,yFinal*tailleCoteCarre,10); // on place bien la valeur par multiple du cotèscarré
			afficherTableau(tblJeu, 13);
		}
		else
			printf("Vous ne pouvez pas replacer un pion ici \n");
	}
	
}





/**
 * on a appuyé sur une touche
 * code: code touche x11 (XK_...)
 * c caractère correspondant si caractere
 * x_souris,y_souris position de la souris
 */
void key_pressed(KeySym code, char c, int x_souris, int y_souris)
{
	switch(code)
	{
		case XK_Down:
			printf("bas\n");
			break;
		case XK_Up:
			printf("haut\n");
			break;
		case XK_Left:
			printf("gauche\n");
			break;
		case XK_Right:
			printf("droite\n");
			break;
	//~ case XK_Return:
	//~ case XK_Shift_L:
	//~ case XK_Control_R:
	//~ ....
		default:
			break;
	}
	
	if (c>' ' && c<'z')
		printf("char: %c \n",c);

	printf(" avec pos souris: %d,%d \n",x_souris,y_souris);

}



int main() 
{
	
	
	init_win(560,560,"Jeu de GO J&A",204,153,102);
	event_loop(13); // 13 est le nombre de lignes de notre jeu de GO
	return EXIT_SUCCESS;
	
	
}


	
	
	
