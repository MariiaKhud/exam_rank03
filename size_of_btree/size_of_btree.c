// binary-size
// Implement function that calculates the size of a binary tree,
// that is to say, the total number of nodes it contains.
// A binary tree is a tree where all nodes have at most 2 children,
// a left one and a right one.
// int size_binary_tree(t_btree *root);
// You have to use the ft_btree.h file, which contains the header:
// typedef struct s_btree
// {
// int value;
// struct s_btree *left;
// struct s_btree *right;
// } t_btree;
// If the root node is NULL , your function must return 0.

#include <stdio.h>
#include <stdlib.h>
#include "ft_btree.h"

t_btree *make_node(int value)
{
	t_btree *node;
	node = malloc(sizeof(t_btree));
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

int size_btree(t_btree *root)
{
	if (root == 0)
		return (0);
	return (1 + size_btree(root->left) + size_btree(root->right));
}

int main()
{
	t_btree *root;
	root = make_node(1);
	root->left = make_node(5);
	root->right = make_node(10);
	root->right->right = make_node(40);
	printf("%d\n", size_btree(0));
	return (0);
}
