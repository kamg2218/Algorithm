//brute force
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int		find_num(vector<int>& v, int n){
	int		tmp;

	tmp = n;
	if (tmp == 0 && !v[tmp])
		return 0;
	while (tmp > 0){
		if (v[tmp % 10]){
			tmp /= 10;
			continue ;
		}
		return 0;
	}
	return 1;
}

int		main(){
	int		n, m, tmp, result;
	vector<int>		v(10, 1);

	cin >> n >> m;
	for (int i = 0; i < m; i++){
		cin >> tmp;
		v[tmp] = 0;
	}
	result = abs(n - 100);
	for (int i = 0; i <= 1000000; i++){
		if (find_num(v, i)){
			tmp = abs(n - i) + to_string(i).size();
			result = min(result, tmp);
		}
	}
	cout << result << endl;
	return 0;
}
