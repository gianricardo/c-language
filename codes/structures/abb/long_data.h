/*
 * long_data.h
 *
 *  Created on: Jun 23, 2016
 *      Author: gian
 */

#ifndef LONG_DATA_H_
#define LONG_DATA_H_

//
//funções específicas do tipo de informação
//
long* crial(long val);
void destroi_long(void *data);
void mostra_long(void *data);
int compara_long(void *key1, void* key2);//0=igual; >0 key2 maior e key 1 menor; <0 key1 maior e key2 menor


#endif /* LONG_DATA_H_ */
