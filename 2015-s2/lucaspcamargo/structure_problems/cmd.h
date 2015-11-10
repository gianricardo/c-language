#pragma once

typedef int (*cmd_fn_p)(void*);

typedef struct cmd_s
{
  const char * name;
  cmd_fn_p fn;
  const char * descr;
} cmd_t;


int cmd_exec(const cmd_t commands[], char *input, void * user_p )
{
  const cmd_t *cmd = commands;
  char * inputTok = strtok(input, " \n\t\r");
  
  if(!inputTok)
    return -3;
  
  while(cmd->name)
  {
    if(!strcmp(cmd->name, inputTok))
    {
      cmd_fn_p fn = (cmd->fn);
      if(fn)
	return fn(user_p);
      else
	return -2;
    }
    cmd++;
  }
  
  return -1;
}

#ifdef CMD_HAS_PROMPT

#include "stdio.h"

int cmd_prompt(const cmd_t commands[], void * user_p)
{
  char cmdbuf[80];
    
    printf("? ");
    fgets(cmdbuf, 80, stdin);
    
    int res = cmd_exec(commands, cmdbuf, user_p);
    
    switch(res)
    {
      case 0:
	printf("OK\n");
	break;
	
      default:
	break;
    }
    
    return res;
}

#endif