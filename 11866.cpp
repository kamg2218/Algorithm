//요세푸스 - vector
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int   n, k, i;
	vector<int> v;
	vector<int>::iterator it;
	vector<int>::iterator tmp;

	//n, k 입력
	cin >> n >> k;
	//vector 초기화
	for (i = 1; i <= n; i++)
		v.push_back(i);
	//it 초기화
	it = v.begin();
	for (i = 0; i < k - 1; i++)
		it++;
	//반복문 시작
	cout << "<";
	while (!(v.empty())){
		//해당 값 출력
		cout << *it;
		//삭제
		v.erase(it);
		if (it == v.end())
			it = v.begin();
		//값이 있는 경우
		if (!v.empty()){
			cout << ", ";
			//위치 이동
			for (i = 0; i < k - 1; i++){
				it++;
				if (it == v.end())
					it = v.begin();
			}
		}
	}
	cout << '>' << endl;
}
