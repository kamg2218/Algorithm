//binary search
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int		find_num(vector<int>& v, int num){
	int		start, end, tmp;

	start = 0;
	end = v.size() - 1;
	while (start <= end){
		tmp = (start + end) / 2;
		if (v[tmp] == num)
			return 1;
		else if (v[tmp] < num)
			start = tmp + 1;
		else if (v[tmp] > num)
			end = tmp - 1;
	}
	return 0;
}

int		main(){
	vector<int>	v;
	int		n, m, k;

	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> k;
		v.push_back(k);
	}
	sort(v.begin(), v.end());
	cin >> m;
	for (int i = 0; i < m; i++){
		cin >> k;
		cout << find_num(v, k) << endl;
	}
	return 0;
}
