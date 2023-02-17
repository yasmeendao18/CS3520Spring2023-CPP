# makefile for practice activity 6 
IDIR =../include
CC=g++
CFLAGS= -I$(IDIR) -g -O0

ODIR=.

LIBS=-lncurses

_DEPS = 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ1 = pa6_main.o


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: pa6_main

	
pa6_main: $(_OBJ1)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)


.PHONY: clean

clean:
	rm -f *~ core $(INCDIR)/*~ 
	rm -f pa6_main
	rm -f *.o

etags: 
	find . -type f -iname "*.[ch]" | xargs etags --append 