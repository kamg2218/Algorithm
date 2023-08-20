#include <iostream>
#include <vector>
using namespace std;

//bfs
void		normal(vector<char>& v, int n, int x, int y, char c){
	int		cnt;
	char	ch;

	if (x < 0 || x >= n || y < 0 || y >= n)
		return ;
	ch = v[x * n + y];
	v[x * n + y] = c;
	if (x > 0 && v[(x - 1) * n + y] == ch)
		normal(v, n, x - 1, y, c);
	if (x < n - 1 && v[(x + 1) * n + y] == ch)
		normal(v, n, x + 1, y, c);
	if (y > 0 && v[x * n + y - 1] == ch)
		normal(v, n, x, y - 1, c);
	if (y < n - 1 && v[x * n + y + 1] == ch)
		normal(v, n, x, y + 1, c);
}
//bfs
int			check(vector<char>& v, int n, int x, int y){
	char	a, b;

	a = b = '1';
	if (v[x * n + y] == '3')
		return 0;
	else if (v[x * n + y] == '1')
		b = '2';
	else if (v[x * n + y] == '2')
		a = '2';
	if (x > 0 && v[(x - 1) * n + y] == b){
		normal(v, n, x - 1, y, a);
		return 1;
	}
	if (x < n - 1 && v[(x + 1) * n + y] == b){
		normal(v, n, x + 1, y, a);
		return 1;
	}
	if (y > 0 && v[x * n + y - 1] == b){
		normal(v, n, x, y - 1, a);
		return 1;
	}
	if (y < n - 1 && v[x * n + y + 1] == b){
		normal(v, n, x, y + 1, a);
		return 1;
	}
	return 0;
}

int		turn_into(vector<char>& v, int n, char* a, char* b){
	int		cnt;

	cnt = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (v[i * n + j] == a[0])
				normal(v, n, i, j, b[0]);
			else if (v[i * n + j] == a[1])
				normal(v, n, i, j, b[1]);
			else if (v[i * n + j] == a[2])
				normal(v, n, i, j, b[2]);
			else
				cnt--;
			cnt++;
		}
	}
	return cnt;
}

int		main(void){
	int				n;
	vector<char>	v;
	char			a[3] = {'R', 'G', 'B'};
	char			b[3] = {'1', '2', '3'};

	cin >> n;
	v.assign(n * n, 0);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			cin >> v[i * n + j];
	}
	cout << turn_into(v, n, a, b) << " ";
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			check(v, n, i, j);
	}
	cout << turn_into(v, n, b, a) << endl;
	return 0;
}
