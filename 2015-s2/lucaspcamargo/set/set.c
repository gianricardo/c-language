#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "set_p.h"

set_p setCreate()
{
  return (set_p) calloc(sizeof(set_t), 1);
}

void setDestroy(set_p p)
{
  if(!p) return;
  free(p);
}

bool setMember(elem_t x, set_p p)
{
  if(!p) return false;
  
  for(int i = 0; i < p->c; i++)
  {
    if(p->v[i] == x)
      return true;
  }
  return false;
}

void setMakeEmpty(set_p p)
{
  if(!p) return;
  
  p->c = 0;
}

void setInsert(elem_t x, set_p p)
{
  if(!p) return;
  if(setMember(x, p)) return;
  
  p->v[p->c] = x;
  p->c++;
}

void setRemove(elem_t x, set_p p)
{
  if(!p) return;
  
  for(int i = 0; i < p->c; i++)
  {
    if(p->v[i] == x)
    {
      memmove(p->v+i, p->v+i+1, sizeof(elem_t) * (SET_SIZE-i-1) );
      p->c --;
    }
  }
}

void setOpUnion(set_p a, set_p b, set_p c)
{
  if(!(a && b && c)) return;
  setMakeEmpty(c);
  
  for(int i = 0; i < a->c; i++)
  {
    setInsert(a->v[i], c);
  }
  
  for(int i = 0; i < b->c; i++)
  {
    setInsert(b->v[i], c);
  }
}

void setOpIntersect(set_p a, set_p b, set_p c)
{
  if(!(a && b && c)) return;
  setMakeEmpty(c);
  
  for(int i = 0; i < a->c; i++)
  {
    if(setMember(a->v[i], b))
      setInsert(a->v[i], c);
  }

}

void setOpDifference(set_p a, set_p b, set_p c)
{
  if(!(a && b && c)) return;
  setMakeEmpty(c);
  
  for(int i = 0; i < a->c; i++)
  {
    if(!setMember(a->v[i], b))
      setInsert(a->v[i], c);
  }
}

void setAssign(set_p a, set_p b)
{
  if(!(a && b)) return;
  memcpy(a, b, sizeof(set_t));
}

bool setEquals(set_p a, set_p b)
{
  if(!(a && b)) return false;
  
  for(int i = 0; i < a->c; i++)
  {
    if(!setMember(a->v[i], b))
      return false;
  }
  
  for(int i = 0; i < b->c; i++)
  {
    if(!setMember(b->v[i], a))
      return false;
  }
  
  return true;
}

elem_t setMax(set_p a)
{
  if(!a) return ELEM_MAX;
  elem_t max = ELEM_MIN;
  
  for(int i = 0; i < a->c; i++)
  {
    if(a->v[i] > max)
      max = a->v[i];
  }
  
  return max;
}

elem_t setMin(set_p a)
{
  if(!a) return ELEM_MIN;
  elem_t min = ELEM_MAX;
  
  for(int i = 0; i < a->c; i++)
  {
    if(a->v[i] < min)
      min = a->v[i];
  }
  
  return min;
}

void setPrint(set_p p)
{
  if(!p) return;
  
  for(int i = 0; i < p->c; i++)
  {
    printf("%d ", p->v[i]);
  }
  printf("\n");
}

