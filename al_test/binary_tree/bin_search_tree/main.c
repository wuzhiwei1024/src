#include <stdio.h>
#include <stdlib.h>
#include "bs_tree.h"

KEY_TYPE array[] = {9,8,7,6,5,4,3,2,1,0};

int main(void)
{
	int i;
	int j;
	struct bs_root *root = NULL;

	root = (struct bs_root *) malloc (sizeof(struct bs_root));
	if (root == NULL) {
		printf("error, alloc root fail!\n");
		return -1;
	}
	root->key = 5;
	root->left = NULL;
	root->right = NULL;

	i = sizeof(array) / sizeof(array[0]);
	
	for (j = 0; j < i; j++) 
		insert_node(array[j], root);

	printf("printf infix tree\n");

	print_infix_tree(root);

	printf("\n");

	make_empty(root);

	return 0;
}
