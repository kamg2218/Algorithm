//Baekjoon 11650 좌표 정렬하기 - quick sort
#include <stdio.h>
#include <stdlib.h>

void		change_num(int **lct, int i, int j)
{
	int		tmp;

	tmp = lct[i][0];
	lct[i][0] = lct[j][0];
	lct[j][0] = tmp;
	tmp = lct[i][1];
	lct[i][1] = lct[j][1];
	lct[j][1] = tmp;
}

void		quick_sort(int **lct, int start, int end)
{
	int		i;
	int		j;
	int		key;

	if (start >= end)
		return ;
	key = start;
	i = start + 1;
	j = end;
	while (i <= j)
	{
		while (i <= end && lct[i][0] <= lct[key][0]
				&& lct[i][1] <= lct[key][1])
			++i;
		while (j > start && lct[j][0] >= lct[key][0]
				&& lct[j][1] >= lct[key][1])
			--j;
		if (i > j)
			change_num(lct, key, j);
		else
			change_num(lct, i, j);
	}
	quick_sort(lct, start, j - 1);
	quick_sort(lct, j + 1, end);
}

int			main(void)
{
	int		i;
	int		j;
	int		n;
	int		**lct;

	scanf("%d", &n);
	getchar();
	if (!(lct = (int **)malloc(sizeof(int *) * (n + 1))))
		return (0);
	i = -1;
	while (++i < n)
	{
		if (!(lct[i] = (int *)malloc(sizeof(int) * 2)))
			return (0);
	}
	lct[n] = NULL;
	i = -1;
	while (++i < n)
	{
		scanf("%d", &lct[i][0]);
		getchar();
		scanf("%d", &lct[i][1]);
		getchar();
	}
	quick_sort(lct, 0, n - 1);
	i = -1;
	while (++i < n)
		printf("%d %d\n", lct[i][0], lct[i][1]);
	i = -1;
	while (++i < n)
		free(lct[i]);
	free(lct);
	return (0);
}
