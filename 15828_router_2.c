//Baekjoon 15828 Router - queue
#include <stdio.h>
#include <stdlib.h>

typedef	struct		s_node
{
	int				num;
	struct s_node	*next;
}					t_node;
//add node
t_node		*inqueue(t_node *tail, int m)
{
	t_node	*new;

	if (!(new = (t_node *)malloc(sizeof(t_node) * 1)))
		return (NULL);
	new->num = m;
	new->next = NULL;
	if (tail == NULL)
		return (new);
	else
		tail->next = new;
	return (new);
}
//remove node
t_node		*dequeue(t_node *head)
{
	t_node	*tmp;

	if (head == NULL)
		return (NULL);
	tmp = head->next;
	head->next = NULL;
	free(head);
	return (tmp);
}

int			main(void)
{
	int		n;
	int		m;
	int		len; //the number of nodes
	t_node	*tmp;
	t_node	*head;
	t_node	*tail;

	scanf("%d", &n);
	getchar();
	head = NULL;
	len = 0;
	while (1)
	{
		scanf("%d", &m);
		getchar();
		if (m == -1)
			break ;
		else if (m && len < n)
		{
			if (head == NULL)
			{
				head = inqueue(head, m);
				tail = head;
			}
			else
				tail = inqueue(tail, m);
			len += 1;
		}
		else if (len > 0 && m == 0)
		{
			head = dequeue(head);
			len -= 1;
		}
	}
	//print all nodes
	if (head == NULL)
		printf("empty");
	while (head)
	{
		printf("%d", head->num);
		tmp = head;
		head = head->next;
		if (head)
			printf(" ");
		free(tmp);
	}
	return (0);
}
