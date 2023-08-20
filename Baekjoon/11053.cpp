//11053 Dynamic Programming
#include <iostream>
#include <vector>

using namespace std;

int		main(void){
	int		n, m;
	vector<int>	v, cnt;

	//숫자의 개수
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> m;
		//v 벡터에 저장
		v.push_back(m);
		//cnt 초기화
		//cnt 에 자기 자신보다 작거나 같은 수의 개수를 저장함
		cnt.push_back(1);
	}

	for (int i = 1; i < n; i++){
		//자신보다 작은 수에 저장된 cnt 값의 최대값을 더함
		m = 0;
		for (int j = i - 1; j >= 0; j--){
			if (v[j] < v[i] && m < cnt[j]){
				m = cnt[j];
			}
		}
		cnt[i] += m;
	}
	//cnt 값들 중 최대 값을 찾아 출력함
	m = 1;
	for (int i = 0; i < n; i++){
		if (m < cnt[i])
			m = cnt[i];
	}
	cout << m << endl;
	return 0;
}
