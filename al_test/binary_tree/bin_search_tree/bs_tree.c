#include <stdio.h>
#include <stdlib.h>
#include "bs_tree.h"

void make_empty(struct bs_root *root)
{
	if (root != NULL) {
		make_empty(root->left);
		make_empty(root->right);
		free(root);
	}
}

struct bs_root *find_node(KEY_TYPE key, struct bs_root *root)
{
	if (root != NULL) {
		if (key > root->key)
			return find_node(key, root->right);
		else if (key < root->key)
			return find_node(key, root->left);
		else 
			return root;
	}

	return NULL;
}
/*
struct bs_root *find_node(KEY_TYPE key, struct bs_root *root)
{
	while (root != NULL) {
		if (key > root->key)
			root = root->right;
		else if (key < root->key)
			root = root->left;
		else
			return root;
	}

	return NULL;
}
*/

struct bs_root *find_min(struct bs_root *root)
{
	if (root->left != NULL)
		return find_min(root->left);

	return root;
}
/*
struct bs_root *find_min(struct bs_root *root)
{
	while (root->left != NULL) 
		root = root->left;

	return root;
}
*/

struct bs_root *find_max(struct bs_root *root)
{
	if (root->right != NULL)
		return find_max(root->right);

	return root;
}
/*
struct bs_root *find_max(struct bs_root *root)
{
	while (root->right != NULL)
		root = root->right;

	return root;
}
*/
/*
struct bs_root *insert_node(KEY_TYPE key, struct bs_root *root)
{
	if (root != NULL) {
		if (key < root->key)
			root->left = insert_node(key, root->left);
		else if (key > root->key)
			root->right = insert_node(key, root->right);
		else {
			printf("the same key : %d, don't insert\n", key);
			return NULL;
		}
	} else {
		root = (struct bs_root *)malloc(sizeof(struct bs_root));
		root->key = key;
		root->left = NULL;
		root->right = NULL;
	}

	return root;
}
*/
struct bs_root *insert_node(KEY_TYPE key, struct bs_root *root)
{
	bool left = false;
	struct bs_root *tmp_node = NULL;

	while (root != NULL) {
		if (key < root->key) {
			left = true;
			tmp_node = root;
			root = root->left;
		} else if (key > root->key) {
			left = false;
			tmp_node = root;
			root = root->right;
		} else {
			printf("the same key : %d, don't insert\n", key);
			return NULL;
		}
	}

	root = (struct bs_root *)malloc(sizeof(struct bs_root));
	root->key = key;
	root->left = NULL;
	root->right = NULL;

	if (tmp_node != NULL) {
		if (left)
			tmp_node->left = root;
		else
			tmp_node->right = root;
	}

	return root;
}

struct bs_root *delete_node(KEY_TYPE key, struct bs_root *root)
{
	struct bs_root *tmp_node;

	if (root == NULL) {
		printf("can nOt find the key : %d\n", key);
		return NULL;
	} else {
		if (key < root->key) {
			root->left = delete_node(key, root->left);
		} else if (key > root->key) {
			root->right = delete_node(key, root->right);
		} else {
			if ( (root->left != NULL) && (root->right != NULL)) {
				tmp_node = find_min(root->right);
				root->key = tmp_node->key;
				root->right = delete_node(root->key, root->right);
			} else {
				tmp_node = root;
				if (root->left != NULL) 
					root = root->left;
				else if (root->right != NULL) 
					root = root->right;
				else
					root = NULL;

				free(tmp_node);
			}
		}
	}

	return root;
}

void print_infix_tree(struct bs_root *root)
{
	if (root != NULL) {
		print_infix_tree(root->left);
		printf("%d ", root->key);
		print_infix_tree(root->right);
	}
}

void print_pre_tree(struct bs_root *root)
{
	if (root != NULL) {
		printf("%d ", root->key);
		print_pre_tree(root->left);
		print_pre_tree(root->right);
	}
}

void print_postorder_tree(struct bs_root *root)
{
	if (root != NULL) {
		print_postorder_tree(root->left);
		print_postorder_tree(root->right);
		printf("%d ", root->key);
	}
}

	







































































