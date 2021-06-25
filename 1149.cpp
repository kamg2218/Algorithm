#include <iostream>
#include <vector>
using namespace std;

void		push_value(int **cost, int num, vector<int>& v, int start)
{
	int		i;

	for (i = start; i < num; i++)
	{
		if (v.empty())
			v.push_back(0);	
		else
		{
			if (v.back() == 0)
				v.push_back(1);
			else
				v.push_back(0);
		}
	}
}

int		count_cost(int **cost, vector<int>& v)
{
	int		sum = 0;

	for (int i = 0; i < v.size(); i++)
		sum += cost[i][v[i]];
	return sum;
}

int		find_cost(int **cost, int num)
{
	int				min;
	int				tmp;
	vector<int>		v;

	push_value(cost, num, v, 0);
	min = count_cost(cost, v);
	while (1){
		cout << "v.size = " << v.size() << endl;
		while (v.size()){
			tmp = v.back();
			v.pop_back();
			if (tmp == 2 || (tmp == 1 && v.back() == 2))
				continue ;
			else if (tmp == 0 && v.back() != 1)
				v.push_back(1);
			else
				v.push_back(2);
			break ;
		}
		if (v.empty())
			break ;
		push_value(cost, num, v, v.size());
		tmp = count_cost(cost, v);
		if (tmp < min)
			min = tmp;
	}
	return min;
}

int		main(void)
{
	int		num;
	int		**cost;

	cin >> num;
	cost = new int*[num];
	for (int i = 0; i < num; i++){
		cost[i] = new int[3];
		cost[i][0] = 0;
		cost[i][1] = 0;
		cost[i][2] = 0;
	}
	for (int i = 0; i < num; i++)
	{
		cout << "i = " << i << endl;
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}
	cout << find_cost(cost, num);
	for (int i = 0; i < num; i++)
		delete [] cost[i];
	delete [] cost;
	return (0);
}
