#include <stdio.h>      /* printf, scanf, puts */
#include <stdlib.h>     /* realloc, free, exit, NULL */
#include <string.h>	/* strcmp */

#ifndef tda_agenda_h
#define tda_agenda_h

typedef struct pilha pilha_t;
typedef struct dados dados_t;
typedef struct agenda agenda_t;
typedef struct aagenda aux_agenda_t;

//colocar prototipos das operacoes do TDA
void cadastra_nome(agenda_t *agenda);
void cadastra_aniversario(agenda_t *agenda);
void cadastra_celular(agenda_t *agenda);
void cadastra_contato(agenda_t *agenda);
void cadastra_twitter(agenda_t *agenda);
void cadastra_facebook(agenda_t *agenda);

void excluir_pelo_nome(agenda_t *agenda, char *nome);
void alterar_pelo_nome(agenda_t *agenda, char *nome);
void consulta_aniversario_dia_mes(agenda_t *agenda, int c_dia, int c_mes);
void consulta_aniversario_mes(agenda_t *agenda, int c_mes);
void consulta_aniversario_letra_nome(agenda_t *agenda, char letra);
void mostra_agenda_ordenada_nome(agenda_t *agenda);
void mostra_agenda_ordenada_mes(agenda_t *agenda);

#endif
