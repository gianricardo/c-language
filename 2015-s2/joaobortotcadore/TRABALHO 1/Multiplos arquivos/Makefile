compile_all: privado operacoes main  
	gcc -o app main.c operacoes_agenda.c tda_agenda_privado.c
main: main.c
	gcc -o main main.c
operacoes: operacoes_agenda.c
	gcc -o operacoes_agenda operacoes_agenda.c
privado: tda_agenda_privado.c
	gcc -o tda_agenda_privado tda_agenda_privado.c
executeall: compile_all
	./app

