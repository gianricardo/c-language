#include "set.h"
#include "limits.h"

#define SET_SIZE 128

#define ELEM_MAX INT_MAX
#define ELEM_MIN INT_MIN

typedef struct set_t 
{
  int c;
  elem_t v[];
} set_t;

