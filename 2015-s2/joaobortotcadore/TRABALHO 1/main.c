#include <stdio.h>      /* printf, scanf, puts */
#include <stdlib.h>     /* realloc, free, exit, NULL */
#include <string.h>	/* strcmp */


/*BUGS E ANOTAÇOES
-Função cadastra nome, não pega string com espaço usar //fgets(agenda->contato[agenda->qnt_agenda].nome, TAM_NOME, stdin);
-Vai ter problema nessa condiçãõ : tiver 2 ou mais contatos, excluir o primeiro, e entãõ adicionar um outro contato, pois quem esta cuidando a posição do vetor do contato é a variavel qnt_agenda. Ao excluir a qnt_agenda vai para 1, e ao adicionar novo contato, ele vai sobreescrever o contato na posiçao 2 do vetor contato (contato[1]). Implementar uma função que retorne a posiçãõ do vetor contato livre para adicionar um contato
-no caso de (contato 1, contato 2, ..) parece que a função excluir libera toda a memoria se excluir contato 1. Quem sabe solucione se copiar os dados do ultimo contato adicionado na agenda e sobreescrever o que se deseja excluir
-ver como limpar a tela depois de escolher o menu
-falta função pra ver se o ano é bissexto, para o cadastro de aniversario
-implementar o agenda inicializa
-implementar pre condições de agenda nao vazia para as funções
-implementar verificaçãõ se a agenda esta criada para pre condições de cadastro
*/

//DEFINIÇÕES
#define TAM_NOME 100
#define TAM_TWITTER 100
#define TAM_FACEBOOK 100
#define TAM_AGENDA 30

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

//PROTÓTIPOS DE FUNÇÕES
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

int main (void)
{
	int opcao; //variavel utilizada no switch case

	FILE *fagenda;
	if((fagenda = fopen("agenda.txt","wr+")) == NULL)
	    {
		printf("Erro na leitura da agenda.");
		exit(-1);
	    }
	printf("agenda criada\n");

	//implementar esse trecho em um agenda_inicializa
	agenda_t *agenda=(agenda_t *)malloc(sizeof(agenda_t)); //inicialização da estrutura agenda
	agenda->qnt_agenda=0; //inicializa posicao em 0
	
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
				char nome[TAM_NOME];
				printf("Digite o nome do contato para excluir:\n");
				scanf("%s",nome);
				excluir_pelo_nome(agenda,nome);
				break;
			}
			case 3: //Alterar dados do contato a partir do nome
			{
				char nome[TAM_NOME];
				printf("Digite o nome do contato para editar:\n");
				scanf("%s",nome);
				alterar_pelo_nome(agenda,nome);	
				break;
			}
			case 4: //Consultar aniversariantes pelo dia e mês
			{
				int c_dia, c_mes;
				printf("Consulta contato por dia/mês:\n");
				scanf("%d/%d",&c_dia,&c_mes);
				consulta_aniversario_dia_mes(agenda,c_dia,c_mes);
				break;
			}
			case 5: //Consultar aniversariantes pelo mês
			{
				int c_mes;
				printf("Consulta contato por mês:\n");
				scanf("%d",&c_mes);
				consulta_aniversario_mes(agenda,c_mes);
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
					printf("\n\n");
				}
				break;
			}

		}
	}	
	return 0;
}

/*
*/

//IMPLEMENTAÇÕES DAS FUNÇÕES

//CADASTRA CONTATO
//parametro de entrada: estrutura agenda
//pre condicoes: agenda nao estar cheia e agenda criada
//pos condicoes: contato cadastrado na agenda, quantidade de contatos incrementado 
void cadastra_contato(agenda_t *agenda)
{
	cadastra_nome(agenda);
	cadastra_aniversario(agenda);
	cadastra_celular(agenda);
	cadastra_twitter(agenda);
	cadastra_facebook(agenda);
	agenda->qnt_agenda++;
}

//CADASTRA NOME
//parametro de entrada: estrutura agenda
//pre condicoes: agenda criada
//pos condicoes: nome cadastrado no contato
void cadastra_nome(agenda_t *agenda)
{
	printf("Digite o nome do contato:");
	//fgets(agenda->contato[agenda->qnt_agenda].nome, TAM_NOME, stdin); //função com bug
	//scanf("%*[^\n]%*c");
	scanf("%s",agenda->contato[agenda->qnt_agenda].nome); //buffer overflow
	scanf("%*[^\n]");  // verifica se sobrou uma nova linha
	scanf("%*c"); //descarta a nova linha 
	
}

//CADASTRA DATA ANIVERSÁRIO
//parametro de entrada: estrutura agenda
//pre condicoes: agenda criada
//pos condicoes: dia cadastrado no contato
void cadastra_aniversario(agenda_t *agenda)
{
	printf("Digite a data de aniversário do contato (dd/mm/aaaa): ");
	scanf("%d/%d/%d",&agenda->contato[agenda->qnt_agenda].dia, &agenda->contato[agenda->qnt_agenda].mes, &agenda->contato[agenda->qnt_agenda].ano);
	scanf("%*[^\n]");  // verifica se sobrou uma nova linha
	scanf("%*c"); //descarta a nova linha 
	while(agenda->contato[agenda->qnt_agenda].dia < 0 || agenda->contato[agenda->qnt_agenda].dia > 31 || agenda->contato[agenda->qnt_agenda].mes <0 || agenda->contato[agenda->qnt_agenda].mes > 12) // falta função pra ver se o ano é bissexto
	{
		printf("Data inválida. Digite novamente (dd/mm/aaaa): ");
		scanf("%d/%d/%d", &agenda->contato[agenda->qnt_agenda].dia, &agenda->contato[agenda->qnt_agenda].mes, &agenda->contato[agenda->qnt_agenda].ano);
		scanf("%*[^\n]");  // verifica se sobrou uma nova linha
		scanf("%*c"); //descarta a nova linha 
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
	scanf("%*[^\n]");  // verifica se sobrou uma nova linha
	scanf("%*c"); //descarta a nova linha 
}

//CADASTRA TWITTER
//parametro de entrada: estrutura agenda
//pre condicoes: agenda criada
//pos condicoes: endereço twitter cadastrado no contato
void cadastra_twitter(agenda_t *agenda)
{
	printf("Digite twitter do contato: ");
	scanf("%s",agenda->contato[agenda->qnt_agenda].twitter);
	scanf("%*[^\n]");  // verifica se sobrou uma nova linha
	scanf("%*c"); //descarta a nova linha 
	
}

//CADASTRA FACEBOOK
//parametro de entrada: estrutura agenda
//pre condicoes: agenda criada
//pos condicoes: endereço facebook cadastrado no contato
void cadastra_facebook(agenda_t *agenda)
{
	printf("Digite o facebook do contato: ");
	scanf("%s",agenda->contato[agenda->qnt_agenda].facebook);
	scanf("%*[^\n]");  // verifica se sobrou uma nova linha
	scanf("%*c"); //descarta a nova linha 
	
}

//EXCLUIR PELO NOME
//parametro de entrada: estrutura agenda, nome do contato a ser excluido
//pre condicoes: agenda nao estar vazia
//pos condicoes: contato excluido e quantidade de contatos decrementado se encontrar o nome
void excluir_pelo_nome(agenda_t *agenda, char *nome)
{
	int i,aux=0; //variavel 'i' auxiliar para o laço for. Variavel 'aux' para teste se caiu ao menos uma vez no teste do if
	for(i=0; i < agenda->qnt_agenda;i++)
	{
		if(strcmp(nome,agenda->contato[i].nome) == 0) //funcao compara o nome informado pelo usuario e os contidos na estrutura
		{
			aux=1;
			//remove o contato
			memset(&agenda->contato[i].nome, 0, sizeof(agenda->contato[i].nome)); //libera memoria do vetor
			agenda->contato[i].dia=0; //zera variavel
			agenda->contato[i].mes=0; //zera variavel
			agenda->contato[i].ano=0; //zera variavel
			agenda->contato[i].celular=0; //zera variavel
			memset(&agenda->contato[i].twitter, 0, sizeof(agenda->contato[i].twitter)); //libera memoria do vetor
			memset(&agenda->contato[i].facebook, 0, sizeof(agenda->contato[i].facebook)); //libera memoria do vetor
			agenda->qnt_agenda--; //decrementa em uma unidade a quantidade de contatos na agenda
		}
	}
	if(aux==0)
	{
		printf("Não existe este contato!\n\n");
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
//pre condicoes: agenda criada e nao estar vazia, data e mes validas (1-31)->(1,3-12), (1-28,29bissexto)->(2)
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
			printf("Contato: %s\n",agenda->contato[i].nome);
			printf("Aniversario: %2d/%2d/%4d\n",agenda->contato[i].dia, agenda->contato[i].mes, agenda->contato[i].ano);
			printf("Celular: %d\n",agenda->contato[i].celular);
			printf("Twitter: %s\n",agenda->contato[i].twitter);
			printf("Facebook: %s\n",agenda->contato[i].facebook);
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
			printf("Contato: %s\n",agenda->contato[i].nome);
			printf("Aniversario: %2d/%2d/%4d\n",agenda->contato[i].dia, agenda->contato[i].mes, agenda->contato[i].ano);
			printf("Celular: %d\n",agenda->contato[i].celular);
			printf("Twitter: %s\n",agenda->contato[i].twitter);
			printf("Facebook: %s\n",agenda->contato[i].facebook);
			printf("\n");
		}
	}
	if(aux==0)
	{
		printf("Não existe nenhum contato cadastrado no mês %d\n\n",c_mes);
	}
	return;
}
