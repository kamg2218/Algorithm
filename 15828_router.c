//Baekjoon 15828 Router - array
#include <stdio.h>
#include <stdlib.h>

int			main(void)
{
	int		i;
	int		n;
	int		m;
	int		len; //the number of array
	int		*buf;

	scanf("%d", &n);
	getchar();
	if (!(buf = (int *)malloc(sizeof(int) * n)))
		return (0);
	//initialize
	i = -1;
	while (++i < n)
		buf[i] = 0;
	len = 0;
	while (1)
	{
		scanf("%d", &m);
		getchar();
		if (m == -1)
			break ;
		else if (m > 0 && len < n)
		{
			buf[len] = m;
			len += 1;
		}
		else if (m == 0)
		{
			i = -1;
			while (++i < len - 1)
				buf[i] = buf[i + 1];
			if (i > -1)
				buf[i] = 0;
			len -= 1;
		}
	}
	//print all the numbers
	i = -1;
	while (++i < n && buf[i])
	{
		printf("%d", buf[i]);
		if (i + 1 < n && buf[i + 1])
			printf(" ");
	}
	if (i == 0)
		printf("empty");
	free(buf);
	return (0);
}
