//Baekjoon 6219 소수의 자격 
#include <stdio.h>
#include <math.h>

int			prime_number(int num)
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

int			check_num(int num, int d)
{
	int		i;

	if (num == d)
		return (1);
	i = num;
	while (i)
	{
		if (i % 10 == d)
			return (1);
		i /= 10;
	}
	return (0);
}

int			main(void)
{
	int		a;
	int		b;
	int		c;
	int		d;
	int		count;

	scanf("%d %d %d", &a, &b, &d);
	c = a;
	count = 0;
	while (c <= b)
	{
		if (prime_number(c) && check_num(c, d))
			++count;
		++c;
	}
	printf("%d", count);
	return (0);
}
