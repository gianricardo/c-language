/**
 * Cabeçalhos das bibliotecas utilizadas;
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 30 /**Tamanho do vetor agenda*/

/**Structs - Todos as estruturas serão nomeadas co m oprefixo "s_"*/
typedef struct {
    char nome[100]; /**Nome, contendo até 100 caracteres*/
    char data[6]; /**Data de aniversario no formato dd/mm*/
    char celular[12]; /**celular no formato dd-88888888*/
    char twitter[16]; /**Nickname do twitter, que possui no maximo 15 caracteres*/
    char facebook[30]; /**Nickname do facebook*/
} s_contato; /**s_contato - Armazena os dados dos contatos*/

/**Protótipos das Funções*/
void clear(void); /**void clear(void): limpa o buffer da stdin após o uso de um scanf, acabou não sendo usada*/
int menu(); /**int menu(): que oferece o menu e pede que seja escolhida uma opção, retorna um inteiro equivalente a opão escolhida se a entrada for coerente com as opções, caso contrario retorna 0*/
void ler_agenda_arquivo(s_contato vetor_agenda[SIZE]); /**void ler_agenda(s_contato vetor_agenda[SIZE]) que lê o arquivo contendo os dados da agenda e manipula o vetor de contatos passado como referencia de forma a preenche-lo com os dados armazenados no txt da agenda. Se o arquivo agenda.txt ainda não existir, preenche os elementos do vetor de contatos com ""*/
void cadastrar(s_contato vetor_agenda[SIZE]); /**void cadastrar(s_contato vetor_agenda[SIZE]): Adquire os dados do usuario (nome, data de aniversario, celular, twitter, facebook) para criar um novo contato na agenda, o unico dado obrigatorio é o nome, o resto pode ser deixado em branco seguindo as orientações das funções de aquisição de dados*/
void adquirir_nome(char nome[100]); /**void adquirir_nome(char nome[100]): Manipula uma string destinada a armazenar um nome de modo a preenchela de forma adequada. Não faz exigencias em relação ao primeiro caractere do nome. Oferece a possibilidade de cancelar a entrada, preenchendo a string passada pelo parametro com um valor que sinaliza o cancelamento: "*" */
void adquirir_data(char data[6]); /**void adquirir_data(char data[6]): Manipula a string de parametro data de forma a encerrar a execução com ela contendo uma data valida ou "" se o usuario optar por pular*/
void adquirir_celular(char celular[12]); /**void adquirir_celular(char celular[12]): Manpula a string celular de mod a preenchela com um valor valido para celular ou com "" se o usuario optar por pular*/
void adquirir_twitter(char twitter[16]); /**void adquirir_twitter(char twitter[16]): preence twitter com um valor valido para o twitter, ou com "" se o usuario optar por pular*/
void adquirir_facebook(char facebook[30]); /**void adquirir_facebook(char facebook[30]): preenche facebook com um valor valido para o facebook ou com "" se o usuario optar por pular*/
void alocar_contato(s_contato vetor_agenda[SIZE], s_contato contato); /**void alocar_contato(s_contato vetor_agenda[SIZE], s_contato contato): Aloca contato na sua devida posição lexica dentro de vetor-agenda; Comportamento indefinido caso vetor_agenda ja esteja cheia*/
void mostrar_agenda_nome(s_contato vetor_agenda[SIZE], int a, int b); /**void mostrar_agenda_nome(s_contato vetor_agenda[SIZE], int a, int b): mostra os contatos presentes na agenda, não vazios, na ordem em que estão posicionados na agenda*/
int gravar(s_contato vetor_agenda[SIZE]); /**int gravar(s_contato vetor_agenda[SIZE]): grava os dados do vetor de contatos em um arquivo chamado de agenda.txt, de forma compativel co ma função de leitura void ler_agenda_arquivo(s_contato vetor_agenda[SIZE])*/
void excluir_pelo_nome(s_contato vetor_agenda[SIZE]);/**void excluir_pelo_nome(s_contato vetor_agenda[SIZE]): Função para excluir um contato a partir do nome. seguindo o nome fornecido pelo usuario ela fornece quais as possibilidade de exclusão, o usuario pode então optar por cancelar, excluir todas as entradas compativeis, ou só a desejada*/
void alterar_pelo_nome(s_contato vetor_agenda[SIZE]);/**void alterar_pelo_nome(s_contato vetor_agenda[SIZE]): Função para editar um contato a partir do nome. seguindo o nome fornecido pelo usuario ela fornece quais as possibilidade de edição, o usuario pode então optar por cancelar ou editar somente a entrada desejada. A edição permite que o usuario altere apenas as partes que quiser alterar do contato escolhido*/
void consultar_aniversariantes(s_contato vetor_agenda[SIZE], char dia[3], char mes[3]); /**void consultar_aniversariantes(s_contato vetor_agenda[SIZE], char dia[3], char mes[3]): Exibe os aniversariantes do dia e mes desejado ou somente do mes se o dia informado for for "00"*/
void aniversariantes_data(s_contato vetor_agenda[SIZE]); /**void aniversariantes_data(s_contato vetor_agenda[SIZE]): Consulta os aniversariantes de uma data no formato dd/mm, obtendo a data do usuario e usando na função void consultar_aniversariantes(s_contato vetor_agenda[SIZE], char dia[3], char mes[3])*/
void aniversariantes_mes(s_contato vetor_agenda[SIZE]); /**void aniversariantes_mes(s_contato vetor_agenda[SIZE]): Consulta os aniversariantes de um mês no formato mm, obtendo o mês do usuario e usando na função void consultar_aniversariantes(s_contato vetor_agenda[SIZE], char dia[3], char mes[3]) com dia = "00"*/
void aniversariantes_inicial(s_contato vetor_agenda[SIZE]); /**void aniversariantes_inicial(s_contato vetor_agenda[SIZE]): Pede ao usuario uma inicial e exibe todos os nomes que começam naquela inicial junto as suas respectivas datas de aniversarios, e avisa se as datas forem desconhecidas*/
void mostrar_agenda_mes(s_contato vetor_agenda[SIZE]);/**void mostrar_agenda_mes(s_contato vetor_agenda[SIZE]): */

/**Fim dos protótipos*/

