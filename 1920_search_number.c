//Baekjoon 1920 수 찾기 - 이진 탐색 트리
#include <stdio.h>
#include <stdlib.h>

typedef struct		s_node
{
	int				num;
	struct s_node	*prev;
	struct s_node	*left_next;
	struct s_node	*right_next;
}					t_node;

t_node				*make_node(int num)
{
	t_node			*new;

	if (!(new = (t_node *)malloc(sizeof(t_node) * 1)))
		return (NULL);
	new->num = num;
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
		printf("num = %d\n", tmp->num);
		free(tmp);
		tmp = pre;
	}
	head = NULL;
}

void			arrange(t_node **head, t_node *new, int num)
{
	int			n;
	t_node		*tmp;
	t_node		*cmp;

	tmp = *head;
	while (tmp)
	{
		if (new->num > tmp->num)
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
	if (new->num > tmp->num)
		tmp->right_next = new;
	else
		tmp->left_next = new;
	new->prev = tmp;
}

int				main(void)
{
	int			i;
	int			j;
	int			n;
	int			m;
	t_node		*tmp;
	t_node		*head;

	head = NULL;
	scanf("%d", &n);
	getchar();
	i = -1;
	while (++i < n)
	{
		scanf("%d", &m);
		getchar();
		tmp = make_node(m);
		if (head == NULL)
			head = tmp;
		else
			arrange(&head, tmp, m);
	}
	printf("arranged\n");
	scanf("%d", &n);
	getchar();
	i = -1;
	while (++i < n)
	{
		scanf("%d", &m);
		getchar();
		tmp = head;
		while (tmp)
		{
			if (tmp->num == m)
			{
				printf("1\n");
				break ;
			}
			else if (tmp->num < m)
			{
				if (tmp->right_next)
					tmp = tmp->right_next;
				else
				{
					printf("0\n");
					break ;
				}
			}
			else
			{
				if (tmp->left_next)
					tmp = tmp->left_next;
				else
				{
					printf("0\n");
					break ;
				}
			}
		}
	}
	clear_node(head);
	return (0);
}
