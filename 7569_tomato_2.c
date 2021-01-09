//7569 토마토 - two queque - 시간초과
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_node
{
	int				x;
	int				y;
	int				z;
	struct s_node	*next;
}				t_node;

int		m, n, h;
t_node	**apple = NULL;
t_node	**a_tail = NULL;
t_node	*cooked = NULL;
t_node	*c_tail = NULL;
t_node	*tail = NULL;

void		destroy(t_node **head)
{
	t_node	*pre;
	t_node	*tmp;

	tmp = *head;
	while (tmp)
	{
		pre = tmp;
		tmp = tmp->next;
		free(pre);
	}
}

void		new(t_node **head, t_node **ta, int x, int y, int z)
{
	t_node	*n;

	if (!(n = (t_node *)malloc(sizeof(t_node))))
		return ;
	n->x = x;
	n->y = y;
	n->z = z;
	n->next = NULL;
	if (*ta == NULL)
		*head = n;
	else
		(*ta)->next = n;
	*ta = n;
}

t_node		*change_node(t_node *pre, t_node *new, t_node **apl)
{
	t_node	*next;

	next = new->next;
	if (pre)
		pre->next = new->next;
	else
		*apl = new->next;
	if (c_tail)
		c_tail->next = new;
	else
		cooked = new;
	c_tail = new;
	new->next = NULL;
	return (next);
}

t_node		*find_node(t_node *c_tmp)
{
	int		x = c_tmp->x;
	int		y = c_tmp->y;
	int		z = c_tmp->z;
	t_node	*tmp;
	t_node	*pre;

	pre = NULL;
	tmp = apple[x];
	while (tmp)
	{
		if ((tmp->y == y - 1 && tmp->z == z)
				|| (tmp->y == y + 1 && tmp->z == z)
				|| (tmp->y == y && tmp->z == z - 1)
				|| (tmp->y == y && tmp->z == z + 1))
		{
			tmp = change_node(pre, tmp, &apple[x]);
			continue ;
		}
		pre = tmp;
		tmp = tmp->next;
	}
	if (x > 0)
	{
		pre = NULL;
		tmp = apple[x - 1];
		while (tmp)
		{
			if (tmp->y == y && tmp->z == z)
			{
				tmp = change_node(pre, tmp, &apple[x - 1]);
				break ;
			}
			pre = tmp;
			tmp = tmp->next;
		}
	}
	pre = NULL;
	tmp = apple[x + 1];
	while (tmp)
	{
		if (tmp->y == y && tmp->z == z)
		{
			tmp = change_node(pre, tmp, &apple[x + 1]);
			break ;
		}
		pre = tmp;
		tmp = tmp->next;
	}
	return (NULL);
}

int			check_apple(void)
{
	int		count;
	t_node	*tmp;
	t_node	*pre;

	tmp = cooked;
	tail = c_tail;
	count = 0;
	while (tmp)
	{
		find_node(tmp);
		if (tmp == tail)
		{
			tail = c_tail;
			++count;
			printf("count = %d\n", count);
		}
		tmp = tmp->next;
	}
	for (int i = 0; i < m; i++)
	{
		if (apple[i] != NULL)
			return (-1);
	}
	return (count - 1);
}

int			main(void)
{
	int		i, j, k, l;
	int		a, b, c;

	scanf("%d %d %d", &m, &n, &h);
	getchar();
	if (!(apple = (t_node **)malloc(sizeof(t_node *) * (m + 1))))
		return (0);
	if (!(a_tail = (t_node **)malloc(sizeof(t_node *) * (m + 1))))
		return (0);
	for (i = 0; i <= m; i++){
		apple[i] = NULL;
		a_tail[i] = NULL;
	}
	for (i = 0; i < h; i++)
	{
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < m; k++)
			{
				scanf("%d", &l);
				getchar();
				if (l == 0)
					new(&apple[k], &a_tail[k], k, j, i);
				else if (l == 1)
					new(&cooked, &c_tail, k, j, i);
			}
		}
	}
	if (cooked == NULL)
		printf("-1");
	else
		printf("%d", check_apple());
	free(a_tail);
	for (i = 0; i < m; i++)
		destroy(&apple[i]);
	free(apple);
	destroy(&cooked);
	return (0);
}
