#include <stdio.h>

char		friend[51][51];
int			visited[51];

int			get_count(int i, int n)
{
	int		a, b;
	int		count;
	int		check[51] = {0, };

	a = -1;
	while (++a < n)
	{
		if (i != a && friend[i][a] == 'Y')
		{
			check[a] = 1;
			b = -1;
			while (++b < n)
			{
				if (i != b && friend[a][b] == 'Y')
					check[b] = 1;
			}
		}
	}
	count = 0;
	a = -1;
	while (++a < n)
	{
		if (check[a] == 1)
			++count;
	}
	return (count);
}

int			main(void)
{
	int		i, j;
	int		n;
	int		max;

	scanf("%d", &n);
	getchar();
	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
			scanf("%c", &friend[i][j]);
		getchar();
	}
	i = -1;
	max = 0;
	while (++i < n)
	{
		j = get_count(i, n);
		if (j > max)
			max = j;
	}
	printf("%d", max);
	return (0);
}
