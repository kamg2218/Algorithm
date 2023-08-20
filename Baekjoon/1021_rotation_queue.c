//Baekjoon 1021 회전하는 큐 - doubly linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct		s_node
{
	int				num;
	struct s_node	*prev; //이전 노드
	struct s_node	*next; //다음 노드
}					t_node;
//원형 큐 만들기
t_node		*make_que(int num)
{
	int		i;
	t_node	*new;
	t_node	*head;
	t_node	*circle;

	i = -1;
	head = NULL;
	circle = NULL;
	while (++i < num)
	{
		if (!(new = (t_node *)malloc(sizeof(t_node))))
			return (0);
		new->num = i + 1;
		new->prev = NULL;
		new->next = NULL;
		if (circle == NULL)
			circle = new;
		else
		{
			circle->next = new;
			new->prev = circle;
			circle = circle->next;
		}
		if (head == NULL)
			head = new;
	}
	circle->next = head;
	head->prev = circle;
	return (head);
}
//원형 큐 메모리 정리
void		clear_que(t_node *head)
{
	t_node	*prev;
	t_node	*tmp;

	if (head == NULL)
		return ;
	prev = head;
	head = head->next;
	prev->next = NULL;
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
//특정 노드 제거
t_node		*remove_node(t_node *circle, int n)
{
	t_node	*tmp;

	if (circle->next == NULL)
	{
		free(circle);
		return (NULL);
	}
	tmp = circle;
	while (tmp->next && tmp->next->num != n)
		tmp = tmp->next;
	while (circle->num != n)
		circle = circle->next;
	tmp->next = circle->next;
	circle->next->prev = tmp;
	tmp = tmp->next;
	if (tmp->next == tmp)
		tmp->next = NULL;
	free(circle);
	return (tmp);
}
//최소 이동 거리 구하기
int			count_que(t_node *circle, int num)
{
	int		min;
	int		count;
	t_node	*head;
	
	min = 0;
	count = 0;
	head = circle;
	//시계방향으로 이동할 때, 이동 횟수
	while (head->num != num)
	{
		head = head->next;
		count += 1;
	}
	min = count;
	count = 1;
	head = circle;
	//반시계방향으로 이동할 때, 이동 횟수
	while (head->prev->num != num)
	{
		head = head->prev;
		count += 1;
	}
	//최솟값 반환
	if (count < min)
		min = count;
	return (min);
}

int			main(void)
{
	int		i;
	int		n;
	int		m;
	int		count;
	int		*que;
	t_node	*circle;

	scanf("%d %d", &n, &m);
	getchar();
	if (!(que = (int *)malloc(sizeof(int) * (m + 1))))
		return (0);
	circle = make_que(n);
	count = 0;
	i = -1;
	while (++i < m)
	{
		scanf("%d", &que[i]);
		getchar();
	}
	que[i] = 0;
	i = -1;
	while (++i < m)
	{
		count += count_que(circle, que[i]);
		circle = remove_node(circle, que[i]);
	}
	printf("%d", count);
	clear_que(circle);
	return (0);
}
