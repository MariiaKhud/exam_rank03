// Assignment name: binary_is_balanced
// Expected files: binary_is_balanced.c
// Allowed functions: none

// Implement a function that checks if a binary tree is balanced.

// A binary tree is a tree where all nodes have at most 2 children,
// a left and a right one.
// A binary tree is balanced if, for each node,
// the difference between the heights of the left subtree
// and the right subtree is at most 1.
// If the tree is balanced, the function should return 1, else return 0.
// If the root node is NULL, the tree is considered balanced.

// The prototype of the function is:
// int is_balanced_binary_tree(t_btree *root);

// You have to use the ft_btree.h file, which will only contain:
// typedef struct s_btree {
// 	int value;
// 	struct s_btree *right;
// 	struct s_btree *left;
// } t_btree;



// #include "ft_btree.h"
// #include <stdio.h>
// #include <stdlib.h>

// // Function to create a new tree node
// t_btree *make_node(int value)
// {
// 	t_btree *node;

// 	node = malloc(sizeof(t_btree));
// 	node->value = value;
// 	node->left = NULL;
// 	node->right = NULL;
// 	return (node);
// }

// // int height_of_tree(t_btree *root)
// // {
// // 	int left;
// // 	int right;
// // 	int max;

// // 	if (root == NULL)
// // 		return (0);
// // 	left = height_of_tree(root->left);
// // 	right = height_of_tree(root->right);
// //     if (left > right)
// //         max = left;
// //     else
// //         max = right;
// //     return (1 + max);
// // }

// // int is_balanced_binary_tree(t_btree *root)
// // {
// // 	int left_height;
// // 	int right_height;
// // 	int diff;

// //	if (root == 0)
// // 		return (1); // empty tree is balanced
// // 	left_height = height_of_tree(root->left);
// // 	right_height = height_of_tree(root->right);
// // 	if (left_height > right_height)
// // 		diff = left_height - right_height;
// // 	else
// // 		diff = right_height - left_height;
// // 	if (diff > 1)
// // 		return (0); // not balanced
// // 	// check both subtrees
// // 	if (is_balanced_binary_tree(root->left) == 0)
// // 		return (0);
// // 	if (is_balanced_binary_tree(root->right) == 0)
// // 		return (0);
// // 	return (1); // balanced
// // }

// int check_balance(t_btree *root, int *height)
// {
// 	int left_height = 0;
// 	int right_height = 0;
// 	int diff;
// 	int left_balanced;
// 	int right_balanced;

// 	if (root == 0)
// 	{
// 		*height = 0;
// 		return (1);
// 	}
// 	left_balanced = check_balance(root->left, &left_height);
// 	right_balanced = check_balance(root->right, &right_height);
// 	if (left_balanced == 0 || right_balanced == 0)
// 		return (0);
// 	if (left_height > right_height)
// 		{
// 			diff = left_height - right_height;
// 			*height = left_height + 1;
// 		}
// 	else
// 		{
// 			diff = right_height - left_height;
// 			*height = right_height + 1;
// 		}
// 	if (diff > 1)
// 		return (0);
// 	return (1);
// }

// 	int is_balanced_binary_tree(t_btree *root)
// 	{
// 		int height = 0;
// 		return (check_balance(root, &height));
// 	}


// int main(void)
// {
// 	// // Example of a unbalanced binary tree:
//     //             50
//     //           /
//     //         5
//     //           \
//     //            7
//     //              \
//     //               15
//     //              /  \
//     //            12    26
//     //                    \
//     //                     41
//     //                       \
//     //                        76
//     //                       /
//     //                     65

// 	t_btree *root = make_node(50);
// 	root->left = make_node(5);
// 	root->left->right = make_node(7);
// 	root->left->right->right = make_node(15);
// 	root->left->right->right->left = make_node(12);
// 	root->left->right->right->right = make_node(26);
// 	root->left->right->right->right->right = make_node(41);
// 	root->left->right->right->right->right->right = make_node(76);
// 	root->left->right->right->right->right->right->left = make_node(65);

// 	if (is_balanced_binary_tree(root))
// 		printf("The tree is balanced!\n");
// 	else
// 		printf("The tree is NOT balanced!\n");

// 	// Example of an balanced tree:
// 	//       1
// 	//      / \
// 	//     2   3
// 	//    /
// 	//   4

// 	t_btree *root2 = make_node(1);
// 	root2->left = make_node(2);
// 	root2->right = make_node(3);
// 	root2->left->left = make_node(4);

// 	if (is_balanced_binary_tree(root2))
// 		printf("Tree 2 is balanced!\n");
// 	else
// 		printf("Tree 2 is NOT balanced!\n");

// 	return (0);
// }




#include "ft_btree.h"
#include <stdio.h>
#include <stdlib.h>

t_btree *make_node(int value)
{
	t_btree *node;
	node = malloc(sizeof(t_btree));
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

int check_balance(t_btree *root, int *height)
{
	int left_height = 0;
	int right_height = 0;
	int diff;
	int left_balanced;
	int right_balanced;

	if (root == 0)
	{
		*height = 0;
		return (1);
	}
	left_balanced = check_balance(root->left, &left_height);
	right_balanced = check_balance(root->right, &right_height);
	if (left_balanced == 0 || right_balanced == 0)
		return (0);
	if (left_height > right_height)
		{
			diff = left_height - right_height;
			*height = left_height + 1;
		}
	else
		{
			diff = right_height - left_height;
			*height = right_height + 1;
		}
	if (diff > 1)
		return (0);
	return (1);
}

	int is_balanced_binary_tree(t_btree *root)
	{
		int height = 0;
		return (check_balance(root, &height));
	}

int main(void)
{
	t_btree *root;
	root = make_node(50);
	root->left = make_node(5);
	root->left->right = make_node(7);
	root->left->right->right = make_node(15);
	root->left->right->right->left = make_node(12);
	root->left->right->right->right = make_node(26);
	root->left->right->right->right->right = make_node(41);
	root->left->right->right->right->right->right = make_node(76);
	root->left->right->right->right->right->right->left = make_node(65);

	if (is_balanced_binary_tree(root))
		printf("The tree is balanced!\n");
	else
		printf("The tree is NOT balanced!\n");
	return (0);
}
