#include <iostream>

using namespace std;

int		check(string s, int n, int start){
	int		cnt;

	cnt = 0;
	for (int i = start + 1; i < s.size() - 1; i++){
		if (s[i] == 'O' && s[i + 1] == 'I'){
			i++;
			cnt++;
		}
		else
			return cnt;
	}
	return cnt;
}

int		main(){
	int	n, m;
	int	cnt;
	int	tmp;
	string	s;

	cin >> n >> m >> s;
	cnt = 0;
	for (int i = 0; i < m - 2 * n; i++){
		if (s[i] == 'O')
			continue;
		tmp = check(s, n, i);
		if (tmp >= n)
			cnt += tmp - n + 1;
		i += tmp * 2;
	}
	cout << cnt << endl;
	return 0;
}
