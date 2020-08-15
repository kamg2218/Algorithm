//Baekjoon 9358 순열 접기 게임

#include <stdio.h>
#include <stdlib.h>
//순열 계산 횟수 반환
int			count(int x)
{
	int		i;

	i = 0;
	while (x > 2)
	{
		if (x % 2)
			x += 1;
		x = x / 2;
		++i;
	}
	return (i);
}
//배열 계산 함수
void		set_array(int  **array, int i, int *max)
{
	int		x;
	int		y;

	y = *max / 2;
	if (*max % 2)
		++y;
	x = -1;
	while (++x < y)
		array[i][x] += array[i][*max - x - 1];
	array[i][x] = 0;
	*max = x;
}
int			main(void)
{
	int		i;
	int		j;
	int		n;
	int		k;
	int		*m;
	int		**array;

	//메모리 할당
	scanf("%d", &n);
	getchar();
	if (!(array = (int **)malloc(sizeof(int *) * (n + 1))))
		return (0);
	if (!(m = (int *)malloc(sizeof(int) * (n + 1))))
		return (0);
	i = -1;
	while (++i < n)
	{
		scanf("%d", &m[i]);
		getchar();
		if (!(array[i] = (int *)malloc(sizeof(int) * (m[i] + 1))))
			return (0);
		j = -1;
		while (++j < m[i])
		{
			scanf("%d", &array[i][j]);
			getchar();
		}
		array[i][j] = 0;
	}
	array[i] = 0;
	//입력 갯수만큼 순열 계산하는 반복문
	i = -1;
	while (++i < n)
	{
		j = -1;
		k = count(m[i]);
		while (++j < k)
			set_array(array, i, &m[i]);
		if (array[i][0] > array[i][1])
			printf("Case #%d: Alice", i + 1);
		else
			printf("Case #%d: Bob", i + 1);
		if (i + 1 < n)
			printf("\n");
	}
	//메모리 해제
	i = -1;
	while (++i < n)
		free(array[i]);
	free(array);
	free(m);
	return (0);
}
