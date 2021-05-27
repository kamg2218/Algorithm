#include <iostream>
#include <cmath>

using namespace std;

int		fee[5][2] = {{0, 1}, {100, 2}, {10000, 3}, {1000000, 5}, {1000000, 7}};

int		feeTousage(int num){
	int		result = 0;
	int		i;

	for (i = 1; i < 4; i++){
		if ((fee[i][0] - fee[i - 1][0]) * fee[i][1] > num)
			break ;
		num -= (fee[i][0] - fee[i - 1][0]) * fee[i][1];
		result += fee[i][0] - fee[i - 1][0];
	}
	result += num / fee[i][1];
	return result;
}

int		usageTofee(int num){
	int		result = 0;
	int		i;

	for (i = 1; i < 4; i++){
		if (num <= fee[i][0])
			break ;
		result += (fee[i][0] - fee[i - 1][0]) * fee[i][1];
	}
	result += (num - fee[i - 1][0]) * fee[i][1];
	return result;
}

int		main(){
	int		a, b;
	int		x, y;
	int		c, d, e, l, r;

	while (1){
		cin >> a >> b;
		//종료 조건
		if (a == 0 && b == 0)
			break ;
		x = feeTousage(a);	//총 사용량
		y = x / 2;	//상근이가 사용한 양
		r = x / 2;	//max
		l = 0;		//min
		d = usageTofee(x - y);
		c = usageTofee(y);
		//이분 탐색
		while (l <= r && d - c != b){
			e = abs(r - l) / 2;
			if (e == 0)
				e = 1;
			//차이가 목표 값보다 작은 경우
			if (d - c < b){
				r = y;
				y -= e;
			}
			//차이가 목표 값보다 큰 경우
			else{
				l = y;
				y += e;
			}
			//요금 계산
			d = usageTofee(x - y);
			c = usageTofee(y);
		}
		//결과 출력
		cout << c << endl;
	}
	return 0;
}
