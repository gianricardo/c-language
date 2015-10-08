#ifndef BUF_H
#define BUF_H

#include <stdio.h>
#include <stdlib.h>

#define BUF_DEFAULT_CAPACITY 512

typedef struct buf_t
{
  char * v; // the memory buffer
  long c; // count in chars
  long cap; // capacity in chars
} buf_t;

void buf_init_n(buf_t * p, long size)
{
  p->v = malloc(size);
  p->c = 0;
  p->cap = size;
}

void buf_init(buf_t * p)
{
  buf_init_n(p, BUF_DEFAULT_CAPACITY);
}

void buf_destroy(buf_t * p)
{
  free(p->v);
  p->v = 0;
  p->c = 0;
  p->cap = 0;
}

void buf_add(buf_t * p, char value)
{
  if(p->c == p->cap)
  {
    if( p->v = realloc(p->v, p->cap * 2 ) )
    {
      p->cap *= 2;
    }
    else
    {
      printf("Out of memory...\n");
      exit(-1);
    }
  }
  
  p->v[p->c] = value;
  p->c++;
}

void buf_swap(buf_t * p, int ia, int ib)
{
  char swap = p->v[ia];
  p->v[ia] = p->v[ib];
  p->v[ib] = swap;
}

void buf_resize(buf_t * p, int size)
{
  
  if( p->v = realloc(p->v, size) )
  {
    p->cap = size;
    p->c = (p->c < size? p->c : size);
  }
  else
  {
    printf("Out of memory...\n");
    exit(-1);
  }
  
}

int buf_load(buf_t * p, const char * filename)
{
  FILE *f = fopen(filename, "rb");
  
  if(!f)
    return -1;
  
  fseek(f, 0, SEEK_END);
  long fs = ftell(f);
  rewind(f);

  buf_resize(p, fs + 1);
  if(fread(p->v, fs, 1, f) != 1)
    return -2;
  fclose(f);

  p->v[fs] = 0;
  p->c = fs;
  return 0;
}

int buf_store(buf_t * p, const char * filename)
{
  FILE *f = fopen(filename, "w");
  fwrite(p->v, p->c, 1, f);
  fclose(f);
  
  return 0;
}

#endif