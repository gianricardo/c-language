
#include <ctype.h>
#include <stdbool.h>

typedef struct stack_t *stack_p, **stack_pp;

stack_p stack_create(int capacity, int elem_s);

void stack_destroy(stack_p p);

void stack_push(stack_p p, void * src);

void stack_pop(stack_p p, void * dest);

bool stack_empty(stack_p p);

bool stack_full(stack_p p);

int stack_size(stack_p p);

int stack_elem_size(stack_p p);

int stack_capacity(stack_p p);

void stack_clear(stack_p p);