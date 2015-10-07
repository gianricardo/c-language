all: agenda

agenda: agenda.o funcoes_agenda.o
	gcc agenda.o funcoes_agenda.o -o agenda
	
agenda.o: agenda.c
	gcc -c agenda.c
	
funcoes_agenda.o: funcoes_agenda.c
	gcc -c funcoes_agenda.c

#Gerar documentação usando o doxygen
docs:
	doxygen Doxyfile
