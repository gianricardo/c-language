/* 
 * File:   agenda.c
 * Author: GuilhermeAugusto
 *
 * Created on 15 de Setembro de 2015, 16:22
 */

#include "funcoes_agenda.h"

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
                excluir_pelo_nome(contatos);
                break;
            case 3 : 
                alterar_pelo_nome(contatos);
                break;
            case 4 : 
                aniversariantes_data(contatos);
                break;
            case 5 : 
                aniversariantes_mes(contatos);
                break;
            case 6 : 
                aniversariantes_inicial(contatos);
                break;
            case 7 : 
                mostrar_agenda_nome(contatos, 0, SIZE); 
                break;
            case 8 : 
                mostrar_agenda_mes(contatos);
                break;
            case 9 : 
                if (gravar(contatos)) return 0;
            default : printf("entre um valor valido\n\n");
        }
    }
    
    return 0;
} /*Fim da funcao principal*/
