#include <stdio.h>      /* printf, scanf, puts */
#include <stdlib.h>     /* realloc, free, exit, NULL */
#include <string.h>	/* strcmp */

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
	int pos_agenda;
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
	agenda->pos_agenda=0; //inicializa posicao em 0
	
	while(1) //loop infinito no main para sempre cair no menu abaixo, a nãõ ser que o usuário insira 9 para SAIR
	{
		printf("Digite: \n1-Cadastro de contato\n2-Excluir contato a partir do nome.\n3-Alterar dados do contato a partir do nome\n4-Consultar aniversariantes pelo dia e mês\n5-Consultar aniversariantes pelo mês\n6-Consultar aniversariantes pela letra inicial do nome.\n7-Mostra agenda ordenada pelo nome\n8-Mostra agenda ordenada por mês.\n9-Para SAIR\n");
		scanf("%d",&opcao);
		switch (opcao)
		{
			case 1:
			{
				cadastra_contato(agenda);
				break;
			}
			case 2:
			{
				char nome[TAM_NOME];
				printf("Digite o nome do contato para excluir:\n");
				scanf("%s",nome);
				excluir_pelo_nome(agenda,nome);
			}
			case 3:
			{
				printf("Digite o nome do contato para editar:\n");
				scanf("%s",nome);
				alterar_pelo_nome(agenda,nome);	
			}
			default:
			{
				//TESTES PARA CONFIRMAR
				printf("Contato cadastrado: %s\n",agenda->contato[agenda->pos_agenda-1].nome);
				printf("Aniversario cadastrado %2d/%2d/%4d\n",agenda->contato[agenda->pos_agenda-1].dia, agenda->contato[agenda->pos_agenda-1].mes, agenda->contato[agenda->pos_agenda-1].ano);
				printf("Celular cadastrado: %d\n",agenda->contato[agenda->pos_agenda-1].celular);
				printf("Twitter cadastrado: %s\n",agenda->contato[agenda->pos_agenda-1].twitter);
				printf("Facebook cadastrado: %s\n",agenda->contato[agenda->pos_agenda-1].facebook);
				printf("Quantidade de contatos cadastrados: %d\n", agenda->pos_agenda);
				fprintf(fagenda, "teste ok%d",agenda->pos_agenda);
				break;
			}
			case 9:
				exit(-1);

		}
	}	
	return 0;
}

/*
*/

//IMPLEMENTAÇÕES DAS FUNÇÕES

//CADASTRA CONTATO
//parametro de entrada: estrutura agenda
//pre condicoes: agenda nao estar cheia
//pos condicoes: contato cadastrado na agenda, quantidade de contatos incrementado 
void cadastra_contato(agenda_t *agenda)
{
	cadastra_nome(agenda);
	cadastra_aniversario(agenda);
	cadastra_celular(agenda);
	cadastra_twitter(agenda);
	cadastra_facebook(agenda);
	agenda->pos_agenda++;
}

//CADASTRA NOME
//parametro de entrada: estrutura agenda
//pre condicoes: agenda nao estar cheia
//pos condicoes: nome cadastrado no contato
void cadastra_nome(agenda_t *agenda)
{
	printf("Digite o nome do contato: ");
	scanf("%s",agenda->contato[agenda->pos_agenda].nome);
	scanf("%*[^\n]");  // verifica se sobrou uma nova linha
	scanf("%*c"); //descarta a nova linha 
	
}

//CADASTRA DATA ANIVERSÁRIO
//parametro de entrada: estrutura agenda
//pre condicoes: agenda nao estar cheia
//pos condicoes: dia cadastrado no contato
void cadastra_aniversario(agenda_t *agenda)
{
	printf("Digite a data de aniversário do contato (dd/mm/aaaa): ");
	scanf("%d/%d/%d",&agenda->contato[agenda->pos_agenda].dia, &agenda->contato[agenda->pos_agenda].mes, &agenda->contato[agenda->pos_agenda].ano);
	scanf("%*[^\n]");  // verifica se sobrou uma nova linha
	scanf("%*c"); //descarta a nova linha 
	while(agenda->contato[agenda->pos_agenda].dia < 0 || agenda->contato[agenda->pos_agenda].dia > 31 || agenda->contato[agenda->pos_agenda].mes <0 || agenda->contato[agenda->pos_agenda].mes > 12) // falta função pra ver se o ano é bissexto
	{
		printf("Data inválida. Digite novamente (dd/mm/aaaa): ");
		scanf("%d/%d/%d", &agenda->contato[agenda->pos_agenda].dia, &agenda->contato[agenda->pos_agenda].mes, &agenda->contato[agenda->pos_agenda].ano);
		scanf("%*[^\n]");  // verifica se sobrou uma nova linha
		scanf("%*c"); //descarta a nova linha 
	}
}

//CADASTRA CELULAR
//parametro de entrada: estrutura agenda
//pre condicoes: agenda nao estar cheia
//pos condicoes: celular cadastrado no contato
void cadastra_celular(agenda_t *agenda)
{
	printf("Digite o celular do contato: ");
	scanf("%d", &agenda->contato[agenda->pos_agenda].celular);
	scanf("%*[^\n]");  // verifica se sobrou uma nova linha
	scanf("%*c"); //descarta a nova linha 
}

//CADASTRA TWITTER
//parametro de entrada: estrutura agenda
//pre condicoes: agenda nao estar cheia
//pos condicoes: endereço twitter cadastrado no contato
void cadastra_twitter(agenda_t *agenda)
{
	printf("Digite twitter do contato: ");
	scanf("%s",agenda->contato[agenda->pos_agenda].twitter);
	scanf("%*[^\n]");  // verifica se sobrou uma nova linha
	scanf("%*c"); //descarta a nova linha 
	
}

//CADASTRA FACEBOOK
//parametro de entrada: estrutura agenda
//pre condicoes: agenda nao estar cheia
//pos condicoes: endereço facebook cadastrado no contato
void cadastra_facebook(agenda_t *agenda)
{
	printf("Digite o facebook do contato: ");
	scanf("%s",agenda->contato[agenda->pos_agenda].facebook);
	scanf("%*[^\n]");  // verifica se sobrou uma nova linha
	scanf("%*c"); //descarta a nova linha 
	
}

//EXCLUIR PELO NOME
//parametro de entrada: estrutura agenda, nome do contato a ser excluido
//pre condicoes: agenda nao estar vazia
//pos condicoes: contato excluido e quantidade de contatos decrementado se encontrar o nome
void excluir_pelo_nome(agenda_t *agenda, char *nome)
{
	int i;
	for(i=0; i < agenda->pos_agenda;i++)
	{
		if(strcmp(nome,agenda->contato[i].nome) == 0) //funcao compara o nome informado pelo usuario e os contidos na estrutura
		{
			//remove o contato
			memset(&agenda->contato[i].nome, 0, sizeof(agenda->contato[i].nome));
			agenda->contato[i].dia=0;
			agenda->contato[i].mes=0;
			agenda->contato[i].ano=0;
			agenda->contato[i].celular=0;
			memset(&agenda->contato[i].twitter, 0, sizeof(agenda->contato[i].twitter));
			memset(&agenda->contato[i].facebook, 0, sizeof(agenda->contato[i].facebook));
			agenda->pos_agenda--;
		}else{
			printf("Não existe este contato");
		}
	}		
}
//ALTERAR PELO NOME
//parametro de entrada: estrutura agenda, nome do contato a ser editado
//pre condicoes: agenda nao estar vazia
//pos condicoes: dado do contato alterado
void alterar_pelo_nome(agenda_t *agenda, char *nome)
{
	int i, opcao_fn_alterar;
	for(i=0; i < agenda->pos_agenda;i++)
	{
		if(strcmp(nome,agenda->contato[i].nome) == 0) //funcao compara o nome informado pelo usuario e os contidos na estrutura
		{
			printf("Digite o número para qual dos dados você deseja alterar: \n1-Nome\n2-Dia\n3-Mês\n4-Ano\n5-Celular\n6-Twitter\n7-Facebook\n");
			switch(opcao_fn_alterar)
			{
				case 1:
				{
					printf("Digite o novo nome:\n");
					scanf("%s",agenda->contato[agenda->pos_agenda].nome);
				}
				


			}
		}else{
			printf("Não existe este contato");
		}
	}	
}
