//Baekjoon 10773 제로
#include <stdio.h>
#include <stdlib.h>

int			main(void)
{
	int		i;
	int		n;
	int		m;
	int		len;
	int		*num;

	scanf("%d", &n);
	getchar();
	if (!(num = (int *)malloc(sizeof(int) * n)))
		return (0);
	len = 0;
	i = -1;
	while (++i < n)
	{
		scanf("%d", &m);
		getchar();
		if (m != 0)
		{
			num[len] = m;
			++len;
		}
		else
			num[--len] = 0;
	}
	i = -1;
	n = 0;
	while (++i < len)
		n += num[i];
	printf("%d", n);
	free(num);
	return (0);
}
