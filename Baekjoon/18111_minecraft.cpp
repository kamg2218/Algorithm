#include <iostream>

using namespace std;

int		n, m, b;
int		map[501][501] = {0, };

int		find_max(){
	int		max = 0;

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (map[i][j] > max)
				max = map[i][j];
		}
	}
	return max;
}

int		check(int height){
	int	time = 0;
	int	block = b;

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (map[i][j] > height){
				time += (map[i][j] - height) * 2;
				block += map[i][j] - height;
			}else if (map[i][j] < height){
				time += height - map[i][j];
				block -= height - map[i][j];
			}
		}
	}
	if (block < 0)
		return -1;
	return time;
}

int		main(){
	int		max, height, time, tmp;
	//input
	cin >> n >> m >> b;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	}
	max = find_max() + 1;
	time = 1000000000;
	height = 0;
	while (--max >= 0){
		tmp = check(max);
		if (tmp != -1 && tmp < time){
			time = tmp;
			height = max;
		}
	}
	cout << time << " " << height << endl;
	return 0;
}
