#include <stdio.h>
#include <stdlib.h>
#include "stack_list.h"

int stack_empty(struct stack_node *stack)
{
	return stack->list.next == NULL;
}

struct stack_node *create_stack(void)
{
	struct stack_node *stack;

	stack = (struct stack_node *)malloc(sizeof(struct stack_node));
	if (stack == NULL) {
		printf("fatal error, create stack fail!\n");
		return NULL;
	}
	
	stack->list.next = NULL;

	return stack;
}

void free_stack(struct stack_node *stack)
{
	if (!stack_empty(stack))
		printf("error:stack not empty!\n");

	free(stack);
}

void make_stack_empty(struct stack_node *stack)
{
	if (stack == NULL)
		printf("error:stack is empty!\n");
	else 
		while (!stack_empty(stack))
			stack_pop(stack);
}

void stack_push(ELEMENT_TYPE x, struct stack_node *stack)
{
	struct stack_node *node;

	node = (struct stack_node *)malloc(sizeof(struct stack_node));
	if (node == NULL)
		printf("error:alloc stack node fail!\n");

	node->element = x;
	node->list.next = stack->list.next;

	stack->list.next = &node->list;
}

ELEMENT_TYPE stack_top(struct stack_node *stack)
{
	struct stack_node *node;
	if (!stack_empty(stack)) {
		node = list_entry(stack->list.next, struct stack_node, list);
		return node->element;
	}

	printf("error:empty stack!\n");
	return -1;
}

void stack_pop(struct stack_node *stack)
{
	struct stack_node *node;

	if (stack_empty(stack))
	{
		printf("error:empty stack!\n");
		return;
	}

	node = list_entry(stack->list.next, struct stack_node, list);

	stack->list.next = node->list.next;

	free(node);
}

