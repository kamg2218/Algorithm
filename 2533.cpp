//DFS + DP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>		tmp;
vector<vector<int> >	visited;

int		dfs(vector<vector<int> >& v, int num, int state){
	int	n;

	if (visited[num - 1][state] != -1)
		return visited[num - 1][state];
	//state == 1
	if (state){
		visited[num - 1][1] = 1;
		for (int i = 0; i < v[num - 1].size(); i++){
			n = v[num - 1][i];
			visited[num - 1][1] += min(dfs(v, n, 0), dfs(v, n, 1));
		}
	}
	//state == 0
	else{
		visited[num - 1][0] = 0;
		for (int i = 0; i < v[num - 1].size(); i++){
			n = v[num - 1][i];
			visited[num - 1][0] += dfs(v, n, 1);
		}
	}
	return visited[num - 1][state];
}

void	make_tree(vector<vector<int> >& v, vector<vector<int> >& tree, int n){
	//visited = 1
	tmp[n - 1] = 1;
	//dfs
	for (int i = 0; i < v[n - 1].size(); i++){
		//visited check
		if (tmp[v[n - 1][i] - 1] == 1)
			continue ;
		tree[n - 1].push_back(v[n - 1][i]);
		make_tree(v, tree, v[n - 1][i]);
	}
}

int		main(){
	int		n, a, b;
	vector<vector<int> >	v;
	vector<vector<int> >	tree;

	cin >> n;
	v.assign(n, vector<int>(0, 0));
	tree.assign(n, vector<int>(0, 0));
	//cin until EOF
	while (1){
		cin >> a >> b;
		v[a - 1].push_back(b);
		v[b - 1].push_back(a);
		if (cin.eof() == true)
			break ;
	}
	//visited for tree initialize
	tmp.assign(n, 0);
	make_tree(v, tree, 1);
	visited.assign(n + 1, vector<int>(2, -1));
	//dfs
	cout << min(dfs(tree, 1, 0), dfs(tree, 1, 1)) << endl;
	return 0;
}
