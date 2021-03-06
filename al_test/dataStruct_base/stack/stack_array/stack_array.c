#include <stdio.h>
#include <stdlib.h>
#include "stack_array.h"

int stack_empty(struct stack_array *stack)
{
	return stack->stack_capacity == STACK_EMPTY;
}

int stack_full(struct stack_array *stack)
{
	return stack->stack_top == STACK_FULL;
}

struct stack_array *create_stack(void)
{
	ELEMENT_TYPE *array;
	struct stack_array *stack;

	stack = (struct stack_array *)malloc(sizeof(struct stack_array));
	if (stack == NULL) {
		printf("error:alloc stack_array fail!\n");
		return NULL;
	}

	array = (ELEMENT_TYPE *)malloc(sizeof(ELEMENT_TYPE) * STACK_CAPACITY);
	if (array == NULL) {
		printf("error:alloc element array fail!\n");
		return NULL;
	}

	stack->stack_top = -1;
	stack->stack_capacity = STACK_CAPACITY;
	stack->element = array;

	return stack;
}

void free_stack(struct stack_array *stack)
{
	if (stack == NULL)
		printf("error:NULL pointer to stack!\n");

	free(stack->element);
	free(stack);
}

void make_stack_empty(struct stack_array *stack)
{
	if (stack == NULL) {
		printf("error:NULL pointer to stack!\n");
		return;
	}

	stack->stack_top = -1;
}

void stack_push(ELEMENT_TYPE x, struct stack_array *stack)
{
	if (stack_full(stack)) {
		printf("error:no more space in stack!\n");
		return;
	}

	(stack->element)[++stack->stack_top] = x;
}

ELEMENT_TYPE stack_top_element(struct stack_array *stack)
{
	ELEMENT_TYPE element;
	if (stack == NULL || stack_empty(stack)) {
		printf("error:NULL pointer to stack or empty stack!\n");
		return;
	}

	printf("\n");
	element = (stack->element)[stack->stack_top--];

	return element;
}

void stack_pop(struct stack_array *stack)
{
	if (stack == NULL || stack_empty(stack)) {
		printf("error:NULL pointer to stack or empty stack!\n");
		return;
	}

	stack->stack_top--;
}

void dump_stack(struct stack_array *stack)
{
	ELEMENT_TYPE element;
	int i;
	//struct stack_array *s = stack;
	
	//printf("s:%p, stack:%p\n", s, stack);

	printf("stack info:\n");
	if (stack = NULL) {
		printf("stack is NULL\n");
		return;
	} 

	printf("top : %d\n", stack->stack_top);
	printf("cap : %d\n", stack->stack_capacity);

	for (i = 0; i <= stack->stack_top; i++) 
		printf("%d\n", (stack->element)[i]);

	return;
}
