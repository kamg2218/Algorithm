#include <iostream>
#include <vector>

using namespace std;

int		count(int small, int big){
	int				i;
	vector<int>		v;

	i = small;
	while (i > 0){
		v.push_back(i);
		i /= 2;
	}
	while (big > small)
		big /= 2;
	i = 0;
	while (big > 0){
		while (big < v[i])
			i++;
		if (big == v[i])
			return big;
		big /= 2;
	}
	return 1;
}

int		main(){
	int		n;
	int		a, b;

	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++){
		cin >> a >> b;
		scanf("%d %d", &a, &b);
		getchar();
		printf("%d\n", count(min(a, b), max(a, b)) * 10);
	}
	return 0;
}
