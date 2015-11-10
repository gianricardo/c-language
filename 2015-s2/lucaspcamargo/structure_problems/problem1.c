#include <stdio.h>
#include "../stack/stack.h"
#include "../queue/queue.h"
#include "ctype.h"

void foo(char *in, char *out, int bufsize)
{
  if(!*in) return;
  
  stack_p stack = stack_create(bufsize/2 + 1, sizeof(char));
  queue_p queue = queue_create(bufsize/2 + 1, sizeof(char), 0);
  
  bool isNum, beginNum;
  
  beginNum = isNum = isdigit(in[0]);
  
  while(*in)
  {
    if(isNum)
      stack_push(stack, in);
    else
      queue_push(queue, in);
    
    isNum = !isNum;
    in  ++;
  }
  
  isNum = beginNum;
  
  for(;;)
  {
    if(isNum)
    {
      if(stack_empty(stack))
	break;
      stack_pop(stack, out);
    }
    else
    {
      if(queue_empty(queue))
	break;
      queue_pop(queue, out);
    }
    
    isNum = !isNum;
    out++;
  }
  
  *out = '\0';
  
}


int main(int argc, char **argv) {
    
    char buf[30], out[30];
    
    for(;;)
    {
      printf("? ");
      scanf("%s", buf);
    
      foo(buf, out, 30);
      
      printf("%s\n", out);
    }
    
    return 0;
}
