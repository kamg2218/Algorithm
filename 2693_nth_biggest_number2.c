//Baekjoon 2693 N번째 큰수
#include <stdio.h>
#include <stdlib.h>

int			compare(const void *first, const void *second)
{
	if (*(int *)first > *(int *)second)
		return (1);
	else if (*(int *)first < *(int *)second)
		return (-1);
	else
		return (0);
}

int			main(void)
{
	int		i;
	int		num;
	int		array[10];

	scanf("%d", &num);
	getchar();
	while (num > 0)
	{
		i = -1;
		while (++i < 10)
		{
			scanf("%d", &array[i]);
			getchar();
		}
		qsort(array, 10, sizeof(int), compare);
		printf("%d", array[7]);
		num--;
		if (num > 0)
			printf("\n");
	}
	return (0);
}
