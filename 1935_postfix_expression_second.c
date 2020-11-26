//Baekjoon 1935 후위표시식2 - stack
#include <stdio.h>
#include <stdlib.h>

typedef struct		s_stack
{
	double			content;
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

t_stack		*new(double content)
{
	t_stack	*n;

	n = (t_stack *)malloc(sizeof(t_stack));
	if (n == NULL)
		return (NULL);
	n->content = content;
	n->next = NULL;
	return (n);
}

void			push(t_stack **head, double content)
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
		return ;
	tmp = *head;
	prev = NULL;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (prev)
		prev->next = NULL;
	else
		*head = NULL;
	free(tmp);
}

double			top(t_stack **head)
{
	double		cont;
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
	int			n;
	double		num[27] = {0, };
	double		result;
	char		str[101] = {0, };
	t_stack		*head;

	scanf("%d", &n); //입력 받는 문자 수
	getchar();
	scanf("%[^\n]s", str); //수식
	getchar();
	i = -1;
	while (++i < n)
	{
		scanf("%lf", &num[i]); //문자에 따른 숫자 값
		getchar();
	}
	head = NULL;
	i = 0;
	result = 0;
	while (str[i])
	{
		//해당 숫자 값 스택에 저장
		if (str[i] >= 'A' && str[i] <= 'Z')
			push(&head, num[str[i] - 'A']);
		//연산인 경우, 스택에서 숫자 2개를 꺼내어 계산
		else
		{
			result = top(&head);
			pop(&head);
			if (str[i] == '*')
				result = result * top(&head);
			else if (str[i] == '+')
				result = result + top(&head);
			else if (str[i] == '-')
				result = top(&head) - result;
			else if (str[i] == '/')
				result = top(&head) / result;
			pop(&head);
			//계산 값 스택에 저장
			push(&head, result);
		}
		++i;
	}
	//결과 값 출력
	printf("%.2f\n", top(&head));
	clear(&head);
	return (0);
}
