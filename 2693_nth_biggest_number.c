//Baekjoon 2693 N번째 큰수
#include <stdio.h>

int			arrange_array(int *array)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	while (++i < 9)
	{
		j = i;
		while (++j < 10)
		{
			if (array[i] < array[j])
			{
				k = array[i];
				array[i] = array[j];
				array[j] = k;
			}
		}
	}
	return (array[2]);
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
		printf("%d", arrange_array(array));
		num--;
		if (num > 0)
			printf("\n");
	}
	return (0);
}
