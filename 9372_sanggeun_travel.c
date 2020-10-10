//Baekjoon 9372 상근이의 여행 - tree, array - 시간초과
#include <stdio.h>
#include <stdlib.h>
//비행기 노선 저장
void		add_plane(int **country, int n, int a, int b)
{
	int		i;

	i = -1;
	while (++i < n)
	{
		if (a < n && country[a - 1][i] == 0)
		{
			country[a - 1][i] = b;
			break ;
		}
	}
	i = -1;
	while (++i < n)
	{
		if (b < n && country[b - 1][i] == 0)
		{
			country[b - 1][i] = a;
			break ;
		}
	}
}
//모든 국가 방문 여부 확인
int			is_visited(int *visited, int n)
{
	int		i;

	i = -1;
	while (++i < n)
	{
		if (visited[i] == 0)
			return (0);
	}
	return (1);
}
// 길 찾기
int			check_plane(int **country, int n)
{
	int		i;
	int		j;
	int		now_i;
	int		now_j;
	int		count;
	int		*visited;

	if (!(visited = malloc(sizeof(int) * n)))
		return (0);
	i = -1;
	while (++i < n)
		visited[i] = 0;
	visited[0] = 1;
	now_i = 0;
	now_j = 0;
	count = 0;
	while (!(is_visited(visited, n)))
	{
		while (visited[country[now_i][now_j] - 1] == 1)
			++now_j;
		now_i = country[now_i][now_j] - 1;
		now_j = 0;
		visited[now_i] = 1;
		count++;
	}
	return (count);
}

int			main(void)
{
	int		i;
	int		j;
	int		k;
	int		n;
	int		m;
	int		t;
	int		a;
	int		b;
	int		**country;

	scanf("%d", &t);
	getchar();
	i = -1;
	while (++i < t) //전체 반복횟수
	{
		scanf("%d %d", &n, &m); //국가의 수와 비행기 종류
		getchar();
		if (!(country = (int **)malloc(sizeof(int *) * (n + 1))))
			return (0);
		j = -1;
		while (++j < n)
		{
			if (!(country[j] = (int *)malloc(sizeof(int) * (n + 1))))
				return (0);
		}
		country[j] = 0;
		j = -1;
		while (++j < m)
		{
			scanf("%d %d", &a, &b); //비행기 쌍 입력
			getchar();
			add_plane(country, n, a, b); //비행기 추가
		}
		printf("%d\n", check_plane(country, n)); //최소 이동 횟수 출력
		k = -1;
		while (++k < n)
			free(country[k]);
		free(country);
	}
	return (0);
}
