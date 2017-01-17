#include "dessine.h"
#include <math.h>

#define tailleCoteCarre 40



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
	printf("Bouton %d presse au coord. %d,%d \n",bouton,x,y);
	
	
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
		//on affiche le point sur l'intersection caculée (traitement)
		color( 1.0,1.0,1.0);
		filled_circle(xFinal*tailleCoteCarre,yFinal*tailleCoteCarre,10); // on place bien la valeur par multiple du cotèscarré
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
	
	int tblJeu [13][13]= {0};
	int x,y;
	for(x=0; x<13; x++)
	{
		for(y=0; y<13; y++)
		{
			printf("%d",tblJeu[x][y]);
		}
	}
	
	init_win(600,600,"Jeu de GO J&A",204,153,102);
	event_loop(13); // 13 est le nombre de lignes de notre jeu de GO
	return EXIT_SUCCESS;
	
	
}
