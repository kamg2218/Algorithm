//Baekjoon 1003 피보나치 함수
#include <stdio.h>

int			p[41] = {0, };

int			fibonacci(int n)
{
	if (n == 0)
	{
		p[0] = 0;
		return (0);
	}
	else if (n == 1)
	{
		p[1] = 1;
		return (1);
	}
	if (p[n] != 0)
		return (p[n]);
	else
		return (p[n] = fibonacci(n-1) + fibonacci(n-2));
}

int			main(void)
{
	int		i;
	int		n;
	int		num;

	scanf("%d", &n);
	i = -1;
	while (++i < n)
	{
		scanf("%d", &num);
		getchar();
		if (num == 0)
			printf("1 0");
		else if (num == 1)
			printf("0 1");
		else
		{
			fibonacci(num);
			printf("%d %d", p[num - 1], p[num]);
		}
		if (i + 1 < n)
			printf("\n");
	}
	return (0);
}
