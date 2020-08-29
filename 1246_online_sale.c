//Baekjoon 1246 온라인 판매 - 배열 정렬
#include <stdio.h>
#include <stdlib.h>

void		sorting(int *p, int m)
{
	int		i;
	int		j;
	int		max;

	i = -1;
	while (++i < m - 1)
	{
		j = i;
		while (++j < m)
		{
			if (p[j] > p[i])
			{
				max = p[i];
				p[i] = p[j];
				p[j] = max;
			}
		}
	}
}

int			sale(int *p, int n, int m)
{
	int		i;
	int		num;
	int		sum;
	int		max;

	if (n > m)
		num = m;
	else
		num = n;
	sorting(p, m);
	i = -1;
	sum = 0;
	max = 0;
	while (++i < num)
	{
		if (p[i] * (i + 1) > sum)
		{
			max = i;
			sum = p[i] * (i + 1);
		}
	}
	return (max);
}

int			main(void)
{
	int		i;
	int		n;
	int		m;
	int		max;
	int		*p;

	scanf("%d %d", &n, &m);
	getchar();
	if (!(p = (int *)malloc(sizeof(int) * (m + 1))))
		return (0);
	i = -1;
	while (++i < m)
	{
		scanf("%d", &p[i]);
		getchar();
	}
	p[i] = 0;
	max = sale(p, n, m);
	printf("%d %d", p[max], p[max] * (max + 1));
	free(p);
	return (0);
}
