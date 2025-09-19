
#include <stdio.h>
#include <unistd.h>
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
		return (0);
	int n = argc - 2;
	int *arr = malloc(n * sizeof(int));
	int *sub = malloc(n * sizeof(int));
	if (arr == NULL || sub == NULL)
		return (1);
	int i = 0;
	while (i < n)
	{
		arr[i] = atoi(argv[i + 2]);
		i++;
	}
	search(arr, sub, n, 0, 0, 0, atoi(argv[1]));
	free(arr);
	free(sub);
	return (0);
}