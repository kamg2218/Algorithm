#include <iostream>
#include <vector>
using namespace std;

int		main(){
	int		n, m;
	vector<int>	v, tmp, result;

	cin >> n;
	tmp.assign(n, 0);
	result.assign(n, 0);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < i + 1; j++){
			cin >> m;
			v.push_back(m);
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j <= i; j++){
			if (j == 0)
				result[0] = tmp[0] + v[i * (i + 1) / 2 + j];
			else if (j == i)
				result[j] = tmp[j - 1] + v[i * (i + 1) / 2 + j];
			else
				result[j] = max(tmp[j - 1], tmp[j]) + v[i * (i + 1) / 2 + j];
		}
		tmp = result;
	}
	m = result[0];
	for (int i = 1; i < n; i++)
		m = max(m, result[i]);
	cout << m << endl;
	return 0;
}
