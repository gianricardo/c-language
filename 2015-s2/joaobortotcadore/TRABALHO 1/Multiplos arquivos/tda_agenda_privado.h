//contem estrutura e prototipos das operacoes privadas
#include "tda_agenda.h"
#ifndef tda_agenda_privado_h
#define tda_agenda_privado_h

#define TAM_NOME 100
#define TAM_TWITTER 100
#define TAM_FACEBOOK 100
#define TAM_AGENDA 30

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

//prototipos
void ordenacao_insercao_nome(agenda_t *agenda);
void ordenacao_insercao_mes(agenda_t *agenda);


#endif
