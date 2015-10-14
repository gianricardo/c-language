#ifndef PILHA_ARRAY_H_INCLUDED
#define PILHA_ARRAY_H_INCLUDED

typedef struct pilha Pilha;
enum error_code {SUCCESS, INVALID, UNDERFLOW, OVERFLOW}; 
typedef enum error_code Error_code;


Pilha* criaPilha(int capacidade_maxima, int size_element);
int emptyPilha(Pilha* p);
Error_code pushPilha(Pilha* p, void *novo);
Error_code popPilha(Pilha* p, void *r);
int topPilha(Pilha* p, void * val);
void clearPilha(Pilha *p);
int fullPilha(Pilha *p);
int sizePilha(Pilha *p);
int maxPilha(Pilha *p);
void destroiPilha(Pilha **p);

//full,size,max,clear


#endif // PILHA_ARRAY_H_INCLUDED
