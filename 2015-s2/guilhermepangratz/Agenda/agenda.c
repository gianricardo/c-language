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

/*Structs - Todos as estruturas serão nomeadas co m oprefixo "s_"*/


typedef struct {
    char *nome; /*Nome, contendo até 40 caracteres*/
    int dia, mes; /*Data de aniversario*/
    int ddd, celular;
    char twitter[15], facebook[30];
} s_contato; /*s_contato - Armazenara todos os dados de cada contato*/

/*Protótipos das Funções*/

void ler_agenda_arquivo(s_contato vetor_agenda[30]); /*Função que lê o arquivo contendo os dados da agenda e retorna um vetor de s_contato*/

void cadastrar(s_contato * contatos); /*Função que adquire os dados de um contato e o posiciona na agenda*/

char *adquirir_nome(); /*Adquire um nome valido e o retorna*/

int menu(); /*Funcão que oferece o menu e pede que seja escolhida uma opção*/

/*Fim dos protótipos*/

/*Inicio da funcao principal*/
int main() { 
    
    s_contato contatos[30];
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

void ler_agenda_arquivo(s_contato vetor_agenda[30]){
    
    FILE *fPtr;
    int contador = 0;
    
    if ( ( fPtr = fopen("C:\agenda.txt", "r+") ) == NULL) {
        printf("Não foi possível abrir o arquivo da agenda, ou ela está vazia!\n\n");
        int i;
        for (i = 0; i < 30; i++) {
            vetor_agenda[i].nome = "";
        }
    } else {
        while (!feof( fPtr )) {
            fscanf(fPtr, "%s-%d/%d-(%d)%d-%s-%s\n", &vetor_agenda[contador].nome , &vetor_agenda[contador].dia , 
                    &vetor_agenda[contador].mes, &vetor_agenda[contador].ddd,&vetor_agenda[contador].celular ,
                    &vetor_agenda[contador].twitter, &vetor_agenda[contador].facebook);
            contador += 1;  
        }
    }
    
    fclose(fPtr);
    return vetor_agenda;
}

void cadastrar(s_contato * contatos){
    
    char *ultimo_nome = contatos[29].nome;
    
    if (ultimo_nome != "") {
        printf("A agenda está cheia\n\n");
    } else {
        s_contato hold;
        hold.nome = adquirir_nome();
    }
    
}

char *adquirir_nome(){
    
    char *nome;
    printf("\nInforme o nome: ");
    scanf("%s", &nome );
    
    return nome;
    
}