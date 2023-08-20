//시간초과
#include <stdio.h>

int			main(void)
{
	int		i, j;
	int		count;
	int		n;
	int		h[80001] = {0, };

	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++)
	{
		scanf("%d", &h[i]);
		getchar();
	}
	count = 0;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (h[j] > h[i])
				j = n;
			else
				count++;
		}
	}
	printf("%d", count);
	return (0);
}
