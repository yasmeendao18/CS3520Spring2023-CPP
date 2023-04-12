IDIR =../include
CC=g++ 
CFLAGS= -I$(IDIR) -g -O0 -std=c++11 -pthread

ODIR=.

LIBS=-lncurses 

_DEPS = 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ1 = fibonacci.o
_OBJ2 = ThreadedFibonacci.o


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: fibonacci ThreadedFibonacci

	
fibonacci: $(_OBJ1)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

ThreadedFibonacci: $(_OBJ2)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)


.PHONY: clean

clean:
	rm -f *~ core $(INCDIR)/*~ 
	rm -f fibonacci
	rm -f ThreadedFibonacci
	rm -f *.o

etags: 
	find . -type f -iname "*.[ch]" | xargs etags --append 