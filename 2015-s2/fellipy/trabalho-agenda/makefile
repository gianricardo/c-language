all: agenda.exe

hello.exe: agenda.o
	gcc -o agenda.exe agenda.o

hello.o: agenda.c
	gcc -c agenda.c

clean:
	rm agenda.o agenda.exe
