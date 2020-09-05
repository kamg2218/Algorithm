//Baekjoon 1308 D-DAY
#include <stdio.h>
#include <stdlib.h>
//윤년 확인
int			check_year(int year)
{
	if (year % 400 == 0)
		return (1);
	else if (year % 100 == 0)
		return (0);
	else if (year % 4 == 0)
		return (1);
	else
		return (0);
}
//연도 더하기
int			add_year(int *start, int *end)
{
	int		n;
	int		count;

	count = 0;
	n = end[0] - start[0];
	if (start[1] <= end[1]) //end의 월이 크면 같은 해까지 더하기
		n += 1;
	while (n > 1)
	{
		//1, 2월은 그 해의 날짜 더하기
		if (start[1] < 3 && check_year(start[0]) == 0)
			count += 365;
		//3월부터는 다음해의 날짜 더하기
		else if (start[1] > 2 && check_year(start[0] + 1) == 0)
			count += 365;
		//윤년일 경우, 366
		else
			count += 366;
		start[0] += 1;
		n -= 1;
	}
	return (count);
}
//달별 날짜 더하기
int			add_month(int *start, int *end)
{
	int		n;
	int		count;

	count = 0;
	//end의 월이 큰 경우, 해의 값은 같다
	if (start[1] <= end[1])
		n = end[1] - start[1];
	//end의 월이 작은 경우, 해는 1 차이 난다
	else
	{
		n = 12 - start[1];
		n += end[1];
	}
	while (n > 0)
	{
		if (start[1] == 1 || start[1] == 3 || start[1] == 5
			|| start[1] == 7 || start[1] == 8 || start[1] == 10
			|| start[1] == 12)
			count += 31;
		else if (start[1] == 4 || start[1] == 6
			|| start[1] == 9 || start[1] == 11)
			count += 30;
		else if (start[1] == 2 && check_year(start[0]) == 0)
			count += 28;
		else if (start[1] == 2)
			count += 29;
		//12월인 경우, 해를 더해주고, 다음 달 1일이 된다.
		if (start[1] == 12)
		{
			start[0] += 1;
			start[1] = 1;
		}
		//다른 달의 경우, 달만 더한다.
		else
			start[1] += 1;
		n -= 1;
	}
	return (count);
}

int			count_date(int *start, int *end)
{
	int		count;

	//천년 보다 긴 경우, -1 반환
	if (end[0] - start[0] > 1000)
		return (-1);
	else if (end[0] - start[0] == 1000 && end[1] > start[1])
		return (-1);
	else if (end[0] - start[0] == 1000 && end[1] == start[1]
			&& end[2] >= start[2])
		return (-1);
	count = 0;
	count += add_year(start, end); //년도 계산
	count += add_month(start, end); //달별 계산
	count += end[2] - start[2]; //날짜 차이 계산
	return (count);
}

int			main(void)
{
	int		count;
	int		start[3] = {0,};
	int		end[3] = {0,};

	scanf("%d %d %d", &start[0], &start[1], &start[2]);
	getchar();
	scanf("%d %d %d", &end[0], &end[1], &end[2]);
	count = count_date(start, end);
	//천년보다 긴 경우, gg 출력
	if (count == -1)
		printf("gg");
	//D-day 출력
	else
		printf("D-%d", count);
	return (0);
}
