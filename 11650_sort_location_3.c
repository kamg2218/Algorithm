//Baekjoon 11650 좌표 정렬하기 - heap sort
#include <stdio.h>
#include <stdlib.h>

typedef struct		s_node
{
	int				num_left;
	int				num_right;
	int				print;
	struct s_node	*prev;
	struct s_node	*left_next;
	struct s_node	*right_next;
}					t_node;

t_node				*make_node(int left, int right)
{
	t_node			*new;

	if (!(new = (t_node *)malloc(sizeof(t_node) * 1)))
		return (NULL);
	new->print = 0;
	new->num_left = left;
	new->num_right = right;
	new->left_next = NULL;
	new->right_next = NULL;
	new->prev = NULL;
	return (new);
}

void			clear_node(t_node *head)
{
	t_node		*pre;
	t_node		*tmp;

	tmp = head;
	while (tmp)
	{
		while (tmp->left_next)
			tmp = tmp->left_next;
		while (tmp->right_next)
			tmp = tmp->right_next;
		pre = tmp->prev;
		if (pre && pre->right_next == tmp)
			pre->right_next = NULL;
		else if (pre && pre->left_next == tmp)
			pre->left_next = NULL;
		free(tmp);
		tmp = pre;
	}
	head = NULL;
}

void			arrange(t_node **head, t_node *new)
{
	t_node		*tmp;

	tmp = *head;
	while (tmp)
	{
		if (new->num_left > tmp->num_left
				|| (new->num_left == tmp->num_left
					&& new->num_right > tmp->num_right))
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
	if ((new->num_left > tmp->num_left)
				|| (new->num_left == tmp->num_left
					&& new->num_right > tmp->num_right))
		tmp->right_next = new;
	else
		tmp->left_next = new;
	new->prev = tmp;
}

void		print_tree(t_node *head)
{
	t_node	*tmp;

	tmp = head;
	while (tmp)
	{
		while (tmp->left_next && !(tmp->left_next->print))
			tmp = tmp->left_next;
		if (tmp->print && tmp->right_next && !tmp->right_next->print)
				tmp = tmp->right_next;
		if (tmp->print == 0)
			printf("%d %d\n", tmp->num_left, tmp->num_right);
		tmp->print = 1;
		if (tmp->prev == NULL
				&& ((tmp->right_next && tmp->right_next->print)
					|| !(tmp->right_next)))
			return ;
		if (tmp->prev && tmp->right_next == NULL)
			tmp = tmp->prev;
		else if (tmp->right_next && !tmp->right_next->print)
			tmp = tmp->right_next;
		if (tmp->print)
		{
			while (tmp->prev && tmp->print)
				tmp = tmp->prev;
		}
	}
}

int			main(void)
{
	int		i;
	int		j;
	int		n;
	int		left;
	int		right;
	t_node	*head;
	t_node	*tmp;

	scanf("%d", &n);
	getchar();
	head = NULL;
	i = -1;
	while (++i < n)
	{
		scanf("%d %d", &left, &right);
		getchar();
		tmp = make_node(left, right);
		if (head == NULL)
			head = tmp;
		else
			arrange(&head, tmp);
	}
	print_tree(head);
	clear_node(head);
	return (0);
}
