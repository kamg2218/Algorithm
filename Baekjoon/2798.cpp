//quick sort - 2798
#include <iostream>
#include <vector>
using namespace std;

void	quick_sort(vector<int>& v, int begin, int end){
	int		pivot, tmp;

	if (begin >= end)
		return ;
	pivot = end;
	for (int i = begin; i < pivot; i++){
		if (v[i] > v[pivot]){
			tmp = v[i];
			for (int j = i; j < pivot; j++)
				v[j] = v[j + 1];
			v[pivot] = tmp;
			pivot -= 1;
			i--;
		}
	}
	quick_sort(v, begin, pivot - 1);
	quick_sort(v, pivot + 1, end);
}

int		find_sum(vector<int>& v, int n, int m){
	int		a, b, c;
	int		sum;

	sum = 0;
	for (int i = 0; i < n - 2; i++){
		for (int j = i + 1; j < n - 1; j++){
			for (int k = j + 1; k < n; k++){
				if (v[i] + v[j] + v[k] > m)
					continue ;
				else if (v[i] + v[j] + v[k] > sum)
					sum = v[i] + v[j] + v[k];
			}
		}
	}
	return sum;
}

int		main(){
	int		n, m, tmp;
	vector<int>	v;
	
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		cin >> tmp;
		v.push_back(tmp);
	}
	quick_sort(v, 0, n - 1);
	cout << find_sum(v, n, m) << endl;
	return 0;
}
