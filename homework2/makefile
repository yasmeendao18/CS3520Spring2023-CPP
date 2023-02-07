IDIR =../include
CC=g++
CFLAGS= -I$(IDIR) -g -O0

ODIR=.

LIBS=-lncurses

_DEPS = 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ1 = Roll_dice.o
_OBJ2 = Maze_generator.o
_OBJ3 = Phishing_scanner.o


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: Roll_dice Maze_generator Phishing_scanner

	
Roll_dice: $(_OBJ1)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

Maze_generator: $(_OBJ2)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

Phishing_scanner: $(_OBJ3)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)



.PHONY: clean

clean:
	rm -f *~ core $(INCDIR)/*~ 
	rm -f Roll_dice
	rm -f Maze_generator
	rm -f Phishing_scanner
	rm -f *.o

etags: 
	find . -type f -iname "*.[ch]" | xargs etags --append 