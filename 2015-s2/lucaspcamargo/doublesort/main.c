#include <stdio.h>
#include <stdlib.h>

#define MAKEINPUT_ON 1

#include "vec.h"
#include "buf.h"
#include "timer.h"

#if MAKEINPUT_ON
#include "mkinput.h"
#include <string.h>
#endif

int main(int argc, char ** argv) {
  
  if(argc != 3)
  {
#if MAKEINPUT_ON
    if(argc == 2 && !(strcmp(argv[1], "-makeinput")))
    {
      mkinput();
      exit(0);
    }    
#endif
    printf("Usage: doublesort infile.txt outfile.txt\n");
#if MAKEINPUT_ON
    printf("       doublesort -mkinput > infile.txt\n");
#endif
    exit(-1);
  }
  
  dblvec_t v;
  vec_init(&v);

  double timeA = get_time();
  double timeB;
  
  if( vec_load(&v, argv[1]) )
  {
    printf("Failed to load file \"%s\".\n", argv[1]);
  }
  else
  {
    timeB = get_time();
    printf("Loading took %.2lfs\n", timeB - timeA);
    printf("Sorting %ld doubles...\n", v.c);
    vec_sort(&v);
    
    timeA = get_time();
    printf("Sorting took %.2lfs\n", timeA - timeB);
    
    if( vec_store_v2(&v, argv[2]) )
    {
      printf("Failed to write to file \"%s\".\n", argv[2]);
    }
    else
    {
      timeB = get_time();
      printf("Writing to file took %.2lfs\n", timeB - timeA);
    }
  }
  
  printf("Done.\n");
  return 0;
}
