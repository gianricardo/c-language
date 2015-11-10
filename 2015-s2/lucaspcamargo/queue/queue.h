
#include <ctype.h>
#include <stdbool.h>

typedef struct queue_t *queue_p, **queue_pp;

typedef int (*compare_t)(void * a, void * b);
typedef bool (*visit_fn_t)(void * p);

queue_p queue_create(int capacity, int elem_s, compare_t comparisonFunc);

void queue_destroy(queue_p p);

void queue_push(queue_p p, void * src);

void queue_pop(queue_p p, void * dest);

bool queue_empty(queue_p p);

bool queue_full(queue_p p);

int queue_size(queue_p p);

int queue_elem_size(queue_p p);

int queue_capacity(queue_p p);

void queue_clear(queue_p p);

void queue_visit(queue_p p, visit_fn_t visitor_fn);

void * queue_peek(queue_p p);