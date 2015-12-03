Para compilar e construir o projeto basta usar o Makefille
O comando make deve ser capaz de compilar e juntar todos 
os arquivos se o seu ambiente possuir o Makefile e o gcc
========================================================================================
Comandos:

make -> compila o area.c que é o .c do TDA e o app.c que é o .c da aplicação de teste e constroi o programa app

make docs //Gera a documentação utilizando o doxygen
=========================================================================================
Uso

O uso do TDA é bem simples, seu objetivo é receber dados que serão ordenado em ordem e oferecer a possibilidade
de remoção das extremidades a custo O(1), Os comentarios das funções descrevem bem o seu funcionamento.
O app faz um teste geral das operações do TDA.
========================================================================================
Arquivos:
	- area.h -> arquivo contendo todas as funções visiveis pelo app
	- area_priv.h -> arquivo contendo as Estruturas de acesso limitado e funções ocultas
	- area.c -> Implementação das operações do TDA area
	
	- app.c -> aplicação de teste do TDA area
