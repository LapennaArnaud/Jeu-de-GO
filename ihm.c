#include "dessine.h"
#include <math.h>


int main() 
{
	
	
	init_win(560,560,"Jeu de GO J&A",204,153,102);
	event_loop(13); // 13 est le nombre de lignes de notre jeu de GO
	return EXIT_SUCCESS;
	
	
}
