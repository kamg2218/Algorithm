#include <iostream>
#include <vector>
using namespace std;

int		main(){
	int		n, m, tmp;
	vector<int>	v;

	//cin >> n;
	scanf("%d", &n);
	getchar();
	v.assign(20000001, 0);
	for (int i = 0; i < n; i++){
		//cin >> tmp;
		scanf("%d", &tmp);
		getchar();
		v[tmp + 10000000] += 1;
	}
	//cin >> m;
	scanf("%d", &m);
	getchar();
	for (int i = 0; i < m; i++){
		//cin >> tmp;
		scanf("%d", &tmp);
		getchar();
		//cout << v[tmp + 10000000];
		printf("%d", v[tmp + 10000000]);
		if (i < m - 1)
			printf(" ");
			//cout << " ";
	}
	//cout << endl;
	printf("\n");
	return 0;
}
