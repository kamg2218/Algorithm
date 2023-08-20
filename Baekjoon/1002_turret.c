//Baekjoon 1002 터렛 - 원 방정식
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int			count_position(int *x, int *y)
{
	double	len;

	len = sqrt(pow(x[0] - y[0], 2) + pow(x[1] - y[1], 2));
	if (len == 0 && x[2] == y[2])
		return (-1);
	else if (len == 0)
		return (0);
	else if (len < x[2] + y[2] && len > abs(x[2] - y[2]))
		return (2);
	else if (len == abs(x[2] - y[2]) || len == x[2] + y[2])
		return (1);
	else
		return (0);
}

int			main(void)
{
	int		i;
	int		num;
	int		x[3];
	int		y[3];

	scanf("%d", &num);
	getchar();
	i = -1;
	while (++i < num)
	{
		scanf("%d %d %d %d %d %d", &x[0], &x[1], &x[2], &y[0], &y[1], &y[2]);
		getchar();
		printf("%d", count_position(x, y));
		if (i + 1 < num)
			printf("\n");
	}
	return (0);
}
