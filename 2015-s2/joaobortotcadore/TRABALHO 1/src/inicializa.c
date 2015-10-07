/**
 *  @file inicializa.c
 *
 *  Created on: Oct 06, 2015
 *      Author: João Gabriel Bortot Cadore
 *		Igor Reinaldo Eineck da Silva
 */
#include "inicializa.h"
/**
 *  parametro de entrada: estrutura agenda.
 *  pre condicoes: agenda criada e nao estar vazia.
 *  pos condicoes: ordena a agenda passada como parametro por nome.
 */
void agenda_inicializa(agenda_t *agenda)
{
	int i;	
	
	agenda->qnt_agenda=0;
	
	for(i=0;i < TAM_AGENDA; i++)
	{ 
		memset(&agenda->contato[i],0,sizeof(dados_t));
	}
}
