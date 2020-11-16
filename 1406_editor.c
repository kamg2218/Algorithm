//Baekjoon 1406 에디터 - array, 시간초과
#include <stdio.h>
#include <time.h>

void		cmd_p(char *str, char *cmd, int cursor, int n)
{
	int		i;
	
	i = n + 1;
	while (i > cursor)
	{
		str[i] = str[i - 1];
		--i;
	}
	str[cursor] = cmd[2];
}

void		cmd_b(char *str, int cursor, int n)
{
	int		i;

	if (cursor == 0)
		return ;
	i = cursor;
	while (i < n)
	{
		str[i - 1] = str[i];
		++i;
	}
	str[n - 1] = 0;
}

int			main(void)
{
	int		i;
	int		n;
	int		m;
	int		cursor;
	char	cmd[4] = {0, };
	char	str[600001] = {0, };
	clock_t start, end;

	scanf("%[^\n]s", str);
	getchar();
	scanf("%d", &m);
	getchar();
	start = clock();
	n = 0;
	while (str[n])
		++n;
	i = -1;
	cursor = n;
	while (++i < m)
	{
		//printf("str = %s, %d, %d\n", str, cursor, n);
		scanf("%[^\n]s", cmd);
		getchar();
		if (cmd[0] == 'L' && cursor > 0)
			cursor -= 1;
		else if (cmd[0] == 'D' && cursor < n)
			cursor += 1;
		else if (cmd[0] == 'B')
		{
			cmd_b(str, cursor, n);
			if (cursor > 0)
			{
				cursor -= 1;
				n -= 1;
			}
		}
		else if (cmd[0] == 'P')
		{
			cmd_p(str, cmd, cursor, n);
			n += 1;
			if (cursor < n)
				cursor += 1;
		}
	}
	printf("%s", str);
	end = clock();
	printf("time = %lf\n", (float)(end - start) / CLOCKS_PER_SEC);
	return (0);
}
