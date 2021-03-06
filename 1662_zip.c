//Baekjoon 1662 압축 - stack
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int				top(t_stack **head)
{
	int			cont;
	t_stack		*tmp;

	if (head == NULL || *head == NULL)
		return (0);
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	cont = tmp->content;
	return (cont);
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

int			main(void)
{
	int		i;
	int		re;
	int		tmp;
	int		len;
	t_stack	*stack = NULL;
	char	str[51] = {0, };

	scanf("%s", str); //문자열 입력
	len = strlen(str); // 길이 확인
	i = 0; 			//문자열 위치
	re = 0;			//반환값
	tmp = 0;		//숫자값
	while (i < len)
	{
		if (str[i] == '(')
		{
			push(&stack, re - 1);	//더할 값 push
			push(&stack, tmp);		//곱할 값 push
			re = 0;					//초기화
			tmp = 0;				//초기화
		}
		else if (str[i] == ')')
		{
			re *= top(&stack);		//곱할 tmp 값
			pop(&stack);			//tmp 값 꺼내기
			re += top(&stack);		//더할 re 값
			pop(&stack);			//re 값 꺼내기
		}
		else
		{
			tmp = str[i] - '0';		//tmp 값 임시 저장
			re++;					//re 값 더하기
		}
		i++;						//다음 문자열로 이동
	}
	printf("%d", re);				//반환값 출력
	clear(&stack);					//스택 비우기
	return (0);
}
