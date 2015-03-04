#ifndef _STACK_ARRAY_H_
#define _STACK_ARRAY_H_

#define STACK_CAPACITY 100
#define STACK_EMPTY (-1)
#define STACK_FULL	(STACK_CAPACITY - 1)

typedef int ELEMENT_TYPE;
struct stack_array
{
	int stack_top;
	int stack_capacity;	
	ELEMENT_TYPE *element;
};

int stack_empty(struct stack_array *stack);
int stack_full(struct stack_array *stack);
struct stack_array *create_stack(void);
void free_stack(struct stack_array *stack);
void make_stack_empty(struct stack_array *stack);
void stack_push(ELEMENT_TYPE x, struct stack_array *stack);
ELEMENT_TYPE stack_top(struct stack_array *stack);
void stack_pop_element(struct stack_array *stack);
void dump_stack(struct stack_array *stack);

#endif
