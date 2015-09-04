#include <stdio.h>      /* printf, scanf, puts */
#include <stdlib.h>     /* realloc, free, exit, NULL */
#include <string.h>	/* strcmp */
#include "tda_agenda_privado.h"

//implementacao das operacoes

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
	system("clear");
}

//CADASTRA NOME
//parametro de entrada: estrutura agenda
//pre condicoes: agenda criada
//pos condicoes: nome cadastrado no contato
void cadastra_nome(agenda_t *agenda)
{
	//system("clear");
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
	//system("clear");
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
	//system("clear");
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
	//system("clear");
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
	//system("clear");
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
	system("clear");
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
		printf("Não existe este contato!\n");
	}
			
}
//ALTERAR PELO NOME
//parametro de entrada: estrutura agenda, nome do contato a ser editado
//pre condicoes: agenda nao estar vazia
//pos condicoes: dado do contato alterado com sucesso
void alterar_pelo_nome(agenda_t *agenda, char *nome)
{
	system("clear");
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
					system("clear");
					printf("Edite o nome :\n");
					scanf("%s",agenda->contato[i].nome);
					printf("Nome editado com sucesso.\n");
					return;
				}
				case 2:
				{
					system("clear");
					printf("Edite o dia:\n");
					scanf("%d",&agenda->contato[i].dia);
					printf("Dia editado com sucesso.\n");
					return;
				}
				case 3:
				{
					system("clear");
					printf("Edite o mês:\n");
					scanf("%d",&agenda->contato[i].mes);
					printf("Mês editado com sucesso.\n");
					return;
				}			
				case 4:
				{
					system("clear");
					printf("Edite o ano:\n");
					scanf("%d",&agenda->contato[i].ano);
					printf("Ano editado com sucesso.\n");
					return;
				}				
				case 5:
				{
					system("clear");
					printf("Edite o celular:\n");
					scanf("%d", &agenda->contato[i].celular);
					printf("Celular editado com sucesso.\n");
					return;
				}
				case 6:
				{
					system("clear");
					printf("Edite o twitter:\n");
					scanf("%s",agenda->contato[i].twitter);
					printf("Twitter editado com sucesso.\n");
					return;
				}
				case 7:
				{
					system("clear");
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
	system("clear");
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
	system("clear");
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

//CONSULTA ANIVERSARIANTES PELA LETRA INICIAL DO NOME
//parametro de entrada: estrutura agenda e letra
//pre condicoes: agenda criada e nao estar vazia
//pos condicoes: imprime o nome e aniversario dos contatos que tenham o nome que comecem com a letra ou imprime que nao foi encontrado nenhum usuario
void consulta_aniversario_letra_nome(agenda_t *agenda, char letra)
{
	system("clear");
	int i, aux=0;
	for (i = 0; i < agenda->qnt_agenda; i++)
	{
		if(agenda->contato[i].nome[0] == letra) //se a comparacao da primeira letra do nome for igual ao do parametro letra
		{
			aux=1;
			printf("Contato: %s\n",agenda->contato[i].nome);
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
	system("clear");
	int i;	
	//agenda_t *cpy_agenda = (agenda_t *)malloc(sizeof(agenda_t));
	//cpy_agenda = agenda; //faz backup da agenda -> nãõ faz backup da agenda
	ordenacao_insercao_nome(agenda); //ordena pelo metodo de insercao
	for (i = 0; i < agenda->qnt_agenda; i++)
	{
		printf("Contato: %s\n",agenda->contato[i].nome);
		printf("Aniversario: %2d/%2d/%4d\n",agenda->contato[i].dia, agenda->contato[i].mes, agenda->contato[i].ano);
		printf("Celular: %d\n",agenda->contato[i].celular);
		printf("Twitter: %s\n",agenda->contato[i].twitter);
		printf("Facebook: %s\n",agenda->contato[i].facebook);
		printf("\n");
	}
	/* NAO FUNCIONA
	for (i=0; i < cpy_agenda->qnt_agenda; i++)
	{
		free(cpy_agenda->contato[i].nome);
		free(cpy_agenda->contato[i].dia);
		free(cpy_agenda->contato[i].mes);
		free(cpy_agenda->contato[i].ano);
		free(cpy_agenda->contato[i].celular);
		free(cpy_agenda->contato[i].twitter);
		free(cpy_agenda->contato[i].facebook);
	}
	free(cpy_agenda.qnt_agenda);
	free(cpy_agenda);
	*/
}

//MOSTRA AGENDA ORDENADA PELO MES
//parametro de entrada: estrutura agenda
//pre condicoes: agenda criada e nao estar vazia
//pos condicoes: imprime os contatos ordenados ordenados pelo mes do aniversario
void mostra_agenda_ordenada_mes(agenda_t *agenda)
{
	system("clear");
	int i;	
	//agenda_t *cpy_agenda = (agenda_t *)malloc(sizeof(agenda_t));
	//cpy_agenda = agenda; //faz backup da agenda -> nãõ faz backup da agenda
	ordenacao_insercao_mes(agenda); //ordena pelo metodo de insercao
	for (i = 0; i < agenda->qnt_agenda; i++)
	{
		printf("Contato: %s\n",agenda->contato[i].nome);
		printf("Aniversario: %2d/%2d/%4d\n",agenda->contato[i].dia, agenda->contato[i].mes, agenda->contato[i].ano);
		printf("Celular: %d\n",agenda->contato[i].celular);
		printf("Twitter: %s\n",agenda->contato[i].twitter);
		printf("Facebook: %s\n",agenda->contato[i].facebook);
		printf("\n");
	}
}

//implementei mas acho que não vai ser utilizado
void troca_dados_contatos(agenda_t *agenda, int pos_contato1, int pos_contato2)
{
	system("clear");
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
