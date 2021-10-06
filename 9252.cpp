//LCS2
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int		main(){
	string	first, second;
	string	answer;
	vector<vector<string> >	LCS;

	//input two string
	cin >> first >> second;
	//result initialize
	answer = "";
	//LCS initialize
	LCS.assign(first.size() + 1, vector<string>(second.size() + 1, ""));
	//LCS row
	for (int i = 1; i <= first.size(); i++){
		//LCS column
		for (int j = 1; j <= second.size(); j++){
			//if the two character is same,
			if (first[i - 1] == second[j - 1]){
				LCS[i][j] = LCS[i - 1][j - 1] + first[i - 1];
				//if result is shorter than LCS,
				if (answer.size() < LCS[i][j].size())
					answer = LCS[i][j];
			}
			//if the two character is different,
			else{
				//find the longest string
				if (LCS[i - 1][j].size() > LCS[i][j - 1].size())
					LCS[i][j] = LCS[i - 1][j];
				else
					LCS[i][j] = LCS[i][j - 1];
			}
		}
	}
	//output result
	cout << answer.size() << endl << answer << endl;
	return 0;
}
