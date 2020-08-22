//Baekjoon 1182 부분수열 - BFS
#include <stdio.h>
#include <stdlib.h>

int			sequence(int *array, int i, int num, int s, int *sum)
{
	int		count;

	if (i == num)
		return (0);
	count = 0;
	if (*sum + array[i] == s)
		count++;
	count += sequence(array, i + 1, num, s, sum);
	*sum += array[i];
	count += sequence(array, i + 1, num, s, sum);
	*sum -= array[i];
	return (count);
}

int			main(void)
{
	int		i;
	int		num;
	int		sum;
	int		integer;
	int		*array;

	scanf("%d %d", &num, &integer);
	getchar();
	if (!(array = (int *)malloc(sizeof(int) * (num + 1))))
		return (0);
	i = -1;
	while (++i < num)
	{
		scanf("%d", &array[i]);
		getchar();
	}
	sum = 0;
	printf("%d", sequence(array, 0, num, integer, &sum));
	free(array);
	return (0);
}
