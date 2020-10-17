//Baekjoon 11399 ATM
#include <stdio.h>
#include <stdlib.h>

int static	compare(const void *first, const void *second)
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
	int		j;
	int		n;
	int		*num;

	scanf("%d", &n);
	getchar();
	if (!(num = malloc(sizeof(int) * n)))
		return (0);
	i = -1;
	while (++i < n)
	{
		scanf("%d", &num[i]);
		getchar();
	}
	qsort(num, n, sizeof(int), compare);
	i = -1;
	j = 0;
	while (++i < n)
		j += (n - i) * num[i];
	printf("%d", j);
	return (0);
}
