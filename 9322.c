//Baekjoon 9322 철벽 보안 알고리즘 - 문자열
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//키 값 구하는 함수
int			*get_key(char **openkey1, char **openkey2, int m)
{
	int		i, j;
	int		*key;

	if (!(key = (int *)malloc(sizeof(int) * (m + 1))))
		return (0);
	i = -1;
	while (++i < m)
	{
		j = -1;
		while (++j < m)
		{
			//두 공개키의 값이 같은 경우, 
			//키 값에, 두번째 공개키의 위치에
			//첫번째 공개키의 위치 값을 저장한다.
			if (strcmp(openkey1[i], openkey2[j]) == 0)
				key[j] = i;
		}
	}
	return (key);
}
//평문 출력하는 함수
void		get_plain_text(char **secret, int *key, int m)
{
	int		i, j;

	i = -1;
	while (++i < m)
	{
		j = -1;
		while (++j < m)
		{
			if (key[j] == i)
			{
				printf("%s", secret[j]);
				if (i + 1 < m)
					printf(" ");
			}
		}
	}
	printf("\n");
}
//문자열을 복사하여 저장하는 함수
char		*get_short_string(char *str, int start, int end)
{
	int		i;
	char	*new;


	if (!(new = (char *)malloc(sizeof(char) * (end - start + 1))))
		return (NULL);
	i = -1;
	while (++i < end - start)
		new[i] = str[start + i];
	new[i] = 0;
	return (new);
}
//스페이스를 기준으로 문자열을 나누어 이중배열로 저장하는 함수
char		**get_string(char *str, int m)
{
	int		i;
	int		start;
	int		count;
	char	**key;

	if (!(key = (char **)malloc(sizeof(char *) * (m + 1))))
		return (NULL);
	i = -1;
	start = 0;
	count = 0;
	while (str[++i])
	{
		if (str[i] == ' ')
		{
			key[count++] = get_short_string(str, start, i);
			start = i + 1;
		}
	}
	key[count++] = get_short_string(str, start, i);
	key[count] = NULL;
	return (key);
}

int			main(void)
{
	int		i, j, k;
	int		n, m;
	char	**openkey1;
	char	**openkey2;
	char	**secret;
	char	str[20001] = {0, };
	int		*key;

	//n 값 저장
	scanf("%d", &n);
	getchar();
	i = -1;
	while (++i < n)
	{
		//단어의 갯수 저장
		scanf("%d", &m);
		getchar();
		j = -1;
		while (++j < 3)
		{
			//문자열 입력
			scanf("%[^\n]s", str);
			getchar();
			//차례대로 오픈키1, 오픈키2, 암호문 저장
			if (j == 0)
				openkey1 = get_string(str, m);
			else if (j == 1)
				openkey2 = get_string(str, m);
			else
				secret = get_string(str, m);
		}
		//키 값 구하기
		key = get_key(openkey1, openkey2, m);
		//평문 구하여 출력하기
		get_plain_text(secret, key, m);
		//초기화
		j = -1;
		while (++j < 20001)
			str[j] = 0;
		//메모리 해제
		j = -1;
		while (++j < m)
		{
			free(openkey1[j]);
			free(openkey2[j]);
			free(secret[j]);
		}
		free(openkey1);
		free(openkey2);
		free(secret);
		free(key);
	}
	return (0);
}
