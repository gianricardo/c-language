#ifndef VEC_H
#define VEC_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "buf.h"
#include "string.h"

#define VEC_INITIAL_CAPACITY 128

//  main optimization parameters
#define VEC_MERGESORT_THR 1000
#define VEC_BUBBLESORT_THR 20

typedef struct dblvec_t
{
  double * v; // the memory buffer
  long c; // count in doubles
  long cap; // capacity in doubles
} dblvec_t;

void vec_init(dblvec_t * p)
{
  p->v = malloc(sizeof(double) * VEC_INITIAL_CAPACITY);
  p->c = 0;
  p->cap = VEC_INITIAL_CAPACITY;
}

void vec_add(dblvec_t * p, double value)
{
  if(p->c == p->cap)
  {
    if( p->v = realloc(p->v, p->cap * 2 * sizeof(double)) )
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

void vec_swap(dblvec_t * p, long ia, long ib)
{
  double swap = p->v[ia];
  p->v[ia] = p->v[ib];
  p->v[ib] = swap;
}

void vec_bubble(dblvec_t * p)
{
  double swap;
  int did = 1, n = p->c;
  while(did)
  {
    did = 0;
    for(int i = 0; i < n -1; i++)
    {
      if(p->v[i] > p->v[i+1])
      {
	vec_swap(p, i, i+1);
	did = 1;
      }
    }
  }
}

int vec_partition( double * p_buf, long lf, long rt) 
{
  
  double pv = p_buf[lf];
  int i = lf; 
  int j = rt + 1;
  double swap;
	      
  while(1)
  {
    do {
      ++i;
    } while( p_buf[i] <= pv && i <= rt );
    do {
      --j;
    } while( p_buf[j] > pv );
    if( i >= j ) break;
    swap = p_buf[i]; p_buf[i] = p_buf[j]; p_buf[j] = swap;
  }
  swap = p_buf[lf]; p_buf[lf] = p_buf[j]; p_buf[j] = swap;
  return j;
}

void vec_quicksort(double * p_buf, long lf, long rt)
{
  
  int part;

  if( lf < rt ) 
  {
    part = vec_partition( p_buf, lf, rt);
    vec_quicksort( p_buf, lf, part-1);
    vec_quicksort( p_buf, part+1, rt);
  }
  
}

void vec_sort_smart(dblvec_t * p, double * scratch, long lf, long rt); // fwd def

void vec_mergesort(dblvec_t * p, double * scratch, long lf, long rt)
{
  long num = (rt-lf + 1);
  if(num < 1)
    return;
  
  // mergesort needs a scratch buffer
  int ownsScratch = 0;
  if(!scratch)
  {
    scratch = (double *) malloc( p->c * sizeof(double) );
    if(!scratch)
    {
      printf("Failed to allocate scratch buffer for merge sort");
    }
    else{
      memset(scratch, 0xff, p->c * sizeof(double));
    }
  }
  
  // mergesort goes here
  
  // midindex is the beginning of the second split
  long midIndex = lf + (rt - lf + 1) / 2;
  
  // let's sort the subarrays using what is best
  vec_sort_smart(p, scratch, lf, midIndex - 1);
  vec_sort_smart(p, scratch, midIndex, rt);
  
  // assemble final array in the swap buffer
  long ia = lf;
  long ib = midIndex;
  long count = 0;
  while(ia < midIndex && ib <= rt)
  {
    if(p->v[ia] < p->v[ib])
    {
      scratch[lf + count++] = p->v[ia++];
    }else
    {
      scratch[lf + count++] = p->v[ib++];
    }
  }
  
  while(ia < midIndex) scratch[lf + count++] = p->v[ia++];
  while(ib <= rt) scratch[lf + count++] = p->v[ib++];
  
  
  // copy result back to array
  memcpy((p->v + lf), (scratch + lf), num * sizeof(double) );
  
  // free scratch buffer if applies
  if(ownsScratch)
  {
    free(scratch);
  }
  
}

void vec_sort_smart(dblvec_t * p, double * scratch, long lf, long rt)
{
  long n = rt-lf + 1;
 
  // this will decide the sorting algorithm used based on the size of the array
  // main optimization heuristic are these constants
  
  if(n > VEC_MERGESORT_THR)
  {
    // do a mergesort
    vec_mergesort(p, scratch, lf, rt);
  }
  else{
    if(n < VEC_BUBBLESORT_THR)
    {
      // do a bubblesort
      vec_bubble(p);
    }
    else
    {
      // do a quicksort
      vec_quicksort(p->v, lf, rt);
    }
  }
}

void vec_sort(dblvec_t * p)
{
  vec_sort_smart(p, NULL, 0, p->c - 1);
}

int vec_load(dblvec_t * p, const char * filename)
{
  printf("Reading %s...\n", filename);
  
  buf_t buf;
  buf_init(&buf);
  if(buf_load(&buf, filename))
  {
    buf_destroy(&buf);
    return -1;
  }
  
  printf("Buffer ready. Parsing...\n");
  
  double dbl;
  char * lastStr = buf.v;
  char * lastPos = buf.v + buf.c;
  
  while(lastStr != lastPos)
  { 
    vec_add(p, dbl = strtod(lastStr, &lastStr));
      
    if(lastStr == lastPos) break;
    
    while(*lastStr && isspace(*lastStr)) lastStr++;
  }
  
  printf("Read %ld doubles total.\n", p->c);
  buf_destroy(&buf);
  
  return 0;
  
}

int vec_store(dblvec_t * p, const char * filename)
{
  const int REQ_FREE = 1024 * 1024; // 1MB buffer space must be available at all times
  const int FREE_FACTOR = 4;
  
  printf("Writing %s...\n", filename);
 
  long estChars = p->c * 12; // estimate necessary space to avoid reallocs
  long onePercent = p->c / 100l;
  
  buf_t buf;
  buf_init_n(&buf, estChars);
  
  int written = 0;
  
  printf("Buffer allocated. Converting...\n");
  printf("0%% ");
  fflush(stdout); // make sure it goes to screen
  
  for(long i = 0; i < p->c; i++)
  {
    sprintf(buf.v + buf.c, "%lf\n%n", p->v[i], &written);
    buf.c += written;
    if(buf.cap - buf.c < REQ_FREE)
    {
      long newSize = buf.cap + REQ_FREE * FREE_FACTOR;
      printf("WARN buf realloc from %ld to %ld, parsed %ld doubles\n", buf.cap, newSize, i);
      buf_resize(&buf, newSize); // avoid frequent reallocs by using a factor
    }
    
    if((i%onePercent) == 0)
    {
      printf("\r%ld%% ", i / onePercent); // print percentage
      fflush(stdout); // make sure it goes to screen
    }
  }
  
  printf("\r100%%  \n");
  fflush(stdout);
  
  buf.v[buf.c] = '\0';
  buf.c++;
  
  printf("Buffer ready. Writing to file...\n");
  
  int ret = buf_store(&buf, filename);
  
  buf_destroy(&buf);
  return ret;
}

#endif