//Baekjoon 2630 색종이 만들기 - array

#include <stdio.h>
#include <stdlib.h>

int			check_paper(int n, int x, int y, int **paper)
{
	int		i;
	int		j;
	int		num;

	i = -1;
	num = paper[x][y];
	while (++i < n)
	{
		j = -1;
		while (++j < n)
		{
			if (num != paper[x + i][y + j])
				return (0);
		}
	}
	return (1);
}

void		change_num(int n, int x, int y, int **paper)
{
	int		i;
	int		j;

	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
			paper[x + i][y + j] += 2;
	}
	paper[x][y] += 2;
}

void		get_paper(int n, int **paper)
{
	int		i;
	int		j;
	int		m;

	m = n;
	while (m)
	{
		i = 0;
		while (i < n)
		{
			j = 0;
			while (j < n)
			{
				if ((paper[i][j] == 1 || paper[i][j] == 0)
					&& check_paper(m, i, j, paper))
					change_num(m, i, j, paper);
				j += m;
			}
			i += m;
		}
		m /= 2;
	}
}

int			main(void)
{
	int		n;
	int		i;
	int		j;
	int		k;
	int		count;
	int		**paper;

	scanf("%d", &n);
	getchar();
	if (!(paper = (int **)malloc(sizeof(int *) * (n + 1))))
		return (0);
	i = -1;
	while (++i < n)
	{
		if (!(paper[i] = (int *)malloc(sizeof(int) * (n + 1))))
			return (0);
	}
	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
		{
			scanf("%d", &paper[i][j]);
			getchar();
		}
	}
	get_paper(n, paper);
	k = -1;
	while (++k < 2)
	{
		count = 0;
		i = -1;
		while (++i < n)
		{
			j = -1;
			while (++j < n)
			{
				if (paper[i][j] == k + 4)
					count += 1;
			}
		}
		printf("%d\n", count);
	}
	i = -1;
	while (++i < n)
		free(paper[i]);
	free(paper);
	return (0);
}
