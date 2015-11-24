#include "common.h"

#include "stdlib.h"
#include "stdio.h"
#include "stdio_ext.h"
#include "string.h"


void clearstdin()
{
  __fpurge(stdin);
}

void trim(char * buf)
{
  char *pos;
  if ((pos=strchr(buf, '\n')) != NULL)
    *pos = '\0';
}
