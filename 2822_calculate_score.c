//Baekjoon 2822 점수계산
#include <stdio.h>

int			main(void)
{
	int		i;
	int		j;
	int		n;
	int		m;
	int		score[8] = {0, };
	
	i = -1;
	while (++i < 8)
	{
		scanf("%d", &score[i]);
		getchar();
	}
	j = -1;
	while (++j < 3)
	{
		n = 0;
		i = -1;
		while (++i < 8)
		{
			if ((score[n] > score[i] || score[n] == -1) && score[i] != -1)
				n = i;
		}
		score[n] = -1;
	}
	i = -1;
	while (++i < 8)
		printf("%d ", score[i]);
	printf("\n");
	i = -1;
	n = 0;
	while (++i < 8)
	{
		if (score[i] != -1)
			n += score[i];
	}
	printf("%d\n", n);
	i = -1;
	while (++i < 8)
	{
		if (score[i] != -1)
			printf("%d", i + 1);
		if (score[i] != -1 && i + 1 < 8)
			printf(" ");
	}
	return (0);
}
