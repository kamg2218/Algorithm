#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void	make_order(vector<int>&	order, int l, int c, int n){
	if (n < 0){
		order[0] += 1;
		return ;
	}
	else if (order[n] < c - 1)
		order[n] += 1;
	else
		make_order(order, l, c, n - 1);
	for (int i = n + 1; i < l; i++)
		order[i] = order[i - 1] + 1;
	if (order[l - 1] >= c)
		make_order(order, l, c, n - 1);
}

int		main(){
	int		l, c;
	vector<char>	v;
	vector<int>	order;
	string		str;
	int			cnt;

	cin >> l >> c;
	v.assign(c, 0);
	order.assign(l, 0);
	for (int i = 0; i < c; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	for (int i = 0; i < l; i++)
		order[i] = i;
	while (order[0] <= c - l){
		str = "";
		cnt = 0;
		for (int i = 0; i < l; i++)
			str += v[order[i]];
		for (int i = 0; i < l; i++){
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i'
					|| str[i] == 'o' || str[i] == 'u')
				cnt++;
		}
		if (cnt > 0 && str.size() - cnt > 1)
			cout << str << endl;
		make_order(order, l, c, l - 1);
	}
	return 0;
}
