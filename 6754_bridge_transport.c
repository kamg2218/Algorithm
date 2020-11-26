//Baekjoon 6754 Bridge Transport - queue
#include <stdio.h>
#include <stdlib.h>

int			count_weight(int *weight, int n, int i, int w)
{
	int		a;
	int		sum;
	
	sum = 0;
	a = i + 1;
	while (--a >= 0 && a > i - 4)
		sum += weight[a];
	if (sum > w)
		return (1);
	return (0);
}

int			main(void)
{
	int		i;
	int		n;	//number of railway cars
	int		w;	//weight
	int		*weight;

	scanf("%d", &w);
	getchar();
	scanf("%d", &n);
	getchar();
	if (!(weight = (int *)malloc(sizeof(int) * n)))
		return (0);
	i = -1;
	while (++i < n)
	{
		scanf("%d", &weight[i]);
		getchar();
	}
	i = -1;
	while (++i < n)
	{
		if (count_weight(weight, n, i, w))
			break ;
	}
	printf("%d", i);
	free(weight);
	return (0);
}
