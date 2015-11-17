#ifndef listSE_f_H
#define listSE_f_H

#include "../common/5603_common.h"

typedef struct list_se_f List_SE_f;

List_SE_f* lsef_create();
void 	   lsef_destroy(List_SE_f** list);
Error_code lsef_push_back(List_SE_f* list, int niv,double ndv);
Error_code lsef_push_front(List_SE_f* list, int niv,double ndv);
Error_code lsef_pop_back(List_SE_f* list, int* niv,double* ndv);
Error_code lsef_pop_front(List_SE_f* list, int* niv,double* ndv);
Error_code lsef_seek_insert(long position,List_SE_f* list, int niv,double ndv);
Error_code lsef_seek_destroy(long position,List_SE_f* list, int* niv,double* ndv);
Error_code lsef_seek(long position,List_SE_f* list, int* niv,double* ndv);
long	   lsef_size(List_SE_f* list);
void 	   lsef_print(List_SE_f* list,void (*visit)(int intg,double doble));

//remove por valor da celula
//
#endif

