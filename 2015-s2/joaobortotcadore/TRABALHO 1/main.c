#include <stdio.h>      /* printf, scanf, puts */
#include <stdlib.h>     /* realloc, free, exit, NULL */
#include <string.h>	/* strcmp */


/*BUGS E ANOTAÇOES
OK - Função cadastra nome, não pega string com espaço usar //fgets(agenda->contato[agenda->qnt_agenda].nome, TAM_NOME, stdin); --> funcionou com o fgets + setbuf (inserido dentro da função quando vai ser feito a leitura) "setbuf(stdin,NULL) = limpa o buffer do stdin para não ter nenhuma sujeira no teclado"
OK - Vai ter problema nessa condiçãõ : tiver 2 ou mais contatos, excluir o primeiro, e entãõ adicionar um outro contato, pois quem esta cuidando a posição do vetor do contato é a variavel qnt_agenda. Ao excluir a qnt_agenda vai para 1, e ao adicionar novo contato, ele vai sobreescrever o contato na posiçao 2 do vetor contato (contato[1]). Implementar uma função que retorne a posiçãõ do vetor contato livre para adicionar um contato --> resolvido, faltou atenção e revisão, era problema da estrutura, se sempre ordenar, a posicao livre é a posicao quantidade de elementos
COISA DE LOUCO!! NÃO OK - no caso de (contato 1, contato 2, ..) parece que a função excluir libera toda a memoria se excluir contato 1. Quem sabe solucione se copiar os dados do ultimo contato adicionado na agenda e sobreescrever o que se deseja excluir --> estava fazendo operações na estrutura errada, basta não imprimir contatos que tenham '0' no nome, pois foi usado o comando memset(&agenda->contato[i],0,sizeof(dados_t));
- não imprimir contatos que tenham somente '0' no nome
OK - ver como limpar a tela depois de escolher o menu
OK - falta função pra ver se o ano é bissexto, para o cadastro de aniversario
OK - implementar pre condições de agenda nao vazia para as funções --> implementado com a macro agenda_vazia  
OK - implementar verificaçãõ se a agenda esta criada para pre condições de cadastro --> a pre condicao é garantida com o teste feito após a alocacao de memória para a estrutura agenda e com o teste do arquivo criado com sucesso
-substituir os comentarios 'liberar memoria' pela implementaçãõ do codigo free
OK - função mostra agenda ordenada esta com problemas, esta alterando a agenda original e nao a copia da agenda --> nao vai ter copia de agenda, ficara salvo na agenda a ultima ordenaçao feita pelo usuario
- depois que cadastra varias vezes, exclui contatos e cadastrar novos, projetando encontrei algumas falhas. Ele deve ser ordenado, criar uma regra na inserção de novos contatos --> sempre ordenar o vetor de contatos para que a posiçao livre esteja sempre na ultima posicao, ordenar sempre por nome, pelo fato de ser mais natural uma agenda estar ordenada pelo nome 
//memcpy(&agenda->contato[i], &agenda->contato[(agenda->qnt_agenda)-1], sizeof(dados_t)); //void * memcpy ( void * destination, const void * source, size_t num );

*/

//DEFINIÇÕES
#define TAM_NOME 100
#define TAM_TWITTER 100
#define TAM_FACEBOOK 100
#define TAM_AGENDA 30

//DEFINIÇÕES (BETA) -> NÃO TESTADO!!!
#define eh_bissexto(ano) (( ano % 4 == 0 && ano % 100 != 0 ) || ano % 400 == 0 ? 1 :0) //macro para ver se é ano bissexto
#define agenda_cheia(agenda) (agenda->qnt_agenda >= TAM_AGENDA ? 1 : 0) //macro para ver se a agenda esta cheia
#define agenda_vazia(agenda) (agenda->qnt_agenda <= 0 ? 1 : 0)

//ESTRUTURAS
//agenda vai ser um vetor de contato
typedef struct dados
{
	char nome[TAM_NOME];
	int dia;
	int mes;
	int ano;
	int celular;
	char twitter[TAM_TWITTER];
	char facebook[TAM_FACEBOOK];
} dados_t;

typedef struct agenda
{
	dados_t contato[TAM_AGENDA];
	int qnt_agenda;
} agenda_t;

typedef struct aagenda
{
	dados_t contato[1];
} aux_agenda_t;

//PROTÓTIPOS DE FUNÇÕES
void agenda_inicializa(agenda_t *agenda);
void cadastra_nome(agenda_t *agenda);
void cadastra_aniversario(agenda_t *agenda);
void cadastra_celular(agenda_t *agenda);
void cadastra_contato(agenda_t *agenda);
void cadastra_twitter(agenda_t *agenda);
void cadastra_facebook(agenda_t *agenda);

void excluir_pelo_nome(agenda_t *agenda, char *nome);
void alterar_pelo_nome(agenda_t *agenda, char *nome);
void consulta_aniversario_dia_mes(agenda_t *agenda, int c_dia, int c_mes);
void consulta_aniversario_mes(agenda_t *agenda, int c_mes);
void consulta_aniversario_letra_nome(agenda_t *agenda, char letra);
void mostra_agenda_ordenada_nome(agenda_t *agenda);
void mostra_agenda_ordenada_mes(agenda_t *agenda);
void ordenacao_insercao_nome(agenda_t *agenda);
void ordenacao_insercao_mes(agenda_t *agenda);

int main (void)
{
	int opcao; //variavel utilizada no switch case
	agenda_t *agenda=(agenda_t *)malloc(sizeof(agenda_t)); //inicialização da estrutura agenda
	
	//Trecho a seguir testa para ver se a alocação foi bem sucedida, garante pré-condições de muitas funções
	if (agenda == NULL) { 
		printf( "ERRO ALOCAÇÃO MEMÓRIA PARA ESTRUTURA AGENDA\n");
		exit(-1);
	}
	agenda_inicializa(agenda);
//teste	agenda->qnt_agenda=30;
	setbuf(stdin,NULL); //limpa o buffer do stdin para não ter nenhuma sujeira no teclado
	
	FILE *fagenda;
	if((fagenda = fopen("agenda.txt","wr+")) == NULL)
	    {
		printf("Erro na leitura da agenda.\n");
		exit(-1);
	    }
	printf("agenda criada\n");
	
	while(1) //loop infinito no main para sempre cair no menu abaixo, a nãõ ser que o usuário insira 9 para SAIR
	{
		printf("Digite: \n1-Cadastro de contato\n2-Excluir contato a partir do nome.\n3-Alterar dados do contato a partir do nome\n4-Consultar aniversariantes pelo dia e mês\n5-Consultar aniversariantes pelo mês\n6-Consultar aniversariantes pela letra inicial do nome.\n7-Mostra agenda ordenada pelo nome\n8-Mostra agenda ordenada por mês.\n9-Para SAIR\n");
		scanf("%d",&opcao);
		switch (opcao)
		{
			case 1: //Cadastro de contato
			{
				cadastra_contato(agenda);
				break;
			}
			case 2: //Excluir contato a partir do nome
			{
				if(agenda_vazia(agenda)) //teste para verificar se a agenda esta vazia. Para que não precise acessar a função e volte ao menu.
				{
					printf("AGENDA VAZIA.\n");
					break;
				}
				char nome[TAM_NOME];
				printf("Digite o nome do contato para excluir:\n");
				setbuf(stdin,NULL); //limpa o buffer do stdin para não ter nenhuma sujeira no teclado	
				fgets(nome, TAM_NOME, stdin);				
				excluir_pelo_nome(agenda,nome);
				break;
			}
			case 3: //Alterar dados do contato a partir do nome
			{
				if(agenda_vazia(agenda)) //teste para verificar se a agenda esta vazia. Para que não precise acessar a função e volte ao menu.
				{
					printf("AGENDA VAZIA.\n");
					break;
				}
				char nome[TAM_NOME];
				printf("Digite o nome do contato para editar:\n");
				setbuf(stdin,NULL); //limpa o buffer do stdin para não ter nenhuma sujeira no teclado	
				fgets(nome, TAM_NOME, stdin);				
				alterar_pelo_nome(agenda,nome);
				break;
			}
			case 4: //Consultar aniversariantes pelo dia e mês
			{
				if(agenda_vazia(agenda)) //teste para verificar se a agenda esta vazia. Para que não precise acessar a função e volte ao menu.
				{
					printf("AGENDA VAZIA.\n");
					break;
				}
				int c_dia, c_mes;
				printf("Consulta contato por dia/mês:\n");
				scanf("%d/%d",&c_dia,&c_mes);
				consulta_aniversario_dia_mes(agenda,c_dia,c_mes);
				break;
			}
			case 5: //Consultar aniversariantes pelo mês
			{
				if(agenda_vazia(agenda)) //teste para verificar se a agenda esta vazia. Para que não precise acessar a função e volte ao menu.
				{
					printf("AGENDA VAZIA.\n");
					break;
				}
				int c_mes;
				printf("Consulta contato por mês:\n");
				scanf("%d",&c_mes);
				while(c_mes < 1 || c_mes > 12)
				{
					printf("Digite um valor de mês válido, 1 a 12:\n");
					scanf("%d", &c_mes);
				}
				consulta_aniversario_mes(agenda,c_mes);
				break;
			}
			case 6: //Consultar aniversariantes pela letra inicial do nome
			{
				if(agenda_vazia(agenda)) //teste para verificar se a agenda esta vazia. Para que não precise acessar a função e volte ao menu.
				{
					printf("AGENDA VAZIA.\n");
					break;
				}
				char letra;
				printf("Consulta aniversariantes pela letra do nome:\n");
				scanf(" %c",&letra);
				consulta_aniversario_letra_nome(agenda, letra);
				break;
			}
			case 7: //mostra agenda ordenada pelo nome
			{
				if(agenda_vazia(agenda)) //teste para verificar se a agenda esta vazia. Para que não precise acessar a função e volte ao menu.
				{
					printf("AGENDA VAZIA.\n");
					break;
				}
				mostra_agenda_ordenada_nome(agenda);		
				break;
			}
			case 8: //mostra agenda ordenada pelo mes
			{
				if(agenda_vazia(agenda)) //teste para verificar se a agenda esta vazia. Para que não precise acessar a função e volte ao menu.
				{
					printf("AGENDA VAZIA.\n");
					break;
				}
				mostra_agenda_ordenada_mes(agenda);
				break;
			}
			case 9:
			{
				exit(-1);
			}			
			default: //imprime toda a agenda
			{
				int i;
				for(i=0; i < agenda->qnt_agenda;i++) //varre todo o vetor de contatos da agenda, que contém a estrutura de dados do contato em cada posiçao do vetor 
				{
					printf("Contato: %s\n",agenda->contato[i].nome);
					printf("Aniversario: %2d/%2d/%4d\n",agenda->contato[i].dia, agenda->contato[i].mes, agenda->contato[i].ano);
					printf("Celular: %d\n",agenda->contato[i].celular);
					printf("Twitter: %s\n",agenda->contato[i].twitter);
					printf("Facebook: %s\n",agenda->contato[i].facebook);
					printf("\n");
				}
				printf("Quantidade de contatos cadastrados: %d\n", agenda->qnt_agenda);
				break;
			}

		}
	}	
	return 0;
}
//IMPLEMENTAÇÕES DAS FUNÇÕES

//AGENDA INICIALIZA
//parametro de entrada: estrutura agenda
//pre condicoes: agenda já ter sido alocada na memória
//pos condicoes: inicializa a quantidade de contatos na agenda em 0, todos os dados dos contatos da agenda inicializam com 0
void agenda_inicializa(agenda_t *agenda)
{
	int i; //variavel auxiliar para o laço for	
	agenda->qnt_agenda=0; //inicializa posicao em 0
	for(i=0;i < TAM_AGENDA; i++) //varre todos os contatos da agenda e seta com 0
	{ 
		memset(&agenda->contato[i],0,sizeof(dados_t));
	}
}

//Para garantir que os novos cadastros sejam feitos na última posição do vetor contatos, é necessário ordenar
//CADASTRA CONTATO
//parametro de entrada: estrutura agenda
//pre condicoes: agenda nao estar cheia, agenda criada, agenda ordenada
//pos condicoes: contato cadastrado na agenda, quantidade de contatos incrementado, agenda ordenada com o novo contato 
void cadastra_contato(agenda_t *agenda)
{
	if (agenda == NULL)
	{
		printf("AGENDA NÃO FOI CRIADA CORRETAMENTE.\n");
		return;	
	}

	if (agenda->qnt_agenda >= TAM_AGENDA)
	{
		printf("NÃO HÁ MAIS ESPAÇO NA AGENDA.\n");
		return;	
	}

	ordenacao_insercao_nome(agenda);
	cadastra_nome(agenda);
	cadastra_aniversario(agenda);
	cadastra_celular(agenda);
	cadastra_twitter(agenda);
	cadastra_facebook(agenda);
	agenda->qnt_agenda++; //quantidade total de contatos incrementado
	ordenacao_insercao_nome(agenda);
}
//-----------------------------------------------------------------------
//As funções deste bloco são acessadas somente pela função 'CADASTRA CONTATO'
//É feito um único teste se a agenda foi criada (!=NULL) ou se a agenda chegou ao seu limite (qnt >=TAM_AGENDA) dentro da função 'CADASTRA CONTATO'
//Implementar os mesmos trechos de teste nesse bloco estaria sendo redundante
//Para cadastrar novos contatos, é necessario que a agenda seja ordenada, garantindo sempre que a ultima posição (agenda->qnt_agenda) esteja disponivel para um novo cadastro
 
//CADASTRA NOME
//parametro de entrada: estrutura agenda
//pre condicoes: agenda criada, agenda estar ordenada
//pos condicoes: nome cadastrado no contato
void cadastra_nome(agenda_t *agenda)
{
	setbuf(stdin,NULL); //limpa o buffer do stdin para não ter nenhuma sujeira no teclado
	printf("Digite o nome do contato: ");
	fgets(agenda->contato[agenda->qnt_agenda].nome, TAM_NOME, stdin);
}

//CADASTRA DATA ANIVERSÁRIO
//parametro de entrada: estrutura agenda
//pre condicoes: agenda criada
//pos condicoes: dia cadastrado no contato
void cadastra_aniversario(agenda_t *agenda)
{
	printf("Digite a data de aniversário do contato (dd/mm/aaaa): ");
	scanf("%d/%d/%d",&agenda->contato[agenda->qnt_agenda].dia, &agenda->contato[agenda->qnt_agenda].mes, &agenda->contato[agenda->qnt_agenda].ano);
	
	//caso o ano for bissexto, o usuário pode inserir datas até dia 29/02
	if(eh_bissexto(agenda->contato[agenda->qnt_agenda].ano) == 1)
	{
		if(agenda->contato[agenda->qnt_agenda].mes == 2 ) // se o mês é fevereiro, a data limite é 29 e não mais 31
		{
			while(agenda->contato[agenda->qnt_agenda].dia < 0 || agenda->contato[agenda->qnt_agenda].dia > 29)
			{
				printf("É ano bissexto. Fevereiro pode ir até 29º dia. Digite novamente (dd/mm/aaaa): ");
				scanf("%d/%d/%d", &agenda->contato[agenda->qnt_agenda].dia, &agenda->contato[agenda->qnt_agenda].mes, &agenda->contato[agenda->qnt_agenda].ano);
			}
		}

	}
	//caso não for ano bissexto, o usuário só pode inserir datas até dia 28/02
	else
	{ 
		if(agenda->contato[agenda->qnt_agenda].mes == 2 ) // se o mês é fevereiro, a data limite é 28 e não mais 29
		{
			while(agenda->contato[agenda->qnt_agenda].dia < 0 || agenda->contato[agenda->qnt_agenda].dia > 28) 
			{
				printf("Não é ano bissexto. Fevereiro pode ir até 28º dia. Digite novamente (dd/mm/aaaa): ");
				scanf("%d/%d/%d", &agenda->contato[agenda->qnt_agenda].dia, &agenda->contato[agenda->qnt_agenda].mes, &agenda->contato[agenda->qnt_agenda].ano);
			}
		}
	}
	while(agenda->contato[agenda->qnt_agenda].dia < 0 || agenda->contato[agenda->qnt_agenda].dia > 31 || agenda->contato[agenda->qnt_agenda].mes <0 || agenda->contato[agenda->qnt_agenda].mes > 12)
	{
		printf("Data inválida. Digite novamente (dd/mm/aaaa): ");
		scanf("%d/%d/%d", &agenda->contato[agenda->qnt_agenda].dia, &agenda->contato[agenda->qnt_agenda].mes, &agenda->contato[agenda->qnt_agenda].ano);
	}
}

//CADASTRA CELULAR
//parametro de entrada: estrutura agenda
//pre condicoes: agenda criada
//pos condicoes: celular cadastrado no contato
void cadastra_celular(agenda_t *agenda)
{
	printf("Digite o celular do contato: ");
	scanf("%d", &agenda->contato[agenda->qnt_agenda].celular);
}

//CADASTRA TWITTER
//parametro de entrada: estrutura agenda
//pre condicoes: agenda criada
//pos condicoes: endereço twitter cadastrado no contato
void cadastra_twitter(agenda_t *agenda)
{
	setbuf(stdin,NULL); //limpa o buffer do stdin para não ter nenhuma sujeira no teclado	
	printf("Digite twitter do contato: @");
	fgets(agenda->contato[agenda->qnt_agenda].twitter, TAM_NOME, stdin);
}

//CADASTRA FACEBOOK
//parametro de entrada: estrutura agenda
//pre condicoes: agenda criada
//pos condicoes: endereço facebook cadastrado no contato
void cadastra_facebook(agenda_t *agenda)
{
	setbuf(stdin,NULL); //limpa o buffer do stdin para não ter nenhuma sujeira no teclado		
	printf("Digite o facebook do contato: https://www.facebook.com/");
	fgets(agenda->contato[agenda->qnt_agenda].facebook, TAM_NOME, stdin);
}
//-----------------------------------------------------------------------

//EXCLUIR PELO NOME
//parametro de entrada: estrutura agenda, nome do contato a ser excluido
//pre condicoes: agenda criada e agenda nao estar vazia
//pos condicoes: contato excluido, quantidade de contatos decrementado se encontrar o nome e agenda ordenada apos a exclusao
void excluir_pelo_nome(agenda_t *agenda, char *nome)
{
	int i,aux=0; //variavel 'i' auxiliar para o laço for. Variavel 'aux' para teste se caiu ao menos uma vez no teste do if
	for(i=0; i < agenda->qnt_agenda;i++)
	{
		if(strcmp(nome,agenda->contato[i].nome) == 0) //funcao compara o nome informado pelo usuario e os contidos na estrutura
		{
			aux=1;
			memset(&agenda->contato[i],0,sizeof(dados_t)); //seta memoria dos dados em zero
			agenda->qnt_agenda--;
			//ordenacao_insercao_nome(agenda);
		}
	}
	if(aux==0)
	{
		printf("Não existe este contato!\n");
	}
			
}
//ALTERAR PELO NOME
//parametro de entrada: estrutura agenda, nome do contato a ser editado
//pre condicoes: agenda nao estar vazia
//pos condicoes: dado do contato alterado com sucesso
void alterar_pelo_nome(agenda_t *agenda, char *nome)
{
	int i, opcao_fn_alterar, aux=0; //variavel 'i' auxiliar para o laço for. 'opcao_fn_alterar' para switch case. Variavel 'aux' para teste se caiu ao menos uma vez no teste do if
	for(i=0; i < agenda->qnt_agenda;i++) //varre todo o vetor de contatos da agenda, que contém a estrutura de dados do contato em cada posiçao do vetor 
	{
		if(strcmp(nome,agenda->contato[i].nome) == 0) //funcao compara o nome informado pelo usuario e os contidos na estrutura
		{
			aux=1;
			printf("Escolha o que você deseja alterar: \n1-Nome\n2-Dia\n3-Mês\n4-Ano\n5-Celular\n6-Twitter\n7-Facebook\n"); //opções do menu alterar_pelo_nome
			scanf("%d",&opcao_fn_alterar);
			switch(opcao_fn_alterar)
			{
				case 1: 
				{
					printf("Edite o nome :\n");
					scanf("%s",agenda->contato[i].nome);
					printf("Nome editado com sucesso.\n");
					return;
				}
				case 2:
				{
					printf("Edite o dia:\n");
					scanf("%d",&agenda->contato[i].dia);
					printf("Dia editado com sucesso.\n");
					return;
				}
				case 3:
				{
					printf("Edite o mês:\n");
					scanf("%d",&agenda->contato[i].mes);
					printf("Mês editado com sucesso.\n");
					return;
				}			
				case 4:
				{
					printf("Edite o ano:\n");
					scanf("%d",&agenda->contato[i].ano);
					printf("Ano editado com sucesso.\n");
					return;
				}				
				case 5:
				{
					printf("Edite o celular:\n");
					scanf("%d", &agenda->contato[i].celular);
					printf("Celular editado com sucesso.\n");
					return;
				}
				case 6:
				{
					printf("Edite o twitter:\n");
					scanf("%s",agenda->contato[i].twitter);
					printf("Twitter editado com sucesso.\n");
					return;
				}
				case 7:
				{
					printf("Edite o facebook:\n");
					scanf("%s",agenda->contato[i].facebook);
					printf("Facebook editado com sucesso.\n");
					return;
				}

			}
		}
	}
	if(aux==0)
	{
		printf("Não existe este contato!!\n\n");
	}
	return;
}

//CONSULTA ANIVERSARIANTE POR DIA E MES
//parametro de entrada: estrutura agenda, dia e mes a ser pesquisado dentro da estrutura agenda
//pre condicoes: agenda criada e nao estar vazia, data e mes validas d(1-31) e m(1,12)
//pos condicoes: imprime os contatos que tenham o dia e mes ou então imprime que não existem ninguém com essa data
void consulta_aniversario_dia_mes(agenda_t *agenda, int c_dia, int c_mes)
{
	int i, aux=0; //variavel 'i' auxiliar para o laço for. Variavel 'aux' para teste se caiu ao menos uma vez no teste do if
	for(i=0; i < agenda->qnt_agenda;i++) //varre todo o vetor de contatos da agenda, que contém a estrutura de dados do contato em cada posiçao do vetor
	{
		if(c_dia==agenda->contato[i].dia && c_mes==agenda->contato[i].mes) //funcao compara se tanto o dia quanto o mes batem com o de algum contato da agenda
		{
			aux=1;
			printf("Encontrado aniversariante: \n");
			printf("Contato: %s",agenda->contato[i].nome);
			printf("Aniversario: %2d/%2d/%4d\n",agenda->contato[i].dia, agenda->contato[i].mes, agenda->contato[i].ano);
			printf("Celular: %d\n",agenda->contato[i].celular);
			printf("Twitter: %s",agenda->contato[i].twitter);
			printf("Facebook: %s",agenda->contato[i].facebook);
			printf("\n");
		}
	}
	if(aux==0)
	{
		printf("Não existe contato cadastrado com a data de aniversário: %d/%d\n\n",c_dia,c_mes);
	}
	return;
}

//CONSULTA ANIVERSARIANTE POR MES
//parametro de entrada: estrutura agenda e mes a ser pesquisado dentro da estrutura agenda
//pre condicoes: agenda criada e nao estar vazia, o mes ser possivel (1-12)
//pos condicoes: imprime os contatos que fazem o aniversario no mes requisitado pelo usuario ou então imprime que não existem ninguém
void consulta_aniversario_mes(agenda_t *agenda, int c_mes)
{
	int i, aux=0; //variavel 'i' auxiliar para o laço for. Variavel 'aux' para teste se caiu ao menos uma vez no teste do if
	for(i=0; i < agenda->qnt_agenda;i++) //varre todo o vetor de contatos da agenda, que contém a estrutura de dados do contato em cada posiçao do vetor
	{
		if(c_mes==agenda->contato[i].mes) //funcao compara se tem algum contato da agenda que faz aniversario no mes requisitado pelo usuario
		{
			if(aux==0)
			{
				printf("Aniversariantes no mês %d: \n", c_mes);
			}
			aux=1;
			printf("Contato: %s",agenda->contato[i].nome);
			printf("Aniversario: %2d/%2d/%4d\n",agenda->contato[i].dia, agenda->contato[i].mes, agenda->contato[i].ano);
			printf("Celular: %d\n",agenda->contato[i].celular);
			printf("Twitter: %s",agenda->contato[i].twitter);
			printf("Facebook: %s",agenda->contato[i].facebook);
			printf("\n");
		}
	}
	if(aux==0)
	{
		printf("Não existe nenhum contato cadastrado no mês %d\n\n",c_mes);
	}
	return;
}

//CONSULTA ANIVERSARIANTES PELA LETRA INICIAL DO NOME
//parametro de entrada: estrutura agenda e letra
//pre condicoes: agenda criada e nao estar vazia
//pos condicoes: imprime o nome e aniversario dos contatos que tenham o nome que comecem com a letra ou imprime que nao foi encontrado nenhum usuario
void consulta_aniversario_letra_nome(agenda_t *agenda, char letra)
{
	int i, aux=0;
	for (i = 0; i < agenda->qnt_agenda; i++)
	{
		if(agenda->contato[i].nome[0] == letra) //se a comparacao da primeira letra do nome for igual ao do parametro letra
		{
			aux=1;
			printf("Contato: %s",agenda->contato[i].nome);
			printf("Aniversario: %2d/%2d/%4d\n",agenda->contato[i].dia, agenda->contato[i].mes, agenda->contato[i].ano);
			printf("\n");
		}
	}
	if(aux==0)
	{
		printf("Não existe nenhum contato que comece com %c\n",letra);
	}
}

//MOSTRA AGENDA ORDENADA PELO NOME
//parametro de entrada: estrutura agenda
//pre condicoes: agenda criada e nao estar vazia
//pos condicoes: imprime os contatos ordenados em ordem alfabética por nome
void mostra_agenda_ordenada_nome(agenda_t *agenda)
{
	int i;	
	ordenacao_insercao_nome(agenda); //ordena pelo metodo de insercao
	for (i = 0; i < agenda->qnt_agenda; i++)
	{
		//pelo memset sabemos que o celular fica com valor 0
		if(agenda->contato[i].celular == 0)
		{
			continue;
		}
		printf("Contato: %s\n",agenda->contato[i].nome);
		printf("Aniversario: %2d/%2d/%4d\n",agenda->contato[i].dia, agenda->contato[i].mes, agenda->contato[i].ano);
		printf("Celular: %d\n",agenda->contato[i].celular);
		printf("Twitter: %s\n",agenda->contato[i].twitter);
		printf("Facebook: %s\n",agenda->contato[i].facebook);
		printf("\n");
	}
}

//MOSTRA AGENDA ORDENADA PELO MES
//parametro de entrada: estrutura agenda
//pre condicoes: agenda criada e nao estar vazia
//pos condicoes: imprime os contatos ordenados ordenados pelo mes do aniversario
void mostra_agenda_ordenada_mes(agenda_t *agenda)
{
	int i;	
	ordenacao_insercao_mes(agenda); //ordena pelo metodo de insercao
	for (i = 0; i < agenda->qnt_agenda; i++)
	{
		//pelo memset sabemos que o celular fica com valor 0
		if(agenda->contato[i].celular == 0)
		{
			continue;
		}
		printf("Contato: %s\n",agenda->contato[i].nome);
		printf("Aniversario: %2d/%2d/%4d\n",agenda->contato[i].dia, agenda->contato[i].mes, agenda->contato[i].ano);
		printf("Celular: %d\n",agenda->contato[i].celular);
		printf("Twitter: %s\n",agenda->contato[i].twitter);
		printf("Facebook: %s\n",agenda->contato[i].facebook);
		printf("\n");
	}
}

//ORDENAÇÃO POR INSERÇÃO->NOMES
//parametro de entrada: estrutura agenda
//pre condicoes: agenda criada e nao estar vazia
//pos condicoes: ordena a agenda passada como parametro por nome
void ordenacao_insercao_nome(agenda_t *agenda) 
{
	int i, j;
	aux_agenda_t *agenda1contato = (aux_agenda_t *)malloc(sizeof(aux_agenda_t)); //inicializa estrutura agenda com apenas um contato, a ser utilizada pelo algoritmo abaixo como pivo
	
	for (i = 1; i < agenda->qnt_agenda; i++) //varre todos os elementos do parametro agenda da função ordenacao_insercao
	{
		agenda1contato->contato[0] = agenda->contato[i]; //agenda1contato (pivo) recebe o contato[i], ou seja, começa na 2ª posição
		j = i - 1; //j sempre recebe o valor anterior
		while ((j>=0) && strcmp(agenda1contato->contato[0].nome, agenda->contato[j].nome)<0)//((agenda1contato->contato[0]) < (agenda->contato[j])))
		{
			agenda->contato[j+1] = agenda->contato[j];
			j--;
		}
		agenda->contato[j+1] = agenda1contato->contato[0];
	}
 	return;
	//liberar moemoria agenda1contato
}

//ORDENAÇÃO POR INSERÇÃO->MÊS
//parametro de entrada: estrutura agenda
//pre condicoes: agenda criada e nao estar vazia
//pos condicoes: ordena a agenda passada como parametro por mês
void ordenacao_insercao_mes(agenda_t *agenda) 
{
	int i, j;
	aux_agenda_t *agenda1contato = (aux_agenda_t *)malloc(sizeof(aux_agenda_t)); //inicializa estrutura agenda com apenas um contato, a ser utilizada pelo algoritmo abaixo como pivo
	
	for (i = 1; i < agenda->qnt_agenda; i++) //varre todos os elementos do parametro agenda da função ordenacao_insercao
	{
		agenda1contato->contato[0] = agenda->contato[i]; //agenda1contato (pivo) recebe o contato[i], ou seja, começa na 2ª posição
		j = i - 1; //j sempre recebe o valor anterior
		while ((j>=0) && agenda1contato->contato[0].mes < agenda->contato[j].mes)
		{
			agenda->contato[j+1] = agenda->contato[j];
			j--;
		}
		agenda->contato[j+1] = agenda1contato->contato[0];
	}
	return;
	//liberar moemoria agenda1contato
}

//implementei mas acho que não vai ser utilizado
void troca_dados_contatos(agenda_t *agenda, int pos_contato1, int pos_contato2)
{
	/*
	dados_t *aux_dado=(dados_t *)malloc(sizeof(dados_t)); //inicialização da estrutura dados para fazer o backup e trocar os dados
	
	aux_dado.nome = agenda->contato[pos_contato1].nome;
	aux_dado.dia = agenda->contato[pos_contato1].dia;
	aux_dado.mes = agenda->contato[pos_contato1].mes;
	aux_dado.ano = agenda->contato[pos_contato1].ano;
	aux_dado.celular = agenda->contato[pos_contato1].celular;
	aux_dado.twitter = agenda->contato[pos_contato1].twitter;
	aux_dado.facebook = agenda->contato[pos_contato1].facebook;
	
	agenda->contato[pos_contato1].nome = agenda->contato[pos_contato2].nome;
	agenda->contato[pos_contato1].dia = agenda->contato[pos_contato2].dia;
	agenda->contato[pos_contato1].mes = agenda->contato[pos_contato2].mes;
	agenda->contato[pos_contato1].ano = agenda->contato[pos_contato2].ano;
	agenda->contato[pos_contato1].celular = agenda->contato[pos_contato2].celular;
	agenda->contato[pos_contato1].twitter = agenda->contato[pos_contato2].twitter;
	agenda->contato[pos_contato1].facebook = agenda->contato[pos_contato2].facebook;

	agenda->contato[pos_contato2].nome = aux_dado.nome;
	agenda->contato[pos_contato2].dia = aux_dado.dia;
	agenda->contato[pos_contato2].mes = aux_dado.mes;
	agenda->contato[pos_contato2].ano = aux_dado.ano;
	agenda->contato[pos_contato2].celular = aux_dado.celular;
	agenda->contato[pos_contato2].twitter = aux_dado.twitter;
	agenda->contato[pos_contato2].facebook = aux_dado.facebook;
	*/

	aux_agenda_t *aux_agenda=(aux_agenda_t *)malloc(sizeof(aux_agenda_t)); //inicialização da estrutura dados 'agenda auxiliar' para fazer o backup e troca de dados
	aux_agenda->contato[0] = agenda->contato[pos_contato1];
	agenda->contato[pos_contato1] = agenda->contato[pos_contato2];	
	agenda->contato[pos_contato2] = aux_agenda->contato[0];

	//liberar memoria aux_agenda
}
