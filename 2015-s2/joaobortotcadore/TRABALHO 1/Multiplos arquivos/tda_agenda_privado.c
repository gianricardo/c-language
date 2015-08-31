#include "tda_agenda_privado.h"

//implementacao das operacoes privadas

//ORDENAÇÃO POR INSERÇÃO->NOMES
//parametro de entrada: estrutura agenda
//pre condicoes: agenda criada e nao estar vazia
//pos condicoes: ordena a agenda passada como parametro por nome
void ordenacao_insercao_nome(agenda_t *agenda) 
{
	system("clear");
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
	system("clear");
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

