/**
 *  @file fn_aniversarios.c
 * 
 *  Created on: Oct 06, 2015
 *      Author: João Gabriel Bortot Cadore
 *		Igor Reinaldo Eineck da Silva
 */

#include <stdlib.h>
#include <stdio.h>
#include "fn_aniversarios.h"

/**
 *  parametro de entrada: estrutura agenda, dia e mes a ser pesquisado dentro da estrutura agenda
 *  pre condicoes: agenda criada e nao estar vazia, data e mes validas d(1-31) e m(1,12)
 *  pos condicoes: imprime os contatos que tenham o dia e mes ou então imprime que não existem ninguém com essa data
 */
void consulta_aniversario_dia_mes(agenda_t *agenda, int c_dia, int c_mes)
{
	int i, aux=0;
	for(i=0; i < agenda->qnt_agenda;i++)
	{
		if(c_dia==agenda->contato[i].dia && c_mes==agenda->contato[i].mes)
		{
			if(strcmp(agenda->contato[i].nome, "") == 0)
			{
				continue;
			}
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

/**
 *  parametro de entrada: estrutura agenda e mes a ser pesquisado dentro da estrutura agenda
 *  pre condicoes: agenda criada e nao estar vazia, o mes ser possivel (1-12)
 *  pos condicoes: imprime os contatos que fazem o aniversario no mes requisitado pelo usuario ou então imprime que não existem ninguém
 */
void consulta_aniversario_mes(agenda_t *agenda, int c_mes)
{
	int i, aux=0;
	for(i=0; i < TAM_AGENDA;i++)
	{
		if(c_mes==agenda->contato[i].mes)
		{
			if(strcmp(agenda->contato[i].nome, "") == 0)
			{
				continue;
			}
			
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

/**
 *  parametro de entrada: estrutura agenda e letra
 *  pre condicoes: agenda criada e nao estar vazia
 *  pos condicoes: imprime o nome e aniversario dos contatos que tenham o nome que comecem com a letra ou imprime que nao foi encontrado nenhum usuario
 */
void consulta_aniversario_letra_nome(agenda_t *agenda, char letra)
{
	int i, aux=0;
	
	for (i = 0; i < TAM_AGENDA; i++)
	{
		if(agenda->contato[i].nome[0] == letra)
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
