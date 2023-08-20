//Baekjoon 2257 화학식량
#include <stdio.h>

int			chemical_food(char c)
{
	if (c == 'C')
		return (12);
	else if (c == 'O')
		return (16);
	else if (c == 'H')
		return (1);
	else
		return (0);
}

int			food_sum(char *ch, int *i)
{
	int		sum;
	int		new;

	sum = 0;
	while (ch[++(*i)])
	{
		if (ch[*i] == ')')
			return (sum);
		if (ch[*i] == '(')
			new = food_sum(ch, i);
		else if (ch[*i] != ')')
			new = chemical_food(ch[*i]);
		if (ch[++*i] && ch[*i] != '(' && ch[*i] != ')'
				&& !(chemical_food(ch[*i])))
			new = new * (ch[*i] - '0');
		else
			--*i;
		sum += new;
	}
	return (sum);
}

int			main(void)
{
	int		i = -1;
	char	ch[101] = {0, };

	scanf("%s", ch);
	printf("%d", food_sum(ch, &i));
	return (0);
}
