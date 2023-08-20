#include <iostream>
#include <cstdlib>

using namespace std;

int		main(){
	int		n, t, s;		//배열 개수, 케이스 개수, 배열 시작 위치
	string	p, x;			//수행할 함수, 숫자
	char	*end = NULL;	//strtod 함수의 매개변수
	bool	d;				//배열의 방향
	int		num[100001];	//숫자 저장 위치

	cin >> t;				//케이스 개수 입력
	for (int i = 0; i < t; i++){	//케이스 개수만큼 반복
		s = 0;						//배열 시작 위치 초기화
		cin >> p >> n >> x;			//함수, 배열 개수, 배열 입력
		end = &x[1];				//입력받은 숫자의 첫 위치
		d = true;					//배열의 방향 초기화
		for (int j = 0; j < n; j++){	//숫자 저장 함수
			num[j] = static_cast<int>(strtod(end, &end));
			end += 1;
		}
		//함수 수행
		for (int j = 0; j < static_cast<int>(p.size()); j++){
			if (p[j] == 'R')	//배열의 방향 변경
				d = !d;
			else{				//삭제 대신,
				--n;			//크기 줄이기
				if (n < 0){
					cout << "error\n";
					break ;
				}
				if (d == true)	//또는, 배열 시작 위치 뒤로 이동
					++s;
			}
		}
		if (n >= 0)
			cout << "[";
		if (d == true){			//순방향인 경우
			for (int j = s; j < s + n; j++){
				cout << num[j];
				if (j + 1 < s + n)
					cout << ",";
			}
		}
		else{					//역방향인 경우
			for (int j = s + n - 1; j >= s; j--){
				cout << num[j];
				if (j - 1 >= s)
					cout << ",";
			}
		}
		if (n >= 0)
			cout << "]\n";
	}
	return 0;
}
