#ifndef COMMON_H
#define COMMON_H

#include <stdlib.h>
#include <ctype.h>

#define ALLOC_NEW(x) (x *) malloc(sizeof(x)); 

#define DESTROY_PP(pp) \
if(pp)\
  {\
    if(*pp)\
    {\
      free(*pp);\
      *pp = NULL;\
    }\
  }
  
#define P_GUARD_V(x) if(!p){return(x);}
#define P_GUARD if(!p){return;}

#endif