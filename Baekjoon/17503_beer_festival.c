#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>

using namespace std;

//도수 기준 오름차순
//도수가 같은 경우,
//선호도가 높은순으로 정렬
struct	compare1
{
	bool operator()(pair<int, int> a, pair<int, int>b)
	{
		if (a.second == b.second)
			return a.first < b.first;
		return a.second > b.second;
	}
};

//선호도 기준 오름차순
struct	compare2
{
	bool operator()(pair<int, int> a, pair<int, int>b)
	{
		return a.first > b.first;
	}
};

priority_queue<pair<int, int>, vector<pair<int, int> >, compare1> pq;
priority_queue<pair<int, int>, vector<pair<int, int> >, compare2> tq;
int	v, c;

void	add_tq()
{
	//선호도 값 더하기
	v += pq.top().first;
	//tq에 push
	tq.push(pq.top());
	//도수 최댓값 저장
	if (c < pq.top().second)
		c = pq.top().second;
	//pq에서 값 삭제
	pq.pop();
}

int		main(void)
{
	//축제 기간, 선호도 합, 맥주 종류
	int	n, m, k;
	pair<int, int>	a;
	//첫 줄 입력
	cin >> n >> m >> k;
	//맥주의 도수와 선호도 입력
	for (int i = 0; i < k; i++)
	{
		cin >> a.first >> a.second;
		pq.push(a);
	}
	v = 0;
	c = 0;
	while (!pq.empty())
	{
		//축제기간 보다 갯수가 작은 경우,
		//push로 값 추가
		if (tq.size() < n)
			add_tq();
		//선호도 합이 작은 경우
		//tq에서 값을 하나 제거한 뒤,
		//새로운 값 추가
		else if (v < m)
		{
			v -= tq.top().first;
			tq.pop();
			add_tq();
		}
		else
			break ;
	}
	//선호도 합을 채운 경우
    if (v >= m)
        cout << c;
	//아닌 경우
    else
	    cout << -1;
	return (0);
}
