flags=-O2 -Wall -std=c2x -I./myutils
ldflags=

.PHONY: all clean

all: chronos-vm

myutils/birchutils.o: myutils/birchutils.c myutils/birchutils.h
	cc $(flags) -c myutils/birchutils.c -o myutils/birchutils.o

chronos-vm: chronos-vm.o myutils/birchutils.o
	cc $(flags) chronos-vm.o myutils/birchutils.o -o chronos-vm $(ldflags)

chronos-vm.o: chronos-vm.c chronos-vm.h
	cc $(flags) -c chronos-vm.c -o chronos-vm.o

clean:
	rm -f *.o chronos-vm