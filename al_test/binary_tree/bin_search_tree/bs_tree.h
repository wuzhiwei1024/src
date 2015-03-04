#ifndef _BS_TREE_H 
#define _BS_TREE_H

#ifndef bool
#define bool char
#define false 0
#define true 1
#endif

typedef int KEY_TYPE;
struct bs_root {
	KEY_TYPE key;
	struct bs_root *left;
	struct bs_root *right;
};

void make_empty(struct bs_root *root);
struct bs_root *find_node(KEY_TYPE key, struct bs_root *root);
struct bs_root *find_min(struct bs_root *root);
struct bs_root *find_max(struct bs_root *root);
struct bs_root *insert_node(KEY_TYPE key, struct bs_root *root);
struct bs_root *delete_node(KEY_TYPE key, struct bs_root *root);
void print_infix_tree(struct bs_root *root);
void print_pre_tree(struct bs_root *root);
void print_postorder_tree(struct bs_root *root);
KEY_TYPE retrieve(struct bs_root *bs_node);

#endif

