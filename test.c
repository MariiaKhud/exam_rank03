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

int search(t_btree *root, int value)
{
	if (root == 0)
		return (0);
	if (root->value == value)
		return (1);
	if (value != root->value)
	{
		if (search(root->left, value))
			return (1);
		else if (search(root->right, value))
			return (1);
		else
			return (0);
	}
	else
		return (0);
	
}

int main()
{
	t_btree *root;
	root = make_node(1);
	root->left = make_node(2);
	root->right = make_node(3);
	root->left->left = make_node(4);

	printf("%d\n", search(root, 4));
	return (0);
}