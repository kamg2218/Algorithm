//Baekjoon 1158 요세푸스 - array
#include <stdio.h>
#include <stdlib.h>

int			main(void)
{
	int		i;
	int		j;
	int		n;
	int		k;
	int		*num;

	scanf("%d %d", &n, &k);
	if (!(num = (int *)malloc(sizeof(int) * (n + 1))))
		return (0);
	i = -1;
	while (++i < n)
		num[i] = i + 1;
	num[i] = 0;
	printf("<");
	i = 0;
	while (n)
	{
		i = (i + k) % n;
		if (i == 0)
			i = n;
		if (n == 1)
		{
			printf("%d>", num[0]);
			break ;
		}
		else
		{
			printf("%d, ", num[i - 1]);
			j = i - 2;
			while (++j < n)
				num[j] = num[j + 1];
			i -= 1;
		}
		n -= 1;
	}
	free(num);
	return (0);
}
