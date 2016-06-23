#ifndef _COMUM_H
#define _COMUM_H

typedef enum {SUCESSO,INVALIDO,BAD_ALLOCATION, POSICAO_INVALIDA,
              ESTADO_INVALIDO,OVERFLOW,UNDERFLOW, DUPLICADO} codigo_erro;
              
typedef enum {SEQUENCIAL, CIRCULAR} tipo_lista; 

typedef enum {SEM_ORDEM, 
              CRESCENTE, DECRESCENTE}classificacao_lista;            

#endif
