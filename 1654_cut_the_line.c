//Baekjoon 1654 랜선 자르기 - 이분탐색
#include <stdio.h>
#include <stdlib.h>

long long		count_line(long long *line, long long k, long long num)
{
	long long	i;
	long long	count;

	if (num == 0)
		return (0);
	count = 0;
	i = -1;
	while (++i < k)
		count += line[i] / num;
	return (count);
}

int			main(void)
{
	long long	k;
	long long	n;
	long long	i;
    long long   cnt;
    long long   mid;
	long long 	num;
	long long	min;
	long long	max;
	long long	*line;

	scanf("%lld %lld", &k, &n);
	getchar();
	if (!(line = (long long *)malloc(sizeof(long long) * k)))
		return (0);
	i = -1;
	while (++i < k)
	{
		scanf("%lld", &line[i]);
		getchar();
	}
	max = line[0];
	i = 0;
	while (++i < k)
	{
		if (line[i] > max)
			max = line[i];
	}
	min = 1;
    while (min <= max)
    {
		printf("%lld, %lld, %lld\n", min, max, num);
        mid = (min + max) / 2;
        cnt = count_line(line, k, mid);
        if (cnt < n)
            max = mid - 1;
        else if (cnt >= n)
    	{
             min = mid + 1;
             num = mid;   
    	}           
    }
	printf("%lld", num);
	free(line);
	return (0);
}
