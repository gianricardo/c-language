/**
 * @file buf.h
 * @author Lucas Camargo
 * @date Oct 2015
 * @brief A byte buffer with auxiliary functions.
 */

#ifndef BUF_H
#define BUF_H

#include <stdio.h>
#include <stdlib.h>

/**
 * Initial buffer size
 */
#define BUF_DEFAULT_CAPACITY 512

/**
 * Holds the data for a character buffer
 */
typedef struct buf_t
{
  char * v; // the memory buffer
  long c; // count in chars
  long cap; // capacity in chars
} buf_t;

/**
 * Initializes a buffer with capacity n
 */
void buf_init_n(buf_t * p, long size)
{
  p->v = malloc(size);
  p->c = 0;
  p->cap = size;
}

/**
 * Initializes a buffer with default capacity
 */
void buf_init(buf_t * p)
{
  buf_init_n(p, BUF_DEFAULT_CAPACITY);
}

/**
 * Destroys a buffer
 */
void buf_destroy(buf_t * p)
{
  free(p->v);
  p->v = 0;
  p->c = 0;
  p->cap = 0;
}

/**
 * Sets the buffer capacity
 */
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

/**
 * Inserts a character into the buffer
 */
void buf_add(buf_t * p, char value)
{
  if(p->c == p->cap)
  {
    buf_resize(p, p->cap * 2);
  }
  
  p->v[p->c] = value;
  p->c++;
}


/**
 * Loads the buffer from the file "filename"
 * @returns Zero on success, something else on error
 */
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

/**
 * Stores the buffer to the file "filename"
 * @returns Zero on success, something else on error
 */
int buf_store(buf_t * p, const char * filename)
{
  FILE *f = fopen(filename, "w");
  fwrite(p->v, p->c, 1, f);
  fclose(f);
  
  return 0;
}

#endif