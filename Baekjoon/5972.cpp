#include <iostream>

using namespace std;

int		graph[50001][50001];
int		visited[50001];

void	clearVisited(int n){
	for (int i = 0; i <= n; i++)
			visited[i] = 0;
}

void	clearGraph(int n){
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			graph[i][j] = -1;
}

int		findCost(int start, int end){
	int	result;
	int	min;

	//cout << "start = " << start << ", end = " << end << endl;
	if (start == end)
		return -1;
	result = 0;
	min = -1;
	for (int i = 1; i <= end; i++){
		if (start == i)
			continue ;
		if (visited[i] != 1 && graph[start][i] != -1){
			visited[start] = 1;
			result = findCost(i, end);
			if (min == -1 && result < 0)
				min = graph[start][i];
			else if (min == -1 || (result >= 0 && result + graph[start][i] < min))
				min = result + graph[start][i];
			visited[start] = 0;
		}
	}
	//cout << "min = " << min << endl;
	return min;
}

int		main(){
	int	n, m;
	int	a, b, c;

	cin >> n >> m;
	clearGraph(n);
	for (int i = 0; i < m; i++){
		cin >> a >> b >> c;
		graph[a][b] = c;
		graph[b][a] = c;
	}
	clearVisited(n);
	visited[1] = 1;
	cout << findCost(1, n) << endl;
	return 0;
}
