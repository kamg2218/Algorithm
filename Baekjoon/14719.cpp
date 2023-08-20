#include <iostream>
using namespace std;

int			main(){
	int		h, w;					//height, width
	int		height[501] = {0, };	//width에 따른 height 저장
	int		tmp = 0;				//빈 공간의 수
	int		count = 0;				//전체 공간의 수
	int		wall = 0;				//벽이 존재하는 지 유무

	cin >> h >> w;					//height, width 입력
	for (int i = 0; i < w; i++)		//height 값 저장
		cin >> height[i];
	for (int i = 0; i < h; i++){	//가로 우선 탐색
		wall = 0;
		tmp = 0;
		for (int j = 0; j < w; j++){
			//높이가 h 보다 높고, 벽이 없을 때 벽이 있음을 표시함
			if (height[j] >= i + 1 && wall == 0)
				wall = 1;
			//높이가 h보다 높고, 벽이 있는 경우
			//물이 받아지므로 tmp 값을 count에 더함
			else if (height[j] >= i + 1 && wall){
				count += tmp;
				tmp = 0;
			}
			//높이가 h보다 낮고, 벽이 있는 경우
			//빗물이 담기므로 tmp 증가
			else if (height[j] < i + 1 && wall == 1)
				tmp++;
		}
	}
	cout << count << endl;			//출력
	return 0;
}
