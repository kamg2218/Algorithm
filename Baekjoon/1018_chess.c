//Baekjoon 1018 체스판다시칠하기
#include <stdio.h>
#include <stdlib.h>

int		check_color(int ch, int row, int col, char **board)
{
	//row : start row, col : start col
	int		i; //row
	int		j; //col
	int		count;

	count = 0;
	i = -1;
	while (++i < 8) //8 * 8 chess board
	{
		j = -1;
		while (++j < 8)
		{
			//if the value of row + col is even
			if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1))
			{
				if (ch != board[row + i][col + j])
					count++;
			}
			//if the value of row + col is odd
			else
			{
				if (ch == board[row + i][col + j])
					count++;
			}
		}
	}
	return (count);
}

int		find_min(int ch, int row, int col, char **board)
{
	int		i; //row count
	int		j; //col count
	int		min;
	int		count;

	i = -1;
	min = row * col; //default max
	while (++i < row - 7) // 8 * 8 chess board
	{
		j = -1;
		while (++j < col - 7)
		{
			count = check_color(ch, i, j, board); //find the number of square
			//compare the value
			if (count < min)
				min = count;
		}
	}
	return (min);
}

int		main(void)
{
	int		i; //row count
	int		j; //col count
	int		row;
	int		col;
	int		min; //minimum number
	int		count; //number of square
	char	**board;

	scanf("%d %d", &row, &col);
	getchar(); //fflush(stdin); //clear buffer
	if (!(board = (char **)malloc(sizeof(char *) * (row + 1))))
		return (0);
	i = -1;
	while (++i < row)
	{
		if (!(board[i] = (char *)malloc(sizeof(char) * (col + 1))))
			return (0);
		j = -1;
		while (++j < col)
			scanf("%c", &board[i][j]);
		board[i][j] = 0;
		getchar(); //fflush(stdin); //clear buffer
	}
	board[i] = 0;
	//find the number
	min = find_min('W', row, col, board); //the first square is 'white'
	count = find_min('B', row, col, board); //the first square is 'black'
	//compare the minimum
	if (count < min)
		min = count;
	//print the result
	printf("%d", min);
	//free allocated memory
	i = -1;
	while (++i < row)
		free(board[i]);
	free(board);
	return (0);
}
