Para construir o projeto basta usar o Makefile em um ambiente compativel, ou o
compilador de sua preferencia! O projeto foi todo escrito apenas usando as bib
liotecas padrões.
__________________________________________________________________________________

comandos para usar o Makefile:

make -> gerar o aplicativo principal: ordenacao_app;
make gera_arq_double -> gerar o palicativo que cria arquivos desordenados;
make docs -> gerar a documentação (usand o doxygen);
__________________________________________________________________________________

Uso dos apps:

exemplo de uso do ordenação_app no linux ou em um ambiente cygwin:
	./ordenação_app arquivo_de_entrada.txt arquivo_de_saida.txt
	
exemplo de uso do gera_arq_double no linux ou em um ambiente cygwin:
	./ordenação_app tamanho_em_bytes nome_arquivo.txt
_________________________________________________________________________________

Funcionamento dos apps:

ordenacao_app:
	le um arquivo de entrada (ex: arquivo_de_entrada.txt) que deve ser um arquivo com
	um numero de linhas indetermindado porem com 10 doubles por linha separados
	por um espaço entre eles. Gera um arquivo (ex: arquivo_de_saida.txt) com os
	valores contidos no arquivo de entrada, ordenados, um valor em cada linha!
	

gera_arq_double:
	Cria um arquivo (ex: nome_arquivo.txt) com aproximadamente tamanho_em_bytes
	bytes, preenchido com linhas com 10 valores de ponto flutuante, separados por
	espaços, em cada linha. O arquivo programa vai criando novas linhas até satisfazer
	o espaço estipulado, e então preenche a ultima linha, gerando um pequeno excedente
	em bytes, caso necessário.
__________________________________________________________________________________

Arquivos do projeto:

	ordenacao_app:
		- main.c
		- arquivo.h
		- arquivo.c
		- vetor.h
		- vetor.c 
		- sort.h
		- sort.c

	gera_arq_double:
		- gera_arq_double.c
