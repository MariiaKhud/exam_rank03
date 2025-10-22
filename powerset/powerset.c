// Assignment name : powerset
// Expected files : *.c *.h
// Allowed functions : atoi, printf, malloc, calloc, realloc, free.
// ---------------------------------------------------------------

// Write a program that will take as argument an integer n follow by a set of integers,
// your program should display all the subsets of whose sum of elements is n.

// In case of a malloc error your program will exit with the code 1.
// We will not test invalid test(for example '1 1 2')
// hint: the empty set is a subset of anyset.


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
// 2 3 7$
// 5 4 3$
// 5 7$
// 5 2 1 4$
// $> ./powerset 7 3 8 2| cat -e
// $
// $> ./powerset 0 1 -1| cat -e
// 1 -1$

// The order of lines is not important, but the order of the element in a subset is.
// You must not have any duplicates (for example 2 1, 1 2)
// $> ./powerset 5 1 2 3 4 5| cat -e
// valid:
// 1 4$
// 2 3$
// 5$

// or:
// 2 3$
// 5$
// 1 4$
// not valid:
// 4 1$
// 3 2$
// 5$ 


#include <stdio.h>
#include <stdlib.h>

void search(int *arr, int *sub, int n, int i, int sub_size, int sum, int target)
{
	if (sum == target)
	{
		int j = 0;
		while (j < sub_size)
		{
			printf("%d ", sub[j]);
			j++;
		}
		printf("\n");
		return ;
	}
	if (sum > target)
        return ;
	if (i >= n)
		return ;
	sub[sub_size] = arr[i];
	search(arr, sub, n, i + 1, sub_size + 1, sum + arr[i], target);
	search(arr, sub, n, i + 1, sub_size, sum, target);
}

int main(int argc, char **argv)
{
	if (argc < 2)
		return 0;
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
	search(arr, sub, n, 0, 0, 0, atoi(argv[1]));
	free(arr);
	free(sub);
	return 0;
}
