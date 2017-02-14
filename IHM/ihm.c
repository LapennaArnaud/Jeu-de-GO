#include "dessine.h"
#include <math.h>
//#include "headers/exemple.h"

#define tailleCoteCarre 40


void mouse_clicked(int bouton, int x, int y)
{

	printf("#########--|| mouse_clickedddd ||--#########\n");
	printf("\nBouton %d presse au coord. %d,%d \n",bouton,x,y);
	
		
	if (x >= 80 && x <= 180 && y >= 60 && y <= 110)
	{
		printf("Dans la ZONE 9X9\n");
	}
			
	
	if (x >= 230 && x <= 330 && y >= 60 && y <= 110)
	{
		printf("Dans la ZONE 13X13\n");
		//get_current_dir_name()+"
		system("./13X13");
		//system("/home/dev/Bureau/Jeu-de-GO/13X13");
	}	
	
	if (x >= 380 && x <= 480 && y >= 60 && y <= 110)
	{
		printf("Dans la ZONE 19X19\n");
	}
	
	if (x >= 80 && x <= 180 && y >= 170 && y <= 220)
	{
		printf("Dans la ZONE I.A\n");
	}

}

void key_pressed(KeySym code, char c, int x_souris, int y_souris)
{

	
}


void draw_win(int nbLigne)
{	
	//I.A
	
	color( 0.8,0.8,0.8);
	filled_rectangle(80, 170, 100, 50);
	color( 0,0,0);
	rectangle(80, 170, 100, 50);
	string(120, 200, "I.A");
	
	
	//9X9
	
	color( 0.8,0.8,0.8);
	filled_rectangle(80, 60, 100, 50);
	color( 0,0,0);
	rectangle(80, 60, 100, 50);
	string(120, 90, "9X9");
	
	
	//13X13
	
	color( 0.8,0.8,0.8);
	filled_rectangle(230, 60, 100, 50);
	color( 0,0,0);
	rectangle(230, 60, 100, 50);
	string(265, 90, "13X13");
	
	
	//19X19
	
	color( 0.8,0.8,0.8);		
	filled_rectangle(380, 60, 100, 50);	
	color( 0,0,0);
	rectangle(380, 60, 100, 50);
	string(415, 90, "19X19");
	
	string(240, 25, "Menu Principal");
	string(270, 250, "Developpe par Arnaud LAPENNA & Julien GROLL");
}



int main() 
{
	
	
	init_win(560,260,"Jeu de GO J&A",204,153,102);
	event_loop(13); // 13 est le nombre de lignes de notre jeu de GO
	return EXIT_SUCCESS;
	
	
}
