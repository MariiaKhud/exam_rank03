// Write a function that returns the largest sum you
// can get from any root-to-leaf path in a binary tree.

// #include <stdio.h>
// #include <stdlib.h>
// #include "ft_btree.h"

// t_btree *make_node(int value)
// {
// 	t_btree *node = malloc(sizeof(t_btree));
// 	if (!node)
// 		return (0);
// 	node->value = value;
// 	node->left = 0;
// 	node->right = 0;
// 	return (node);
// }

// int max_path_sum(t_btree *root)
// {
// 	int left;
// 	int right;

// 	if (root == 0)
// 		return (0);
// 	if (root->left == 0 && root->right == 0)
// 		return (root->value);
// 	left = max_path_sum(root->left);
// 	right = max_path_sum(root->right);
// 	if (left > right)
// 		return (root->value + left);
// 	else
// 		return (root->value + right);
// }

// int main(void)
// {
// 	// Tree:
// 	//        5
// 	//       / \
// 	//      4   8
// 	//     /   / \
// 	//    11 13  4
// 	//   /  \
// 	//  7    2

// 	t_btree *root = make_node(5);
// 	root->left = make_node(4);
// 	root->right = make_node(8);
// 	root->left->left = make_node(11);
// 	root->left->left->left = make_node(7);
// 	root->left->left->right = make_node(2);
// 	root->right->left = make_node(13);
// 	root->right->right = make_node(4);

// 	int result = max_path_sum(root);
// 	printf("Max path sum: %d\n", result); // Expected: 27 (5+4+11+7)

// 	// Test empty tree
// 	printf("Empty tree: %d\n", max_path_sum(0)); // Expected: 0

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

int max_path_sum(t_btree *root)
{
	int left;
	int right;

	if (root == 0)
		return (0);
	if (root->left == 0 && root->right == 0)
		return (root->value);
	left = max_path_sum(root->left);
	right = max_path_sum(root->right);
	if (left > right)
		return (root->value + left);
	else
		return (root->value + right);
}


// int max_path_sum(t_btree *root)
// {
// 	int left;
// 	int right;
// 	int max;

// 	if (root == 0)
// 		return (0);
// 	if (root->left == 0 && root->right == 0)
// 		return (root->value);
// 	left = max_path_sum(root->left);
// 	right = max_path_sum(root->right);
// 	if (left > right)
// 		max = left;
// 	else
// 		max = right;
// 	return (root->value + max);
// }

int main(void)
{
	t_btree *root;
	root = make_node(5);
	root->left = make_node(4);
	root->right = make_node(8);
	root->left->left = make_node(11);
	root->left->left->left = make_node(7);
	root->left->left->right = make_node(2);
	root->right->left = make_node(13);
	root->right->right = make_node(4);

	printf("Max path sum: %d\n", max_path_sum(root));
	return (0);
}