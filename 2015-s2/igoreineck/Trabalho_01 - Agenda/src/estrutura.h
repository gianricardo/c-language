/**
 *  @file estrutura.h
 *
 *  Created on: Oct 6, 2015
 *      Author: João Gabriel Bortot Cadore
 *		Igor Reinaldo Eineck da Silva
 */

#include "defines.h"

#ifndef ESTRUTURA_H
#define ESTRUTURA_H

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
	int qnt_agenda;
} agenda_t;

typedef struct aagenda
{
	dados_t contato[1];
} aux_agenda_t;

#endif
