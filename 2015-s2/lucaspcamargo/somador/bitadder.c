#include "bitadder_p.h"
#include "common.h"
#include "port.h"

bitadder_p BitAdderCreate()
{
  bitadder_p p = ALLOC_NEW(bitadder_t);
  
  p->haAand = PortCreate(PORT_AND);
  p->haAxor = PortCreate(PORT_XOR);
  p->haBand = PortCreate(PORT_AND);
  p->haBxor = PortCreate(PORT_XOR);
  p->outOR  = PortCreate(PORT_OR);
  
  return p;
}

void BitAdderDestroy(bitadder_pp pp)
{
  if(*pp)
  {
    PortDestroy(&(*pp)->haAand);
    PortDestroy(&(*pp)->haAxor);
    PortDestroy(&(*pp)->haBand);
    PortDestroy(&(*pp)->haBxor);
    PortDestroy(&(*pp)->outOR);
  }
  
  DESTROY_PP(pp);
}

void BitAdderExec(bit_p inA, bit_p inB, bit_p inC, bit_p outS, bit_p outC)
{

}
