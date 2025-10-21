
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

int check_bal(t_btree *root, int *height)
{
	int left_height;
	int right_height;
	int diff;
	int left_bal;
	int right_bal;

	if (root == NULL)
	{
		*height = 0;
		return (1);
	}
	left_bal = check_bal(root->left, &left_height);
	right_bal = check_bal(root->right, &right_height);
	if (left_bal == 0 || right_bal == 0)
		return (0);
	if (left_height > right_height)
	{
		diff = left_height - right_height;
		*height = 1 + left_height;
	}
	else
	{
		diff = right_height - left_height;
		*height = 1 + right_height;
	}
	if (diff > 1)
		return (0);
	return (1);
}

int is_bal(t_btree *root)
{
	int height = 0;
	return (check_bal(root, &height));
}

int main()
{
	t_btree *root;
	root = make_node(1);
	root->left = make_node(2);
	root->right = make_node(3);
	root->right->right = make_node(4);
	if (is_bal(root))
		printf("bal\n");
	else
		printf("no\n");
	return (0);
}