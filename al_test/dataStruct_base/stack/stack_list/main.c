#include <stdio.h>
#include "stack_list.h"

void print_stack(struct stack_node *stack)
{
	struct stack_node *pos, *n;
	if (stack_empty(stack))
		return;
	list_for_each_entry_safe(pos, n, &stack->list, list) {
		printf("%d ", pos->element);
	}

	printf("\n");
}

int main(void)
{
	int i, j;
	ELEMENT_TYPE element_array[10] = {0,1,2,3,4,5,6,7,8,9};
	ELEMENT_TYPE element;
	struct stack_node *stack;

	stack = create_stack();
	if (stack == NULL)
		return -1;

	i = sizeof(element_array) / sizeof(ELEMENT_TYPE);
	printf("i:%d\n", i);

	for (j = 0; j < i; j++) {
		printf("%d ", element_array[j]);
		stack_push(element_array[j], stack);
	}
	printf("\n");

	//print_stack(stack);

	while (!stack_empty(stack)) {
		element = stack_top(stack);
		printf("%d ", element);
		stack_pop(stack);
	}
	printf("\n");

	free_stack(stack);

	return 0;
}

