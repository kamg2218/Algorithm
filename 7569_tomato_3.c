//Baekjoon 7569 토마토 - queue
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
t_node	*apple = NULL;
t_node	*tail = NULL;
int		box[101][101][101];

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

int			is_in(void)
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (box[k][j][i] == 0)
					return (1);
			}
		}
	}
	return (0);
}

void		new(int x, int y, int z)
{
	t_node	*n;

	if (!(n = (t_node *)malloc(sizeof(t_node))))
		return ;
	n->x = x;
	n->y = y;
	n->z = z;
	n->next = NULL;
	if (tail == NULL)
		apple = n;
	else
		tail->next = n;
	tail = n;
}

int			check_apple(void)
{
	int		i, count = 0;
	t_node	*tmp;
	t_node	*pre;
	t_node	*a_tail = NULL;

	tmp = apple;
	a_tail = tail;
	while (tmp)
	{
		i = 0;
		if (tmp->x > 0 && box[tmp->x - 1][tmp->y][tmp->z] == 0)
		{
			box[tmp->x - 1][tmp->y][tmp->z] = 1;
			new(tmp->x - 1, tmp->y, tmp->z);
		}
		if (tmp->x + 1 < m && box[tmp->x + 1][tmp->y][tmp->z] == 0)
		{
			box[tmp->x + 1][tmp->y][tmp->z] = 1;
			new(tmp->x + 1, tmp->y, tmp->z);
		}
		if (tmp->y > 0 && box[tmp->x][tmp->y - 1][tmp->z] == 0)
		{
			box[tmp->x][tmp->y - 1][tmp->z] = 1;
			new(tmp->x, tmp->y - 1, tmp->z);
		}
		if (tmp->y + 1 < n && box[tmp->x][tmp->y + 1][tmp->z] == 0)
		{
			box[tmp->x][tmp->y + 1][tmp->z] = 1;
			new(tmp->x, tmp->y + 1, tmp->z);
		}
		if (tmp->z > 0 && box[tmp->x][tmp->y][tmp->z - 1] == 0)
		{
			box[tmp->x][tmp->y][tmp->z - 1] = 1;
			new(tmp->x, tmp->y, tmp->z - 1);
		}
		if (tmp->z + 1 < h && box[tmp->x][tmp->y][tmp->z + 1] == 0)
		{
			box[tmp->x][tmp->y][tmp->z + 1] = 1;
			new(tmp->x, tmp->y, tmp->z + 1);
		}
		if (tmp == a_tail)
		{
			++count;
			a_tail = tail;
		}
		pre = tmp;
		tmp = tmp->next;
		free(pre);
	}
	if (is_in())
		return (-1);
	return (count - 1);
}

int			main(void)
{
	int		i, j, k;

	scanf("%d %d %d", &m, &n, &h);
	getchar();
	for (i = 0; i < h; i++)
	{
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < m; k++)
			{
				scanf("%d", &box[k][j][i]);
				getchar();
				if (box[k][j][i] == 1)
					new(k, j, i);
			}
		}
	}
	if (apple == NULL)
		printf("-1");
	else
		printf("%d", check_apple());
	//destroy(&apple);
	return (0);
}
