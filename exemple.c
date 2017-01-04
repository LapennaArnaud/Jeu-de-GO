#include "dessine.h"

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
	
	
	
	/*
	// vide la fenetre
	clear_win();

	int i,j;
	for(i=0; i<height_win()/2; i+=2)
	{
		for(j=0; j<width_win(); j+=2)
		{
			float r = (float)rand()/RAND_MAX;
			float v = (float)rand()/RAND_MAX;
			float b = (float)rand()/RAND_MAX;
			color(r,v,b);
			pixel(j,i);
		}
	}
		
	for(i=height_win()/2; i<height_win(); i+=4)
	{
		for(j=0; j<width_win(); j+=4)
		{
			float g = (float)rand()/RAND_MAX;
			color(g,g,g);
			filled_rectangle(j,i,4,4);
		}
	}
	
	color(1,0,0);
	for(j=0; j<width_win(); j+=20)
		line(j,24, width_win()-j, height_win()-24);

	color(11,1,1);
	string(5,5,"Test Affichage chaine");
	*/
}


/**
 * on a cliqué a la souris:
 * bouton: 1,2,3,4,5,... : gauche, milieu, droit, molette, ...
 * x,y position
 */
void mouse_clicked(int bouton, int x, int y)
{
	printf("Bouton %d presse au coord. %d,%d \n",bouton,x,y);
	
	color( 1.0,0.0,1.0);
	filled_circle(x,y,10);
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
	init_win(600,600,"Jeu de GO J&A",204,153,102);
	event_loop(13);
	return EXIT_SUCCESS;
}
