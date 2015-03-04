#include <stdio.h>
#include "double_list.h"

void print_double_list(struct list_head *head)
{
	struct double_node *node, *tmp_node;
	
	list_for_each_entry_safe(node, tmp_node, head, list) {
		printf("%d ", node->element);
	}

	printf("\n");
}

int main(void)
{
	int i, j;
	node_type node_array[10] = {0,1,2,3,4,5,6,7,8,9};
	struct double_node queue_head;
	struct double_node *node;

	INIT_LIST_HEAD(&queue_head.list);

	i = sizeof(node_array) / sizeof(node_type);
	printf("i : %d\n", i);	

	for (j = 0; j < i; j++) {
		node = alloc_double_node();
		node->element = node_array[j];
		INIT_LIST_HEAD(&node->list);
		list_add_tail(&node->list,&queue_head.list);
		printf("%d ", node_array[j]);
	}
	printf("\n");

	print_double_list(&queue_head.list);
	
	free_double_list(&queue_head.list);

	return 0;
}
