//dp
#include <iostream>
#include <vector>
using namespace std;

int		main(){
	int		n, m, k;
	vector<int>	v;

	cin >> n;
	v.push_back(0);
	m = 1;
	while (m <= n){
		//initialize
		v.push_back(m);
		//dp[m] = dp[m - k^2] + 1
		k = 1;
		while (k * k <= m){
			if (v[m - k * k] + 1 < v[m])
				v[m] = v[m - k * k] + 1;
			k++;
		}
		m++;
	}
	cout << v[n] << endl;
	return 0;
}
