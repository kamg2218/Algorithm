#include <iostream>
#include <vector>

using namespace std;
//아두이노 이동방향
int		dir[9][2] = {{1, -1}, {1, 0}, {1, 1}, {0, -1}, {0, 0}, {0, 1}, {-1, -1}, {-1, 0}, {-1, 1}};
//출력할 맵
char	map[101][101] = {0, };
//출력 함수
void	print(int r, int c, int location, vector<int> v){
	//'.'으로 초기화
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++)
			map[i][j] = '.';
	}
	//맵에 아두이노 저장
	for (int i = 0; i < v.size(); i++)
		map[v[i] / c][v[i] % c] = 'R';
	//맵에 종수 위치 저장
	map[location / c][location % c] = 'I';
	//맵 출력
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++)
			cout << map[i][j];
		cout << endl;
	}
}
//아두이노 이동시키는 함수
int		move_arduino(int r, int c, int location, vector<int>& v){
	int	k, l;		//이동할 위치
	int	tmp;		//저장 할 아두이노 표시
	vector<int>	n;	//새로운 벡터에 아두이노 위치 저장

	//종수의 위치와 가까워지도록 이동
	for (int i = 0; i < v.size(); i++){
		k = v[i] / c;
		l = v[i] % c;
		if (location / c - k < 0)
			k -= 1;
		else if (location / c - k > 0)
			k += 1;
		if (location % c - l < 0)
			l -= 1;
		else if (location % c - l > 0)
			l += 1;
		v[i] = k * c + l;
		//이동한 위치가 종수의 위치인 경우, 종료
		if (location == k * c + l)
			return 1;
	}
	//같은 위치에 있는 아두이노 확인
	for (int i = 0; i < v.size(); i++){
		tmp = 0;
		for (int j = 0; j < v.size(); j++){
			//같은 위치에 있는 경우, tmp = 1
			if (i != j && v[i] == v[j]){
				tmp = 1;
				break ;
			}
		}
		//중복되는 아두이노가 없는 경우,
		//새로운 벡터에 저장
		if (!tmp)
			n.push_back(v[i]);
	}
	//새로운 벡터로 값 바꾸기
	v = n;
	return 0;
}

int		main(void){
	int				r, c;				//행, 열
	int				location;			//종수 위치
	int				turn = 0;			//이동 횟수
	char			tmp;				//입력 받는 값 임시저장
	char			cmd[101] = {0, };	//명령어 저장
	vector<int>		v;					//아두이노 위치 저장

	//행, 열 저장
	cin >> r >> c;
	//맵 값 저장
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			cin >> tmp;
			//아두이노 v 벡터에 저장
			if (tmp == 'R')
				v.push_back(i * c + j);
			//종수 위치 저장
			else if (tmp == 'I')
				location = i * c + j;
		}
	}
	//명령어 입력
	cin >> cmd;
	//명령어 수행
	while (cmd[turn]){
		//종수 위치 이동
		location = (location / c + dir[(int)cmd[turn] - (int)'1'][0]) * c + (location % c + dir[(int)cmd[turn] - (int)'1'][1]);
		//이동 횟수 추가
		turn++;
		//종수의 위치에 아두이노가 있는 경우, 종료
		for (int i = 0; i < v.size(); i++){
			if (location == v[i]){
				cout << "kraj " << turn << endl;
				return 0;
			}
		}
		//아두이노 움직이기
		if (move_arduino(r, c, location, v) > 0){
			cout << "kraj " << turn << endl;
			return 0;
		}
	}
	//맵 출력
	print(r, c, location, v);
	return 0;
}
