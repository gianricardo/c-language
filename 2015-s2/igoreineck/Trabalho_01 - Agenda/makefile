#compila o programa
all: cadastro.o fn_aniversarios.o fn_modifica_pelo_nome.o fn_ordenacao.o fn_excluir.o fn_mostra_ordenado.o import_export.o inicializa.o programa.o
	gcc -o app cadastro.o fn_aniversarios.o fn_modifica_pelo_nome.o fn_ordenacao.o fn_excluir.o fn_mostra_ordenado.o import_export.o inicializa.o programa.o

cadastro.o: src/cadastro.c
	gcc -c src/cadastro.c

fn_aniversarios.o: src/fn_aniversarios.c
	gcc -c src/fn_aniversarios.c

fn_modifica_pelo_nome.o: src/fn_modifica_pelo_nome.c
	gcc -c src/fn_modifica_pelo_nome.c

fn_ordenacao.o: src/fn_ordenacao.c
	gcc -c src/fn_ordenacao.c

fn_excluir.o: src/fn_excluir.c
	gcc -c src/fn_excluir.c

fn_mostra_ordenado.o: src/fn_mostra_ordenado.c
	gcc -c src/fn_mostra_ordenado.c

import_export.o: src/import_export.c
	gcc -c src/import_export.c

inicializa.o: src/inicializa.c
	gcc -c src/inicializa.c

programa.o: src/programa.c
	gcc -c src/programa.c

executa: app
	./app

#gera a documentação
docs: 
	doxygen Doxyfile
