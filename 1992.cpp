#include <iostream>
#include <vector>
#include <string>

using namespace std;

void	dfs(vector<int>& v, int x, int y, int n, int m);
int		check(vector<int>& v, int x, int y, int n, int m){
	int		num;

	num = v[x * n + y];
	for (int i = x; i < x + m; i++){
		for (int j = y; j < y + m; j++){
			if (v[i * n + j] != num)
				return 0;
		}
	}
	return 1;
}

void	do_it(vector<int>& v, int x, int y, int n, int m){
	if (check(v, x, y, n, m) == 0)
		dfs(v, x, y, n, m);
	else if (v[x * n + y] == 0)
		cout << "0";
	else
		cout << "1";
}

void	dfs(vector<int>& v, int x, int y, int n, int m){
	if (m == 1){
		do_it(v, x, y, n, m);
		return ;
	}
	else if (check(v, x, y, n, m) == 0){
		cout << "(";
		do_it(v, x, y, n, m / 2);
		do_it(v, x, y + m / 2, n, m / 2);
		do_it(v, x + m / 2, y, n, m / 2);
		do_it(v, x + m / 2, y + m / 2, n, m / 2);
		cout << ")";
	}
	else if (v[x * n + y] == 0)
		cout << "0";
	else
		cout << "1";
}

int		main(void){
	int				n;
	vector<int>		v;
	string			str;

	cin >> n;
	v.assign(n * n, 0);
	for (int i = 0; i < n; i++){
		cin >> str;
		for (int j = 0; j < n; j++){
			if (str[j] == '1')
				v[i * n + j] = 1;
		}
	}
	dfs(v, 0, 0, n, n);
	return 0;
}
