//완전 탐색 - 시간 초과
#include <iostream>
#include <vector>

using namespace std;

int		getDepth(vector<int>& v_d, vector<int>& v_n, int d, int n){
	int		i, j, k;
	int		last;

	last = d;
	for (i = 0; i < n; i++){
		//피자를 넣을 수 있는 오븐의 깊이까지
		//반복하며 피자를 넣는다.
		for (j = 0; j < last; j++){
			//오븐의 지름보다 피자의 지름이 큰 경우
			if (v_d[j] < v_n[i]){
				last = j - 1;
				break ;
			}
			//오븐의 제일 안 쪽에 피자를 넣을 수 있는 경우
			else if (j == last - 1)
				last -= 1;
		}
		//오븐에 더이상 피자를 넣을 수 없는 경우
		if (last < 0)
			break ;
	}
	//index는 1부터 시작하므로 1을 더한다.
	return last + 1;
}

int		main(void){
	int		d, n, i, j;
	vector<int>	v_d, v_n;

	cin >> d >> n;
	//oven
	for (i = 0; i < d; i++){
		cin >> j;
		v_d.push_back(j);
	}
	//pizza
	for (i = 0; i < n; i++){
		cin >> j;
		v_n.push_back(j);
	}
	//get the depth
	cout << getDepth(v_d, v_n, d, n) << endl;
	return 0;
}
