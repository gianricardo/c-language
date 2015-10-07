/**
 *  @file fn_excluir.c
 *
 *  Created on: Oct 06, 2015
 *      Author: João Gabriel Bortot Cadore
 *		Igor Reinaldo Eineck da Silva
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fn_excluir.h"

/**
 *  parametro de entrada: estrutura agenda, nome do contato a ser excluido.
 *  pre condicoes: agenda criada e agenda nao estar vazia.
 *  pos condicoes: contato excluido, quantidade de contatos decrementado se encontrar o nome e agenda ordenada apos a exclusao.
 */
void excluir_pelo_nome(agenda_t *agenda, char *nome)
{
	int i,aux=0;
	
	for(i=0; i < TAM_AGENDA;i++)
	{
		if( (strcmp(agenda->contato[i].nome,nome) == 0))
		{
			printf("Achamos o nome... Contato excluído!\n");
			aux=1;
			strcpy(agenda->contato[i].nome,"");
			
			break;
		}
	}
	
	if(aux==0)
	{
		printf("Não existe este contato!\n");
	
	}else{
		
		agenda->qnt_agenda--;
	}	
}
