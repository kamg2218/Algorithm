//Baekjoon 4963 섬의 개수
#include <stdio.h>
#include <stdlib.h>

int			check_map(int **map, int h, int w, int x, int y)
{
	map[x][y] = 2;
	if (y + 1 < w && map[x][y + 1] == 1)
		check_map(map, h, w, x, y + 1);
	if (y - 1 >= 0 && map[x][y - 1] == 1)
		check_map(map, h, w, x, y - 1);
	if (x + 1 < h && map[x + 1][y] == 1)
		check_map(map, h, w, x + 1, y);
	if (x - 1 >= 0 && map[x - 1][y] == 1)
		check_map(map, h, w, x - 1, y);
	if (x + 1 < h && y + 1 < w && map[x + 1][y + 1] == 1)
		check_map(map, h, w, x + 1, y + 1);
	if (x + 1 < h && y - 1 >= 0 && map[x + 1][y - 1] == 1)
		check_map(map, h, w, x + 1, y - 1);
	if (x - 1 >= 0 && y + 1 < w && map[x - 1][y + 1] == 1)
		check_map(map, h, w, x - 1, y + 1);
	if (x - 1 >= 0 && y - 1 >= 0 && map[x - 1][y - 1] == 1)
		check_map(map, h, w, x - 1, y - 1);
	return (1);
}

int			count_island(int **map, int h, int w)
{
	int		i;
	int		j;
	int		count;

	count = 0;
	i = -1;
	while (++i < h)
	{
		j = -1;
		while (++j < w)
		{
			if (map[i][j] == 1)
				count += check_map(map, h, w, i, j);
		}
	}
	return (count);
}

int			main(void)
{
	int		i, j;
	int		w, h;
	int		**map;

	while (1)
	{
		scanf("%d %d", &w, &h);
		getchar();
		if (w == 0 && h == 0)
			break ;
		if (!(map = (int **)malloc(sizeof(int *) * h)))
			return (0);
		i = -1;
		while (++i < h)
		{
			if (!(map[i] = (int *)malloc(sizeof(int) * w)))
				return (0);
			j = -1;
			while (++j < w)
			{
				scanf("%d", &map[i][j]);
				getchar();
			}
		}
		printf("%d\n", count_island(map, h, w));
		i = -1;
		while (++i < h)
			free(map[i]);
		free(map);
	}
	return (0);
}
