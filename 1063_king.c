//Baekjoon 1063 킹 - two dimensional array
#include <stdio.h>
#include <stdlib.h>

// 8 * 8 체스판을 벗어나는 지 확인
int			check_edge(char *horse, int x, int y)
{
	if ((horse[1] + x < '9' && horse[1] + x > '0')
			&& (horse[0] + y > 'A' - 1 && horse[0] + y < 'H' + 1))
		return (1);
	else
		return (0);
}
// 입력에 따른 행, 열 값 부여
void		check_order(char *order, int *x, int *y)
{
	if (order[0] == 'B')
		*x = -1;
	else if (order[0] == 'T')
		*x = 1;
	else if (order[0] == 'R' && order[1] == 'T')
	{
		*x = 1;
		*y = 1;
	}
	else if (order[0] == 'L' && order[1] == 'T')
	{
		*x = 1;
		*y = -1;
	}
	else if (order[0] == 'R' && order[1] == 'B')
	{
		*x = -1;
		*y = 1;
	}
	else if (order[0] == 'L' && order[1] == 'B')
	{
		*x = -1;
		*y = -1;
	}
	else if (order[0] == 'R')
		*y = 1;
	else
		*y = -1;
}
//stone이 있는 지 확인
int			is_stone(char *king, char *stone, int x, int y)
{
	if ((king[0] + y == stone[0])
			&& (king[1] + x == stone[1]))
		return (1);
	else
		return (0);
}

int			main(void)
{
	int		i;
	int		x;
	int		y;
	int		num;
	char	king[3];
	char	stone[3];
	char	**order;

	scanf("%s %s %d", king, stone, &num);
	getchar();
	//메모리 할당하여 order 입력 받기
	if (!(order = (char **)malloc(sizeof(char *) * (num + 1))))
		return (0);
	i = -1;
	while (++i < num)
	{
		if (!(order[i] = (char *)malloc(sizeof(char) * 2)))
			return (0);
		scanf("%s", order[i]);
		getchar();
	}
	order[i] = 0;
	i = -1;
	while (++i < num)
	{
		x = 0;
		y = 0;
		//x, y 값 부여
		check_order(order[i], &x, &y);
		//돌이 있을 경우
		if (is_stone(king, stone, x, y))
		{
			//돌을 이동해도 체스판 위에 있는 지 확인
			if (!(check_edge(stone, x, y)))
				continue ;
			//킹을 이동해도 체스판 위에 있는 지 확인
			if (!(check_edge(king, x, y)))
				continue ;
			//돌 이동
			stone[0] += y;
			stone[1] += x;
		}
		//킹 이동 여부 확인
		if (!(check_edge(king, x, y)))
			continue ;
		//킹 이동
		king[0] += y;
		king[1] += x;
	}
	printf("%s\n%s", king, stone);
	//메모리 해제
	i = -1;
	while (++i < num)
		free(order[i]);
	free(order);
	return (0);
}
