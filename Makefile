all: ihm 13X13

clean:
	rm IHM/ihm src/13X13 IHM/dessine.o IHM/libdessine.a
	
ihm: IHM/ihm.c IHM/dessine.c IHM/dessine.h IHM/libdessine.a
	cd IHM; gcc -g -c dessine.c
	cd IHM; ar -r libdessine.a dessine.o
	cd IHM; gcc -g ihm.c -o ihm -L. -ldessine -lX11 -lm
	
13X13: src/jeu.c IHM/dessine.h IHM/libdessine.a
	cd src; gcc -g jeu.c -o 13X13 -L. -ldessine -lX11 -lm

libdessine.a:IHM/dessine.c IHM/dessine.h IHM/libdessine.a
	cd IHM; gcc -g -c dessine.c
	cd IHM; ar -r libdessine.a dessine.o
	
