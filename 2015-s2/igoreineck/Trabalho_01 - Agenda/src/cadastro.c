/**
 *  @file cadastro.c
 *
 *  Created on: Oct 06, 2015
 *      Author: João Gabriel Bortot Cadore
 *		Igor Reinaldo Eineck da Silva
 */

#include <stdlib.h>
#include <stdio.h>
#include "cadastro.h"
#include "helper.h"

/**
 *  parametro de entrada: estrutura agenda.
 *  pre condicoes: agenda nao estar cheia, agenda criada, agenda ordenada.
 *  pos condicoes: contato cadastrado na agenda, quantidade de contatos incrementado, agenda ordenada com o novo contato.
 */
void cadastra_contato(agenda_t *agenda)
{
	if (agenda == NULL)
	{
		printf("AGENDA NÃO FOI CRIADA CORRETAMENTE.\n");
		return;	
	}

	if (agenda->qnt_agenda >= TAM_AGENDA)
	{
		printf("NÃO HÁ MAIS ESPAÇO NA AGENDA.\n");
		return;	
	}

	ordenacao_decrescente_insercao_nome(agenda);
	cadastra_nome(agenda);
	cadastra_aniversario(agenda);
	cadastra_celular(agenda);
	cadastra_twitter(agenda);
	cadastra_facebook(agenda);
	agenda->qnt_agenda++;
	
}

/** 
 *  parametro de entrada: estrutura agenda.
 *  pre condicoes: agenda criada, agenda estar ordenada.
 *  pos condicoes: nome cadastrado no contato.
 */
void cadastra_nome(agenda_t *agenda)
{
	setbuf(stdin,NULL);
	printf("Digite o nome do contato: ");
	fgets(agenda->contato[agenda->qnt_agenda].nome, TAM_NOME, stdin); 
}

/**
 *  parametro de entrada: estrutura agenda.
 *  pre condicoes: agenda criada.
 *  pos condicoes: dia cadastrado no contato.
 */
void cadastra_aniversario(agenda_t *agenda)
{
	printf("Digite a data de aniversário do contato (dd/mm/aaaa): ");
	scanf("%d/%d/%d",&agenda->contato[agenda->qnt_agenda].dia, &agenda->contato[agenda->qnt_agenda].mes, &agenda->contato[agenda->qnt_agenda].ano);
	
	if(eh_bissexto(agenda->contato[agenda->qnt_agenda].ano) == 1)
	{
		if(agenda->contato[agenda->qnt_agenda].mes == 2 )
		{
			while(agenda->contato[agenda->qnt_agenda].dia < 0 || agenda->contato[agenda->qnt_agenda].dia > 29)
			{
				printf("É ano bissexto. Fevereiro pode ir até 29º dia. Digite novamente (dd/mm/aaaa): ");
				scanf("%d/%d/%d", &agenda->contato[agenda->qnt_agenda].dia, &agenda->contato[agenda->qnt_agenda].mes, &agenda->contato[agenda->qnt_agenda].ano);
			}
		}

	}
	
	else
	{ 
		if(agenda->contato[agenda->qnt_agenda].mes == 2 )
		{
			while(agenda->contato[agenda->qnt_agenda].dia < 0 || agenda->contato[agenda->qnt_agenda].dia > 28) 
			{
				printf("Não é ano bissexto. Fevereiro pode ir até 28º dia. Digite novamente (dd/mm/aaaa): ");
				scanf("%d/%d/%d", &agenda->contato[agenda->qnt_agenda].dia, &agenda->contato[agenda->qnt_agenda].mes, &agenda->contato[agenda->qnt_agenda].ano);
			}
		}
	}
	
	while(agenda->contato[agenda->qnt_agenda].dia < 0 || agenda->contato[agenda->qnt_agenda].dia > 31 || agenda->contato[agenda->qnt_agenda].mes <0 || agenda->contato[agenda->qnt_agenda].mes > 12)
	{
		printf("Data inválida. Digite novamente (dd/mm/aaaa): ");
		scanf("%d/%d/%d", &agenda->contato[agenda->qnt_agenda].dia, &agenda->contato[agenda->qnt_agenda].mes, &agenda->contato[agenda->qnt_agenda].ano);
	}
}

/**
 *  parametro de entrada: estrutura agenda.
 *  pre condicoes: agenda criada.
 *  pos condicoes: celular cadastrado no contato.
 */
void cadastra_celular(agenda_t *agenda)
{
	printf("Digite o celular do contato: ");
	scanf("%d", &agenda->contato[agenda->qnt_agenda].celular);
}

/**
 *  parametro de entrada: estrutura agenda.
 *  pre condicoes: agenda criada.
 *  pos condicoes: endereço twitter cadastrado no contato.
 */
void cadastra_twitter(agenda_t *agenda)
{
	setbuf(stdin,NULL);
	printf("Digite twitter do contato: @");
	fgets(agenda->contato[agenda->qnt_agenda].twitter, TAM_NOME, stdin);
}

/**
 *  parametro de entrada: estrutura agenda.
 *  pre condicoes: agenda criada.
 *  pos condicoes: endereço facebook cadastrado no contato.
 */
void cadastra_facebook(agenda_t *agenda)
{
	setbuf(stdin,NULL);		
	printf("Digite o facebook do contato: https://www.facebook.com/");
	fgets(agenda->contato[agenda->qnt_agenda].facebook, TAM_NOME, stdin);
}
