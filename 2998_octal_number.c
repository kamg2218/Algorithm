//Baekjoon 2998 8진수 - array
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void		print_num(char *num)
{
	if (strncmp(num, "000", 3) == 0)
		printf("0");
	else if (strncmp(num, "001", 3) == 0)
		printf("1");
	else if (strncmp(num, "010", 3) == 0)
		printf("2");
	else if (strncmp(num, "011", 3) == 0)
		printf("3");
	else if (strncmp(num, "100", 3) == 0)
		printf("4");
	else if (strncmp(num, "101", 3) == 0)
		printf("5");
	else if (strncmp(num, "110", 3) == 0)
		printf("6");
	else if (strncmp(num, "111", 3) == 0)
		printf("7");
}

int			main(void)
{
	int		i;
	int		j;
	int		k;
	char	decimal[101] = {0, };
	char	array[4] = {'0', '0', '0', 0};

	scanf("%s", decimal);
	i = 0;
	while (decimal[i])
		++i;
	j = i % 3;
	if (j != 0)
	{
		k = j;
		while (--k >= 0)
			array[2 - k] = decimal[j - k - 1];
		print_num(array);
		//printf("array = %s\n", array);
	}
	while (j < i)
	{
		print_num(&decimal[j]);
		j += 3;
	}
	return (0);
}
