//Baekjoon 2617 구슬 찾기 - dfs
#include <stdio.h>
#include <stdlib.h>

int			dfs(int **head, int start, int *result)
{
	int		i, j;
	int		count;

	result[start] = 1;
	count = 0;
	i = 0;
	while (head[start][i] != 0)
	{
		if (result[head[start][i] - 1] == 0)
			count += dfs(head, head[start][i] - 1, result) + 1;
		++i;
	}
	return (count);
}

int			count_node(int **more, int **less, int n)
{
	int		i, j, count, lcount, sum;
	int		visited[100];
	int		lvisited[100];

	sum = 0;
	i = -1;
	while (++i < n)
	{
		//방문 기록 초기화
		j = -1;
		while (++j < n){
			visited[j] = 0;
			lvisited[j] = 0;
		}
		//이상에 대한 계산
		count = dfs(more, i, visited);
		//이하에 대한 계산
		lcount = dfs(less, i, lvisited);
		//절반 초과일 경우, 횟수 저장
		if (count > n / 2 || lcount > n / 2)
			++sum;
	}
	return (sum);
}

//배열 저장
void		add_num(int *beads, int num)
{
	int		i;

	i = 0;
	while (beads[i] != 0)
		++i;
	beads[i] = num;
}

int			main(void)
{
	int		n, m;
	int		x, y, i, j;
	int		sum;
	int		**more;
	int		**less;

	scanf("%d %d", &n, &m);
	getchar();
	//메모리 할당
	if (n == 1)
	{
		printf("0");
		return (0);
	}
	if (!(more = (int **)malloc(sizeof(int *) * n)))
		return (0);
	if (!(less = (int **)malloc(sizeof(int *) * n)))
		return (0);
	i = -1;
	while (++i < n)
	{
		if (!(more[i] = (int *)malloc(sizeof(int) * m)))
			return (0);
		if (!(less[i] = (int *)malloc(sizeof(int) * m)))
			return (0);
		j = -1;
		while (++j < m)
		{
			more[i][j] = 0;
			less[i][j] = 0;
		}
	}
	//배열 값 입력
	i = -1;
	while (++i < m)
	{
		scanf("%d %d", &x, &y);
		getchar();
		add_num(more[y - 1], x);
		add_num(less[x - 1], y);
	}
	//dfs
	printf("%d", count_node(more, less, n));
	//메모리 해제
	i = -1;
	while (++i < n)
	{
		free(more[i]);
		free(less[i]);
	}
	free(more);
	free(less);
	return (0);
}
