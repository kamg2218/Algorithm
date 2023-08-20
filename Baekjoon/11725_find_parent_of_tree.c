//Baekjoon 11725 트리의 부모 찾기 - bfs
#include <stdio.h>
#include <stdlib.h>

typedef struct		s_node
{
	int				num;
	struct s_node	*next;
}					t_node;

int				put_number(t_node **left, int n)
{
	t_node		*new;
	t_node		*tmp;

	tmp = *left;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (!(new = (t_node *)malloc(sizeof(t_node))))
		return (0);
	new->num = n;
	new->next = NULL;
	if (tmp == NULL)
		*left = new;
	else
		tmp->next = new;
	return (0);
}

void			clear_node(t_node **left, int n)
{
	int			i;
	t_node		*pre;
	t_node		*tmp;

	i = 0;
	while (++i < n)
	{
		if (left[i])
		{
			tmp = left[i];
			while (tmp)
			{
				pre = tmp;
				tmp = tmp->next;
				free(pre);
			}
		}
	}
}

void			arrange_number(int *num, t_node **left)
{
	int			x, y, z, f;
	int			queue[100001] = {1, };
	t_node		*tmp;

	x = 0;	//탐색할 노드의 순서
	y = 1;	//queue 배열에 저장할 위치
	z = 1;	//x, y의 차이 값
	queue[0] = 1;	//우선순위 1
	while (z)
	{
		f = queue[x];
		tmp = left[f - 1];
		while (tmp)
		{
			if (num[tmp->num - 1] == 0)
			{
				num[tmp->num - 1] = f;
				queue[y] = tmp->num;
				++y;
			}
			tmp = tmp->next;
		}
		++x;
		z = y - x;
	}
}

int				main(void)
{
	int			i;
	int			n, a, b;
	int			len;
	int			num[100001] = {1, };
	t_node		**left;				//입력받은 값을 연결리스트로 저장

	scanf("%d", &n);
	getchar();
	//메모리 할당
	if (!(left = (t_node **)malloc(sizeof(t_node *) * n)))
		return (0);
	//초기화
	i = -1;
	while (++i < n)
		left[i] = NULL;
	i = 0;
	while (++i < n)
	{
		scanf("%d %d", &a, &b);
		getchar();
		//left에 연결리스트로 저장
		put_number(&left[a - 1], b);
		put_number(&left[b - 1], a);
	}
	//bfs 자료구조로 부모노드 찾기
	arrange_number(num, left);
	//결과 출력
	i = 0;
	while (++i < n)
		printf("%d\n", num[i]);
	//메모리 해제
	clear_node(left, n);
	free(left);
	return (0);
}
