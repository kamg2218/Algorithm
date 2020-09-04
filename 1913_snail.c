//Baekjoon 1913 달팽이

#include <stdio.h>
#include <stdlib.h>
//행 채우기
int			fill_row(int **snail, int *row, int num, int n)
{
	int		i;
	int		count;

	count = num;
	//값 채우기
	i = -1;
	while (++i < n)
	{
		snail[row[0]][row[1]] = count;
		--count;
		row[0] += row[2];
	}
	//행렬 위치 조정
	row[0] -= row[2];
	row[1] += row[3];
	//행의 방향 반대로 변경
	row[2] *= -1;
	//마지막 수 반환
	return (count);
}
//열 채우기
int			fill_col(int **snail, int *col, int num, int n)
{
	int		i;
	int		count;

	count = num;
	//값 채우기
	i = -1;
	while (++i < n)
	{
		snail[col[0]][col[1]] = count;
		--count;
		col[1] += col[3];
	}
	//행렬 위치 조정
	col[1] -= col[3];
	col[0] += col[2];
	//열의 방향 반대로 변경
	col[3] *= -1;
	//마지막 수 반환
	return (count);
}
//달팽이 만들기
void		make_snail(int **snail, int n)
{
	int		i;
	int		j;
	int		rc[4];
	int		num;

	rc[0] = 0; //행
	rc[1] = 0; //열
	rc[2] = 1; //행 방향
	rc[3] = 1; //열 방향
	num = n * n; //시작 값
	num = fill_row(snail, rc, num, n); //첫 열 채우기
	//달팽이 채우기
	i = n;
	while (--i > 0)
	{
		num = fill_col(snail, rc, num, i); //행 채우기-열 이동하면서 채우기
		num = fill_row(snail, rc, num, i); //열 채우기-행 이동하면서 채우기
	}
	//달팽이 출력
	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
			printf("%d ", snail[i][j]);
		printf("\n");
	}
}

int			main(void)
{
	int		n;
	int		num;
	int		row;
	int		col;
	int		**snail;

	//달팽이 크기 입력
	scanf("%d", &n);
	getchar();
	//출력할 값 입력
	scanf("%d", &num);
	//메모리 할당
	if (!(snail = (int **)malloc(sizeof(int *) * (n + 1))))
		return (0);
	row = -1;
	while (++row < n)
	{
		if (!(snail[row] = (int *)malloc(sizeof(int) * (n + 1))))
			return (0);
		snail[row][n] = 0;
	}
	snail[row] = 0;
	//달팽이 만들기
	make_snail(snail, n);
	//출력할 값의 위치 찾기 및 메모리 해제
	row = -1;
	while (++row < n)
	{
		col = -1;
		while (++col < n)
		{
			if (snail[row][col] == num)
			{
				printf("%d ", row + 1);
				printf("%d", col + 1);
			}
		}
		free(snail[row]);
	}
	free(snail);
	return (0);
}
