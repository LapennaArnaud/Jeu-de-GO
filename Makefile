all: ihm

clean:
	rm ihm dessine.o libdessine.a
	
ihm: ihm.c dessine.h libdessine.a
	gcc -g ihm.c -o ihm -L. -ldessine -lX11 -lm

libdessine.a: dessine.c dessine.h
	gcc -g -c dessine.c
	ar -r libdessine.a dessine.o
	
