//Baekjoon 11478 서로 다른 부분 문자열의 개수
#include <stdio.h>
#include <string.h>

int			check_string(char *str, int start, int len, int s_len)
{
	int		i;

	if (start + len > s_len)
		return (0);
	i = -1;
	while (++i <= s_len - len)
	{
		if (start == i)
			continue ;
		if (!(strncmp(&str[i], &str[start], len)))
		{
			if (i > start)
				return (1);
			return (0);
		}
	}
	return (1);
}

int			main(void)
{
	int		i;
	int		j;
	int		s_len;
	int		count;
	char	str[1001] = {0, };

	scanf("%s", str);
	s_len = strlen(str);
	printf("len = %d\n", s_len);
	i = 0;
	count = 0;
	while (++i <= s_len)
	{
		j = -1;
		while (++j <= s_len - i)
			count += check_string(str, j, i, s_len);
		//printf("i, count = %d, %d\n", i, count);
	}
	printf("count = %d\n", count);
	return (0);
}
