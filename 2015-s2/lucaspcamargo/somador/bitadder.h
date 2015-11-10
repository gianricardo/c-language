#ifndef BITADDER_H
#define BITADDER_H

#include "bit.h"

typedef struct bitadder_t *bitadder_p, **bitadder_pp;

bitadder_p BitAdderCreate();
void BitAdderDestroy(bitadder_pp);

void BitAdderExec(bit_p inA, bit_p inB, bit_p inC, bit_p outS, bit_p outC);

#endif