//Baekjoon 11724 연결 요소의 개수 - 시간초과
#include <stdio.h>
#include <stdlib.h>

typedef struct		s_node
{
	int				num;
	struct s_node	*next;
}					t_node;

int		n, m;
int		*visited;
t_node	**head;

t_node		*add_node(int a, int b)
{
	t_node	*tmp;
	t_node	*new;

	if (!(new = (t_node *)malloc(sizeof(t_node))))
		return (NULL);
	new->num = b;
	new->next = NULL;
	tmp = head[a - 1];
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp == NULL)
		head[a - 1] = new;
	else
		tmp->next = new;
	return (new);
}

t_node		*clear_node(int num, t_node *pre, t_node *tmp)
{
	t_node	*new;

	if (pre == NULL)
		head[num] = tmp->next;
	else
		pre->next = tmp->next;
	new = tmp->next;
	free(tmp);
	return (new);
}

void		dfs(int i)
{
	t_node	*pre;
	t_node	*tmp;

	visited[i] = 1;
	pre = NULL;
	tmp = head[i];
	while (tmp)
	{
		if (visited[tmp->num - 1] == 0)
			dfs(tmp->num - 1);
		tmp = clear_node(i, pre, tmp);
	}
}

int			count_component(void)
{
	int		count;
	int		i;

	count = 0;
	i = -1;
	while (++i < n)
	{
		if (visited[i] == 0)
		{
			dfs(i);
			count += 1;
		}
	}
	return (count);
}

int			main(void)
{
	int		i, j;
	int		a, b, c;

	scanf("%d %d", &n, &m);
	getchar();
	if (!(head = (t_node **)malloc(sizeof(t_node *) * (n + 1))))
		return (0);
	if (!(visited = (int *)malloc(sizeof(int) * (n + 1))))
		return (0);
	i = -1;
	while (++i <= n)
	{
		head[i] = NULL;
		visited[i] = 0;
	}
	i = -1;
	while (++i < m)
	{
		scanf("%d %d", &a, &b);
		getchar();
		add_node(b, a);
		add_node(a, b);
	}
	printf("%d", count_component());
	free(head);
	free(visited);
	return (0);
}
