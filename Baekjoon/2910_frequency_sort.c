//Baekjoon 2910 빈도 정렬 - sort
#include <stdio.h>
#include <stdlib.h>

void		check(int *num, int n, int a, int b)
{
	int		i;
	int		j;
	int		tmp;
	int		count_i;
	int		count_j;

	if (a == n || b == n)
		return ;
	//a부터 갯수 확인
	i = a - 1;
	count_i = 0;
	while (num[a] == num[++i])
		++count_i;
	//b부터 갯수 확인
	j = b - 1;
	count_j = 0;
	while (num[b] == num[++j])
		++count_j;
	// b의 갯수가 많은 경우, 정렬
	if (count_j > count_i)
	{
		tmp = num[b];
		//배열 값 뒤로 밀기
		i = -1;
		while (++i < b - a)
			num[b + count_j - i - 1] = num[b - i - 1];
		//tmp 값 넣기
		i = a - 1;
		while (++i < a + count_j)
			num[i] = tmp;
		//a, b 값과 갯수 정리
		b = a + count_j;
		tmp = count_j;
		count_j = count_i;
		count_i = tmp;
	}
	//재귀함수
	if (b + count_j < n)
		check(num, n, a, b + count_j);
	else if (a + count_i < n)
	{
		i = a + count_i;
		while (i < n && num[a + count_i] == num[i])
			++i;
		check(num, n, a + count_i, i);
	}
}

int			main(void)
{
	int		i;
	int		j;
	int		k;
	int		n;
	int		c;
	int		*num;

	//n, c 입력받기
	scanf("%d %d", &n, &c);
	getchar();
	if (!(num = malloc(sizeof(int) * n)))
		return (0);
	//숫자 입력
	i = -1;
	while (++i < n)
	{
		scanf("%d", &num[i]);
		getchar();
	}
	//입력 받은 순서대로 숫자 모으기
	i = -1;
	while (++i < n)
	{
		j = i;
		while (++j < n)
		{
			if (num[i] == num[j])
			{
				k = j - i;
				while (--k > 0)
					num[i + k + 1] = num[i + k];
				num[i + 1] = num[i];
			}
		}
	}
	//정렬
	check(num, n, 0, 0);
	//출력
	i = -1;
	while (++i < n)
		printf("%d ", num[i]);
	printf("\n");
	free(num);
	return (0);
}
