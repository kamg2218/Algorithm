//Baekjoon 11170 0의 개수
#include <stdio.h>

int			count_zero(int num)
{
	int		i;
	int		count;

	if (num == 0)
		return (1);
	i = num;
	count = 0;
	while (i)
	{
		if (i % 10 == 0)
			++count;
		i = i / 10;
	}
	return (count);
}

int			main(void)
{
	int		t;
	int		n;
	int		m;
	int		i;
	int		count;

	scanf("%d", &t);
	getchar();
	i = -1;
	while (++i < t)
	{
		scanf("%d %d", &n, &m);
		getchar();
		count = 0;
		while (n <= m)
		{
			count += count_zero(n);
			++n;
		}
		printf("%d\n", count);
	}
	return (0);
}
