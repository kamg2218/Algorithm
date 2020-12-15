//Baekjoon 1012 유기농배추 - search
#include <stdio.h>
#include <stdlib.h>

//상하좌우 값 확인
int			check_field(int **field, int m, int n, int x, int y)
{
	field[x][y] = 2;
	if (y + 1 < n && field[x][y + 1] == 1)
		check_field(field, m, n, x, y + 1);
	if (y - 1 >= 0 && field[x][y - 1] == 1)
		check_field(field, m, n, x, y - 1);
	if (x + 1 < m && field[x + 1][y] == 1)
		check_field(field, m, n, x + 1, y);
	if (x - 1 >= 0 && field[x - 1][y] == 1)
		check_field(field, m, n, x - 1, y);
	return (1);
}

//좌표 전체를 확인하면서 배추 위치 확인
int			count_cabbage(int **field, int m, int n)
{
	int		i;
	int		j;
	int		count;

	count = 0;
	i = -1;
	while (++i < m)
	{
		j = -1;
		while (++j < n)
		{
			if (field[i][j] == 1)
				count += check_field(field, m, n, i, j);
		}
	}
	return (count);
}

int			main(void)
{
	int		t, m, n, k;
	int		i, j, a;
	int		x, y;
	int		**field;

	scanf("%d", &t);
	getchar();
	i = -1;
	while (++i < t)
	{
		scanf("%d %d %d", &m, &n, &k);
		getchar();
		//밭 메모리 할당
		if (!(field = (int **)malloc(sizeof(int *) * m)))
			return (0);
		j = -1;
		while (++j < m)
		{
			if (!(field[j] = (int *)malloc(sizeof(int) * n)))
				return (0);
			a = -1;
			while (++a < n)
				field[j][a] = 0;
		}
		//배추 위치 표시
		j = -1;
		while (++j < k)
		{
			scanf("%d %d", &x, &y);
			getchar();
			field[x][y] = 1;
		}
		//지렁이 수 확인
		printf("%d\n", count_cabbage(field, m, n));
		//밭 메모리 해제
		j = -1;
		while (++j < m)
			free(field[j]);
		free(field);
	}
	return (0);
}
