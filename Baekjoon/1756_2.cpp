//이분 탐색
#include <iostream>
#include <vector>

using namespace std;

int		find_space(vector<int>& arrange, int last, int num){
	int start, end, tmp;

	start = 0;
	end = last - 1;
	//오븐의 가장 안 쪽에 넣을 수 있는 경우
	if (last > 0 && arrange[last - 1] >= num)
		return last - 1;
	//오븐의 가장 바깥쪽에 넣을 수 없는 경우
	else if (arrange[0] < num)
		return -1;
	//이분 탐색
	tmp = end;
	while (start <= end){
		if (arrange[(start + end) / 2] < num)
			end = (start + end) / 2 - 1;
		else{
			tmp = (start + end) / 2;
			start = (start + end) / 2 + 1;
		}
	}
	//같은 값을 가진 위치 중 가장 안 쪽으로 이동
	while (tmp >= 0 && tmp < last && arrange[tmp] == arrange[tmp + 1])
		tmp++;
	return tmp;
}

int		main(void){
	int		d, n, i, j, tmp, last;
	vector<int>	arrange;

	cin >> d >> n;
	//오븐 지름 입력
	for (i = 0; i < d; i++){
		cin >> j;
		//해당 깊이에 넣을 수 있는 최대 피자의 지름을 저장
		if (i == 0 || j <= tmp){
			tmp = j;
			arrange.push_back(j);
		}
		else
			arrange.push_back(tmp);
	}
	//피자 지름 입력
	last = d;
	for (i = 0; i < n; i++){
		cin >> j;
		//피자를 오븐에 넣은 후
		//오븐에 피자를 넣을 수 있는 마지막 위치
		last = find_space(arrange, last, j);
		if (last < 0)
			break ;
	}
	//피자를 모두 넣지 못하는 경우
	if (last < 0)
		cout << '0' << endl;
	//피자를 모두 넣은 경우
	else
		cout << last + 1 << endl;
	return 0;
}
