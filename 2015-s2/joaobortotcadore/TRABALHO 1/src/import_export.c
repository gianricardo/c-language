/**
 *  @file import_export.c
 *
 *  Created on: Oct 06, 2015
 *      Author: João Gabriel Bortot Cadore
 *		Igor Reinaldo Eineck da Silva
 */

#include <stdlib.h>
#include <stdio.h>
#include "import_export.h"

void exporta_backup(agenda_t *agenda, FILE * arquivo)
{
	if((arquivo = fopen("Agenda.txt","wr+")) == NULL)
	    {
		printf("Erro na leitura da agenda.\n");
		exit(-1);
	    }
	
	int i;
	
	for(i=0; i < TAM_AGENDA; i++)
	{
		if(strcmp(agenda->contato[i].nome,"") == 0)
			continue;	
		fprintf(arquivo, "%s%d/%d/%d\n%d\n%s%s",agenda->contato[i].nome,agenda->contato[i].dia, agenda->contato[i].mes, agenda->contato[i].ano, agenda->contato[i].celular, agenda->contato[i].twitter, agenda->contato[i].facebook);
	}
	
	fclose(arquivo);
	
}

void importa_backup(agenda_t *agenda, FILE * arquivo)
{
	agenda->qnt_agenda=-1;
	
	if((arquivo = fopen("Agenda.txt","r")) == NULL)
	    {
		printf("Erro na leitura da agenda.\n");
		exit(-1);
	    }
	
	int i=0;
	
	while ( !feof(arquivo) )
	{
		agenda->qnt_agenda++;
		fscanf(arquivo,"%s%d/%d/%d\n%d\n%s%s",agenda->contato[i].nome,&agenda->contato[i].dia, &agenda->contato[i].mes, &agenda->contato[i].ano, &agenda->contato[i].celular, agenda->contato[i].twitter, agenda->contato[i].facebook);
		i++;
	}
	
}
