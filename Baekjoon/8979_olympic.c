//8979 올림픽
#include <stdio.h>

int		medal[1000][4];

int			count_medal(int n, int k)
{
	int		i;
	int		count = 0;

	i = -1;
	while (++i < n)
	{
		if (i == k)
			continue ;
		if (medal[i][1] > medal[k][1])
			++count;
		else if (medal[i][1] == medal[k][1]
				&& medal[i][2] > medal[k][2])
			++count;
		else if (medal[i][1] == medal[k][1]
				&& medal[i][2] ==  medal[k][2]
				&& medal[i][3] > medal[k][3])
			++count;
	}
	return (count + 1);
}

int			main(void)
{
	int		n, k;
	int		i, j;
	int		country;

	scanf("%d %d", &n, &k);
	getchar();
	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < 4)
		{
			scanf("%d", &medal[i][j]);
			getchar();
			if (medal[i][0] == k)
				country = i;
		}
	}
	printf("%d", count_medal(n, country));
	return (0);
}
