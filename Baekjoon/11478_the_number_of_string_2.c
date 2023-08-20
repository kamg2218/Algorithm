//Baekjoon 11478 서로 다른 부분 문자열의 개수
#include <stdio.h>
#include <string.h>

int			check_string(char *str, int start, int len, int s_len)
{
	int		i;
	int		count;

	count = 1;
	printf("start, len = %d, %d, %d\n", start, len, s_len);
	if (start + len > s_len)
		return (0);
	i = -1;
	while (++i <= s_len - len)
	{
		if (start == i)
			continue ;
		if (!(strncmp(&str[i], &str[start], len)))
		{
			if (i < start)
				count = 0;
			break ;
		}
	}
	if (start < s_len - len)
		count += check_string(str, start + 1, len, s_len);
	else if (len <= s_len)
		count += check_string(str, 0, len + 1, s_len);
	return (count);
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
	count = check_string(str, 0, 1, s_len);
	/*
	while (++i <= s_len)
	{
		j = -1;
		while (++j <= s_len - i)
			count += check_string(str, j, i, s_len);
		//printf("i, count = %d, %d\n", i, count);
	}
	*/
	printf("count = %d\n", count);
	return (0);
}
