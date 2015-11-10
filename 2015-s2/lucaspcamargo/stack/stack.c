#include <stdlib.h>
#include <string.h>
#include "stack_p.h"

char* s_get(stack_p p, int i)
{
  return p->data + i * p->elem_s;
}

stack_p stack_create(int capacity, int elem_s)
{
  stack_p ret = malloc(sizeof(stack_t));
  if(ret)
  {
    ret->cap = capacity;
    ret->top = -1;
    ret->elem_s = elem_s;
    ret->data = malloc(elem_s * capacity);
    if(!ret->data)
    {
      free(ret);
      ret = 0;
    }
  }
  return ret;
}

void stack_destroy(stack_p p)
{
  if(!p) return;
  
  free(p->data);
  free(p);
}

void stack_push(stack_p p, void* src)
{
  if(!p) return;
  if(stack_full(p)) return;
  
  memcpy(s_get(p, p->top + 1), src, p->elem_s);
  p->top++;
  
}


void stack_pop(stack_p p, void* dest)
{
  if(!p) return;
  if(stack_empty(p)) return;
  
  memcpy(dest, s_get(p, p->top), p->elem_s);
  p->top--;
  
}

bool stack_full(stack_p p)
{
  if(!p) return false;
  return p->top == p->cap - 1;
}

bool stack_empty(stack_p p)
{
  if(!p) return false;
  return p->top == -1;
}

int stack_capacity(stack_p p)
{
  if(!p) return 0;
  return p->cap;
}

void stack_clear(stack_p p)
{
  if(!p) return;
  p->top = -1;
}

int stack_size(stack_p p)
{
  if(!p) return 0;
  return p->top + 1;
}

int stack_elem_size(stack_p p)
{
  if(!p) return 0;
  return p->elem_s;
}

