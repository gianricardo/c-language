#include "aplicacao.h"

int main (void)
{
	int opcao; //variavel utilizada no switch case
	agenda_t *agenda=(agenda_t *)malloc(sizeof(agenda_t)); //inicialização da estrutura agenda
	agenda->qnt_agenda=0; //inicializa posicao em 0
	
	FILE *fagenda;
	if((fagenda = fopen("agenda.txt","wr+")) == NULL)
	    {
		printf("Erro na leitura da agenda.");
		exit(-1);
	    }
	printf("agenda criada\n");
	
	while(1) //loop infinito no main para sempre cair no menu abaixo, a nãõ ser que o usuário insira 9 para SAIR
	{
		printf("Digite: \n1-Cadastro de contato\n2-Excluir contato a partir do nome.\n3-Alterar dados do contato a partir do nome\n4-Consultar aniversariantes pelo dia e mês\n5-Consultar aniversariantes pelo mês\n6-Consultar aniversariantes pela letra inicial do nome.\n7-Mostra agenda ordenada pelo nome\n8-Mostra agenda ordenada por mês.\n9-Para SAIR\n");
		scanf("%d",&opcao);
		switch (opcao)
		{
			case 1: //Cadastro de contato
			{
				system("clear");
				cadastra_contato(agenda);
				break;
			}
			case 2: //Excluir contato a partir do nome
			{
				system("clear");
				char nome[TAM_NOME];
				printf("Digite o nome do contato para excluir:\n");
				scanf(" %s",nome);
				excluir_pelo_nome(agenda,nome);
				break;
			}
			case 3: //Alterar dados do contato a partir do nome
			{
				system("clear");
				char nome[TAM_NOME];
				printf("Digite o nome do contato para editar:\n");
				scanf("%s",nome);
				alterar_pelo_nome(agenda,nome);
				break;
			}
			case 4: //Consultar aniversariantes pelo dia e mês
			{
				system("clear");
				int c_dia, c_mes;
				printf("Consulta contato por dia/mês:\n");
				scanf("%d/%d",&c_dia,&c_mes);
				consulta_aniversario_dia_mes(agenda,c_dia,c_mes);
				break;
			}
			case 5: //Consultar aniversariantes pelo mês
			{
				system("clear");
				int c_mes;
				printf("Consulta contato por mês:\n");
				scanf("%d",&c_mes);
				consulta_aniversario_mes(agenda,c_mes);
				break;
			}
			case 6: //Consultar aniversariantes pela letra inicial do nome
			{
				system("clear");
				char letra;
				printf("Consulta aniversariantes pela letra do nome:\n");
				scanf(" %c",&letra);
				consulta_aniversario_letra_nome(agenda, letra);
				break;
			}
			case 7: //mostra agenda ordenada pelo nome
			{
				system("clear");
				mostra_agenda_ordenada_nome(agenda);		
				break;
			}
			case 8: //mostra agenda ordenada pelo mes
			{
				system("clear");
				mostra_agenda_ordenada_mes(agenda);
				break;
			}
			case 9:
			{
				exit(-1);
			}			
			default: //imprime toda a agenda
			{
				int i;
				for(i=0; i < agenda->qnt_agenda;i++) //varre todo o vetor de contatos da agenda, que contém a estrutura de dados do contato em cada posiçao do vetor 
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
