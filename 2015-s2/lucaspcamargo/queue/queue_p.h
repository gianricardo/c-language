
#include "queue.h"
#include "stdint.h"

typedef struct queue_t
{
  int cap;
  int head;
  int tail;
  int elem_s;
  compare_t priorityCmpFn;
  uint8_t *data;
} queue_t;