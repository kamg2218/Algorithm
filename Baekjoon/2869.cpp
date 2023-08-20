//snail
#include <iostream>

using namespace std;

int		main(){
	int	a, b, v;
	int	cnt;

	cin >> a >> b >> v;
	//단계별 원리
	/*
	int	location = 0;
	cnt = 0;
	while (location < v){	//최종 목적지에 도달할 때 까지
		cnt++;				//이동 횟수
		location += a;		//하루에 이동하는 거리
		if (location < v)	//목적지에 도달하지 못한 경우
			location -= b;	//자는 동안 내려가는 거리
	}						//시간 초과
	*/
	cnt = (v - a) / (a - b);	//v = a + (a - b) * cnt
								//목적지 = 첫 날 + a, b 차이 * 이동한 날짜
	if ((v - a) % (a - b))		//나머지 값이 있는 경우,
		cnt++;					//하루 더 이동해야 하므로 cnt 1 증가

	cout << cnt + 1 << endl;	//cnt는 첫 날을 포함하지 않으므로 +1 출력
	return 0;
}
