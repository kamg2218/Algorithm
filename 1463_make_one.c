//Baekjoon 1463 1로 만들기 - 동적계획법
#include <stdio.h>
#include <stdlib.h>

int			main(void)
{
	int		i;
	int		n;
	int		a;
	int		b;
	int		*num;

	scanf("%d", &n);
	if (!(num = malloc(sizeof(int) * (n + 1))))
		return (0);
	num[0] = 0;
	num[1] = 0;
	num[2] = 1;
	num[3] = 1;
	i = 3;
	while (++i < n + 1)
	{
		a = num[i / 3] + i % 3 + 1;
		b = num[i / 2] + i % 2 + 1;
		if (a > b)
			num[i] = b;
		else
			num[i] = a;
	}
	printf("%d", num[n]);
	free(num);
	return (0);
}
