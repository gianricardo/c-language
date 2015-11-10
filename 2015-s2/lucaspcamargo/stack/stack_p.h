
#include "stack.h"
#include "stdint.h"

typedef struct stack_t
{
  int cap;
  int top;
  int elem_s;
  uint8_t *data;
} stack_t;