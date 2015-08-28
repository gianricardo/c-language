#include <stdio.h>      /* printf, scanf, puts */
#include <stdlib.h>     /* realloc, free, exit, NULL */
#include <string.h>

#define TAM_NOME 100
#define TAM_TWITTER 100
#define TAM_FACEBOOK 100
#define TAM_AGENDA 30

//agenda vai ser um vetor de contato
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
	int pos_agenda;
} agenda_t;


int main (void)
{


	printf("Digite a data de aniversário do contato (dd/mm/aaaa): ");
	scanf("%d/%d/%d",agenda->contato[agenda->pos_agenda].dia,agenda->contato[agenda->pos_agenda].mes,agenda->contato[agenda->pos_agenda].ano);
	while(agenda->contato[agenda->pos_agenda].dia < 0 && agenda->contato[agenda->pos_agenda].dia > 31 || agenda->contato[agenda->pos_agenda].mes <0 && agenda->contato[agenda->pos_agenda].mes > 12) // falta função pra ver se o ano é bissexto
	{
		printf("Data inválida. Digite novamente (dd/mm/aaaa): "
		scanf("%d/%d/%d",agenda->contato[agenda->pos_agenda].dia;
	}

/* //teste vetor
int v[10];
printf("&v=%p\n", &v);
printf("v=%p\n",v);
printf("v[0]=%p\n",&v[0]);
*/

/*int a=99621693;

printf("%d",a);
*/


}

//Cadastrar pessoa na agenda de contato (Nome, Dia de aniversário, Celular, Twitter e Facebook).
//Excluir pessoa a partir do nome.
//Alterar dados a partir do nome.
//Consultar aniversariantes de uma data (dia e mês).
//Consultar aniversariantes por mês.
//Consultar aniversariantes pela letra inicial do nome.
//Mostrar toda a agenda ordenada pelo nome.
//Mostrar toda a agenda ordenada por mês.
//Sair.
