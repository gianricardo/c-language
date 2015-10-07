/**
 *  @file fn_mostra_ordenacao.c
 *
 *  Created on: Oct 06, 2015
 *      Author: João Gabriel Bortot Cadore
 *		Igor Reinaldo Eineck da Silva
 */

#include <stdlib.h>
#include <stdio.h>
#include "fn_mostra_ordenado.h"

/**
 *  parametro de entrada: estrutura agenda.
 *  pre condicoes: agenda criada e nao estar vazia.
 *  pos condicoes: imprime os contatos ordenados em ordem alfabética por nome.
 */
void mostra_agenda_ordenada_nome(agenda_t *agenda)
{
	int i;	
	
	ordenacao_insercao_nome(agenda);
	
	for (i = 0; i < TAM_AGENDA; i++)
	{
		if(strcmp(agenda->contato[i].nome, "") == 0)
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

/**
 *  parametro de entrada: estrutura agenda
 *  pre condicoes: agenda criada e nao estar vazia
 *  pos condicoes: imprime os contatos ordenados ordenados pelo mes do aniversario
 */
void mostra_agenda_ordenada_mes(agenda_t *agenda)
{
	int i;	
	ordenacao_insercao_mes(agenda);
	
	for (i = 0; i < TAM_AGENDA; i++)
	{
		if(strcmp(agenda->contato[i].nome, "") == 0)
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
