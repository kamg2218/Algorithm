//DP
#include <iostream>
#include <vector>

using namespace std;

int		main(){
	int		num;
	string	str;
	vector<int>	v;

	cin >> str;
	v.assign(str.size() + 1, 0);
	if (str.size() == 1 && str[0] == '0'){
		cout << 0 << endl;
		return 0;
	}
	v[0] = 1;
	for (int i = 1; i <= str.size(); i++){
		num = (int)str[i - 1] - (int)'0';
		if (num > 0 && num < 10){
			v[i] = (v[i - 1] + v[i]) % 1000000;
		}
		if (i > 1){
			num = ((int)str[i - 2] - (int)'0') * 10 + (int)str[i - 1] - (int)'0';
			if (num > 9 && num < 27)
				v[i] = (v[i - 2] + v[i]) % 1000000;
		}
	}
	cout << v[str.size()] << endl;
	return 0;
}
