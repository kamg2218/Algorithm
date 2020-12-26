//Baekjoon 2805 나무자르기
#include <stdio.h>
#include <stdlib.h>

long long		count_wood(long long *wood, long long n, long long h)
{
	long long	i;
	long long	count;

	i = -1;
	count = 0;
	while (++i < n)
	{
		if (wood[i] - h > 0)
			count += wood[i] - h;
	}
	return (count);
}

int				main(void)
{
	long long	n, m;
	long long	i, j, h;
	long long	min, max;
	long long	*wood;

	scanf("%lld %lld", &n, &m);
	getchar();
	if (!(wood = (long long *)malloc(sizeof(long long) * n)))
		return (0);
	i = -1;
	while (++i < n)
	{
		scanf("%lld", &wood[i]);
		getchar();
	}
	min = 0;
	max = wood[0];
	i = 0;
	while (++i < n)
	{
		if (max < wood[i])
			max = wood[i];
	}
	h = max;
	while (min <= max)
	{
		if (count_wood(wood, n, h) >= m)
		{
			min = h + 1;
			j = h;
		}
		else
			max = h - 1;
		h = (min + max) / 2;
	}
	printf("%lld", j);
	free(wood);
	return (0);
}
