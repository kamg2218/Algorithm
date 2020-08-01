//Baekjoon 1110번 더하기 사이클
#include <stdio.h>

int			calculate(int num)
{
	int		i;
	int		new;

	i = num / 10 + num % 10;
	new = (num % 10) * 10 + i % 10;
	return (new);
}

int		main(void)
{
	int		num;
	int		new;
	int		count;

	scanf("%d", &num);
	new = num;
	count = 0;
	while (1)
	{
		//printf("%d, ", new);
		new = calculate(new);
		count++;
		if (new == num)
			break;
	}
	printf("%d", count);
	return (0);
}
