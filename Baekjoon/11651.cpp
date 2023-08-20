//mergesort
#include <iostream>
#include <vector>
using namespace std;

void	sort_v(vector<pair<int, int> >& v){
	int		pivot, i;
	vector<pair<int, int> >	a;
	vector<pair<int, int> >	b;

	if (v.size() <= 1)
		return ;
	pivot = v.size() - 1;
	for (i = 0; i < v.size() - 1; i++){
		if (v[i].second < v[pivot].second ||
				(v[i].second == v[pivot].second && v[i].first < v[pivot].first))
			a.push_back(v[i]);
		else
			b.push_back(v[i]);
	}
	sort_v(a);
	sort_v(b);
	for (i = 0; i < a.size(); i++)
		v[i] = a[i];
	v[i++] = v[pivot];
	for (; i < a.size() + b.size() + 1; i++)
		v[i] = b[i - a.size() - 1];
}

int		main(){
	int		n, x, y, j;
	vector<pair<int, int> >	v;

	//cin >> n;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++){
		//cin >> x >> y;
		scanf("%d %d", &x, &y);
		getchar();
		v.push_back(pair<int, int>(x, y));
	}
	sort_v(v);
	for (int i = 0; i < n; i++)
		printf("%d %d\n", v[i].first, v[i].second);
		//cout << v[i].first << " " << v[i].second << endl;
	return 0;
}
