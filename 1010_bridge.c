//Baekjoon 1010 다리놓기
#include <stdio.h>
#include <stdlib.h>

int					count_bridge(int w, int e)
{
	int				i;
	long long		mul;
	long long		div;

	if (w > e / 2)
		w = e - w;
	i = -1;
	mul = 1;
	div = 1;
	while (++i < w)
	{
		mul *= (e - i);
		div *= (i + 1);
	}
	return (mul / div);
}

int			main(void)
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
		printf("%d", count_bridge(bridge[i][0], bridge[i][1]));
		if (i + 1 < num)
			printf("\n");
		free(bridge[i]);
	}
	free(bridge);
	return (0);
}
