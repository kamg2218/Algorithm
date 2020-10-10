//Baekjoon 2204 도비의 난독증 테스트
#include <string.h>
#include <stdio.h>

int			compare_string(char *string, char *first)
{
	int		i;
	int		a;
	int		b;
	int		n;
	int		len;

	if (first[0] == 0)
		return (-1);
	n = strlen(string);
	len = strlen(first);
	if (n > len)
		len = n;
	i = -1;
	while (++i < len)
	{
		if (string[i] >= 97)
			a = string[i] - 97;
		else
			a = string[i] - 65;
		if (first[i] >= 97)
			b = first[i] - 97;
		else
			b = first[i] - 65;
		if (a > b)
			return (1);
		else if (a < b)
			return (-1);
	}
	return (0);
}

int			main(void)
{
	int		i;
	int		j;
	int		n;
	char	string[21] = {0, };
	char	first[21] = {0, };

	while (1)
	{
		scanf("%d", &n);
		getchar();
		if (n == 0)
			break ;
		i = -1;
		while (++i < n)
		{
			scanf("%s", string);
			getchar();
			if (compare_string(string, first) == -1)
				strcpy(first, string);
		}
		printf("%s\n", first);
		i = -1;
		while (first[++i])
			first[i] = 0;
	}
	return (0);
}
