flags=-O2 -Wall -std=c2x
ldflags=-lbu

.PHONY: all clean

all: clean myvm

myvm: myvm.o
	cc $(flags) $^ -o $@ $(ldflags)

myvm.o: myvm.c myvm.h
	cc $(flags) -c $<

clean:
	rm -f *.o myvm