#include <stdio.h>

char		friend[51][51];
int		visited[51];

//친구의 수르 확인하는 함수
int			get_count(int i, int n)
{
	int		a, b;
	int		count;
	int		check[51] = {0, }; //친구 여부를 저장하는 변수

	//사람의 숫자만큼 친구 여부 확인(friend 변수의 열을 확인한다.)
	a = -1;
	while (++a < n)
	{
		//자기 자신을 제외하고, 친구인 경우
		if (i != a && friend[i][a] == 'Y')
		{
			check[a] = 1; //친구 임을 표시
			//한다리 건너 친구인지 확인한다.
			b = -1;
			while (++b < n)
			{
				if (i != b && friend[a][b] == 'Y')
					check[b] = 1;
			}
		}
	}
	//친구의 수 세기
	count = 0;
	a = -1;
	while (++a < n)
	{
		if (check[a] == 1)
			++count;
	}
	//친구의 수 반환
	return (count);
}

int			main(void)
{
	int		i, j;
	int		n;
	int		max;

	//사람으 수 입력받기
	scanf("%d", &n);
	getchar();
	//사람으 수만큼 친구 확인하기
	i = -1;
	while (++i < n)
	{
		//친구 여부를 friend 이중배열에 저장(T or F)
		j = -1;
		while (++j < n)
			scanf("%c", &friend[i][j]);
		getchar();
	}
	i = -1;
	max = 0; //max는 가장 많은 친구의 수를 저장
	while (++i < n)
	{
		//친구의 수를 확인하는 함수
		j = get_count(i, n);
		//최댓값 저장
		if (j > max)
			max = j;
	}
	//최댓값 출력
	printf("%d", max);
	return (0);
}
