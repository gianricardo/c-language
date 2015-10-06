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

void mostrar_agenda_nome(s_contato vetor_agenda[SIZE]);

int gravar(s_contato vetor_agenda[SIZE]); /*grava os dados do vetor de contatos no arquivo*/

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
            case 2 : 
                break;
            case 3 : break;
            case 4 : break;
            case 5 : break;
            case 6 : break;
            case 7 : 
                mostrar_agenda_nome(contatos); 
                break;
            case 8 : break;
            case 9 : 
                if (gravar(contatos)) return 0;
            default : printf("entre um valor valido\n\n");
        }
    }
    
    return 0;
} /*Fim da funcao principal*/

void clear (void) {    
  while ( getchar() != '\n' );
}

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
    
    char buf_opcao[BUFSIZ];
    fgets(buf_opcao, BUFSIZ, stdin);
    
    printf("\n");
    return (buf_opcao[0] - '0');
}

void ler_agenda_arquivo(s_contato vetor_agenda[SIZE]){
    
    FILE *fPtr;
    int contador = 0;
    
    if ( ( fPtr = fopen("agenda.txt", "r+") ) == NULL) {
        printf("Não foi possível abrir o arquivo da agenda, ou ela está vazia!\n\n");
        int i;
        for (i = 0; i < SIZE; i++) {
            strcpy(vetor_agenda[i].nome, "");
            strcpy(vetor_agenda[i].data, "");
            strcpy(vetor_agenda[i].celular, "");
            strcpy(vetor_agenda[i].facebook, "");
            strcpy(vetor_agenda[i].twitter, "");
        }
    } else {
        char segura_linha[170];
        while (!feof( fPtr )) {
            fgets(segura_linha, 170, fPtr);
            
            if(!strtok(segura_linha, "\n")) break;
           
            strcpy(vetor_agenda[contador].nome, strtok(segura_linha, "|"));
            strcpy(vetor_agenda[contador].data, strtok(NULL, "|"));
            strcpy(vetor_agenda[contador].celular, strtok(NULL, "|"));
            strcpy(vetor_agenda[contador].twitter, strtok(NULL, "|"));
            strcpy(vetor_agenda[contador].facebook, strtok(NULL, "|"));
            strcpy(segura_linha, "");
            /*printf("\ncontato :-%s-%s-%s-%s-%s-\n", vetor_agenda[contador].nome, vetor_agenda[contador].data,
            vetor_agenda[contador].celular, vetor_agenda[contador].twitter, vetor_agenda[contador].facebook);*/
            contador += 1;
        }
    }
    fclose(fPtr);
}

void cadastrar(s_contato vetor_agenda[SIZE]){
    
    if (strcmp(vetor_agenda[SIZE - 1].nome, "")) {
        printf("A agenda está cheia\n\n");
    } else {
        s_contato hold;
        adquirir_nome(hold.nome);
        if (!strcmp(hold.nome, "*")) { return;}
        adquirir_data(hold.data);
        adquirir_celular(hold.celular);
        adquirir_twitter(hold.twitter);
        adquirir_facebook(hold.facebook);
        
        printf("\nDados Recebidos:\n");
        printf("nome -> %s\n", hold.nome);
        printf("data de aniversario -> %s\n", hold.data);
        printf("celular -> %s\n", hold.celular);
        printf("twitter -> %s\n", hold.twitter);
        printf("facebook -> %s\n", hold.facebook);
        
        char confirmar[BUFSIZ];
        printf("Enter para confirmar (Qualquer outra entrada para cancelar): ");
        fgets(confirmar, BUFSIZ, stdin);
        if (strcmp(confirmar, "\n")){
            printf("CANCELADO!\n\n");
            return;
        }
        printf("CONFIRMADO!\n\n");
        
        alocar_contato(vetor_agenda, hold);
        
        
    }
}

void adquirir_nome(char nome[100]){
    
    char buff_nome[BUFSIZ];
    printf("NOME\n(\"!\" para mais informacoes ou * para cancelar)\nInforme o nome: ");
    
    fgets(buff_nome, BUFSIZ, stdin);
    strtok(buff_nome, "\n");
    
    while (!strcmp(buff_nome, "!") || strlen(buff_nome) > 99) {
        printf("\nInformar o nome eh obrigatorio;\nEvite acentos ortograficos\nSe e"
                " somente se desejar cacelar insira somente \"*\" ( caso contrario não "
                "use esse caractere. Use no maximo 100 caracteres;\n");
        printf("\nInforme o nome (\"!\" para mais informacoes): ");
        fgets(buff_nome, BUFSIZ, stdin);
        strtok(nome, "\n");
    }
    
    strcpy(nome, buff_nome);   
}

void adquirir_data(char data[6]){ /*Adquire uma data de aniversario valida e a retorna, caso o usuario opte por pular retorna 0/0 como data*/
    
    char array_data[BUFSIZ], dia[3], mes[3];
    printf("\nDATA DE ANIVERSÁRIO\nformato dd/mm ou somente -1 para pular: ");
        
    while (1) {
        
        fgets(array_data, BUFSIZ, stdin);
        strtok(array_data, "\n");
        
        if (!strcmp(array_data, "-1")) {
            strcpy(data, "");
            break;
        }
        if ( isdigit(array_data[0]) && isdigit(array_data[1]) && array_data[2] == '/' &&
            isdigit(array_data[3]) && isdigit(array_data[4]) && array_data[5] == '\0') {
            
            strncpy(dia, array_data, 2);
            dia[2] = '\0';
            strncpy(mes, array_data + 3 , 3);
            
            if (atoi(dia) > 0 && atoi(dia) < 32 && atoi(mes) > 0 && atoi(mes) < 13) {
                strcpy(data, array_data);
                break;
            }
        }
        printf("\npor favor, informe uma data valida dentro do formato dd/mm: ");
    }     
}

void adquirir_celular(char celular[13]){ /*Adquire um numero de celualr valido e o retorna*/
    
    strcpy(celular,"");
    
    int i, check;
    
    char ddd[BUFSIZ] = "", numero[BUFSIZ];
    
    printf("\nNUMERO TELEFONICO");
    while (1) {
        if (!strcmp(ddd,"")) {
            printf("\nInforme o DDD ou -1 para cancelar:");
            fgets(ddd, BUFSIZ, stdin);
            strtok(ddd, "\n");
            if(!strcmp(ddd,"-1")) return;
            if (!isdigit(ddd[0]) || !isdigit(ddd[1]) || ddd[2] != '\0'){
                printf("\nInforme somente os dois digitos do DDD, exemplo: 47");
                strcpy(ddd,"");
                continue;
            }
        }
        printf("\nInforme o numero do telefone ou -1 para pular:");
        fgets(numero, BUFSIZ, stdin);
        strtok(numero, "\n");
        if(!strcmp(numero,"-1")) return;
        for (i = 0; numero[i] != '\0' ; i++) {
            if (!isdigit(numero[i]) || i > 9) {
                check = 0;
                break;
            } else {
                check = 1;
            }
        }
        
        if (check) break;
        
    }
    
    strcat(celular,(strcat(strcat(ddd, "-"),numero)));
}

void adquirir_twitter(char twitter[16]){ /*Adquire um twitter nickname e o retorna*/
    char buf[BUFSIZ] = "                ";
    printf("\nTWITTER");
    while (strlen(buf) > 15){
        printf("\nTwitter nick name (15 caracteres) ou -1 para pular: ");
        fgets(buf, BUFSIZ, stdin);
        strtok(buf, "\n");
        if (!strcmp(buf, "-1")) return;
    }
    strcpy(twitter, buf);    
}

void adquirir_facebook(char facebook[30]){ /*Adquire um facebook nickname e o retorna*/
    char buf[BUFSIZ] = "                                         ";
    printf("\nFACEBOOK");
    while (strlen(buf) > 30){
        printf("\nFacebook nick name (30 caracteres) ou -1 para pular: ");
        fgets(buf, BUFSIZ, stdin);
        strtok(buf, "\n");
        if (!strcmp(buf, "-1")) return;
    }
    strcpy(facebook, buf); 
}

void alocar_contato(s_contato vetor_agenda[SIZE], s_contato contato) {
    int i;   
    for ( i = SIZE - 1; i > 0 ; i-- ) {       
        if (strcmp(contato.nome, vetor_agenda[i-1].nome) >= 0 && strcmp(vetor_agenda[i-1].nome, "")) {
            vetor_agenda[i] = contato;
            break;
        }        
        vetor_agenda[i] = vetor_agenda[i-1];
    }
    
    if (i == 0) {
        vetor_agenda[i] = contato;
    }
    
}

void mostrar_agenda_nome(s_contato vetor_agenda[SIZE]){
    int i;
    printf("\nnome | data de aniversario | celular | twitter | facebook\n");
    for (i = 0; i < SIZE && strcmp(vetor_agenda[i].nome, ""); i++){
        printf("\n%s | %s | %s | %s | %s", vetor_agenda[i].nome, vetor_agenda[i].data,
                vetor_agenda[i].celular, vetor_agenda[i].twitter, vetor_agenda[i].facebook);
    }
    printf("\n\n");
}

int gravar(s_contato vetor_agenda[30]) {
    
    int contador;
    FILE *fPtr;
    
    if ( ( fPtr = fopen("agenda.txt", "w") ) == NULL) { 
        printf("\nNao foi possivel salvar as alteracoes! Aperte enter para sair "
                "sem salvar, qualquer outra entrada para voltar: ");
        char sair[BUFSIZ];
        fgets(sair, BUFSIZ, stdin);
        if (strcmp(sair, "\n")) {
            return 0;
        }
    } else {
        for (contador = 0; contador < SIZE && strcmp(vetor_agenda[contador].nome, ""); contador++) {
            fprintf(fPtr, "%s|%s|%s|%s|%s\n", 
                    &vetor_agenda[contador].nome ,
                    &vetor_agenda[contador].data,
                    &vetor_agenda[contador].celular ,
                    &vetor_agenda[contador].twitter,
                    &vetor_agenda[contador].facebook);
        }
    }
    return 1;
}