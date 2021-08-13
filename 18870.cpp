#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int		main(void){
	int		n, m;
	vector<int>	v;
	vector<int>	origin;

	cin >> n;
	for (vector<int>::size_type i = 0; i < n; i++){
		cin >> m;
		origin.push_back(m);
		v.push_back(m);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (vector<int>::size_type	i = 0; i < n; i++){
		cout << lower_bound(v.begin(), v.end(), origin[i]) - v.begin();
		if (i + 1 < n)
			cout << " ";
	}
	return 0;
}
