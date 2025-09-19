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

int height_of_tree(t_btree *root)
{
	int left;
	int right;
	int max;

	if (root == NULL)
		return (0);
	left = height_of_tree(root->left);
	right = height_of_tree(root->right);
    if (left > right)
        max = left;
    else
        max = right;
    return (1 + max);
}

int main()
{
    t_btree *root;
	root = make_node(1);
    root->left = make_node(2);
    root->right = make_node(3);
    root->left->left = make_node(4);
    root->left->left->left = make_node(6);

    printf("Tree height: %d\n", height_of_tree(root));
    return (0);
}
