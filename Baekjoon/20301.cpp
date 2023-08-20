//요세푸스 - vector
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int   n, m, k, i, j;
	bool	dir;
	vector<int> v;
	vector<int>::iterator it;
	vector<int>::iterator tmp;

	//n, k 입력
	cin >> n >> k >> m;
	//vector 초기화
	for (i = 1; i <= n; i++)
		v.push_back(i);
	//it 초기화
	it = v.begin();
	for (i = 0; i < k - 1; i++)
		it++;
	//반복문 시작
	j = 0;
	dir = true;
	while (!(v.empty())){
		j++;
		if (j % m == 0)
			dir = !dir;
		//해당 값 출력
		cout << *it << endl;
		//삭제
		v.erase(it);
		if (dir && it == v.end())
			it = v.begin();
		else if (!dir && it == v.begin()){
			it = v.end();
			it--;
		}
		else if (!dir)
			it--;
		//값이 있는 경우
		if (!v.empty()){
			//위치 이동
			for (i = 0; i < k - 1; i++){
				if (dir){
					it++;
					if (it == v.end())
						it = v.begin();
				}
				else{
					if (it == v.begin())
						it = v.end();
					it--;
				}
			}
		}
	}
}
