#include <stdio.h>
#include "stack_array.h"

int main(void)
{
	int i, j;
	ELEMENT_TYPE element[10] = {0,1,2,3,4,5,6,7,8,9};
	ELEMENT_TYPE local_elememt;
	struct stack_array *stack;

	i = sizeof(element) / sizeof(ELEMENT_TYPE);
	printf("i:%d\n", i);

	stack = create_stack();
	if (stack == NULL) 
		return -1;

	for (j = 0; j < i; j++) {
		stack_push(element[j], stack);
		printf("%d ", element[j]);
	}
	printf("\n");

	printf("top : %d\n", stack->stack_top);
	printf("cap : %d\n", stack->stack_capacity);

	//dump_stack(stack);

	while (!stack_empty(stack)) {
		local_elememt = stack_top_element(stack);
		printf("%d ", local_elememt);
		stack_pop(stack);
	}
	printf("\n");

	free_stack(stack);

	return 0;
}



