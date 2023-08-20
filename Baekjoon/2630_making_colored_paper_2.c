//Baekjoon 2630 색종이 만들기- recursive

#include <stdio.h>
#include <stdlib.h>

void		colored_paper(int **paper, int *count, int i, int j, int n)
{
	int		a;
	int		b;
	int		ch;

	ch = paper[i][j];
	a = i - 1;
	while (++a < i + n)
	{
		b = j - 1;
		while (++b < j + n)
		{
			if (ch != paper[a][b])
			{
				colored_paper(paper, count, i, j, n / 2);
				colored_paper(paper, count, i + n / 2, j, n / 2);
				colored_paper(paper, count, i, j + n / 2, n / 2);
				colored_paper(paper, count, i + n / 2, j + n / 2, n / 2);
				return ;
			}
		}
	}
	if (ch == 0)
		count[0] += 1;
	else
		count[1] += 1;
}

int			main(void)
{
	int		n;
	int		i;
	int		j;
	int		count[2] = {0, };
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
	colored_paper(paper, count, 0, 0, n);
	printf("%d\n%d", count[0], count[1]);
	i = -1;
	while (++i < n)
		free(paper[i]);
	free(paper);
	return (0);
}
