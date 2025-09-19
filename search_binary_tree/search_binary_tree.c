// Assignment name: binary_search
// Expected file: binary_search.c
// Allowed functions: none

// Implement a function that searches for a given value in a binary tree.
// A binary tree is a tree where all nodes have at most 2 children -
// a left one and a right one. The function should return 1 if the
// value is found in the tree, otherwise it should return 0.
// The function should be declared as follows:
// int search_binary_tree(t_btree *root, int value);
// You have to use the ft_btree.h file which will only contain:
// typedef struct s_btree {
// int value; struct s_btree *left; struct s_btree *right; 
// } t_btree;
// The tree will not be ordered in any specific way.

// #include <stdio.h>
// #include <stdlib.h>
// #include "ft_btree.h"

// t_btree *make_node(int value)
// {
// 	t_btree *node;
// 	node = malloc(sizeof(t_btree));
// 	node->value = value;
// 	node->left = 0;
// 	node->right = 0;
// 	return (node);
// }

// int search_binary_tree(t_btree *root, int value)
// {
// 	if (root == 0)
// 		return (0);
// 	if (root->value == value)
// 		return (1);
// 	if (search_binary_tree(root->left, value))
// 		return (1);
// 	if (search_binary_tree(root->right, value))
// 		return (1);
// 	return (0);
// }

// int main(void)
// {
// 	t_btree *root;
// 	root = make_node(1);
// 	root->left = make_node(2);
// 	root->right = make_node(3);
// 	root->right->left = make_node(4);

// 	printf("Search 3: %d\n", search_binary_tree(root, 3));
// 	return (0);
// }

#include <stdio.h>
#include <stdlib.h>
#include "ft_btree.h"

t_btree *make_node(int value)
{
	t_btree *node;
	node = malloc(sizeof(t_btree));
	node->value = value;
	node->left = 0;
	node->right = 0;
	return (node);
}

int search_binary_tree(t_btree *root, int value)
{
    if (root == NULL)
        return (0);
    if (root->value == value)
        return (1);
	if (value != root->value)
    {
		if (search_binary_tree(root->left, value))
			return (1);
    	else if (search_binary_tree(root->right, value))
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

int main(void)
{
	t_btree *root;
	root = make_node(10);
    root->left = make_node(5);
    root->right = make_node(20);
    root->left->left = make_node(2);
    root->left->right = make_node(7);

	printf("Search 3: %d\n", search_binary_tree(root, 7));
	return (0);
}
