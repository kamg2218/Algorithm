//Baekjoon 14501 퇴사
#include <stdio.h>
#include <stdlib.h>

int			count(int **schedule, int n, int m)
{
	int		i;
	int		sal;
	int		sal2;

	sal = 0;
	sal2 = 0;
	if (n + 1 == m)
	{
		if (schedule[n][0] == 1)
			return (schedule[n][1]);
		return (0);
	}
	if (n == m)
		return (0);
	if (n + schedule[n][0] <= m)
	{
		sal += schedule[n][1];
		sal += count(schedule, n + schedule[n][0], m);
	}
	sal2 = count(schedule, n + 1, m);
	return (sal > sal2 ? sal : sal2);
}

int			main(void)
{
	int		i;
	int		j;
	int		n;
	int		max;
	int		sal;
	int		**schedule;

	scanf("%d", &n);
	getchar();
	if (!(schedule = (int **)malloc(sizeof(int *) * (n + 1))))
		return (0);
	i = -1;
	while (++i < n)
	{
		if (!(schedule[i] = (int *)malloc(sizeof(int) * 2)))
			return (0);
		scanf("%d %d", &schedule[i][0], &schedule[i][1]);
		getchar();
	}
	printf("%d", count(schedule, 0, n));
	i = -1;
	while (++i < n)
		free(schedule[i]);
	free(schedule);
	return (0);
}
