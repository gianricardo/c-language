#CRIAR APLICATIVO PRINCIPAL: ordenacao_app
all: ordenacao_app

ordenacao_app: main.o arquivo.o vetor.o sort.o
	gcc main.o arquivo.o vetor.o sort.o -o ordenacao_app
	
main.o: main.c
	gcc -c main.c
	
arquivo.o: arquivo.c
	gcc -c arquivo.c
	
vetor.o: vetor.c
	gcc -c vetor.c

sort.o:
	gcc -c sort.c
	
#CRIAR APLICATIVO PARA GERAR ARQUIVO DE DOUBLES: gera_arq_double
gera_arq_double: gera_arq_double.o
	gcc gera_arq_double.o -o gera_arq_double
	
gera_arq_double.o: gera_arq_double.c
	gcc -c gera_arq_double.c
	
#GERAR DOCUMENTAÇÃO USANDO O DOXYGEN
docs: Doxyfile
	doxygen Doxyfile

	
	
