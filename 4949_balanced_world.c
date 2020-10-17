//Baekjoon 4949 균형잡힌 세상 - stack
#include <stdio.h>

int			main(void)
{
	int		i;
	int		j;
	char	bracket[101] = {0, };
	char	string[101] = {0, };
	
	while (1)
	{
		scanf("%[^.]s", string);
		getchar();
		getchar();
		if (!string[0])
			break ;
		i = -1;
		j = -1;
		while (++i < 100 && string[i])
		{
			if (string[i] == '(')
				bracket[++j] = 1;
			else if (string[i] == ')')
			{
				if (j < 0 || bracket[j] != 1)
				{
					j = 0;
					break ;
				}
				else
				{
					bracket[j] = 0;
					--j;
				}
			}
			else if (string[i] == '[')
				bracket[++j] = 2;
			else if (string[i] == ']')
			{
				if (j < 0 || bracket[j] != 2)
				{
					j = 0;
					break ;
				}
				else
				{
					bracket[j] = 0;
					--j;
				}
			}
		}
		if (j >= 0)
			printf("no\n");
		else
			printf("yes\n");
		i = -1;
		while (++i < 100)
		{
			string[i] = 0;
			bracket[i] = 0;
		}
	}
	return (0);
}
