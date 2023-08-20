//완전탐색 - 시간초과
#include <iostream>
#include <cctype>
#include <vector>
using namespace std;

int		main(){
	int		i, j, k, n, m;
	int		cnt, zero;
	string	str;
	vector<int>	v;

	cin >> str;
	cnt = 0;
	zero = 0;
	if (str.size() == 0 || str[0] == '0'){
		cout << 0 << endl;
		return 0;
	}
	for (i = 0; i < str.size(); i++){
		if (str[i] == '0')
			zero = 1;
		else if (!isdigit(str[i])){
			cout << 0 << endl;
			return 0;
		}
	}
	if (!zero)
		cnt++;
	for (i = 1; i <= str.size() / 2; i++){
		v.assign(i, 0);
		for (j = 0; j < i; j++)
			v[j] = j * 2;
		n = i - 1;
		while (n >= 0){
			//cout << "v = ";
			//for (m = 0; m < v.size(); m++)
			//	cout << v[m] << " ";
			//cout << endl;
			for (k = 0; k < i; k++){
				if (k + 1 >= str.size() || v[k] == '0')
					break ;
				zero = ((int)str[v[k]] - (int)'0') * 10 + ((int)str[v[k] + 1] - (int)'0');
				//cout << "zero = " << zero << endl;
				if (zero > 26 || zero < 10)
					break ;
				m = 0;
				if (k > 0)
					m = v[k - 1] + 2;
				//cout << "m = " << m << endl;
				for (zero = m; zero < v[k]; zero++){
					if (str[zero] == '0')
						break ;
				}
				if (zero != v[k])
					break ;
			}
			if (k == i){
				//cout << "m = " << m << endl;
				for (zero = v[k - 1] + 2; zero < str.size(); zero++){
				//	cout << "z = " << zero << endl;
					if (str[zero] == '0')
						break ;
				}
				if (zero == str.size()){
					cnt++;
					if (cnt > 1000000)
						cnt = cnt % 1000000;
				}

				//cout << "i = " << i << " k = " << k << ", v = ";
				//for (m = 0; m < v.size(); m++)
				//	cout << v[m] << " ";
				//cout << endl;
			}
			while (n >= 0){
				v[n] += 1;
				if (v[n] >= str.size() - 1)
					n--;
				else{
					for (k = n + 1; k < v.size(); k++)
						v[k] = v[k - 1] + 2;
					if (v[k - 1] >= str.size() - 1)
						n--;
					else
						break ;
				}
			}
			//cout << "i = " << i << " k = " << k << endl;
			//for (k = 0; k < v.size(); k++)
			//	cout << v[k] << " ";
			//cout << endl;
		}
	}
	cout << cnt << endl;
	return 0;
}
