#include <iostream>

using namespace std;

int		main(void){
	string	r;
	string	c;
	int		map[1002][1002] = {0, };

	cin >> r >> c;
	for (int i = 1; i <= (int)r.size(); i++){
		for (int j = 1; j <= (int)c.size(); j++){
			//값이 같은 경우, 대각선 위의 값을 확인한다.
			if (r[i - 1] == c[j - 1])
				map[i][j] = map[i - 1][j - 1] + 1;
			//값이 다른 경우, 두 값 중 더 큰 값을 저장한다.
			else if (map[i][j - 1] > map[i - 1][j])
				map[i][j] = map[i][j - 1];
			else
				map[i][j] = map[i - 1][j];
		}
	}
	cout << map[r.size()][c.size()] << endl;
	return 0;
}
