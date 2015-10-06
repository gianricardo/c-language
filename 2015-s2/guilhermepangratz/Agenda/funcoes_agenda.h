#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 30

/*Structs - Todos as estruturas serão nomeadas co m oprefixo "s_"*/
typedef struct {
    char nome[100]; /*Nome, contendo até 40 caracteres*/
    char data[6]; /*Data de aniversario*/
    char celular[12];
    char twitter[16], facebook[30];
} s_contato; /*s_contato - Armazenara todos os dados de cada contato*/

/*Protótipos das Funções*/
void clear(void); /*clear de input buffer*/

int menu(); /*Funcão que oferece o menu e pede que seja escolhida uma opção*/
void ler_agenda_arquivo(s_contato vetor_agenda[SIZE]); /*Função que lê o arquivo contendo os dados da agenda e retorna um vetor de s_contato*/
void cadastrar(s_contato vetor_agenda[SIZE]); /*Função que adquire os dados de um contato e o posiciona na agenda*/
void adquirir_nome(char nome[100]); /*Adquire um nome valido e o retorna*/
void adquirir_data(char data[6]); /*Adquire uma data de aniversario valida e a retorna*/
void adquirir_celular(char celular[12]); /*Adquire um numero de celualr valido e o retorna*/
void adquirir_twitter(char twitter[16]); /*Adquire um twitter nickname e o retorna*/
void adquirir_facebook(char facebook[30]); /*Adquire um facebook nickname e o retorna*/
void alocar_contato(s_contato vetor_agenda[SIZE], s_contato contato); /*aloca um novo contato no seu devido local na agenda*/
void mostrar_agenda_nome(s_contato vetor_agenda[SIZE], int a, int b);
int gravar(s_contato vetor_agenda[SIZE]); /*grava os dados do vetor de contatos no arquivo*/
void excluir_pelo_nome(s_contato vetor_agenda[SIZE]);/*excluir um contato pelo nome*/
void alterar_pelo_nome(s_contato vetor_agenda[SIZE]);/*Selecionar um contato pelo nome e alterar*/
void consultar_aniversariantes(s_contato vetor_agenda[SIZE], char dia[3], char mes[3]); /*Exibe os aniversariantes do dia desejado ou somente do mes se o dia for "00"*/
void aniversariantes_data(s_contato vetor_agenda[SIZE]); /*Consultar os aniversariantes de uma data no formato dd/mm*/
void aniversariantes_mes(s_contato vetor_agenda[SIZE]); /*Consultar os aniversariantes de um mes*/
void aniversariantes_inicial(s_contato vetor_agenda[SIZE]); /*Exibir todos os nomes com a inicial solicitada e as suas datas de aniversario*/
void mostrar_agenda_mes(s_contato vetor_agenda[SIZE]);

/*Fim dos protótipos*/

