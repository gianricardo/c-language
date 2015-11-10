
#include "stdbool.h"

typedef struct set_t *set_p, **set_pp;
typedef int elem_t;

set_p setCreate();
void setDestroy(set_p p);

void setMakeEmpty(set_p p);
bool setMember(elem_t x, set_p p);
void setInsert(elem_t x, set_p p);
void setRemove(elem_t x, set_p p);

void setOpUnion(set_p a, set_p b, set_p c);
void setOpIntersect(set_p a, set_p b, set_p c);
void setOpDifference(set_p a, set_p b, set_p c);

void setAssign(set_p a, set_p b);
elem_t setMin(set_p a);
elem_t setMax(set_p a);
bool setEquals(set_p a, set_p b);

void setPrint(set_p p);