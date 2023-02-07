IDIR =../include
CC=g++
CFLAGS= -I$(IDIR) -g -O0

ODIR=.

LIBS=-lncurses

_DEPS = 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ1 = Rolling_dice.o


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: Rolling_dice

	
Rolling_dice: $(_OBJ1)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)


.PHONY: clean

clean:
	rm -f *~ core $(INCDIR)/*~ 
	rm -f Rolling_dice
	rm -f *.o

etags: 
	find . -type f -iname "*.[ch]" | xargs etags --append 