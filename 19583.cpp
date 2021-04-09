//백준 19583 사이버 개강 총회 - priority queue
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

//오름차순 정렬
struct	compare
{
	bool operator()(string a, string b)
	{
		return a > b;
	}
};

int		main(void)
{
	int		count;			//출석한 사람 수
	std::string	s, e, q;	//시작시간, 종료시간, 스트리밍 종료시간
	std::string time, name; //입력받는 값
	priority_queue<string, vector<string>, compare> pq; //시작전 댓글
	priority_queue<string, vector<string>, compare> tq; //종료후 댓글

	getline(cin, s, ' ');	//s 입력
	getline(cin, e, ' ');	//e 입력
	getline(cin, q);		//q 입력
	//eof 까지 입력
	while (getline(cin, time, ' ') && getline(cin, name))
	{
		//시간이 시작시간 보다 작은 경우
		if (time <= s)
			pq.push(name);
		//시간이 종료시간과 스트리밍 종료시간 사이인 경우
		else if (time >= e && time <= q)
			tq.push(name);
	}
	count = 0;
	name = "";
	//두 개의 큐에 값이 있는 동안
	while (!pq.empty() && !tq.empty())
	{
		//두 개의 값이 같고, 이전 값과 다른 경우
		if (pq.top() == tq.top() && name != pq.top())
		{
			++count;
			pq.pop();			//tq 는 뒤에서 제거
			name = tq.top();	//이름 변경
		}
		if (pq.top() < tq.top())
			pq.pop();
		else
			tq.pop();
	}
	//출석한 사람 수 출력
	cout << count;
	return 0;
}
