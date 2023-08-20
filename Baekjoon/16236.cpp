//16236 bfs
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int		find_min(vector<int>& v, vector<int>& tmp, int n, int size){
	int		min;

	min = 0;
	for (int i = 0; i < n * n; i++){
		if (tmp[i] > 0 && v[i] < size && min == 0)
			min = tmp[i];
		else if (tmp[i] > 0 && v[i] < size && min > tmp[i])
			min = tmp[i];
	}
	return min;
}

//bfs
vector<int>		find_way(vector<int>& v, int n, int size, int shark){
	int			i;
	vector<int>	visited;
	deque<int>	tmp;

	visited.assign(n * n + 1, 0);
	tmp.push_back(shark);
	while (tmp.size()){
		i = tmp.front();
		tmp.pop_front();
		//up
		if (i - n >= 0 && visited[i - n] == 0 && v[i - n] <= size){
			visited[i - n] = visited[i] + 1;
			tmp.push_back(i - n);
		}
		//down
		if (i + n < n * n && visited[i + n] == 0 && v[i + n] <= size){
			visited[i + n] = visited[i] + 1;
			tmp.push_back(i + n);
		}
		//left
		if (i > 0 && (i - 1) % n < i % n && visited[i - 1] == 0 && v[i - 1] <= size){
			visited[i - 1] = visited[i] + 1;
			tmp.push_back(i - 1);
		}
		//right
		if ((i + 1) % n > i % n && visited[i + 1] == 0 && v[i + 1] <= size){
			visited[i + 1] = visited[i] + 1;
			tmp.push_back(i + 1);
		}
	}
	return visited;
}

int			eating(vector<int>& v, int n, int& shark, int& size, int& cnt){
	int				min;
	vector<int>		tmp;

	tmp.assign(n * n + 1, 0);
	tmp = find_way(v, n, size, shark);
	//arrange the bfs
	tmp[shark] = 0;
	for (int i = 0; i < n * n; i++){
		if (v[i] == 0 || v[i] >= size)
			tmp[i] = 0;
	}
	//find the min value in tmp
	min = find_min(v, tmp, n, size);
	if (min == 0){
		shark = -1;
		return 0;
	}
	//up > left
	for (int i = 0; i < n * n; i++){
		if (tmp[i] == min){
			v[i] = 0;
			shark = i;
			//the number of eaten fishes
			cnt += 1;
			if (cnt == size){
				cnt = 0;
				size += 1;
			}
			return min;
		}
	}
	return 0;
}

int		main(){
	int		n, m, shark, size, cnt;
	vector<int>	v;

	//input n size
	cin >> n;
	//initialize vector v
	v.assign(n * n + 1, 0);
	//input n * n array
	shark = -1;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> m;
			v[i * n + j] = m;
			//the shark location
			if (m == 9){
				shark = i * n + j;
				v[i * n + j] = 0;
			}
		}
	}
	if (shark == -1){
		cout << 0 << endl;
		return 0;
	}
	m = 0;
	cnt = 0;
	size = 2;
	//until the shark can move
	while (shark != -1)
		m += eating(v, n, shark, size, cnt);
	//ouput the result 
	cout << m << endl;
	return 0;
}
