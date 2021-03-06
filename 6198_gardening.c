//Baekjoon 6198	옥상정원 꾸미기 - stack
#include <stdio.h>
#include <stdlib.h>

typedef struct		s_stack
{
	long long		content;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

t_stack		*new(long long content)
{
	t_stack	*n;

	n = (t_stack *)malloc(sizeof(t_stack));
	if (n == NULL)
		return (NULL);
	n->content = content;
	n->prev = NULL;
	n->next = NULL;
	return (n);
}

void			push(t_stack **head, t_stack **last, long long content)
{
	t_stack		*n;
	t_stack		*tmp;

	if (!(n = new(content)))
		return ;
	if (head == NULL || *head == NULL)
	{
		*head = n;
		*last = n;
		return ;
	}
	tmp = *last;
	tmp->next = n;
	n->prev = tmp;
	n->next = NULL;
	*last = n;
}

void			pop(t_stack **head, t_stack **last)
{
	t_stack		*prev;
	t_stack		*tmp;

	if (head == NULL || *head == NULL)
		return ;
	tmp = *last;
	prev = tmp->prev;
	if (prev)
		prev->next = NULL;
	else
		*head = NULL;
	*last = prev;
	free(tmp);
}

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

int			main(void)
{
	long long	i;
	long long	count;				//볼 수 있는 정원 수
	long long	n;					//건물 수
	long long	size = 0;			//스택의 갯수
	long long	h[80001] = {0, };	//건물 층수
	t_stack		*stack = NULL;		//스택 헤드
	t_stack		*last = NULL;		//스택 마지막

	scanf("%lld", &n);				//건물 수 입력
	getchar();
	for (i = 0; i < n; i++)			//건물 층수 입력
	{
		scanf("%lld", &h[i]);
		getchar();
	}
	count = 0;						//볼 수 있는 정원 수 초기화
	for (i = 0; i < n; i++)
	{
		//스택의 마지막 건물 층수와 현재 건물을 비교,
		//현재의 건물을 스택에 있는 건물에서 볼 수 있는 지 확인
		//현재의 건물을 볼 수 없는 경우, pop으로 스택에서 제거
		while (last && last->content <= h[i])
		{
			pop(&stack, &last);
			--size;
		}
		//스택에 남아 있는 건물들은 현재의 건물을 볼 수 있으므로,
		//count에 갯수를 더해준다.
		count += size;
		//현재의 건물을 스택에 저장
		push(&stack, &last, h[i]);
		++size;
	}
	//정원을 볼 수 있는 건물의 수 출력
	printf("%lld", count);
	//스택 해제
	clear(&stack);
	return (0);
}
