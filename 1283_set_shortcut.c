//Baekjoon 1283 단축키 지정
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int			is_in_shortcut(char *shortcut, int n, char m)
{
	int		i;

	if (m == ' ')
		return (1);
	i = -1;
	while (++i < n)
	{
		if (shortcut[i] == m)
			return (1);
		else if (shortcut[i] - 32 == m)
			return (1);
		else if (shortcut[i] + 32 == m)
			return (1);
	}
	return (0);
}

int			check_word(char *word, char *shortcut, int n)
{
	int		i;
	int		len;

	len = strlen(word);
	i = -1;
	while (++i < len)
	{
		while (i != 0 && i < len && word[i - 1] != ' ')
			++i;
		if (i < len && !(is_in_shortcut(shortcut, n, word[i])))
		{
			shortcut[n] = word[i];
			return (i);
		}
	}
	i = -1;
	while (++i < len)
	{
		if (i < len && !(is_in_shortcut(shortcut, n, word[i])))
		{
			shortcut[n] = word[i];
			return (i);
		}
	}
	return (-1);
}

int			main(void)
{
	int		i;
	int		j;
	int		n;
	int		m;
	int		len;
	char	word[61] = {0, };
	char	*shortcut;

	scanf("%d", &n);
	getchar();
	if (!(shortcut = (char *)malloc(sizeof(char) * n)))
		return (0);
	i = -1;
	while (++i < n)
		shortcut[i] = 0;
	i = -1;
	while (++i < n)
	{
		scanf("%[^\n]s", word);
		getchar();
		m = check_word(word, shortcut, i);
		len = strlen(word);
		j = -1;
		while (++j < len)
		{
			if (m == j)
				printf("[%c]", word[j]);
			else
				printf("%c", word[j]);
		}
		printf("\n");
		j = -1;
		while (++j < len)
			word[j] = 0;
	}
	free(shortcut);
	return (0);
}
