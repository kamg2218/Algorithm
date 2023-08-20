//19942 - 완전탐색
#include <iostream>
#include <vector>
using namespace std;

//check cost and compare with previous result
void	check_value(vector<vector<int> >&table, vector<int>& goal, int n, vector<int>& result, vector<int>& tmp){
	int		value;

	//check sum of each ingredients and compare with goal
	for (int i = 0; i < 4; i++){
		value = 0;
		for (int j = 0; j < tmp.size(); j++)
			value += table[tmp[j]][i];
		if (value < goal[i])
			return ;
	}
	//calculate the cost of tmp
	value = 0;
	for (int i = 0; i < tmp.size(); i++)
		value += table[tmp[i]][4];
	//if the cost is lower than previous result,
	//or result is empty
	//change the result
	if (!result.size() || value <= result.back()){
		//if the cost is same with previous result,
		//check the priority
		if (result.size() && value == result.back()){
			for (int j = 0; j < tmp.size(); j++){
				if (result[j] == tmp[j])
					continue ;
				else if (result[j] < tmp[j])
					return ;
				else {
					result = tmp;
					result.push_back(value);
				}
			}
		}
		//if the result is empty,
		//or the cost is lower than before
		else {
			result = tmp;
			result.push_back(value);
		}
	}
}

//move tmp locations to next
int		move_next(vector<int>& tmp, int n){
	int		location;

	//until location is over -1,
	//check tmp number and move next
	location = tmp.size() - 1;
	while (location >= 0){
		//move next
		if (tmp[location] < n - 1
				&& tmp[location] < n - tmp.size() + location){
			tmp[location] += 1;
			break ;
		}
		//move the location to front
		else
			location -= 1;
	}
	//if location is changed, arrange the next values
	if (location >= 0){
		for (int i = location + 1; i < tmp.size(); i++)
			tmp[i] = tmp[i - 1] + 1;
		//this means possible
		return 0;
	}
	//this means impossible
	return 1;
}

//To find the min cost
void	find_min(vector<vector<int> >& table, vector<int>& goal, int n){
	vector<int>	result;
	vector<int>	tmp;

	for (int i = 1; i <= n; i++){
		//initialize tmp values
		//this variable means location
		for (int j = 0; j < i; j++)
			tmp.push_back(j);
		//until the location is possible
		while (1){
			//find the cost with tmp
			check_value(table, goal, n, result, tmp);
			//move tmp to the next
			if (move_next(tmp, n))
				break ;
		}
		tmp.clear();
	}
	//if the result is empty, it means impossible
	if (result.size() == 0){
		cout << -1 << endl;
		return ;
	}
	//if it's possible, print the cost, first
	cout << result.back() << endl;
	//print the location, to the second line
	for (int i = 0; i < result.size() - 1; i++){
		cout << result[i] + 1;
		if (i + 1 < result.size() - 1)
			cout << " ";
	}
	cout << endl;
}

int		main(){
	int		n, m;
	vector<int>		goal;
	vector<vector<int> >	table;

	//input size n
	cin >> n;
	//initialize goal and table to 0.
	goal.assign(4, 0);
	table.assign(n, vector<int>(5, 0));
	//input goal
	for (int i = 0; i < 4; i++){
		cin >> m;
		goal[i] = m;
	}
	//input table
	for (int i = 0; i < n; i++){
		for (int j = 0; j < 5; j++){
			cin >> m;
			table[i][j] = m;
		}
	}
	//fine the min cost
	find_min(table, goal, n);
	return 0;
}
