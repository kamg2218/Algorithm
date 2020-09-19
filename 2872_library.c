//Baekjoon 2872 우리집엔 도서관이 있어
#include <stdio.h>
#include <stdlib.h>

int			find_num(int *array, int num)
{
	int		i;

	i = 0;
	while (array[i] != num)
		i++;
	return (i);
}

int			check_left(int *array, int num, int count)
{
	int		i;

	i = count;
	while (i >= 0 && array[i] != num)
		i--;
	if (i < 0)
		return (-1);
	else
		return (i);
}

int			main(void)
{
	int		i;
	int		num;
	int		count;
	int		*array;

	scanf("%d", &num);
	getchar();
	if (!(array = (int *)malloc(sizeof(int) * (num + 1))))
		return (0);
	i = -1;
	while (++i < num)
	{
		scanf("%d", &array[i]);
		getchar();
	}
	array[i] = 0;
	count = find_num(array, num);
	while ((count = check_left(array, num - 1, count)) != -1)
		num -= 1;
	printf("%d", num - 1);
	free(array);
	return (0);
}
