IDIR =../include
CC=g++
CFLAGS= -I$(IDIR) -g -O0

ODIR=.

LIBS=-lncurses

_DEPS = 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ1 = file1debug.o
_OBJ2 = file2debug.o
_OBJ3 = file3debug.o
_OBJ4 = compound_interest.o
_OBJ5 = stats_from_paragraph.o
_OBJ6 = find_and_replace.o

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: file1debug file2debug file3debug compound_interest stats_from_paragraph find_and_replace

	
file1debug: $(_OBJ1)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

file2debug: $(_OBJ2)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

file3debug: $(_OBJ3)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

compound_interest: $(_OBJ4)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

stats_from_paragraph: $(_OBJ5)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

find_and_replace: $(_OBJ6)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *~ core $(INCDIR)/*~ 
	rm -f file1debug
	rm -f file2debug
	rm -f file3debug
	rm -f compound_interest
	rm -f stats_from_paragraph
	rm -f find_and_replace
	rm -f *.o

etags: 
	find . -type f -iname "*.[ch]" | xargs etags --append 