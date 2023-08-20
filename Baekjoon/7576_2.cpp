//7576 tomato - vector
#include <iostream>
#include <vector>
using namespace std;

bool	check_map(int n, int m, vector<int> &v){
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (v[i * n + j] == 0)
				return false;
		}
	}
	return true;
}

vector<int>	cook_tomato(int n, int m, vector<int> &v, vector<int> &apple){
	int		s, a, b;
	vector<int>	tmp;

	s = apple.size();
	for (int i = 0; i < s; i++){
		a = apple[i] / n;
		b = apple[i] % n;
		if (a > 0 && v[(a - 1) * n + b] == 0){
			v[(a - 1) * n + b] = 1;
			tmp.push_back((a - 1) * n + b);
		}
		if (a + 1 < m && v[(a + 1) * n + b] == 0){
			v[(a + 1) * n + b] = 1;
			tmp.push_back((a + 1) * n + b);
		}
		if (b > 0 && v[a * n + b - 1] == 0){
			v[a * n + b - 1] = 1;
			tmp.push_back(a * n + b - 1);
		}
		if (b + 1 < n && v[a * n + b + 1] == 0){
			v[a * n + b + 1] = 1;
			tmp.push_back(a * n + b + 1);
		}
	}
	return tmp;
}

int		tomato(int n, int m, vector<int> &v, vector<int> &apple){
	int		i = 0;
	vector<int>	tmp;

	tmp = apple;
	while (tmp.size() > 0){
		tmp = cook_tomato(n, m, v, tmp);
		i++;
	}
	if (check_map(n, m, v))
		return i - 1;
	return -1;
}

int		main(){
	int	n, m;
	vector<int>	v;
	vector<int>	apple;

	cin >> n >> m;
	v.reserve(n * m);
	for (int i = 0; i < m; i++){		//col
		for (int j = 0; j < n; j++){		//row
			cin >> v[i * n + j];
			if (v[i * n + j] == 1)
				apple.push_back(i * n + j);
		}
	}
	cout << tomato(n, m, v, apple) << endl;
	return 0;
}
