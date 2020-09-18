//Baekjoon 1783 병든 나이트
#include <stdio.h>
//이동 횟수가 아닌, 방문한 위치의 갯수 출력
int			main(void)
{
	int		n; //row
	int		m; //col
	int		max; //방문한 위치

	scanf("%d %d", &n, &m);
	if (n == 1) //이동 불가능
		max = 1;
	else if (n == 2) //row == 1인 경우만, 이동 가능
	{
		if ((m + 1) / 2 < 4) //처음 위치를 더하기 위해, m + 1 사용
			max = (m + 1) / 2;
		else //이동 횟수가 4이상은, 모든 경우를 사용해야한다.
			max = 4;
	}
	else //행의 갯수는 무의미
	{
		if (m < 4) //이동 횟수가 4미만인 경우, 제약이 없다.
			max = m;
		else if (m <= 6) //5, 6인 경우, 최대가 4
			max = 4;
		else //4가지 경우를 사용하고, 열을 1씩만 이동 가능
			max = m - 2;
	}
	printf("%d", max);
	return (0);
}
