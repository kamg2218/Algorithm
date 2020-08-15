//Baekjoon 1158 오세푸스 - circular linked list
#include <stdio.h>
#include <stdlib.h>
//define node
typedef struct	t_node
{
	int				x;
	struct t_node	*next;
}				s_node;
//create node
s_node			*create_node(int y)
{
	s_node		*new;

	if (!(new = (s_node *)malloc(sizeof(s_node))))
		return (0);
	new->x = y;
	new->next = NULL;
	return (new);
}

int				main(void)
{
	int			i;
	int			n; //number
	int			k; //count
	s_node		*node;
	s_node		*last;
	s_node		*new;

	scanf("%d %d", &n, &k);
	i = n + 1;
	node = NULL;
	while (--i > 0)
	{
		new = create_node(i);
		new->next = node;
		if (node == NULL)
			last = new;
		node = new;
	}
	last->next = node;
	//원형 연결 리스트
	i = 0;
	while (++i < k)
		last = last->next;
	//k - 1 번 이동
	new = last;
	node = last->next;
	//다음 노드 변경
	if (node)
		printf("<");
	//출력시작
	while (node)
	{
		new->next = node->next; //다음 노드 변경
		printf("%d", node->x);
		if (node->x == node->next->x)
			break ;
		//노드 한 개일 경우, 출력 중단
		last = node;
		i = 0;
		while (++i < k)
			new = new->next;
		//k - 1번 이동
		node = new->next; //다음 노드 변경
		free(last); //할당된 메모리 해제
		if (node)
			printf(", ");
	}
	free(node);
	printf(">");
	return (0);
}
