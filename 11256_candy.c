//Baekjoon 11256 사탕
#include <stdio.h>
#include <stdlib.h>

void		sort(int *box, int n)
{
	int		i, j, z;

	i = -1;
	while (++i < n - 1)
	{
		j = i;
		while (++j < n)
		{
			if (box[i] < box[j])
			{
				z = box[i];
				box[i] = box[j];
				box[j] = z;
			}
		}
	}
}

int			main(void)
{
	int		t, j, n;
	int		x, y, length, width;
	int		count;
	int		*box;

	scanf("%d", &t);
	getchar();
	x = -1;
	while (++x < t)
	{
		scanf("%d %d", &j, &n);
		getchar();
		if (!(box = (int *)malloc(sizeof(int) * n)))
			return (0);
		y = -1;
		while (++y < n)
		{
			scanf("%d %d", &length, &width);
			getchar();
			box[y] = length * width;
		}
		sort(box, n);
		y = -1;
		count = 0;
		while (++y < n && count < j)
			count += box[y];
		printf("%d\n", y);
		free(box);
	}
	return (0);
}
