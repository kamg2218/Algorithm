#include <iostream>
#include <vector>
using namespace std;

int				num[100001];
vector<int>		arr[100001];

int			dfs(vector<bool>& visited, int n){
	int		cnt = 1;
	int		i;

	if (num[n] != 0)
		return num[n];
	visited[n] = true;
	for (i = 0; i < arr[n].size(); i++){
		if (visited[arr[n][i]] == true)
			continue ;
		cnt += dfs(visited, arr[n][i]);
	}
	num[n] = cnt;
	return cnt;
}

int		main(void){
	int		n, r, q;
	int		a, b;
	int		i, j;
	vector<bool>	visited(1000001);

	scanf("%d %d %d", &n, &r, &q);
	getchar();
	for (i = 0; i < n - 1; i++){
		scanf("%d %d", &a, &b);
		getchar();
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	num[r] = dfs(visited, r);
	for (i = 0; i < q; i++){
		scanf("%d", &a);
		getchar();
		printf("%d\n", num[a]);
	}
	return 0;
}
