/**
 *  @file fn_ordenacao.c
 *
 *  Created on: Oct 06, 2015
 *      Author: João Gabriel Bortot Cadore
 *		Igor Reinaldo Eineck da Silva
 */

#include <stdlib.h>
#include <stdio.h>
#include "fn_ordenacao.h"

/**
 *  parametro de entrada: estrutura agenda.
 *  pre condicoes: agenda criada e nao estar vazia.
 *  pos condicoes: ordena a agenda passada como parametro por nome.
 */
void ordenacao_insercao_nome(agenda_t *agenda) 
{
	int i, j;
	
	aux_agenda_t *agenda1contato = (aux_agenda_t *)malloc(sizeof(aux_agenda_t));

	for (i = 1; i < TAM_AGENDA; i++)
	{
		agenda1contato->contato[0] = agenda->contato[i];
		j = i - 1;
		
		while ((j>=0) && strcmp(agenda1contato->contato[0].nome, agenda->contato[j].nome)<0)
		{
			agenda->contato[j+1] = agenda->contato[j];
			j--;
		}
		agenda->contato[j+1] = agenda1contato->contato[0];
	}
	
	free(agenda1contato);
 	
 	return;
}

/**
 *  parametro de entrada: estrutura agenda.
 *  pre condicoes: agenda criada e nao estar vazia.
 *  pos condicoes: ordena a agenda passada como parametro por mês.
 */
void ordenacao_insercao_mes(agenda_t *agenda) 
{
	int i, j;
	
	aux_agenda_t *agenda1contato = (aux_agenda_t *)malloc(sizeof(aux_agenda_t));
	
	for (i = 1; i < TAM_AGENDA; i++)
	{
		agenda1contato->contato[0] = agenda->contato[i];
		j = i - 1;
		
		while ((j>=0) && agenda1contato->contato[0].mes < agenda->contato[j].mes)
		{
			agenda->contato[j+1] = agenda->contato[j];
			j--;
		}
		agenda->contato[j+1] = agenda1contato->contato[0];
	}
	
	free(agenda1contato);
	
	return;
	
}

/**
 *  parametro de entrada: estrutura agenda
 *  pre condicoes: agenda criada e nao estar vazia
 *  pos condicoes: ordena a agenda passada como parametro por nome
 */
void ordenacao_decrescente_insercao_nome(agenda_t *agenda) 
{
	int i, j;
	
	aux_agenda_t *agenda1contato = (aux_agenda_t *)malloc(sizeof(aux_agenda_t));

	for (i = 1; i < TAM_AGENDA; i++)
	{
		agenda1contato->contato[0] = agenda->contato[i];
		j = i - 1;
		
		while ((j>=0) && strcmp(agenda1contato->contato[0].nome, agenda->contato[j].nome) > 0)
		{
			agenda->contato[j+1] = agenda->contato[j];
			j--;
		}
		agenda->contato[j+1] = agenda1contato->contato[0];
	}
	
	free(agenda1contato);
 	
 	return;
}
