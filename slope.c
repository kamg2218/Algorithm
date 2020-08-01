//Baekjoon 14890 경사로
#include <stdio.h>
#include <stdlib.h>

int		check_paral(int **array, int len, int l)
{
	int		row;
	int		col;
	int		num;
	int		count;

	count = 0;
	row = -1;
	while (++row < len)
	{
		num = 1;
		col = -1;
		while (++col < len - 1)
		{
			if (array[row][col] == array[row][col + 1])
				num++;
			else if (array[row][col] == array[row][col + 1] - 1)
			{
				if (num < l)
					col = len;
				num = 1;
			}
			else if (array[row][col] == array[row][col + 1] + 1)
			{
				num = 1;
				while (num < l
						&& ++col < len - 1
						&& array[row][col] == array[row][col + 1])
					num++;
				if (num != l)
					col = len;
				num = 0;
			}
			else
				col = len;
		}
		if (col != len + 1)
			count++;
	}
	return (count);
}

int		check_vert(int **array, int len, int l)
{
	int		row;
	int		col;
	int		num;
	int		count;

	count = 0;
	col = -1;
	while (++col < len)
	{
		num = 1;
		row = -1;
		while (++row < len - 1)
		{
			if (array[row][col] == array[row + 1][col])
				num++;
			else if (array[row][col] == array[row + 1][col] - 1)
			{
				if (num < l)
					row = len;
				else
					num = 1;
			}
			else if (array[row][col] == array[row + 1][col] + 1)
			{
				num = 1;
				while (num < l
						&& ++row < len - 1
						&& array[row][col] == array[row + 1][col])
					num++;
				if (num != l)
					row = len;
				num = 0;
			}
			else
				row = len;
		}
		if (row != len + 1)
			count++;
	}
	return (count);
}

int		main(void)
{
	int		i;
	int		j;
	int		l;
	int		len;
	int		count;
	int		**array;

	scanf("%d %d", &len, &l);
	if (!(array = (int **)malloc(sizeof(int *) * (len + 1))))
		return (0);
	i = -1;
	while (++i < len)
	{
		if (!(array[i] = (int *)malloc(sizeof(int) * (len + 1))))
			return (0);
		j = -1;
		while (++j < len)
			scanf("%d", &array[i][j]);
		array[i][len] = 0;
	}
	array[len] = 0;
	//가로 확인
	count = check_paral(array, len, l);
	//세로 확인
	count += check_vert(array, len, l);
	printf("%d", count);
	i = -1;
	while (++i <= len)
		free(array[i]);
	free(array);
	return (0);
}
