#include <stdio.h>
#include <stdlib.h>

void		put(int **num, int n, int a, int b)
{
	int		i;

	i = 0;
	while (i < n && num[a - 1][i] != 0)
		++i;
	num[a - 1][i] = b;
}

int			is_in(int *p, int n, int num)
{
	int		i;
	
	i = -1;
	while (++i < n)
	{
		if (p[i] == num)
			return (1);
	}
	return (0);
}

void		dfs(int **num, int *p, int n, int v)
{
	int		i;
	int		j;

	i = -1;
	while (++i < n && num[v - 1][i] != 0)
	{
		if (!(is_in(p, n, num[v - 1][i])))
		{
			j = 0;
			while (j < n && p[j])
				++j;
			p[j] = num[v - 1][i];
			dfs(num, p, n, num[v - 1][i]);
		}
	}
}

void		bfs(int **num, int *p, int n, int v)
{
	int		i;
	int		p_len;

	if (v == 0)
		return ;
	p_len = 0;
	while (p[p_len])
		++p_len;
	i = 0;
	while (num[v - 1][i])
	{
		if (!(is_in(p, n, num[v - 1][i])))
		{
			//printf("bfs = %d\n", num[v - 1][i]);
			p[p_len] = num[v - 1][i];
			++p_len;
		}
		++i;
	}
}

void		arrange(int **num, int n)
{
	int		i;
	int		j;
	int		tmp;

	i = -1;
	while (++i < n)
	{
		j = 0;
		while (++j < n && num[i][j])
		{
			if (num[i][j] < num[i][j - 1])
			{
				tmp = num[i][j];
				num[i][j] = num[i][j - 1];
				num[i][j - 1] = tmp;
				j = 0;
			}
		}
	}
}

int			main(void)
{
	int		i;
	int		j;
	int		n;
	int		m;
	int		v;
	int		a;
	int		b;
	int		*p;
	int		**num;

	scanf("%d %d %d", &n, &m, &v);
	getchar();
	if (!(num = (int **)malloc(sizeof(int *) * n)))
		return (0);
	i = -1;
	while (++i < n)
	{
		if (!(num[i] = (int *)malloc(sizeof(int) * n)))
			return (0);
		j = -1;
		while (++j < n)
			num[i][j] = 0;
	}
	if (!(p = (int *)malloc(sizeof(int) * n)))
		return (0);
	i = -1;
	while (++i < m)
	{
		scanf("%d %d", &a, &b);
		getchar();
		put(num, n, a, b);
		put(num, n, b, a);
	}
	arrange(num, n);
	p[0] = v;
	dfs(num, p, n, v);
	i = -1;
	while (++i < n && p[i] != 0)
	{
		printf("%d", p[i]);
		if (i + 1 < n && p[i + 1] != 0)
			printf(" ");
	}
	printf("\n");
	i = 0;
	while (++i < n)
		p[i] = 0;
	i = -1;
	while (++i < n)
		bfs(num, p, n, p[i]);
	i = -1;
	while (++i < n && p[i] != 0)
	{
		printf("%d", p[i]);
		if (i + 1 < n && p[i + 1] != 0)
			printf(" ");
	}
	free(p);
	i = -1;
	while (++i < n)
		free(num[i]);
	free(num);
	return (0);
}
