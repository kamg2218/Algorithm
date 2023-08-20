//Baekjoon 11000 강의실배정 - 시간초과
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct		s_node
{
	int				print;
	int				start;
	int				end;
	struct s_node	*prev;
	struct s_node	*left_next;
	struct s_node	*right_next;
}					t_node;

void			destroy(t_node **head)
{
	t_node		*pre;
	t_node		*tmp;

	tmp = *head;
	while (tmp)
	{
		while (tmp->left_next)
			tmp = tmp->left_next;
		while (tmp->right_next)
			tmp = tmp->right_next;
		if (tmp->left_next)
			continue ;
		pre = tmp->prev;
		if (pre && pre->right_next == tmp)
			pre->right_next = NULL;
		else if (pre && pre->left_next == tmp)
			pre->left_next = NULL;
		free(tmp);
		tmp = pre;
	}
	*head = NULL;
}

static t_node	*tmp_right_next(t_node *tmp)
{
	t_node		*new;
	t_node		*old;
	t_node		*tail;

	new = tmp->right_next;
	old = new;
	while (new->left_next)
		new = new->left_next;
	if (new != old)
	{
		old = new->prev;
		new->prev = NULL;
		while (old != tmp)
		{
			tail = new;
			while (tail->right_next)
				tail = tail->right_next;
			old->left_next = NULL;
			tail->right_next = old;
			old = old->prev;
			tail->right_next->prev = tail;
		}
		if (tmp->prev == NULL)
			new->prev = NULL;
		else
			new->prev = tmp->prev;
	}
	return (new);
}

void			delete(t_node **head, t_node *tmp)
{
	t_node		*new;

	new = NULL;
	while (tmp->left_next || tmp->right_next)
	{
		while (tmp->left_next)
		{
			tmp->start = tmp->left_next->start;
			tmp->end = tmp->left_next->end;
			tmp = tmp->left_next;
		}
		if (tmp->right_next)
		{
			new = tmp_right_next(tmp);
			break ;
		}
	}
	if (tmp->prev && tmp == tmp->prev->left_next)
		tmp->prev->left_next = new;
	else if (tmp->prev && tmp == tmp->prev->right_next)
		tmp->prev->right_next = new;
	if (tmp == *head)
		*head = new;
	free(tmp);
}

t_node				*create(int start, int end)
{
	t_node			*new;

	if (!(new = (t_node *)malloc(sizeof(t_node) * 1)))
		return (NULL);
	new->start = start;
	new->end = end;
	new->left_next = NULL;
	new->right_next = NULL;
	new->prev = NULL;
	new->print = 0;
	return (new);
}

void			insert(t_node **head, t_node *new)
{
	t_node		*tmp;

	tmp = *head;
	if (tmp == NULL)
	{
		*head = new;
		return ;
	}
	while (tmp)
	{
		if (new->start > tmp->start
				|| (new->start == tmp->start && new->end > tmp->end))
		{
			if (tmp->right_next == NULL)
				break ;
			tmp = tmp->right_next;
		}
		else
		{
			if (tmp->left_next == NULL)
				break ;
			tmp = tmp->left_next;
		}
	}
	if (new->start > tmp->start ||
			(new->start == tmp->start && new->end > tmp->end))
		tmp->right_next = new;
	else
		tmp->left_next = new;
	new->prev = tmp;
}

t_node		*check_room(t_node *head, int start)
{
	t_node	*tmp;

	tmp = head;
	while (tmp)
	{
		if (tmp->end <= start)
			return (tmp);
		tmp = tmp->right_next;
	}
	return (NULL);
}

t_node		*top(t_node **head)
{
	t_node	*tmp;

	tmp = *head;
	while (tmp && tmp->left_next)
		tmp = tmp->left_next;
	return (tmp);
}

void		add_back(t_node **head, t_node *new_node)
{
	t_node	*tmp;

	tmp = *head;
	if (tmp == NULL)
	{
		*head = new_node;
		return ;
	}
	while (tmp && tmp->right_next)
		tmp = tmp->right_next;
	tmp->right_next = new_node;
}

int			main(void)
{
	int		i;
	int		start, end;
	int		n;		//강의 수
	t_node	*class;	//강의 시간 저장
	t_node	*room;	//강의실 저장
	t_node	*ctmp;
	t_node	*rtmp;
	t_node	*tmp;

	class = NULL;
	room = NULL;
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &start, &end);
		getchar();
		insert(&class, create(start, end));
	}
	i = 0;
	while (class)
	{
		ctmp = top(&class);
		if ((rtmp = check_room(room, ctmp->start)))
			rtmp->end = ctmp->end;
		else
		{
			add_back(&room, create(ctmp->start, ctmp->end));
			++i;
		}
		delete(&class, ctmp);
	}
	printf("%d", i);
	destroy(&class);
	destroy(&room);
	return (0);
}
