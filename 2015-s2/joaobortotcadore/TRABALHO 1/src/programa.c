/**
 * @file programa.c
 * @brief Programa principal da Agenda de Contatos.
 *
 *  Created on: Oct 06, 2015
 *      Author: João Gabriel Bortot Cadore
 *				Igor Reinaldo Eineck da Silva
 */

#include <stdlib.h>     
#include <stdio.h>      
#include <string.h>
#include "cadastro.h"
#include "defines.h"
#include "helper.h"
#include "estrutura.h"
#include "fn_aniversarios.h"
#include "fn_excluir.h"
#include "fn_modifica_pelo_nome.h"
#include "fn_mostra_ordenado.h"
#include "fn_ordenacao.h"
#include "import_export.h"
#include "inicializa.h"

/**
 * @fn int main()
 * @brief Função principal do programa.
 *
 * @return Status de fim do programa.
 */
int main (void)
{
	int opcao;
	agenda_t *agenda=(agenda_t *)malloc(sizeof(agenda_t));
	
	if (agenda == NULL) { 
		printf("ERRO ALOCAÇÃO MEMÓRIA PARA ESTRUTURA AGENDA\n");
		exit(-1);
	}

	agenda_inicializa(agenda);
	setbuf(stdin,NULL);

	FILE *fagenda;
	importa_backup(agenda,fagenda);
	
	while(1)
	{
		printf("Digite: \n1-Cadastro de contato\n2-Excluir contato a partir do nome.\n3-Alterar dados do contato a partir do nome\n4-Consultar aniversariantes pelo dia e mês\n5-Consultar aniversariantes pelo mês\n6-Consultar aniversariantes pela letra inicial do nome.\n7-Mostra agenda ordenada pelo nome\n8-Mostra agenda ordenada por mês.\n9-Para SAIR\n");

		scanf("%d",&opcao);
		
		switch (opcao)
		{
			case 1: // Cadastro de contato
			{
				cadastra_contato(agenda);
				exporta_backup(agenda,fagenda);
				
				break;
			}
			
			case 2: // Excluir contato a partir do nome
			{
				if(agenda_vazia(agenda))
				{
					printf("AGENDA VAZIA.\n");
					
					break;
				}
				
				char nome[TAM_NOME];
				printf("Digite o nome do contato para excluir:\n");
				setbuf(stdin,NULL);	
				fgets(nome, TAM_NOME, stdin);				
				excluir_pelo_nome(agenda,nome);
				
				break;
			}
			
			case 3: // Alterar dados do contato a partir do nome
			{
				if(agenda_vazia(agenda))
				{
					printf("AGENDA VAZIA.\n");
					
					break;
				}
				
				char nome[TAM_NOME];
				
				printf("Digite o nome do contato para editar:\n");
				setbuf(stdin,NULL);	
				fgets(nome, TAM_NOME, stdin);				
				alterar_pelo_nome(agenda,nome);
				
				break;
			}
			
			case 4: //Consultar aniversariantes pelo dia e mês
			{
				if(agenda_vazia(agenda))
				{
					printf("AGENDA VAZIA.\n");
					
					break;
				}
				
				int c_dia, c_mes;
				printf("Consulta contato por dia/mês:\n");
				scanf("%d/%d",&c_dia,&c_mes);
				consulta_aniversario_dia_mes(agenda,c_dia,c_mes);
				
				break;
			}
			
			case 5: //Consultar aniversariantes pelo mês
			{
				if(agenda_vazia(agenda))
				{
					printf("AGENDA VAZIA.\n");
					
					break;
				}
				
				int c_mes;
				printf("Consulta contato por mês:\n");
				scanf("%d",&c_mes);
				
				while(c_mes < 1 || c_mes > 12)
				{
					printf("Digite um valor de mês válido, 1 a 12:\n");
					scanf("%d", &c_mes);
				}
				
				consulta_aniversario_mes(agenda,c_mes);
				
				break;
			}
			
			case 6: // Consultar aniversariantes pela letra inicial do nome
			{
				if(agenda_vazia(agenda))
				{
					printf("AGENDA VAZIA.\n");
					
					break;
				}
				
				char letra;
				printf("Consulta aniversariantes pela letra do nome:\n");
				scanf(" %c",&letra);
				consulta_aniversario_letra_nome(agenda, letra);
				
				break;
			}
			
			case 7: // Mostra agenda ordenada pelo nome
			{
				if(agenda_vazia(agenda))
				{
					printf("AGENDA VAZIA.\n");
					
					break;
				}
				
				mostra_agenda_ordenada_nome(agenda);		
				
				break;
			}
			
			case 8: // Mostra agenda ordenada pelo mes
			{
				if(agenda_vazia(agenda))
				{
					printf("AGENDA VAZIA.\n");
					
					break;
				}
				
				mostra_agenda_ordenada_mes(agenda);
				
				break;
			}
			
			case 9: // Caso de saída do programa
			{
				exit(-1);
			}			
			
			default: // Imprime toda a agenda
			{
				int i;
				
				for(i=0; i < TAM_AGENDA;i++) 
				{
					printf("Contato: %s\n",agenda->contato[i].nome);
					printf("Aniversario: %2d/%2d/%4d\n",agenda->contato[i].dia, agenda->contato[i].mes, agenda->contato[i].ano);
					printf("Celular: %d\n",agenda->contato[i].celular);
					printf("Twitter: %s\n",agenda->contato[i].twitter);
					printf("Facebook: %s\n",agenda->contato[i].facebook);
					printf("\n");
				}
				
				printf("Quantidade de contatos cadastrados: %d\n", agenda->qnt_agenda);
				
				break;
			}

		}
	}	
	
	return 0;
}
