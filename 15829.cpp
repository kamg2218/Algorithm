//mod
#include <iostream>
#include <string>
using namespace std;

long	get_r(int n){
	long result;

	result = 1;
	for (int i = 0; i < n; i++){
		result *= 31;
		if (result > 1234567891)
			result %= 1234567891;
	}
	return result;
}

int		main(){
	long	n, tmp, result;
	string str;

	cin >> n >> str;
	result = 0;
	for (int i = 0; i < n; i++){
		tmp = str[i] - 'a' + 1;
		result += tmp * get_r(i);
		if (result >= 1234567891)
			result %= 1234567891;
	}
	cout << result << endl;
	return 0;
}
