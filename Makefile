all: ihm 13X13

clean:
	rm ihm 13X13 dessine.o libdessine.a
	
ihm: ihm.c dessine.h libdessine.a
	gcc -g ihm.c -o ihm -L. -ldessine -lX11 -lm
	
13X13: exemple.c dessine.h libdessine.a
	gcc -g exemple.c -o 13X13 -L. -ldessine -lX11 -lm

libdessine.a: dessine.c dessine.h
	gcc -g -c dessine.c
	ar -r libdessine.a dessine.o
	
