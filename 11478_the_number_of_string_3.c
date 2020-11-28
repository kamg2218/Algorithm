#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct		s_node
{
	char			*str;
	int				print;
	struct s_node	*prev;
	struct s_node	*left_next;
	struct s_node	*right_next;
}					t_node;

t_node				*make_node(char *str)
{
	t_node			*new;

	if (!(new = (t_node *)malloc(sizeof(t_node) * 1)))
		return (NULL);
	new->print = 0;
	new->str = str;
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
		free(tmp->str);
		free(tmp);
		tmp = pre;
	}
	head = NULL;
}

void			arrange(t_node **head, t_node *new)
{
	int			cmp;
	t_node		*tmp;

	tmp = *head;
	while (tmp)
	{
		cmp = strcmp(new->str, tmp->str);
		if (cmp == 0)
		{
			free(new->str);
			free(new);
			return ;
		}
		if (cmp > 0)
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
	if (cmp > 0)
		tmp->right_next = new;
	else
		tmp->left_next = new;
	new->prev = tmp;
}

int			print_tree(t_node *head)
{
	int		count;
	t_node	*tmp;

	count = 0;
	tmp = head;
	while (tmp)
	{
		while (tmp->left_next && !(tmp->left_next->print))
			tmp = tmp->left_next;
		if (tmp->print && tmp->right_next && !tmp->right_next->print)
				tmp = tmp->right_next;
		if (tmp->print == 0)
			++count;
		tmp->print = 1;
		if (tmp->prev == NULL
				&& ((tmp->right_next && tmp->right_next->print)
					|| !(tmp->right_next)))
			return (count);
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
	return (count);
}

int			main(void)
{
	int		i;
	int		j;
	int		n;
	int		count;
	char	str[1001] = {0, };
	char	cpy[1001] = {0, };
	t_node	*head;
	t_node	*tmp;

	scanf("%[^\n]s", str);
	getchar();
	count = 0;
	n = strlen(str);
	i = 0;
	while (++i <= n)
	{
		head = NULL;
		j = -1;
		while (++j <= n - i)
		{
			strncpy(cpy, &str[j], i);
			tmp = make_node(strdup(cpy));
			if (head == NULL)
				head = tmp;
			else
				arrange(&head, tmp);
		}
		count += print_tree(head);
		clear_node(head);
	}
	printf("%d", count);
	return (0);
}
