/**
 *  @file helper.h
 *
 *  Created on: Oct 6, 2015
 *      Author: João Gabriel Bortot Cadore
 *		Igor Reinaldo Eineck da Silva
 */

#define eh_bissexto(ano) (( ano % 4 == 0 && ano % 100 != 0 ) || ano % 400 == 0 ? 1 :0)
#define agenda_cheia(agenda) (agenda->qnt_agenda >= TAM_AGENDA ? 1 : 0)
#define agenda_vazia(agenda) (agenda->qnt_agenda <= 0 ? 1 : 0)