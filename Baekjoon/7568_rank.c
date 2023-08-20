//baekjoon 덩치 7568번호

#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	int		i;
	int		j;
	int		num;
	int		count;
	int		**table;

	//사람 수 입력
	scanf("%d", &num);
	//사람 수에 따라 배열 동적할당
	if (!(table = (int **)malloc(sizeof(int *) * (num + 1))))
		return (0);
	//몸무게 키
	i = -1;
	while (++i < num)
	{
		if (!(table[i] = (int *)malloc(sizeof(int) * 2)))
			return (0);
		scanf("%d %d", &table[i][0], &table[i][1]);
	}
	table[num] = 0;
	//자신보다 덩치가 큰 사람 수 계산
	i = -1;
	while (++i < num)
	{
		j = -1;
		count = 0;
		while (++j < num)
		{
			if ((table[i][0] < table[j][0])
					&& (table[i][1] < table[j][1]))
				count++;
		}
		printf("%d", count + 1);
		//공백
		if (i + 1 < num)
			printf(" ");
	}
	/*
	   for (int i = 0; i < num; i++)
	   {
	   		count = 0;
	   		for (int j = 0; j < num; j++)
			{
				if ((table[i][0] < table[j][0])
					&& (table[i][1] < table[j][1]))
					count++;
			}
	   }
	 */
	//동적할당 해제
	i = -1;
	while (++i < num)
		free(table[i]);
	free(table);
	return (0);
}
