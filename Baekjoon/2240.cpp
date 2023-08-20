//DP
#include <iostream>
using namespace std;

int		main(){
	int		t, w, n;
	int		dp[3][1001][32] = {0, };
	
	cin >> t >> w;
	//fill the square
	for (int i = 1; i <= t; i++){
		cin >> n;
		for (int j = 1; j <= w + 1; j++){
			if (n == 1){
				dp[1][i][j] = max(dp[1][i - 1][j], dp[2][i - 1][j - 1]) + 1;
				dp[2][i][j] = max(dp[1][i - 1][j - 1], dp[2][i - 1][j]);
			}
			else if (i != 1 || j != 1){
				dp[2][i][j] = max(dp[1][i - 1][j - 1], dp[2][i - 1][j]) + 1;
				dp[1][i][j] = max(dp[1][i - 1][j], dp[2][i - 1][j - 1]);
			}
		}
	}
	//find the max
	n = 0;
	int m = 0;
	for (int i = 1; i <= w + 1; i++){
		if (n < dp[1][t][i])
			n = dp[1][t][i];
		if (m < dp[2][t][i])
			m = dp[2][t][i];
	}
	cout << max(m, n) << endl;
	return 0;
}
