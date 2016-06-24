#ifndef _COMUM_H
#define _COMUM_H

typedef enum {SUCESSO,INVALIDO,BAD_ALLOCATION, POSICAO_INVALIDA,
              ESTADO_INVALIDO,OVERFLOW,UNDERFLOW, DUPLICADO, VALOR_INVALIDO} codigo_erro;
              
typedef enum {SEQUENCIAL, CIRCULAR} tipo_lista; 

typedef enum {SEM_ORDEM, 
              CRESCENTE, DECRESCENTE}classificacao_lista;

const char* codigo_erro_cstr(codigo_erro erro_n);

#endif
