#include <iostream>
#include <string>
using namespace std;

bool	check_tmp(string& tmp){
	int	cnt;

	cnt = 0;
	for (int i = 0; i < tmp.size(); i++){
		if (tmp[i] == '(')
			cnt++;
		else
			cnt--;
		if (cnt < 0)
			return false;
	}
	if (cnt == 0)
		return true;
	return false;
}

int		main(){
	int		n;
	string	tmp;

	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> tmp;
		if (check_tmp(tmp))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
