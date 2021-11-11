//DP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct info{
	//x, y, value
	int	x, y, z;
	//compare
	bool operator< (const info& i) const { return x < i.x; }
};

int		find_max(vector<info>& v, int n){
	vector<int>	DP(n);

	for (int i = 0; i < n; i++){
		//initialize
		DP[i] = v[i].z;
		//find max
		for (int j = 0; j < i; j++){
			//1, 3 location for ascending
			//2, 4 location for descending
			if (v[j].y < v[i].y)
				DP[i] = max(DP[i], DP[j] + v[i].z);
		}
	}
	//return max value
	return *max_element(DP.begin(), DP.end());
}

int		main(){
	int		n, result;
	info	tmp;
	vector<info>	v;

	//input
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> tmp.x >> tmp.y >> tmp.z;
		v.push_back(tmp);
	}
	//for ascending
	sort(v.begin(), v.end());
	result = find_max(v, n);
	//for descending
	sort(v.rbegin(), v.rend());
	result = max(result, find_max(v, n));
	//print max
	cout << result << endl;
	return 0;
}
