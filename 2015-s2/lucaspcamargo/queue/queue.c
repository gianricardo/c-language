#include <stdlib.h>
#include <string.h>
#include "queue_p.h"

char* get(queue_p p, int i)
{
  return p->data + i * p->elem_s;
}

int advance(queue_p p, int *i)
{
  (*i) = (*i + 1) % p->cap;
}

queue_p queue_create(int capacity, int elem_s, compare_t comparisonFunc)
{
  queue_p ret = malloc(sizeof(queue_t));
  if(ret)
  {
    ret->cap = capacity + 1;
    ret->tail = 0;
    ret->head = 0;
    ret->elem_s = elem_s;
    ret->priorityCmpFn = comparisonFunc;
    ret->data = malloc(elem_s * (capacity + 1)); // we need an extra space for where the tail is going to point
    if(!ret->data)
    {
      free(ret);
      ret = 0;
    }
  }
  return ret;
}

void queue_destroy(queue_p p)
{
  if(!p) return;
  
  free(p->data);
  free(p);
}

#include <stdio.h>

#define queue_enqueue queue_push
void queue_push(queue_p p, void* src)
{
  if(!p) return;
  if(queue_full(p)) return;
  
  if(!p->priorityCmpFn)
  {
    memcpy(get(p, p->tail), src, p->elem_s);
  }
  else
  {
    // has priority
    if(queue_empty(p))
      memcpy(get(p, p->tail), src, p->elem_s);
    else
    {
      int virtualTail = p->tail;
      while(p->tail < p->head) p->tail +=  p->cap;
      
      int i; // will hold the index of insertion place
      for(i = p->head; i < (virtualTail); i++)
      {
	if(p->priorityCmpFn(src, get(p, (i) % p->cap)) < 0)
	  break;
      }
      
      // i is the position of insertion
      for(int j = virtualTail; j > i; j--)
      {
	memcpy(get(p, j%p->cap), get(p, (j-1)%p->cap), p->elem_s);
      }
      
      memcpy(get(p, i%p->cap), src, p->elem_s);
      
    }
  }
  // always advance tail
  advance(p, &(p->tail));
}

#define queue_dequeue queue_pop
void queue_pop(queue_p p, void* dest)
{
  if(!p) return;
  if(queue_empty(p)) return;
  
  if(dest) memcpy(dest, get(p, p->head), p->elem_s);
  advance(p, &(p->head));
  
}

bool queue_full(queue_p p)
{
  if(!p) return false;
  return ((p->tail + 1) % p->cap) == p->head;
}

bool queue_empty(queue_p p)
{
  if(!p) return false;
  return p->tail == p->head;
}

int queue_capacity(queue_p p)
{
  if(!p) return 0;
  return p->cap - 1; // capacity exposed is one less
}

void queue_clear(queue_p p)
{
  if(!p) return;
  p->tail = 0;
  p->head = 0;
}

int queue_size(queue_p p)
{
  if(!p || queue_empty(p)) return 0;
  if(p->tail > p->head)
    return p->tail - p->head;
  else
    return p->cap - (p->head - p->tail - 1);
}

int queue_elem_size(queue_p p)
{
  if(!p) return 0;
  return p->elem_s;
}

void queue_visit(queue_p p, visit_fn_t visitor_fn)
{
  int i = 0;
  int size = queue_size(p);
  
  while(i < size && visitor_fn(get(p, (p->head + i) % p->cap)))
  { 
    i++;
  }
}

void* queue_peek(queue_p p)
{
  return get(p, p->head);
}

