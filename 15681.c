#include <stdio.h>
#include <stdlib.h>

void	do_first(int *visited, int **arr, int n, int r, int a){
	int		i;

	printf("do_first = %d, %d\n", r, a);
	i = 0;
	while (arr[r][i]){
		if (arr[r][i] == a)
			return ;
		else if (visited[arr[r][i]] == 1){
			i++;
			continue ;
		}
		visited[arr[r][i]] = 1;
		do_first(visited, arr, n, arr[r][i], a);
		i++;
	}
}

int		dfs(int *visited, int **arr, int n, int r, int a){
	int		cnt = 1;
	int		i, re;

	if (a == r)
		return n;
	visited[a] = 1;
	i = 0;
	while (arr[a][i] != 0){
		if (visited[arr[a][i]] == 1){
			i++;
			continue ;
		}
		visited[arr[a][i]] = 1;
		re = dfs(visited, arr, n, r, arr[a][i]);
		printf("arr[%d][%d] = %d, re = %d\n", a, i, arr[a][i], re);
		if (re < n)
			cnt += re;
		i++;
	}
	return cnt;
}

int		main(void){
	int		n, r, q;
	int		a, b;
	int		i, j;
	int		**arr;
	int		*visited;

	scanf("%d %d %d", &n, &r, &q);
	getchar();
	visited = (int *)malloc(sizeof(int) * (n + 1));
	arr = (int **)malloc(sizeof(int *) * (n + 1));
	for (i = 0; i <= n; i++){
		arr[i] = (int *)malloc(sizeof(int) * (n + 1));
		for (j = 0; j <= n; j++)
			arr[i][j] = 0;
	}
	for (i = 0; i < n - 1; i++){
		scanf("%d %d", &a, &b);
		getchar();
		j = 0;
		while (arr[a][j])
			j++;
		arr[a][j] = b;
		j = 0;
		while (arr[b][j])
			j++;
		arr[b][j] = a;
	}
	for (i = 0; i < q; i++){
		scanf("%d", &a);
		getchar();
		if (a == r)
			printf("%d\n", n);
		else
		{
			for (j = 0; j <= n; j++)
				visited[j] = 0;
			do_first(visited, arr, n, r, a);
			printf("%d\n", dfs(visited, arr, n, r, a));
		}
	}
	for (i = 0; i <= n; i++)
		free(arr[i]);
	free(arr);
	free(visited);
	return 0;
}
