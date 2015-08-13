/**
 * @file first.c
 * 
 * Nesse programa uma mensagem ao usuário é apresentada.
 * A mensagem é "Hello!".
 * 
 * As bibliotecas usadas são:
 * - stdio.h para a função printf
 * - stdlib.h para a <A HREF="http://en.cppreference.com/w/c/program/EXIT_status">constante de saída com sucesso</A>.
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * Função principal. 
 * 
 * @return código de finalização do programa.
 */
int main(void){
  printf("Hello!\n");
  return EXIT_SUCCESS;
}