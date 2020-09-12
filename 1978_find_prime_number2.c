//Baekjoon 1978 소수찾기
#include <stdio.h>
#include <math.h>

int			check_number(int num)
{
	int		i;

	if (num < 2)
		return (0);
	if (num == 2)
		return (1);
	if (num % 2 == 0)
		return (0);
	i = 3;
	while (i <= sqrt(num))
	{
		if (num % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

int			main(void)
{
	int		i;
	int		n;
	int		num;
	int		count;

	scanf("%d", &n);
	getchar();
	count = 0;
	i = -1;
	while (++i < n)
	{
		scanf("%d", &num);
		getchar();
		if (check_number(num) == 1)
			count += 1;
	}
	printf("%d", count);
	return (0);
}
