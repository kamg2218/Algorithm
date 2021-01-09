//7569 토마토 - array - 시간초과
#include <stdio.h>
#include <stdlib.h>

int		box[101][101][101];
int		n, m, h;

void		bfs(int a, int b, int c, int x)
{
	if (a - 1 >= 0 && box[a - 1][b][c] == 0)
		box[a - 1][b][c] = x + 1;
	if (a + 1 < m && box[a + 1][b][c] == 0)
		box[a + 1][b][c] = x + 1;
	if (b - 1 >= 0 && box[a][b - 1][c] == 0)
		box[a][b - 1][c] = x + 1;
	if (b + 1 < n && box[a][b + 1][c] == 0)
		box[a][b + 1][c] = x + 1;
	if (c - 1 >= 0 && box[a][b][c - 1] == 0)
		box[a][b][c - 1] = x + 1;
	if (c + 1 < h && box[a][b][c + 1] == 0)
		box[a][b][c + 1] = x + 1;
}

int			tomato(int t, int *count)
{
	int		i, j, z;
	int		time;

	time = 0;
	i = -1;
	while (++i < h)
	{
		j = -1;
		while (++j < n)
		{
			z = -1;
			while (++z < m)
			{
				if (box[z][j][i] == t + 1)
				{
					bfs(z, j, i, box[z][j][i]);
					time = 1;
				}
				else if (box[z][j][i] == 0)
					*count += 1;
			}
		}
	}
	return (time);
}

int			main(void)
{
	int		i, j, z;
	int		k;
	int		time;

	scanf("%d %d %d", &m, &n, &h);
	getchar();
	i = -1;
	while (++i < h)
	{
		j = -1;
		while (++j < n)
		{
			z = -1;
			while (++z < m)
			{
				scanf("%d", &box[z][j][i]);
				getchar();
			}
		}
	}
	time = 0;
	while (tomato(time, &k))
	{
		k = 0;
		++time;
		/*
		printf("\n");
		for (i = 0; i < h; i++){
			for (j = 0; j < n; j++){
				for (z = 0; z < m; z++){
					printf("%d ", box[z][j][i]);
				}
				printf("\n");
			}
		}*/
	}
	if (k == 0)
		printf("%d", time - 1);
	else
		printf("-1");
	return (0);
}
