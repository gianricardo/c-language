#ifndef listSE_H
#define listSE_H

typedef struct list_se List_SE;
enum error_code {SUCCESS, INVALID, BAD_ALLOCATION, UNDERFLOW, OVERFLOW}; 
typedef enum error_code Error_code;

List_SE* create_list_se();
void destroy_list_se(List_SE** list);
Error_code push_back(List_SE* list, int niv,double ndv);
Error_code push_front(List_SE* list, int niv,double ndv);
Error_code pop_back(List_SE* list, int* niv,double* ndv);
Error_code pop_front(List_SE* list, int* niv,double* ndv);
Error_code seek_insert(long position,List_SE* list, int niv,double ndv);
Error_code seek_destroy(long position,List_SE* list, int* niv,double* ndv);
Error_code seek_lse(long position,List_SE* list, int* niv,double* ndv);
long size_list_se(List_SE* list);

//remove por valor da celula
//
#endif

