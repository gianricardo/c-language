#ifndef BIT_H
#define BIT_H

typedef struct bit_t *bit_p, **bit_pp;

bit_p BitCreate();
void BitDestroy(bit_pp);

int BitGet(bit_p);
void BitSet(bit_p, int);
void BitClear(bit_p);

#endif