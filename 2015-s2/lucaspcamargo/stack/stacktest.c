#include <stdio.h>
#include "stack.h"

int main(int argc, char **argv) {
  
  stack_p stack = stack_create(100, sizeof(int));
  
  for(int i = 1; i <= 10; i++)
  {
    stack_push(stack, &i);
    printf("pushed %d\n", i);
  }
  
  int popd;
  
  while(!stack_empty(stack))
  {
    stack_pop(stack, &popd);
    printf("popped %d\n", popd);
  }
  
  if(stack_empty(stack))
    printf("stack empty\n");
  else
    printf("stack not empty\n");
  
  return 0;
}
