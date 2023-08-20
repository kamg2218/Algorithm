//Baekjoon 1026 보물 - sorting two array
#include <stdio.h>
#include <stdlib.h>

void		change_array(int *array, int i, int j)
{
	int		k;

	k = array[i];
	array[i] = array[j];
	array[j] = k;
}

int			move_array(int n, int *a_array, int *b_array)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	while (++i < n)
	{
		j = i;
		while (++j < n)
		{
			if (a_array[i] > a_array[j])
				change_array(a_array, i, j);
			if (b_array[i] < b_array[j])
				change_array(b_array, i, j);
		}
	}
	i = -1;
	k = 0;
	while (++i < n)
		k += a_array[i] * b_array[i];
	return (k);
}

int			main(void)
{
	int		i;
	int		n;
	int		*a_array;
	int		*b_array;

	scanf("%d", &n);
	getchar();
	if (!(a_array = (int *)malloc(sizeof(int) * n)))
		return (0);
	if (!(b_array = (int *)malloc(sizeof(int) * n)))
		return (0);
	i = -1;
	while (++i < n)
	{
		scanf("%d", &a_array[i]);
		getchar();
	}
	i = -1;
	while (++i < n)
	{
		scanf("%d", &b_array[i]);
		getchar();
	}
	printf("%d", move_array(n, a_array, b_array));
	free(a_array);
	free(b_array);
	return (0);
}
