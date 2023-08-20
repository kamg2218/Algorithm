//Baekjoon 2346 풍선 터뜨리기 - doubly linked list - runtime ERROR!!!
#include <stdio.h>
#include <stdlib.h>

typedef struct		s_node
{
	int				num;
	struct s_node	*prev;
	struct s_node	*next;
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

	tmp = circle->prev;
	tmp->next = circle->next;
	circle->next->prev = tmp;
	free(circle);
	return (tmp);
}

t_node		*find_balloon(t_node *head, int *que, int n)
{
	int		i;
	int		j;
	int		k;
	t_node	*circle;

	i = -1;
	k = 0;
	circle = head;
	while (++i < n - 1)
	{
		printf("%d ", circle->num);
		head = circle;
		j = -1;
		while (++j < abs(que[k]))
		{
			if (que[k] > 0)
				circle = circle->next;
			else
				circle = circle->prev;
		}
		remove_node(head, k + 1);
		k = circle->num - 1;
	}
	return (circle);
}

int			main(void)
{
	int		i;
	int		n;
	int		*que;
	t_node	*circle;

	scanf("%d", &n);
	getchar();
	if (!(que = (int *)malloc(sizeof(int) * (n + 1))))
		return (0);
	circle = make_que(n);
	i = -1;
	while (++i < n)
	{
		scanf("%d", &que[i]);
		getchar();
	}
	que[i] = 0;
	if (n == 1)
	{
		free(que);
		return (0);
	}
	circle = find_balloon(circle, que, n);
	printf("%d", circle->num);
	clear_que(circle);
	return (0);
}
