#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../stack/stack.h"
#include "../queue/queue.h"

#define CMD_HAS_PROMPT 1
#include "cmd.h"

int count_cmd(void * queue);
int auth_cmd(void * queue);
int add_cmd(void * queue);
int list_cmd(void * queue);
int first_cmd(void * queue);
int quit_cmd(void * unused);
int help_cmd(void * unused);

const cmd_t g_commands[] =
{
  {"count", &count_cmd, "Say how many airplanes are in the queue"},
  {"auth", &auth_cmd, "Authorize takeoff of the first airplane"},
  {"add", &add_cmd, "Adds an airplane to the queue"},
  {"list", &list_cmd, "Lists all airplanes in the queue"},
  {"first", &first_cmd, "Info about the first airplane in the takeoff queue"},
  {"quit", &quit_cmd, "Exit app"},
  {"help", &help_cmd, "Prints this listing"},
  {0}
};


typedef struct airplane_s
{
  char airline[80];
  int id;
  int passengers;
  int crew;
  char destination[80];
} airplane_t;

void airplane_fill(airplane_t * p)
{
  printf("Airline? ");
  scanf("%s", p->airline);
  printf("Id? ");
  scanf("%d", &(p->id));
  printf("Passenger count? ");
  scanf("%d", &(p->passengers));
  printf("Crew count? ");
  scanf("%d", &(p->crew));
  printf("Destination (3-letter code)? ");
  scanf("%s", p->destination);
}

void airplane_print(airplane_t * p)
{
  printf("Airplane:\n");
  printf("\tAirline: %s\n", p->airline);
  printf("\tId: %d\n", p->id);
  printf("\tPassengers: %d\n", p->passengers);
  printf("\tCrew: %d\n", p->crew);
  printf("\tDestination: %s\n", p->destination);
}

bool airplane_print_vp(void * vp)
{
  airplane_print((airplane_t*)vp);
  return true;
}


int count_cmd(void* queue)
{
  queue_p p = (queue_p) queue;
  
  printf("There are %d airplanes in the queue.\n", queue_size(p));
  return 0;
}

int auth_cmd(void* queue)
{
  queue_p p = (queue_p) queue;
  
  if(queue_empty(p))
  {
    printf("No airplanes in queue.\n");
    return -1;
  }
  
  queue_pop(p, 0);
  return 0;
}


int list_cmd(void* queue)
{
  queue_p p = (queue_p) queue;
  
  if(queue_empty(p))
  {
    printf("No airplanes in queue.\n");
    return -1;
  }
  
  queue_visit(p, airplane_print_vp);
  
  return 0;
}

int first_cmd(void* queue)
{
  queue_p p = (queue_p) queue;
  
  if(queue_empty(p))
  {
    printf("No airplanes in queue.\n");
    return -1;
  }
  
  airplane_print((airplane_t*) queue_peek(p));
}


int add_cmd(void* queue)
{
  queue_p p = (queue_p) queue;
  airplane_t plane;
  airplane_fill(&plane);
  
  queue_push(p, &plane);
  return 0;
}

int quit_cmd(void* unused)
{
  exit(0);
  return 0; // quench warnings
}

int help_cmd(void * unused)
{
  printf("Command list:\n");
  const cmd_t *cmd= g_commands;
  
  while(cmd->name)
  {
    printf("\t%s\t%s\n", cmd->name, cmd->descr);
    cmd++;
  }
  
  return 0;
}

int main(int argc, char **argv)
{
  queue_p queue = queue_create(200, sizeof(airplane_t), 0);
  
  for(;;)
  {
    cmd_prompt(g_commands, queue);
  }
  
  return 0;
}