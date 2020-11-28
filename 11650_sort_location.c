//Baekjoon 11650 좌표 정렬하기 - bubble sort
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
		if (i != 0 && lct[i])
	}
	i = -1;
	while (++i < n - 1)
	{
		j = i;
		while (++j < n)
		{
			if (lct[i][0] > lct[j][0])
				change_num(lct, i, j);
			else if (lct[i][0] == lct[j][0]
					&& lct[i][1] > lct[j][1])
				change_num(lct, i, j);
		}
	}
	i = -1;
	while (++i < n)
		printf("%d %d\n", lct[i][0], lct[i][1]);
	i = -1;
	while (++i < n)
		free(lct[i]);
	free(lct);
	return (0);
}
