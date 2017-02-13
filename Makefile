all: ihm 13X13

clean:
	rm src/ihm 13X13 src/dessine.o libdessine.a
	
ihm: src/ihm.c src/dessine.h libdessine.a
	gcc -g src/ihm.c -o ihm -L. -ldessine -lX11 -lm
	
13X13: src/exemple.c src/dessine.h libdessine.a
	gcc -g src/exemple.c -o 13X13 -L. -ldessine -lX11 -lm

libdessine.a: src/dessine.c src/dessine.h
	gcc -g -c src/dessine.c
	ar -r libdessine.a src/dessine.o
	
