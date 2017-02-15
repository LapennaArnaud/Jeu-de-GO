#include "dessine.h"
#include <math.h>
#include <time.h>
#include <unistd.h>
#include "jeu19.h"

#define tailleCoteCarre 40


int tblJeu[19][19]= {0};
int tourJoueur = 1;

//focntion qui calcule et affiche les points
void compteurPoint(int tblJeu[19][19], int tailleTbl)
{
	int i,j;
	int compteurN = 0;
	int compteurB = 0;
	
	for(i=0; i<tailleTbl; i++)
	{
		for(j=0; j<tailleTbl; j++)
		{
			if (tblJeu[i][j]==1)
			{
				compteurN++;
			}else
				if (tblJeu[i][j]==2)
				{
					compteurB++;
				}
		}
	}
	//cocnaténation du string à afficher pour le compeur
	char chaineCaractereN[] = "COMPTEUR  Noir : ";
	char chaineCaractereB[] = "| Blanc : ";
	char chaineNoir[10];
	char chaineBlanc[10];
	sprintf(chaineNoir, "%d",compteurN);
	sprintf(chaineBlanc, "%d",compteurB);
	strcat(chaineCaractereN,chaineNoir);
	strcat(chaineCaractereB,chaineBlanc);
	color( 0.0,0.0,0.0);
	string(25,800, chaineCaractereN );
	string(145,800, chaineCaractereB );
}

//pour afficher le tableau représentant la table dans la console 
void afficherTableau(int tblJeu[19][19], int tailleTbl)
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

// vérie pour un emplacement donnée si il n'y a pas de pion
int checkEmplacementLibre(int tblJeu[19][19], int xFinal, int yFinal)
{
	if(tblJeu[((int)yFinal)-1][((int)xFinal)-1]==0)
		return 1;
	else
		return 0;
}


//vérifie si le coup est un coup suicide
int coupSuicide(int tourJoueur, int x ,int y,int tbl[19][19]){
	
	int aucuneLiberte = checkAucuneLiberte(x,y,tbl); // 1 si aucune liberte 0 si liberte
	int encercleParEnnemis=0;
	
	int Enord =0; // initialisation à 5 pour éviter les bugs ( 5 ne représente rien) 
	int Eest=0;
	int Esud=0;
	int Eouest=0;
	
	int tourAdverse;
	
	if(tourJoueur==1)
		tourAdverse=1;
	else
		tourAdverse=2;
	
	//check des 4 positions adjacentes au pion placé (Nord Est Sud Ouest)
	if(tblJeu[(((int)y)-1)-1][(((int)x)-1)] == tourAdverse) // Nord
	{
		Enord=1;
	}
	//xFinal+1; yFinal;
	if(tblJeu[(((int)y)-1)][(((int)x)-1)+1] == tourAdverse) // Est
	{
		Eest=1;
	}
	//xFinal; yFinal+1;
	if( tblJeu[(((int)y)-1)+1][(((int)x)-1)] == tourAdverse ) // Sud
	{
		Esud=1;
	}						
	//xFinal-1; yFinal;
	if(tblJeu[(((int)y)-1)][(((int)x)-1)-1] == tourAdverse) // Ouest
	{
		Eouest=1;
	}	
	
	if (Enord == 0 && Eest == 0 && Esud == 0 && Eouest == 0)
		encercleParEnnemis = 1;
	
	if(aucuneLiberte==1 && encercleParEnnemis==1)
		return 1;
	else
		return 0;
	
}

//vérifie si le pion donné n'a pas de liberté 
int checkAucuneLiberte(int x ,int y,int tbl[19][19])
{
	int Pnord =5; // initialisation à 5 pour éviter les bugs ( 5 ne représente rien) 
	int Pest=5;
	int Psud=5;
	int Pouest=5;
	
	//afficherTableau(tbl,19);
	Pnord = checkEmplacementLibre(tbl,((int)x),(((int)y)-1));
	Pest = checkEmplacementLibre(tblJeu,(((int)x)+1), ((int)y));
	Psud = checkEmplacementLibre(tblJeu, ((int)x), (((int)y)+1));	
	Pouest = checkEmplacementLibre(tblJeu, (((int)x)-1), ((int)y));
	
	//printf("check aucune liberté coord (xy):%d;%d  ## nord: %d | est: %d | sud: %d | ouest: %d\n",x,y,Pnord,Pest,Psud,Pouest);
	if (Pnord == 0 && Pest == 0 && Psud == 0 && Pouest == 0)
		return 1;
	else
		return 0;
}
/**
//remplace un pion noir par un pion blanc et vice versa
void transformePion(int xFinal,int yFinal,int tblJeu[19][19])
{
	if(tblJeu[(yFinal-1)][(xFinal-1)]!=0)
	{
		printf("la transformation commence au position : xy : %d|%d!!!\n",xFinal,yFinal);
		//tblJeu[2][5];// position xy 6|3
		if(tblJeu[(yFinal-1)][(xFinal-1)]==1)
		{
			tblJeu[(yFinal-1)][(xFinal-1)]=2;
			color( 1.0,1.0,1.0);
			filled_circle(xFinal*tailleCoteCarre,yFinal*tailleCoteCarre,10);
		} else {
			if(tblJeu[(yFinal-1)][(xFinal-1)]==2)
			{
				tblJeu[(yFinal-1)][(xFinal-1)]=1;
				color( 0.0,0.0,0.0);
				filled_circle(xFinal*tailleCoteCarre,yFinal*tailleCoteCarre,10);
			}
		}
	}
}
**/

//supprime un pion capturer
void transformePion(int xFinal,int yFinal,int tblJeu[19][19])
{
	if(tblJeu[(yFinal-1)][(xFinal-1)]!=0)
	{
		if(tblJeu[(yFinal-1)][(xFinal-1)]==1)
		{
			tblJeu[(yFinal-1)][(xFinal-1)]=0;
		} else {
			if(tblJeu[(yFinal-1)][(xFinal-1)]==2)
			{
				tblJeu[(yFinal-1)][(xFinal-1)]=0;
			}
		}
	}
}


//vérifie si il y a un ou des pion ennemis autours et les tranformes
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
		if( checkAucuneLiberte(xFinal,(yFinal-1),tblJeu) )
		{
			printf("il n'a pas de liberté ! => on le transforme\n");
			transformePion(xFinal,(yFinal-1),tblJeu);
			checkEnnemieAutour(tourJoueur,xFinal,(yFinal-1));
		}
	}
	//xFinal+1; yFinal;
	if(tblJeu[(((int)yFinal)-1)][(((int)xFinal)-1)+1] == tourAdverse) // Est
	{
		printf("WOW YA UN PION ADVERSE A L'EST \n");
		if( checkAucuneLiberte((xFinal+1),yFinal,tblJeu) )
		{
			printf("il n'a pas de liberté ! => on le transforme\n");
			transformePion((xFinal+1),yFinal,tblJeu);
			checkEnnemieAutour(tourJoueur,(xFinal+1),yFinal);
		}
	}
	//xFinal; yFinal+1;
	if( tblJeu[(((int)yFinal)-1)+1][(((int)xFinal)-1)] == tourAdverse ) // Sud
	{
		printf("WOW YA UN PION ADVERSE AU SUD \n");
		if( checkAucuneLiberte(xFinal,(yFinal+1),tblJeu) )
		{
			printf("il n'a pas de liberté ! => on le transforme\n");
			transformePion(xFinal,(yFinal+1),tblJeu);
			checkEnnemieAutour(tourJoueur,xFinal,(yFinal+1));
		}
	}						
	//xFinal-1; yFinal;
	if(tblJeu[(((int)yFinal)-1)][(((int)xFinal)-1)-1] == tourAdverse) // Ouest
	{
		printf("WOWd YA UN PION ADVERSE A L'OUEST \n");
		if( checkAucuneLiberte((xFinal-1),yFinal,tblJeu) )
		{
			printf("il n'a pas de liberté ! => on le transforme\n");
			transformePion((xFinal-1),yFinal,tblJeu);
			checkEnnemieAutour(tourJoueur,(xFinal-1),yFinal);
		}
	}	
}

int customRandom(int minInclu, int maxInclu)
{
	int valeur;
	
	valeur = ((rand()%(maxInclu-minInclu))+minInclu);
}


void tourIA(int tblJeu[19][19])
{
	int xFinal;
	int yFinal;
	
	do
	{
		xFinal = customRandom(1,19);
		yFinal = customRandom(1,19);
	}while(xFinal < 1 || yFinal < 1 || xFinal > 19 || yFinal > 19 );
	
	
	
	if(checkEmplacementLibre(tblJeu,xFinal,yFinal))
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
			//sleep(1);
			filled_circle(xFinal*tailleCoteCarre,yFinal*tailleCoteCarre,10); // on place bien la valeur par multiple du cotèscarré
			afficherTableau(tblJeu, 19);
	}else{
		tourIA(tblJeu);
	}
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
	placerHoshi(nbLigne);
	compteurPoint(tblJeu,19);
	
	color( 0.8,0.8,0.8);
	filled_rectangle(400, 800, 60, 40);
	color( 0,0,0);
	rectangle(400, 800, 60, 40);
	string(415, 820, "Save");
}

void redessinerWin(int nbLigne, int tblJeu[19][19],int tailleTbl)
{
	//clear le contenu de la frame et redessine les lignes 
	clear_win();
	color( 0.0,0.0,0.0);
	draw_win(nbLigne);
	placerHoshi(nbLigne);
	
	// places les pions sur le tableau
	int i,j;
	for(i=0; i<tailleTbl; i++)
	{
		for(j=0; j<tailleTbl; j++)
		{
			
			if(tblJeu[i][j] == 1) // noir
			{
				//on affiche le point sur l'intersection caculée (traitement)
				color( 0.0,0.0,0.0);						
				filled_circle((j+1)*tailleCoteCarre,(i+1)*tailleCoteCarre,10); // on place bien la valeur par multiple du cotèscarré	
			}else
			{
				if(tblJeu[i][j] == 2) // blanc
				{
					//on affiche le point sur l'intersection caculée (traitement)
					color( 1.0,1.0,1.0);		
					filled_circle((j+1)*tailleCoteCarre,(i+1)*tailleCoteCarre,10); // on place bien la valeur par multiple du cotèscarré	
				}
			}			
		}
	}
	compteurPoint(tblJeu,tailleTbl);
	
	
}

//le placement des Hoshi
void placerHoshi(int nbLigne)
{
	int x;
	color( 0.0,0.0,0.0);
    if(nbLigne == 9)
    {
        filled_circle(120,120, 4);
        filled_circle(120,280, 4);
        filled_circle(280,120, 4);
        filled_circle(280,280, 4);
    }   
    else if(nbLigne == 13)
    {
        for(x=0; x<=2; x++)
        {
            filled_circle(160 + (x*120),160, 4);
            filled_circle(160 + (x*120),280, 4);
            filled_circle(160 + (x*120),400, 4);
        }
    }   
    else if(nbLigne == 19)
    {
        for(x=0; x<=2; x++)
        {
            filled_circle(160 + (x*240),160, 4);
            filled_circle(160 + (x*240),400, 4);
            filled_circle(160 + (x*240),640, 4);
        }
    }
}

//sauvegarde du plateau
int sauvegarder_partie(int nbLigne,int tblJeu[19][19])
{
	time_t rawtime;
	char buffer [255];

	time (&rawtime);
	sprintf(buffer,"save/Save_GO_%s",ctime(&rawtime) );

	char *p = buffer;
	for (; *p; ++p)
	{
		if (*p == ' ')
			  *p = '_';
	}

	FILE *fichier = fopen(buffer,"a");
	if (fichier != NULL){
		
		int savei;
		int savej;
		printf("%s",buffer);
		fprintf(fichier,"Table de jeu en cours :");
		fputs("\n", fichier);
		for ( savei = 0; savei<nbLigne; savei++ )
		{
			for ( savej = 0; savej<nbLigne; savej++ )
			{
				fputs(" [", fichier);					
				fprintf(fichier,"%d",tblJeu[savei][savej]);
				fprintf(fichier,"] ");
				//fputs(",", fichier);				
				
			}
			fputs("\n", fichier);
		}
		fputs("\n", fichier);
		fputs("\n", fichier);
		
		fclose(fichier);
		return 1;
	}
	else
	{
		printf("Ecriture impossible");
		return 0;
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
	
	//vérifie si ce n'est pas un clic sur le boutont sauvegarde
	if (x >= 400 && x <= 460 && y >= 800 && y <= 840)
	{
		printf("Vous demandez la sauvegarde\n");
		sauvegarder_partie(19,tblJeu);		
	}
	
	//on calcule la l'intersection selectionné
	double xFinal= x;
	double yFinal= y;
	
	xFinal /=tailleCoteCarre; //on divise par le cotes carre
	yFinal /=tailleCoteCarre;
	xFinal = round(xFinal); // et on arrondit 
	yFinal = round(yFinal);
	
	printf("x : %f y :%f \n",xFinal,yFinal);

	//vérification que le clic est dans la grille de jeu
	if( xFinal < 1 || xFinal > 19 || yFinal < 1 || yFinal > 19 )
	{
		printf("vous avez cliquer hors de la zone \n");
		
	}else
	{
		if (checkEmplacementLibre(tblJeu, xFinal, yFinal)==1 && coupSuicide(tourJoueur,xFinal,yFinal,tblJeu)==0)
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
			afficherTableau(tblJeu, 19);
			//tourIA(tblJeu);
			redessinerWin(19,tblJeu,19);
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
			redessinerWin(19,tblJeu,19);
			break;
		case XK_Up:
			printf("haut\n");
			clear_win();
			break;
		case XK_Left:
			printf("gauche\n");
			placerHoshi(19);
			break;
		case XK_Right:
			printf("droite\n");
			sauvegarder_partie(19,tblJeu);
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
	
	srand(time(NULL));
	init_win(840,880,"19X19",204,153,102);
	event_loop(19); // 19 est le nombre de lignes de notre jeu de GO
	return EXIT_SUCCESS;
	
	
}


	
	
	
