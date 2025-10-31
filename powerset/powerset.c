// Assignment name : powerset
// Expected files : *.c *.h
// Allowed functions : atoi, printf, malloc, calloc, realloc, free.
// ---------------------------------------------------------------

// Write a program that will take an integer n follow by a set s of distinct integers as arguments.
// Your program should display all subsets of s whose sum of elements is n.

// In case of a malloc error your program will exit with the code 1.
// We will not test invalid test(for example '1 1 2')
// hint: the empty set is a subset of anyset.

// The order of lines is not important, but the order of the element in a subset must 
// match the order in the initial ses s.
// This way you should not have any duplicates (e.g. '1 2' and '2 1')
// For example, using the command ./powerset 5 1 2 3 4 5| cat -e
// this output is valid:
// 1 4$
// 2 3$
// 5$

// this one is also valid:
// 2 3$
// 5$
// 1 4$
// but not this one:
// 4 1$
// 3 2$
// 5$ 

// In case of a malloc error, your program should exit with a code 1.
// We will not test your program with invalid sets (e.g. '1 1 2')
// Hint: The empty subset is a valid subset of any set and will be displayed
// as an empty line.  
// For example this should work:
// $> ./powerset 3 1 0 2 4 5 3 | cat -e
// 3$
// 0 3$
// 1 2$
// 1 0 2$
// $> ./powerset 12 5 2 1 8 4 3 7 11 | cat -e
// 8 4$
// 1 11$
// 1 4 7$
// 1 8 3$
// 2 3 7$
// 5 7$
// 5 4 3$
// 5 2 1 4$
// $> ./powerset 7 3 8 2| cat -e
// $
// $> ./powerset 0 1 -1| cat -e
// $
// 1 -1$


#include <stdio.h>
#include <stdlib.h>

// void search(int *arr, int *sub, int n, int i, int sub_size, int sum, int target)
// {
// 	if (sum == target)
// 	{
// 		int j = 0;
// 		while (j < sub_size)
// 		{
// 			printf("%d ", sub[j]);
// 			j++;
// 		}
// 		printf("\n");
// 		return ;
// 	}
// 	if (sum > target)
//         return ;
// 	if (i >= n)
// 		return ;
// 	sub[sub_size] = arr[i];
// 	search(arr, sub, n, i + 1, sub_size + 1, sum + arr[i], target);
// 	search(arr, sub, n, i + 1, sub_size, sum, target);
// }

// int main(int argc, char **argv)
// {
// 	if (argc < 2)
// 		return 0;
// 	int n = argc - 2;
// 	int *arr = malloc(n * sizeof(int));
// 	int *sub = malloc(n * sizeof(int));
// 	if (arr == NULL || sub == NULL)
// 		return 1;
// 	int i = 0;
// 	while (i < n)
// 	{
// 		arr[i] = atoi(argv[i + 2]);
// 		i++;
// 	}
// 	search(arr, sub, n, 0, 0, 0, atoi(argv[1]));
// 	free(arr);
// 	free(sub);
// 	return 0;
// }


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void	search(int *arr, int *sub, int n, int i, int sub_size, int sum, int target, int *found)
{
	if (i == n)
	{
		if (sum == target)
		{
			int j = 0;
			while (j < sub_size)
			{
				if (j > 0)
					printf(" ");
				printf("%d", sub[j]);
				j++;
			}
			printf("\n");
			*found = 1;
		}
		return ;
	}
	sub[sub_size] = arr[i];
	search(arr, sub, n, i + 1, sub_size + 1, sum + arr[i], target, found);
	search(arr, sub, n, i + 1, sub_size, sum, target, found);
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	int n = argc - 2;
	int *arr = malloc(n * sizeof(int));
	int *sub = malloc(n * sizeof(int));
	if (arr == NULL || sub == NULL)
		return 1;
	int i = 0;
	while (i < n)
	{
		arr[i] = atoi(argv[i + 2]);
		i++;
	}
	int found = 0;
	int target = atoi(argv[1]);
	search(arr, sub, n, 0, 0, 0, target, &found);
	if (!found && target == 0)
		printf("\n");
	else if (!found)
		printf("\n");
	free(arr);
	free(sub);
	return 0;
}

