#include <iostream>
using namespace std;

int		main(){
	int	n, m;
	int	cnt;
	int	tmp;
	string	s;

	cin >> n >> m >> s;
	cnt = 0;
	tmp = 0;
	for (int i = 0; i < m - 2; i++){
		if (s[i] == 'O')
			continue;
		else if (s[i + 1] == 'O' && s[i + 2] == 'I'){
			tmp += 1;
			if (tmp == n){
				cnt += 1;
				tmp -= 1;
			}
			i++;
		}
		else
			tmp = 0;
	}
	cout << cnt << endl;
	return 0;
}
