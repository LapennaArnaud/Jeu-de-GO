VPATH = ./src ./IHM
IHM = ./IHM/
SRC = ./src/
CFLAGS = -I./IHM/
LDFLAGS = -lX11 -lm

all: ihm 19X19 13X13 9X9 IA



ihm: ihm.o dessine.o
	gcc -o $@ $^ $(LDFLAGS)

	
19X19: jeu19.o dessine.o
	gcc -o $@ $^ $(LDFLAGS)

13X13: jeu.o dessine.o
	gcc -o $@ $^ $(LDFLAGS)

9X9: jeu9.o dessine.o
	gcc -o $@ $^ $(LDFLAGS)

IA: jeuIA.o dessine.o
	gcc -o $@ $^ $(LDFLAGS)

%.o: %.c
	gcc -c $< $(CFLAGS)
	
clean:
	rm ihm 13X13 19X19 9X9 IA *.o
	
