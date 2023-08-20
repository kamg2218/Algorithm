//vector, pair
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int		main(){
	int		t, n;
	int		a, b;
	int		cnt, num;
	vector<pair<int, int> > v;

	cin >> t;
	for (int i = 0; i < t; i++){
		cin >> n;
		v.clear();
		v.assign(n, pair<int, int>(0, 0));
		for (int j = 0; j < n; j++){
			cin >> a >> b;
			v[j] = pair<int, int>(a, b);
		}
		sort(v.begin(), v.end());
		cnt = n;
		num = v[0].second;
		for (int j = 1; j < n; j++){
			if (num < v[j].second)
				cnt--;
			else
				num = v[j].second;
		}
		cout << cnt << endl;
	}
	return 0;
}

/*
 * 시간초과
 cnt = n;
 for (int j = 1; j < n; j++){
 	for (int k = 0; k < j; k++){
		if (v[k].second < v[j].second){
			cnt--;
			break ;
		}
	}
 }
 */
