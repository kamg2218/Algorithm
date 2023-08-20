//시간초과 - vector
#include <iostream>
#include <vector>
using namespace std;

int		check_tomato(int num, int a, int b, int n, int m, vector<int> &v){
	if (a > 0 && v[(a - 1) * n + b] == num)
		return 1;
	else if (a + 1 < m && v[(a + 1) * n + b] == num)
		return 1;
	else if (b > 0 && v[a * n + b - 1] == num)
		return 1;
	else if (b + 1 < n && v[a * n + b + 1] == num)
		return 1;
	return 0;
}

bool	check_map(int n, int m, vector<int> &v){
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (v[i * n + j] == 0)
				return false;
		}
	}
	return true;
}

int		cook_tomato(int num, int n, int m, vector<int> &v){
	int		cnt = 0;

	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (v[i * n + j] == 0 && check_tomato(num, i, j, n, m, v)){
				cnt++;
				v[i * n + j] = num + 1;
			}
		}
	}
	return cnt;
}

int		tomato(int n, int m, vector<int> &v){
	int		i = 1;

	while (cook_tomato(i, n, m, v))
		i++;
	if (check_map(n, m, v))
		return i - 1;
	return -1;
}

int		main(){
	int	n, m;
	vector<int>	v;

	cin >> n >> m;
	v.reserve(n * m);
	for (int i = 0; i < m; i++){		//col
		for (int j = 0; j < n; j++)		//row
			cin >> v[i * n + j];
	}
	cout << tomato(n, m, v) << endl;
	return 0;
}
