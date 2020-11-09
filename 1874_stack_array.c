//Baekjoon 1874 스택수열 - stack with array
#include <stdio.h>
#include <stdlib.h>

int			make_order(int n, int *num, char *order)
{
	int		i;
	int		j;
	int		num_i;
	int		order_i;
	int		stack_i;
	int		*stack;
	
	//stack 배열선언
	if (!(stack = (int *)malloc(sizeof(int) * n)))
		return (0);
	//초기화
	i = -1;
	while (++i < n)
		stack[i] = 0;
	i = -1; 	//입력받은 숫자의 인덱스
	num_i = 1; 	//오름차순의 숫자
	stack_i = 0; //스택의 인덱스
	order_i = 0; //명령 순서 인덱스

	//입력받은 숫자를 차례로 확인
	while (++i < n)
	{
		//스택의 마지막 숫자와 입력받은 숫자 비교
		if (stack_i > 0 && stack[stack_i - 1] == num[i]) //pop
		{
			//명령 순서에 pop 내용 저장
			order[order_i] = '-';
			order_i += 1;
			//스택에서 숫자 꺼내기
			stack[stack_i - 1] = 0;
			stack_i -= 1;
		}
		else	//push
		{
			j = num_i;
			//원하는 숫자가 나올떄까지 Push
			num_i -= 1;
			while (++num_i <= num[i])
			{
				//명령 순서에 push 저장
				order[order_i] = '+';
				order_i += 1;
				//스택에 숫자 저장
				stack[stack_i] = num_i;
				stack_i += 1;
			}
			if (j == num_i) //push 연산을 전혀하지 않은 경우
			{
				//불가능한 배열
				free(stack);
				return (0);
			}
			--i; //num_i == num[i] 까지 push 했기떄문!
		}
	}
	free(stack);
	return (1);
}

int			main(void)
{
	int		i;
	int		j;
	int		n;
	int		*num;
	char	*order;

	//숫자의 갯수
	scanf("%d", &n);
	getchar();
	if (!(num = (int *)malloc(sizeof(int) * (n + 1))))
		return (0);
	//숫자 배열 입력
	i = -1;
	while (++i < n)
	{
		scanf("%d", &num[i]);
		getchar();
	}
	if (!(order = (char *)malloc(sizeof(char) * (2 * n + 1))))
		return (0);
	i = -1;
	while (++i < 2 * n + 1)
		order[i] = 0;
	if (!(make_order(n, num, order))) //불가능한 배열
		printf("NO");
	else	//가능한 배열
	{
		//모든 명령 순서 출력
		i = -1;
		while (order[++i])
			printf("%c\n", order[i]);
	}
	free(num);
	free(order);
	return (0);
}
