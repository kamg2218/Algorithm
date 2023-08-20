//Baekjoon 10828 stack
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct		s_stack
{
	int				content;
	struct s_stack	*next;
}					t_stack;

void			clear(t_stack **head)
{
	t_stack		*pre;
	t_stack		*tmp;

	if (head == NULL || *head == NULL)
		return ;
	tmp = *head;
	while (tmp)
	{
		pre = tmp;
		tmp = tmp->next;
		free(pre);
	}
}

t_stack		*new(int content)
{
	t_stack	*n;

	n = (t_stack *)malloc(sizeof(t_stack));
	if (n == NULL)
		return (NULL);
	n->content = content;
	n->next = NULL;
	return (n);
}

void			push(t_stack **head, int content)
{
	t_stack		*n;
	t_stack		*tmp;

	if (!(n = new(content)))
		return ;
	if (head == NULL || *head == NULL)
	{
		*head = n;
		return ;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = n;
	n->next = NULL;
}

void			pop(t_stack **head)
{
	t_stack		*prev;
	t_stack		*tmp;

	if (head == NULL || *head == NULL)
	{
		printf("-1\n");
		return ;
	}
	tmp = *head;
	prev = NULL;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	printf("%d\n", tmp->content);
	if (prev)
		prev->next = NULL;
	else
		*head = NULL;
	free(tmp);
}

int				size(t_stack **head)
{
	int			count;
	t_stack		*tmp;

	if (head == NULL || *head == NULL)
		return (0);
	count = 1;
	tmp = *head;
	while (tmp->next)
	{
		++count;
		tmp = tmp->next;
	}
	return (count);
}

int			empty(t_stack **head)
{
	if (head == NULL || *head == NULL)
		return (1);
	else
		return (0);
}

int				top(t_stack **head)
{
	int			cont;
	t_stack		*tmp;

	if (head == NULL || *head == NULL)
		return (-1);
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	cont = tmp->content;
	return (cont);
}

int				main(void)
{
	int			i;
	int			j;
	int			n;
	int			num;
	char		str[12] = {0, };
	t_stack		*head;
	t_stack		*tmp;

	scanf("%d", &n);
	getchar();
	head = NULL;
	i = -1;
	while (++i < n)
	{
		scanf("%[^\n]s", str);
		getchar();
		if (!(strncmp(str, "push", 4)))
		{
			num = 0;
			j = 5;
			while (str[j])
			{
				num = num * 10 + (str[j] - '0');
				++j;
			}
			//printf("num = %d\n", num);
			push(&head, num);
		}
		else if (!(strncmp(str, "pop", 3)))
			pop(&head);
		else if (!(strncmp(str, "size", 4)))
			printf("%d\n", size(&head));
		else if (!(strncmp(str, "empty", 5)))
			printf("%d\n", empty(&head));
		else if (!(strncmp(str, "top", 3)))
			printf("%d\n", top(&head));
		j = -1;
		while (++j < 12)
			str[j] = 0;
	}
	clear(&head);
	return (0);
}
