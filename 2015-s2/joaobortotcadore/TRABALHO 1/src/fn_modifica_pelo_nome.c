/**
 *  @file fn_modifica_pelo_nome.c
 *
 *  Created on: Oct 06, 2015
 *      Author: João Gabriel Bortot Cadore
 *		Igor Reinaldo Eineck da Silva
 */

#include <stdlib.h>
#include <stdio.h>
#include "fn_modifica_pelo_nome.h"

/**
 *  parametro de entrada: estrutura agenda, nome do contato a ser editado
 *  pre condicoes: agenda nao estar vazia
 *  pos condicoes: dado do contato alterado com sucesso
 */
void alterar_pelo_nome(agenda_t *agenda, char *nome)
{
	int i, opcao_fn_alterar, aux=0;
	
	for(i=0; i < TAM_AGENDA;i++) 
	{
		if(strcmp(nome,agenda->contato[i].nome) == 0)
		{
			aux=1;
			printf("Escolha o que você deseja alterar: \n1-Nome\n2-Dia\n3-Mês\n4-Ano\n5-Celular\n6-Twitter\n7-Facebook\n");
			scanf("%d",&opcao_fn_alterar);
			
			switch(opcao_fn_alterar)
			{
				
				case 1: 
				{
					printf("Edite o nome :\n");
					scanf("%s",agenda->contato[i].nome);
					printf("Nome editado com sucesso.\n");
					
					return;
				}
				
				case 2:
				{
					printf("Edite o dia:\n");
					scanf("%d",&agenda->contato[i].dia);
					printf("Dia editado com sucesso.\n");
					
					return;
				}
				
				case 3:
				{
					printf("Edite o mês:\n");
					scanf("%d",&agenda->contato[i].mes);
					printf("Mês editado com sucesso.\n");
					
					return;
				}			
				
				case 4:
				{
					printf("Edite o ano:\n");
					scanf("%d",&agenda->contato[i].ano);
					printf("Ano editado com sucesso.\n");
					
					return;
				}				
				
				case 5:
				{
					printf("Edite o celular:\n");
					scanf("%d", &agenda->contato[i].celular);
					printf("Celular editado com sucesso.\n");
					
					return;
				}
				
				case 6:
				{
					printf("Edite o twitter:\n");
					scanf("%s",agenda->contato[i].twitter);
					printf("Twitter editado com sucesso.\n");
					
					return;
				}
				
				case 7:
				{
					printf("Edite o facebook:\n");
					scanf("%s",agenda->contato[i].facebook);
					printf("Facebook editado com sucesso.\n");
					
					return;
				}

			}
		}
	}
	
	if(aux==0)
	{
		printf("Não existe este contato!!\n\n");
	}
	
	return;
}

