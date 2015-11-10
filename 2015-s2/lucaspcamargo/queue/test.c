#include <stdio.h>
#include "queue.h"

int priority_cmp_int(void * a, void * b)
{
  int ai = (*((int*) a)) % 4;
  int bi = (*((int*) b)) % 4;
  
  if(ai == bi)
    return 0;
  else if(ai > bi)
    return 1;
  else 
    return -1;
}

int main(int argc, char **argv) {
  
  queue_p queue = queue_create(10, sizeof(int), &priority_cmp_int);
  
  for(int i = 1; i <= 10; i++)
  {
    queue_push(queue, &i);
    printf("pushed %d\n", i);
  }
  
  int popd;
  
  while(!queue_empty(queue))
  {
    queue_pop(queue, &popd);
    printf("popped %d\n", popd);
  }
  
  if(queue_empty(queue))
    printf("queue empty\n");
  else
    printf("queue not empty\n");
  
  return 0;
}
