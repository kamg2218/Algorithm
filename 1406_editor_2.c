//Baekjoon 1406 editor - doubly linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct		s_node
{
	char			content;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

t_node		*make_node(t_node *tail, char cont)
{
	t_node	*new;

	if (!(new = (t_node *)malloc(sizeof(t_node) * 1)))
		return (NULL);
	new->content = cont;
	new->next = NULL;
	new->prev = NULL;
	if (tail == NULL)
		return (new);
	tail->next = new;
	new->prev = tail;
	return (new);
}

void		clear_node(t_node *head)
{
	t_node	*tmp;

	tmp = head;
	while (tmp)
	{
		head = tmp;
		tmp = tmp->next;
		free(head);
	}
}

int			main(void)
{
	int		i;
	int		n;
	int		m;
	char	c;
	char	cmd[4] = {0, };
	t_node	*head;
	t_node	*tail;
	t_node	*tmp;
	t_node	*cursor;

	head = NULL;
	tail = NULL;
	while (1)
	{
		scanf("%c", &c);
		if (c == '\n')
			break ;
		tail = make_node(tail, c);
		if (head == NULL)
			head = tail;
	}
	tail = make_node(tail, '\0');
	tmp = head;
	scanf("%d", &m);
	getchar();
	cursor = tail;
	i = -1;
	while (++i < m)
	{
		scanf("%[^\n]s", cmd);
		getchar();
		if (cmd[0] == 'L' && cursor->prev)
			cursor = cursor->prev;
		else if (cmd[0] == 'D' && cursor->next)
			cursor = cursor->next;
		else if (cmd[0] == 'B' && cursor->prev)
		{
			tmp = cursor->prev;
			if (tmp->prev)
			{
				tmp->prev->next = cursor;
				cursor->prev = tmp->prev;
			}
			else
			{
				cursor->prev = NULL;
				head = cursor;
			}
			free(tmp);
		}
		else if (cmd[0] == 'P')
		{
			tmp = make_node(NULL, cmd[2]);
			tmp->next = cursor;
			if (cursor->prev == NULL)
			{
				cursor->prev = tmp;
				head = tmp;
			}
			else
			{
				tmp->prev = cursor->prev;
				cursor->prev->next = tmp;
				cursor->prev = tmp;
			}
		}
	}
	/*
	tmp = head;
	while (tmp->content)
	{
		printf("%c", tmp->content);
		tmp = tmp->next;
	}*/
	clear_node(head);
	return (0);
}
