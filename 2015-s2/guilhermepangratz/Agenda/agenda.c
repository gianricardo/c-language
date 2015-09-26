/* 
 * File:   agenda.c
 * Author: GuilhermeAugusto
 *
 * Created on 15 de Setembro de 2015, 16:22
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 30

/*Structs - Todos as estruturas serão nomeadas co m oprefixo "s_"*/
typedef struct {
    char *nome; /*Nome, contendo até 40 caracteres*/
    unsigned int data[2]; /*Data de aniversario*/
    char *celular;
    char *twitter, *facebook;
} s_contato; /*s_contato - Armazenara todos os dados de cada contato*/

/*Protótipos das Funções*/
int menu(); /*Funcão que oferece o menu e pede que seja escolhida uma opção*/

void ler_agenda_arquivo(s_contato vetor_agenda[SIZE]); /*Função que lê o arquivo contendo os dados da agenda e retorna um vetor de s_contato*/

void cadastrar(s_contato vetor_agenda[SIZE]); /*Função que adquire os dados de um contato e o posiciona na agenda*/

char *adquirir_nome(); /*Adquire um nome valido e o retorna*/
unsigned int *adquirir_data(); /*Adquire uma data de aniversario valida e a retorna*/
char *adquirir_celular(); /*Adquire um numero de celualr valido e o retorna*/
char *adquirir_twitter(); /*Adquire um twitter nickname e o retorna*/
void *adquirir_facebook(); /*Adquire um facebook nickname e o retorna*/

void gravar(s_contato vetor_agenda[30]);

/*Fim dos protótipos*/

/*Inicio da funcao principal*/
int main() { 
    
    s_contato contatos[SIZE];
    ler_agenda_arquivo(contatos);
    
    while (1) {
        switch (menu()) {
            case 1 :
                cadastrar(contatos);
                break;
            case 2 : break;
            case 3 : break;
            case 4 : break;
            case 5 : break;
            case 6 : break;
            case 7 : break;
            case 8 : break;
            case 9 : return 0;
            default : printf("entre um valor valido\n\n");
        }
    }
    
    return 0;
} /*Fim da funcao principal*/

int menu(){
    
    int valor;
    
    printf("1 - Cadastrar pessoa na agenda de contato (Nome, Dia de aniversario, Celular, Twitter e facebook)\n"
            "2 - Excluir pessoa a partir do nome\n"
            "3 - Alterar dados a partir do nome\n"
            "4 - Consultar aniversariantes de uma data (dia e mês)\n"
            "5 - Consultar aniversariantes por mes\n"
            "6 - Consultar aniversariantes pela letra inicial do nome\n"
            "7 - Mostrar toda a agenda ordenada pelo nome\n"
            "8 - Mostrar toda a agenda ordenada por mes\n"
            "9 - Sair\n"
            "\nOpcao desejada: ");
    scanf("%i", &valor);
    printf("\n");
    return valor;    
}

void ler_agenda_arquivo(s_contato vetor_agenda[SIZE]){
    
    FILE *fPtr;
    int contador = 0;
    
    if ( ( fPtr = fopen("C:\agenda.txt", "r+") ) == NULL) {
        printf("Não foi possível abrir o arquivo da agenda, ou ela está vazia!\n\n");
        int i;
        for (i = 0; i < SIZE; i++) {
            vetor_agenda[i].nome = "";
        }
    } else {
        while (!feof( fPtr )) {
            fscanf(fPtr, "%s|%d/%d|%s|%s|%s\n", &vetor_agenda[contador].nome ,
                    &vetor_agenda[contador].data[0] ,&vetor_agenda[contador].data[1],
                    &vetor_agenda[contador].celular ,&vetor_agenda[contador].twitter,
                    &vetor_agenda[contador].facebook);
            contador += 1;
        }
    }
    
    fclose(fPtr);
    return vetor_agenda;
}

void cadastrar(s_contato vetor_agenda[SIZE]){
    
    if (vetor_agenda[SIZE - 1].nome != "") {
        printf("A agenda está cheia\n\n");
    } else {
        s_contato hold;
        hold.nome = adquirir_nome();
        if (hold.nome == "|") {
            return;
        }
        hold.data = adquirir_data();
        hold.celular = adquirir_celular();
        hold.twitter = adquirir_twitter();
        hold.facebook = adquirir_facebook();
    }
    
    
    
}

char *adquirir_nome(){
    
    char *nome;
    printf("\nInforme o nome (i para mais informacoes): ");
    scanf("%s", &nome );
    while (nome = "i") {
        printf("Informar o nome eh obrigatorio;\nO evite acentos ortografico\nSe e"
                "soemnte se desejar cacelar insira | ( caso contrario não use esse caractere; \n");
        printf("\nInforme o nome (i para mais informacoes): ");
        scanf("%s", &nome );
    }
    
    return nome;
    
}

unsigned int *adquirir_data(){ /*Adquire uma data de aniversario valida e a retorna, caso o usuario opte por pular retorna 0/0 como data*/
    
    static unsigned int data[2];
    printf("\nInforme a data de aniversário\nformato: dd/mm (ou somente -1 para pular): ");
    scanf("%d", &data[0]);
    if (data[0] == -1) {
        data[0] = 0;
        data[1] = 0;
        return data;
    }
    scanf("/%d", &data[1]);
    while ( (data[0] < 1 || data[0] > 31) && (data[1] < 1 || data[1] > 12)){
        printf("Informe uma data valida por gentileza (ou somente -1 para sair): ");
        scanf("%d", &data[0]);
        if (data[0] == -1) {
            data[0] = 0;
            data[1] = 0;
            return data;
    }
    scanf("/%d", &data[1]);
    }
    
    return data;
    
}

char *adquirir_celular(){ /*Adquire um numero de celualr valido e o retorna*/
    
    char *celular;
    printf("\nInforme o numero telefonico (ou i para mais informacoes, ou somente p para pular): ");
    scanf("%s", %celular);
    while (celular == "i") {
        printf("\nO numero de telefone será lido como um texo, portanto qualquer entrada será aceita como valida, \nrecomendo"
                "usar o seguinte formato dd-cccccccc; para facilitar uma posterior visualizacao\nInforme o numero: ");
        scanf("%s", %celular);
    }
    if (celular == "p") {
        celular = "";
        return celular;
    }
    
    return celular;
    
}

char *adquirir_twitter(){ /*Adquire um twitter nickname e o retorna*/
    
    char *twitter;
    printf("\nInforme o twitter (ou i para mais informacoes, ou somente p para pular): ");
    scanf("%s", %twitter);
    while (twitter == "i") {
        printf("\nO twitter será lido como um texo, portanto qualquer entrada será aceita como valida, \nrecomendo"
                "informar apenas o nickname; para facilitar uma posterior visualizacao\nInforme o twitter: ");
        scanf("%s", %twitter);
    }
    if (twitter == "p") {
        twitter = "";
        return twitter;
    }
    
    return twitter;
    
}

void *adquirir_facebook(){ /*Adquire um facebook nickname e o retorna*/
    
    char *facebook;
    printf("\nInforme o facebook (ou i para mais informacoes, ou somente p para pular): ");
    scanf("%s", %facebook);
    while (facebook == "i") {
        printf("\nO facebook será lido como um texo, portanto qualquer entrada será aceita como valida, \nrecomendo"
                "informar apenas o nickname; para facilitar uma posterior visualizacao\nInforme o facebook: ");
        scanf("%s", %facebook);
    }
    if (facebook == "p") {
        facebook = "";
        return facebook;
    }
    
    return facebook;
    
}