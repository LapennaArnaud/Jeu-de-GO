VPATH = ./src ./IHM
IHM = ./IHM/
SRC = ./src/
CFLAGS = -I./IHM/
LDFLAGS = -lX11 -lm

all: clean ihm 13X13



ihm: ihm.o dessine.o
	gcc -o $@ $^ $(LDFLAGS)
	
13X13: jeu.o dessine.o
	gcc -o $@ $^ $(LDFLAGS)

%.o: %.c
	gcc -c $< $(CFLAGS)
	
clean:
	rm ihm 13X13 *.o
	
