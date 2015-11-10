#include <stdio.h>
#include "stack.h"

int main()
{
  stack_p stack = stack_create(100, sizeof(int));
  
  int in, tmp;
  printf("Input number to convert: ");
  scanf("%d", &in);
  
  while(in)
  {
    tmp = in%2;
    stack_push(stack, &tmp);
    in /= 2;
  }	
   
  while(!stack_empty(stack))
  {
    stack_pop(stack, &tmp);
    printf("%d", tmp);
  }
  printf("\n");
  
  return 0;
}