#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <utility>
using namespace	std;

int		main(){
	int	n;
	int	a, b;
	int	now, next;
	string	way;
	queue<pair<int, string> >	q;
	vector<bool>	v(10000, 0);

	cin >> n;
	for (int i = 0; i < n; i++){
		v.clear();
		v.resize(10000);
		while (!q.empty())
			q.pop();
		cin >> a >> b;
		v[a] = true;
		q.push(make_pair<int, string>(a, ""));
		while (!q.empty()){
			now = q.front().first;
			way = q.front().second;
			q.pop();
			if (now == b){
				cout << way << endl;
				break ;
			}
			else{
				next = (now * 2) % 10000;
				if (v[next] == false){
					v[next] = true;
					q.push(make_pair<int, string>(next, way + "D"));
				}
				if (now == 0)
					next = 9999;
				else
					next = now - 1;
				if (v[next] == false){
					v[next] = true;
					q.push(make_pair<int, string>(next, way + "S"));
				}
				if (now != 0){
					next = (now % 1000) * 10 + now / 1000;
					if (v[next] == false){
						v[next] = true;
						q.push(make_pair<int, string>(next, way + "L"));
					}
					next = now / 10 + (now % 10) * 1000;
					if (v[next] == false){
						v[next] = true;
						q.push(make_pair<int, string>(next, way + "R"));
					}
				}
			}
		}
	}
	return 0;
}
