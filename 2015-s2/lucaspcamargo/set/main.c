#include <stdio.h>
#include "set.h"

int main(int argc, char **argv) {
    printf("SETS!\n");
    
    set_p a = setCreate();
    set_p b = setCreate();
    set_p c = setCreate();
    
    setInsert(2, a);
    setInsert(3, a);
    setInsert(7, a);
    
    
    setInsert(3, b);
    setInsert(7, b);
    setInsert(9, b);
    
    printf("a is ");
    setPrint(a);
    printf("b is ");
    setPrint(b);
    
    setOpUnion(a, b, c);
    printf("a ∪ b is ");
    setPrint(c);
    
    setOpIntersect(a, b, c);
    printf("a ∩ b is ");
    setPrint(c);
    
    setOpDifference(a, b, c);
    printf("a - b is ");
    setPrint(c);
    
    printf("max(a) is %d\n", setMax(a));
    printf("min(b) is %d\n", setMin(b));
    
    printf("seting a to b...\n");
    setAssign(a, b);
    printf("a is now ");
    setPrint(a);
    
    if(setEquals(a, b))
      printf("a is equal to b\n");
    else
      printf("a is not equal to b\n");
    
    return 0;
}
