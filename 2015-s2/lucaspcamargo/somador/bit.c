#include "bit_p.h"
#include "common.h"

bit_p BitCreate()
{
  return ALLOC_NEW(bit_t);
}

void BitDestroy(bit_pp pp)
{
  DESTROY_PP(pp);
}

int BitGet(bit_p p)
{
  P_GUARD_V(0);
  
  return p->v;
}

void BitSet(bit_p p, int v)
{
  P_GUARD;
  
  p->v = v;
}
  
void BitClear(bit_p p)
{
  P_GUARD;
  
  p->v = 0;
}
