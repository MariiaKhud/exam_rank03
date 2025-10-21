// #ifndef GNL
// # define GNL
// # ifndef BUFFER_SIZE
// #  define BUFFER_SIZE 10
// # endif
// char    *get_next_line(int fd);
// #endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

char    *get_next_line(int fd);
#endif



















// Assignment name  : binary_search
// Expected files   : binary_search.c
// Allowed functions: None
// --------------------------------------------------------------------------------

// Implement a function that searches for a given value in a binary tree.

// A binary tree is a tree where all nodes have at most 2 children, a left one and
// a right one.

// The function should return 1 if the value is found in the tree,
// otherwise it should return 0.

// The function should be declared as follows:
// int search_binary_tree(t_btree *root, int value);

// You have to use the ft_btree.h file, which will ONLY contain:

// typedef struct		s_btree
// {
// 	int				value;
// 	struct s_btree	*left;
// 	struct s_btree	*right;
// }					t_btree;

// The tree will not be ordered in any specific way.



// #include "ft_btree.h"

// t_btree *make_node(int value)
// {
//     t_btree *node;
//     node = malloc(sizeof(t_btree));
//     node->value = value;
//     node->left = NULL;
//     node->right = NULL;
//     return (node);
// }

// int search_binary_tree(t_btree *root, int value)
// {
//     if (root == 0)
//         return (0);
//     if (root->value == value)
//         return (1);
//     if (value != root->value)
//     {
//         if (search_binary_tree(root->left, value))
//             return (1);
//         else if (search_binary_tree(root->right, value))
//             return (1);
//         else
//             return (0);
//     }
//     else
//         return (0);
// }

// int main()
// {
//     t_btree *root;
//     root = make_node(1);
//     root->left = make_node(5);
//     root->right = make_node(6);
//     if (search_binary_tree(root, 0))
//         printf("yes");
//     else
//         printf("no");
//     return (0);
//         return (search_binary_tree(root->left, value));
//     else
//         return (search_binary_tree(root->right, value));
// }