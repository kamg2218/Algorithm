//Baekjoon 1010 다리놓기
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double				factorial(double n)
{
	if (n == 1 || n == 0)
		return (1);
	else if (n == 2)
		return (2);
	else
		return (n * factorial(n - 1));
}

double				count_bridge(int w, int e)
{
	return ((factorial(e) / (factorial(w) * factorial((e - w)))));
}

int				main(void)
{
	int		i;
	int		num; //number
	int		**bridge;

	scanf("%d", &num);
	getchar();
	if (!(bridge = (int **)malloc(sizeof(int *) * (num + 1))))
		return (0);
	i = -1;
	while (++i < num)
	{
		if (!(bridge[i] = (int *)malloc(sizeof(int) * 3)))
			return (0);
		scanf("%d %d", &bridge[i][0], &bridge[i][1]);
		getchar();
	}
	bridge[i] = 0;
	i = -1;
	while (++i < num)
	{
		printf("%.f", count_bridge(bridge[i][0], bridge[i][1]));
		if (i + 1 < num)
			printf("\n");
		free(bridge[i]);
	}
	free(bridge);
	return (0);
}
