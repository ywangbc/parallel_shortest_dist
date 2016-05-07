IDIR =../lib
CC=gcc
CFLAGS=-I$(IDIR) -Wall -Werror

ODIR=../lib
LDIR =../lib

LIBS=-lm

_DEPS = queue.h list.h graph.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = test.o queue.o list.o graph.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ)
		gcc -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
		rm -f ./*.o $(ODIR)/*.o *~ core $(INCDIR)/*~  test ../lib/test.o ../lib/queue.o ../lib/list.o ../lib/graph.o
