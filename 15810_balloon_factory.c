//Baekjoon 15810 풍선공장 - 이분 탐색
#include <stdio.h>
#include <stdlib.h>
//해당 시간에 만든 풍선 갯수 반환
long long		count_balloon(long long *balloon, long long  n, long long time)
{
	long long	i;
	long long	b;

	i = -1;
	b = 0;
	while (++i < n)
	{
		if (balloon[i] != 0)
			b += time / balloon[i]; 
	}
	return (b);
}

int			main(void)
{
	long long	n, m, b;
	long long	i;
	long long	time;
	long long	start, end, mid;
	long long	*balloon;

	scanf("%lld %lld", &n, &m);
	getchar();
	if (!(balloon = (long long *)malloc(sizeof(long long) * n)))
		return (0);
	i = -1;
	while (++i < n)
	{
		scanf("%lld", &balloon[i]);
		getchar();
	}
	//이분 탐색
	start = 0;
	end = 1000000000000; //가능한 경우의 수 중 최댓값
	while (start <= end)
	{
		mid = (start + end) / 2; //중간값
		b = count_balloon(balloon, n, mid); //풍선 갯수 확인
		if (b < m)
			start = mid + 1;
		else					//풍선 갯수가 목표보다 많은 경우
		{						//목표에 도달한 것으로
			time = mid;			//time 값에 저장
			end = mid - 1;
		}
	}
	printf("%lld", time);
	free(balloon);
	return (0);
}
