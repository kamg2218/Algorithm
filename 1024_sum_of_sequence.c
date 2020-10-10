//Baekjoon 1024 순열의 합
#include <stdio.h>

int			main(void)
{
	int		i;
	int		n;
	int		m;
	int		num;
	int		start;

	scanf("%d %d", &n, &m);
	while ((num = n - (m * (m - 1) / 2)) % m || num / m < 0)
		++m;
	if (m > 100)
		printf("-1");
	else
	{
		start = num / m;
		i = -1;
		while (++i < m - 1)
			printf("%d ", start + i);
		printf("%d", start + i);
	}
	return (0);
}
